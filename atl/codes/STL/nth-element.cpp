struct node
{
    int val,pos;
}A[10];

int cmp(node a,node b)
{
    return a.pos < b.pos;
}

int main()
{
    int a[10] = {-1,3,9,1,4,5,8,7,6,2};
    int i;
    while(0){
        cin >> i;
        nth_element(a+1,a+i,a+9+1);
        cout << a[i];
    }
    for(int i=1;i<=9;i++) A[i].pos = 10-i,A[i].val=i;
    nth_element(A+1,A+4,A+9+1,cmp);
    printf("%d\n",A[4].pos);
}