#include <iostream>
#include <vector>

using namespace std;

vector<int> num;
long long dp[100001];

int main() {
  int n , input;
  cin >> n;
  
  for(int i =0; i<n; i++){
    cin >> input;
    num.push_back(input);
  }

  long long  ans=-1001;
  
  dp[0] = num[0];

  for(int i =1; i< n;i++){

    if(num[i] >= 0){
      if(dp[i-1] < 0 ){
        dp[i] = num[i];
      }
      else{
        dp[i] = dp[i-1] + num[i];
      }
    }

    else{ // minus
      if(dp[i-1] < 0){
        dp[i] = num[i];
      }
      else{
        dp[i] = dp[i-1] + num[i];
      }
      
    }
  }
  
  for(int i =0; i<n; i++){
    //cout << dp[i] << " ";
    if(ans < dp[i]){
      ans = dp[i];
    }
  }
  
  cout << ans;

  return 0;
} 