struct node
{
    int x,y;
};

struct cmp{
    bool operator()(node a,node b)
    {
        if(a.x==b.x) return a.y > b.y;
        return a.x < b.x;
    }
};

priority_queue<int,vector<int>,greater<int> > q;
priority_queue<node,vector<node>,cmp > qq;
