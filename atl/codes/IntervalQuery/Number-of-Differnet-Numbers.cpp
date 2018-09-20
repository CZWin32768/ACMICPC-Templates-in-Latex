int N,M;
const int SIZE = 50005;
int c[SIZE], A[SIZE], Next[SIZE], res[200005], show[1000005];
bool fir[SIZE];
struct Q{
  int l,r;
  int pos;
} q[200005];
int lowbit(int k) {return k&(-k);}
void modify(int n,int v){
  while(n <= N){
    c[n] += v;
    n += lowbit(n);
  }
}
int sum(int n) {
  int ans = 0;
  while(n > 0) {
      ans += c[n];
      n -= lowbit(n);
  }
  return ans;
}
int cmp(Q a, Q b){
  return a.l < b.l;
}
int main()
{
  scanf("%d",&N);
  for(int i=1;i<=N;i++) scanf("%d",&A[i]);
  for(int i=N;i>=1;i--){
    if(!show[A[i]]){
        show[A[i]] = i;
        fir[i] = true;
    }
    else{
        Next[i] = show[A[i]];
        fir[Next[i]] = false;
        fir[i] = true;
        show[A[i]] = i;
    }
  }
  scanf("%d",&M);
  for(int i=1;i<=M;i++){
      scanf("%d%d",&q[i].l,&q[i].r);
      q[i].pos = i;
  }
  sort(q+1,q+1+M,cmp);
  for(int i=1;i<=N;i++)
    if(fir[i])
    {
        modify(i,1);
    }
  int qtemp = q[1].l;
  int ptr = 1;
  for(int i=1;i<=M;i++){
    for(;ptr<q[i].l;ptr++){
      if(fir[ptr]){
        modify(ptr,-1);
        fir[ptr] = false;
        if(Next[ptr])
        {
          fir[Next[ptr]] = true;
          modify(Next[ptr],1);
        }
      }
    }
    ptr = q[i].l;
    qtemp = q[i].l;
    res[q[i].pos] = sum(q[i].r) - sum(q[i].l-1);
  }
  for(int i=1;i<=M;i++) printf("%d\n",res[i]);
  return 0;
}
