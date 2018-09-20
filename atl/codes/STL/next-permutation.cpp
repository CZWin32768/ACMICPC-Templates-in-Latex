// Example for Array:
int a[N];
sort(a, a+N);
next_permutation(a, a+N);
// Example for vector:
vector<int> ivec;
sort(ivec.begin(), ivec.end());
next_permutation(ivec.begin(), ivec.end());
//Example for loop:
vector<int> myVec;
sort(myVec.begin(),myVec.end());
do{
    for (i = 0 ;i < size;i ++ ) cout << myVec[i] << " \t " ;
    cout << endl;
}while (next_permutation(myVec.begin(), myVec.end()));