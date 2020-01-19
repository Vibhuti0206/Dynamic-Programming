#include<bits/stdc++.h>
using namespace std;
void count(int n,int k,int arr[])
{
    int zero_count =0;
    int left =0;
    int right =0;
    int length =0;
    int max_length =0;
    int lp =-1; //left index of the subarray having max number of 1
    int rp=-1;  //right index of the subarray having max number of 1
    for(int i=0;i<n;i++)
    {
        if(arr[i] == 1)
        {
            length = right - left + 1;
            right++;
        }
        else
        {
             zero_count++;
             while(zero_count > k )
                {
                    if(arr[left] == 0)
                      zero_count--;
                    left++;
                }
                length = right - left + 1;
                right++;
            
        }
        if(length > max_length)
        {
            max_length = length;
            rp = right - 1;
            lp = left; 
        }
    }
    cout<<max_length<<endl;
    for(int i=0;i<lp;i++)
     cout<<arr[i]<<" ";
    if(lp != -1)
    {
        for(int i=lp; i<=rp;i++)
          cout<<1<<" ";
    }
    for(int i=rp+1;i<n;i++)
     cout<<arr[i]<<" ";

}
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
     cin>>arr[i];
    count(n,k,arr);
    return 0;
}
Close
