#include <iostream>
#include <vector>
using namespace std;
int c=0;
int inversion(vector<int>& a , vector<int>& b){      
    int i=0;
    int j=0; 
    int count=0;
    while(i<a.size() && j<b.size()){
        if((long long)a[i]>(long long)2*b[j]){
            count += (a.size()-i);
            j++;           // j=2   i=0 count=2
        } else { // a[i]<=b[j]
            i++;
        }
    }
    return count;
}
void merge(vector<int>& a , vector<int>& b, vector<int>& res){
    int i=0, j=0, k=0;
    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]) res[k++]=a[i++]; 
        else res[k++]=b[j++];
    }
    if(i==a.size()){
        while(j<b.size()){
            res[k++]=b[j++];
        }    }
    if(j==b.size()){
        while(i<a.size()){
            res[k++]=a[i++];
        }
    }
}
int mergeSort(vector<int>& v){
    int n=v.size();   // {5,1,3,0,4,9,6}           5,1,3  0,4,9,6     5  1,3   1  3 
    if(n==1) return 0;
    int n1=n/2, n2=n-n/2; 
    vector<int> a(n1),b(n2);
    //copy paste
    for(int i=0;i<n1;i++){
        a[i]=v[i]; 
    }
    for(int i=0;i<n2;i++){
        b[i]=v[i+n1];
    }
    mergeSort(a);      //c=2
    mergeSort(b);      // 0,4,9,6,       
    // inversion             // c=0        a= 5      b=1,3
    c += inversion(a,b);             // 5    1,3            inversion=2         c=2
    merge(a,b,v); //merging two sorted arrays 
    a.clear();
    b.clear();
    return c;
}
int main(){
    int arr[]={5,1,3,0,4,9,6};
    int n1=sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr,arr+n1); //copy paste of the given array
    for(int i=0;i<n1;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl<<endl<<"After sorting ";
    mergeSort(v);
    for(int i=0;i<n1;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl<<"Number of required such pairs ";
    cout<<mergeSort(v);
}