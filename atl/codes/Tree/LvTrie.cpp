#include<bits/stdc++.h>

using namespace std;

const int SIZE = 1005;
int a[SIZE];

const int maxn = 1000005;

int chd[maxn*32][2],nn = 0,num[maxn*32];

void init(){
    nn = 1;
    memset(chd[0],-1,sizeof(chd[0]));
    //memset(num,0,sizeof(num));
    num[0] = 0;
}

void insert(int x){
    int p = 0;
    //printf("--insert\n");
    for(int i = 31;i >= 0;i--){
        int t = (x>>i)&1;
        //printf("%d\n",p);
        if(chd[p][t]==-1){
            chd[p][t] = nn;
            memset(chd[nn],-1,sizeof(chd[nn]));
            num[nn] = 0;
            nn++;
        }
        p = chd[p][t];
    }
    num[p]++;
    //printf("num = %d\n",num[p]);
}

int remove(int x,int p = 0,int d = 31){
    if(d == -1){
        num[p]--;
        if(num[p] == 0){
            return 1;
        }
        return 0;
    }
    int ret;
    int t = (x>>d)&1;
    int s = chd[p][t];
    ret = remove(x,s,d-1);
    if(ret) chd[p][t] = -1;
    if(chd[p][0]==-1&&chd[p][1]==-1) return 1;
    return 0;
}

int find(int x){
    int p = 0;
    int ret = 0;
    //printf("find---\n");
    for(int i = 31;i >= 0;i--){
        //printf("%d\n",p);
        int t = (x>>i)&1;
        if(chd[p][t]==-1) t^=1;
        p = chd[p][t];
        ret <<= 1;
        ret |= t;
    }
    //printf("num = %d\n",num[p]);
    return ret;
}
// find the most distant number
int f(int n) {
    int p = 0;
    int ret = 0;
    for(int i = 31; i >= 0; i--) {
        int t = (n >> i) & 1 ^ 1;
        if(chd[p][t] == -1) t ^= 1;
        p = chd[p][t];
        ret <<= 1;
        ret |= t;
    }
    //printf("ret=%d\n",ret);
    return ret ^ n;
}