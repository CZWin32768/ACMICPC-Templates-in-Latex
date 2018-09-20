const int SIZEP = 10005;
const int SIZET = 1000005;
char pat[SIZEP];

int Next[SIZEP];
char text[SIZET];
int lt,lp;

void getNext()
{
    for(int i=0,j=-1;i<=lp;i++,j++)
    {
        Next[i] = j;
        while(j!=-1 && pat[i]!=pat[j]) j = Next[j];
    }
}

int query()
{
    int cnt = 0;
    for(int i=0,j=0;i<=lt;i++,j++)
    {
        if(j==lp) cnt++;
        while(~j && text[i] != pat[j]) j = Next[j];
    }
    return cnt;
}
