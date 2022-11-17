#include <bits/stdc++.h>
using namespace std;


int ceilingIndex(vector<int>& vec, vector<int>& endIndex, int l, int r, int key) { //returns the index of smallest element among elements at indices in endIndex greater than key
    int mid;
    int best = -1;
    while(l<=r) {
        mid = l + (r-l)/2;
        if(vec[endIndex[mid]]<=key) {
            l = mid+1;
        } else {
            r = mid-1;
            best = mid;
        }
    }
    return best;
}

vector<int> LIS(vector<int>& input, int begin, int end) { //LIS in input between begin and end, inclusive
    //This algo deals stores indexes and not the elements so that it is possible
    //to construct the LIS

    int n = end-begin+1;
    
    if(n<1) {vector<int> empty; return empty;}                               //handle empty case
    
    vector<int> endIndex(n+1,-1);                                            //stores end (or tail) indexes for each active subsequence
    vector<int> previousIndex(n+1,-1);                                       //stores previous index for each index, except elements that might be first element of LIS

    endIndex[0]=begin;                                                       //initialise endIndex

    int length = 1;                                                          //length of lis found so far

    for(int i=begin+1;i<=end;i++) {
        if(input[i]<input[endIndex[0]]) {
            endIndex[0] = i;                                                 //new smallest, might initiate new LIS
        } else if(input[i]>=input[endIndex[length-1]]) {                      //new possible last for LIS, add new element index
            previousIndex[i] = endIndex[length-1];                           //current last index is the previous index for i
            endIndex[length] = i;                                            //append new active subsequence
            length++;                                                        //with end element index as i
        } else /* if(input[i]<input[endIndex[length-1]]) */{
            int ceil = ceilingIndex(input, endIndex, 0, length-1, input[i]); //retrieve the smallest input element among end elements greater than input[i]
            //if(input[endIndex[ceil-1]]!=input[i]) {
            endIndex[ceil] = i;                                              //update that end index
            previousIndex[i] = endIndex[ceil-1];                             //update the previous index for the new end index
            //}
        }
    }
    //this is code finding non-decreasing sequence
    //to find strictly increasing sequence, comment out commented code and change
    //>= to > on line 38
    
    //Now, using the vector previousIndex, we can retrieve the LIS ending at any index.
    //We construct the LIS, with the observation that the last element of LIS is 
    //the element at last index in endIndex.
    //Also, since endIndex will be of no use after initialisation of this loop,
    //we store our answer in endIndex to save memory
    for(int currentIndex = endIndex[length-1], i=length-1;i>=0;currentIndex = previousIndex[currentIndex], i--) {
        endIndex[i] = input[currentIndex];
    }
    endIndex.resize(length);
    return endIndex;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
    cin>>n;
    vector<int> input(n);
    for(int i=0;i<n;i++) {
        cin>>input[i];
    }
    vector<int> answer = LIS(input,0,n-1);
    cout<<answer.size()<<"\n";
    for(int i=0;i<answer.size();i++) {
        cout<<answer[i]<<" ";
    }
    cout<<"\n";
	return 0;
}


