#include<iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef unsigned long long int llint;

int main()
{
  llint N=0;
  char ORI[10000];
  int cal[10000]={0};
  int x;//string_length
  int i,temp,flag=0;
  char str_temp[1];

  cin >> ORI;//最初の文字列
  x = strlen(ORI);

  cin >> N;//入力数
  rep(i,N){
    cin >> temp;//temp=1は１文字目
    cal[temp-1]++;
    cal[x-temp]++;
  }
  rep(i,(x-1)/2+1){//文字列の半分までを考慮すればよい
    if((cal[i]+flag)%2 == 1){//自分を入れ替えるか、前が入れ替わっているかを同時に判定
     flag=1;//入れ替えた時は１
     str_temp[0]=ORI[i];//スワップ
     ORI[i]=ORI[x-1-i];
     ORI[x-1-i]=str_temp[0];
    }else{
     flag=0;//入れ替えない時は0
    }
  }
   cout << ORI <<endl;
   return 0;
}


