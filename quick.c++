#include <iostream>
#include <iomanip>
#include<string>
#include <cmath>
#include<algorithm>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<stack>
#include<queue>
#define ll long long
using namespace std;
void fast() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
}
int partition(int arr[],int begin,int end){
    int i=begin,j=end,pivot=i;
    while(1){
        while(arr[pivot]<=arr[j] && pivot!=j){
            j--;
        }
      if(pivot==j){
          break;
      }else if(arr[pivot]>arr[j]){
          swap(arr[pivot],arr[j]);
          pivot=j;
      }
      while(arr[pivot]>=arr[i] && pivot!=i){
            i++;
        }
        if(pivot==i){
            break;
        }else if(arr[pivot]<arr[i]){
            swap(arr[pivot],arr[i]);
            pivot=i;
        }
    }
    return pivot;
}
void quickSort(int arr[],int begin,int end){
    if(begin<end){
        int piv=partition(arr,begin,end);
        quickSort(arr,begin,piv-1);
        quickSort(arr,piv+1,end);
    }
}
int main() {
    fast();
    int n;cin>>n;
int *arr=new int[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
quickSort(arr,0,n-1);
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
}
