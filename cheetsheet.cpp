#include <stdio.h>
#include <vector>
#include <deque>
#include <iostream>
#include <string.h>
#include <map>


using namespace std;

int main()
{
// ----------  VECTOR  ---------- //
/* --- 宣言 --- */
vector<int> v1;
vector<int> v2(10);
vector<int> v3 = v1;
vector<int> v4(v1);

/* --- 操作 --- */
v1.front();               //先頭の要素を取得
v1.back();                //末尾の要素を取得
v1.push_back(10);         //末尾に要素を追加
v1.pop_back();            //末尾に要素を追加

v1.size();                //要素数を取得
v1.empty();               //bool型で空ならtrue、その他はfalseを返す
v1.clear();               //空のコンテナに初期化



// ----------  DEQUE  ---------- //
/* --- 宣言 --- */
deque<int> deq1;
deque<int> deq2(10);
deque<int> deq3 = deq1;
deque<int> deq4(deq1);

/* --- 操作 --- */
deq1.front();             //先頭の要素を取得
deq1.back();              //末尾の要素を取得
deq1.push_front(10);      //先頭に要素を追加
deq1.pop_front();         //先頭の要素を削除
deq1.push_back(10);       //末尾に要素を追加
deq1.pop_back();          //末尾に要素を削除

deq1[3];                  //3番目の要素を取得

deq1.size();              //要素数を取得
deq1.empty();             //bool型で空ならtrue、その他はfalseを返す
deq1.clear();             //空のコンテナに初期化



// ----------  STRING  --------- //
/* --- 宣言 --- */
string s1;
string s2(s1);
string s3;
string s4( "abc" );
string s5 = "abc";

/* --- 操作 --- */
s1.length();               //文字列の長さを取得
s1.size();                 //文字列の長さを取得(同じ)
s1.clear();

s3 = s1 + s2;              //文字列の連結
s3 += s1;                  //文字列の追加

s4.find("cd");             //合致する文字列の最初のインデックスを返す 無い時はstring::nposを返す

string::iterator it = s4.begin();
for (it = s4.begin(); it < s4.end(); it++ )
    cout << *it << endl;


// ----------  MAP  ---------- //
/* --- 宣言 --- */
map<string, int> m1;
map<string, int>::iterator ite;

/* --- 操作 --- */
m1.erase( "key");
m1["key"] = 100;
ite = m1.find( "key" );     //キーの位置を、存在しなければend()を返す

for (ite = m1.begin(); ite != m1.end(); ite++)
{
    cout << ite->first << endl;          // キーを出力
    cout << ite->second << endl;         // 値を出力
}


// ----------  IO  ---------- //
char c;
while( (c = getchar() ) != EOF && c !='#' ) { cout << c; }


    return 0;
}

