#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<iostream>
#include<iomanip>
#include<map>
#include<queue>
#include<vector>
#include<stack>
#include<set>
#include<string>
#include<sstream>
#include<complex>

#define pb push_back
#define clr clear()
#define sz size()
#define EPS (1e-8)
#define INF (1<<25)
#define fs first
#define sc second

#define rep(i,n) for(int i=0;i<n;i++)
#define let(i,a) __typeof(a)i=(a)
#define all(a) (a).begin(),(a).end()
#define each(i,a) for(let(i,(a).begin());i!=(a).end();i++)
#define ZINIT(i) memset(i,0,sizeof(i))
#define EQ(a,b) (abs((a)-(b))<EPS)

using namespace std;

typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;

int s,n,t,m;
string weekday,time_time;
double p;

double solve();

//シミュレーションでやる
//一週間の全秒についてｓの範囲かつボーナスタイムの範囲の場合
//秒数を++する
int main(){
  int n;
  while( cin >>s>>n>>t>>weekday>>time_time>>p>>m && weekday != "none"){
    cout << solve() << endl;
  }
  return 0;
}

double solve(){
	int chance_count;
	int mytime=m*t;
	if(weekday == "All" && time_time == "All"){
		int all_count=0;
		while(mytime > all_count * t+s){
			all_count++;
		}
		chance_count=all_count;
	}else if ( weekday == "All") {
		int b_t = 12*60;
		int z=0;
		while( b_t > t*z + s ){
		    z++;
		}	
		int mytime = t*m;
		int starttime = b_t - t*z +s;
		int tmp_count = 1;
		int day_count=0;
		while( mytime > t*z + s ){
			mytime -= b_t;
			mytime -= b_t;
			if (tmp_count == 1){
				mytime -= starttime;
			}
			day_count++;
		}
		int y =0; 
		while( mytime >= t && y <= z){
			mytime -= t;
			y++;	
		}
		int onemore=0;
		if(mytime >= s){
			onemore++;
		}
		//
		chance_count = z*day_count + y + onemore;
	
	} else {
		int week_count;
		int b_t = 12*60;
		int x=0;
		while( b_t > t*x + s){
		    x++;
		}	
		int mytime = t*m;
		int starttime = b_t - t*x +s;
		int tmp_count = 1;
		while( mytime > t*x + s ){
			mytime -= t*x + s;
			mytime -= 7*24*60;
			if (tmp_count == 1){
				mytime -= starttime;
			}
			week_count++;
			tmp_count++;
		}
		int y =0; 
		while( mytime >= t && y <= x){
			mytime -= t;
			y++;	
		}
		int onemore=0;
		if(mytime >= s){
			onemore++;
		}
		chance_count = (x + 1)*week_count + y + onemore;
	}
	return ( pow(1- 1/p, n*chance_count));
}

