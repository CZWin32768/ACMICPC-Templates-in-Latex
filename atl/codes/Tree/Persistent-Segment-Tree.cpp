// calc number of different prefix in the string list [s_l, ..., s_i, ..., s_r]
#include<bits/stdc++.h>
using namespace std;

namespace Trie {
    const int SIZE = 100005;
    int node[SIZE][26];
    int tot, bel[SIZE];
    void Insert(string& str) {
        int cur = 0;
        for(int i = 0; i < str.size(); i++) {
            int p = str[i] - 'a';
            if(node[cur][p] == 0) {
                tot++;
                node[cur][p] = tot;
                memset(node[tot], 0, sizeof(node[tot]));
            }
            cur = node[cur][p];
            bel[cur] = 0;
        }
    }
    void init() {
        tot = 0;
        memset(node[0], 0, sizeof(node[0]));
    }
}

namespace PST {
    const int MAXN = 100005;
    const int M = MAXN * 40;
    int tot;
    int n;
    int T[MAXN],lson[M],rson[M],c[M];
    void init(int _n) {
        tot = 0;
        n = _n;
    }
    int build(int l,int r) {
        int root = tot++;
        c[root] = 0;
        if(l != r) {
            int mid = (l+r)>>1;
            lson[root] = build(l,mid);
            rson[root] = build(mid+1,r);
        }
        return root;
    }
    int update(int root,int pos,int val) {
        int newroot = tot++, tmp = newroot;
        c[newroot] = c[root] + val;
        int l = 1, r = n;
        while(l < r) {
            int mid = (l+r)>>1;
            if(pos <= mid) {
                lson[newroot] = tot++; rson[newroot] = rson[root];
                newroot = lson[newroot]; root = lson[root];
                r = mid;
            }
            else {
                rson[newroot] = tot++; lson[newroot] = lson[root];
                newroot = rson[newroot]; root = rson[root];
                l = mid+1;
            }
            c[newroot] = c[root] + val;
        }
        return tmp;
    }
    int query(int root,int pos) {
        int ret = 0;
        int l = 1, r = n;
        while(pos < r) {
            int mid = (l+r)>>1;
            if(pos <= mid) {
                r = mid;
                root = lson[root];
            }
            else {
                ret += c[lson[root]];
                root = rson[root];
                l = mid+1;
            }
        }
        return ret + c[root];
    }
}
string s[PST::MAXN];

int main() {
    int N;
    while(~scanf("%d",&N)) {
        PST::init(N);
        Trie::init();
        for(int i = 1; i <= N; i++) {
            cin >> s[i];
            Trie::Insert(s[i]);
        }
        PST::T[N+1] = PST::build(1, N);
        for(int i = N; i >= 1; i--) {
            int cur = 0;
            PST::T[i] = PST::T[i+1];
            for(int j = 0; j < s[i].size(); j++) {
                int p = s[i][j] - 'a';
                cur = Trie::node[cur][p];
                if(Trie::bel[cur]) {
                    //Eliminate the influence of appeared prefix
                    PST::T[i] = PST::update(PST::T[i], Trie::bel[cur], -1);
                }
                Trie::bel[cur] = i; //record the last position of prefix 
            }

            PST::T[i] = PST::update(PST::T[i],i,s[i].size());
        }
        int Q;
        scanf("%d",&Q);
        int Z = 0;
        while(Q--) {
            int l, r;
            scanf("%d%d",&l,&r);
            l += Z; l %= N;
            r += Z; r %= N;
            if(l > r) swap(l, r);
            Z = PST::query(PST::T[l+1],r+1);
            printf("%d\n",Z);
        }
    }
}