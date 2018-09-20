const int MAXN=100010;
int t1[MAXN],t2[MAXN],c[MAXN];

//sa[1...n]->[0,N) rank[0...n-1]->[1,N]  height[1...n]
bool cmp(int *r,int a,int b,int l)
{
    return r[a] == r[b] && r[a+l] == r[b+l];
}
void da(int str[],int sa[],int Rank[],int height[],int n,int m)
{
    n++;
    int i, j, p, *x = t1, *y = t2;
    for(i = 0;i < m;i++)c[i] = 0;
    for(i = 0;i < n;i++)c[x[i] = str[i]]++;
    for(i = 1;i < m;i++)c[i] += c[i-1];
    for(i = n-1;i >= 0;i--)sa[--c[x[i]]] = i;
    for(j = 1;j <= n; j <<= 1)
    {
        p = 0;
        for(i = n-j; i < n; i++)y[p++] = i;
        for(i = 0; i < n; i++)if(sa[i] >= j)y[p++] = sa[i] - j;
        for(i = 0; i < m; i++)c[i] = 0;
        for(i = 0; i < n; i++)c[x[y[i]]]++;
        for(i = 1; i < m;i++)c[i] += c[i-1];
        for(i = n-1; i >= 0;i--)sa[--c[x[y[i]]]] = y[i];
        swap(x,y);
        p = 1; x[sa[0]] = 0;
        for(i = 1;i < n;i++)
            x[sa[i]] = cmp(y,sa[i-1],sa[i],j)?p-1:p++;
        if(p >= n)break;
        m = p;
    }
    int k = 0;
    n--;
    for(i = 0;i <= n;i++)Rank[sa[i]] = i;
    for(i = 0;i < n;i++)
    {
        if(k)k--;
        j = sa[Rank[i]-1];
        while(str[i+k] == str[j+k])k++;
        height[Rank[i]] = k;
    }
}
int Rank[MAXN],height[MAXN];

char str[MAXN];
int r[MAXN];
int sa[MAXN];
int A[MAXN];

int main()
{
    while(~scanf("%s", str)) {
        int n = strlen(str);
        for(int i = 0; i < n; i++) r[i] = str[i];
        r[n] = 0;
        da(r,sa,Rank,height,n,128);
        int res = n;
        int temp = n;
        for(int i = Rank[0]; i > 1; i--) {
            temp = min(temp, height[i]);
            res += temp;
            res %= 256;
        }
        temp = n;
        for(int i = Rank[0] + 1; i <= n; i++) {
            temp = min(temp, height[i]);
            res += temp;
            res %= 256;
        }
        res %= 256;
        printf("%d\n",res);
    }
    return 0;
}