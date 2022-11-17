/*

10 3           q n
1 7 3 6 9 4 9 3 9 6                a

1 2 3 4 5 6 7 8 9 10
1 0 2 1 0 2 1 0 3 0    count_array    count_array[i] = array me kitni baar i hai
1 1 3 4 4 6 7 7 10 10  prefix sum array



1 8 11 17 26 30 ......

5 8                   =3  5<=x<=8  pref[8]-pref[5-1]
3 5                   =19
4 9                   =39


number of elements in the given array that are greater than or equal
to l and less than or equal to r

O(nq)
O(n+q)

ll n;
cin>>n;
vector<int> a(n);
for(int i=0;i<n;i++) {
	cin>>a[i];
}
vector<int> cnt(1e6+1,0);
for(int i=0;i<n;i++) {
	cnt[a[i]]++;
}
vector<int> pref(1e6+1); //prefix sum array
pref[0]=1;
for(int i=1;i<=1e6;i++) {
	pref[i] = pref[i-1]+cnt[i];
}	

for(int i=0;i<q;i++) {
	cin>>l>>r;
	if(l==0) cout<<pref[r];
	else cout<<pref[r]-pref[l-1];
}

1 <= n <= 1000000
1 <= q <= 1000000
0 <= a[i] <= 1000000


O(n+q)




01011010
10101101
00101101
01110010
10110001

0
1
0
1
1
0
1
0

0 1 1 2 3 3 4 4


n*logn
q*logn

q*n

4e10



2243.....

a[i][j] 

a[7][2]


*/