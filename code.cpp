#include<bits/stdc++.h>

using namespace std;

char dch[500],ch2[4];
int ch[500],dch2[500];

void Init() {
	ch2[0]='-',ch2[1]='=',ch2[2]='+',ch2[3]='*';
	dch2['-']=0,dch2['=']=1,dch2['+']=2,dch2['*']=3;
	ch['A']=37,ch['B']=17,ch['C']=1,ch['D']=32,ch['E']=33,ch['F']=5,ch['G']=38,ch['H']=16,ch['I']=40,ch['J']=26,ch['K']=9,ch['L']=18,ch['M']=22,ch['N']=10,ch['O']=6,ch['P']=20,ch['Q']=34,ch['R']=0,ch['S']=4,ch['T']=41,ch['U']=8,ch['V']=42,ch['W']=2,ch['X']=25,ch['Y']=36,ch['Z']=24;
	dch[0]='R',dch[1]='C',dch[2]='W',dch[4]='S',dch[5]='F',dch[6]='O',dch[8]='U',dch[9]='K',dch[10]='N',dch[16]='H',dch[17]='B',dch[18]='L',dch[20]='P',dch[22]='M',dch[24]='Z',dch[25]='X',dch[26]='J',dch[32]='D',dch[33]='E',dch[34]='Q',dch[36]='Y',dch[37]='A',dch[38]='G',dch[40]='I',dch[41]='T',dch['V']=42;
}

string Generate() {
	srand(time(NULL));
	mt19937 g(rand());
	int len=g()%100;
	string s;
	for(int i=0; i<len; i++) {
		int tmp=g()%4;
		s.push_back(ch2[tmp]);
		if(i<=1)continue;
		if(s[i-2]=='='&&s[i-1]=='='&&s[i]=='=') {
			tmp=(tmp+g()%3+1)%4;
			s[i]=ch2[tmp];
		}
	}
	if(s.back()=='=')s=s+ch2[(g()%3+2)%4];
	return s+"===";
}

string Encode(char cht) {
	int x=ch[cht];
	int F=(x>>4)&3,S=(x>>2)&3,T=x&3;
	string s;
	s.push_back(ch2[F]),s.push_back(ch2[S]),s.push_back(ch2[T]);
	return s;
}

string Encode(string s1) {
	string s2;
	for(auto x:s1)s2=s2+Encode(toupper(x));
	return s2;
}

bool Check(string s) {return true;}

char Decode1(string s) {return dch[(dch2[s[0]]<<4)|(dch2[s[1]]<<2)|(dch2[s[2]])];}

string Decode(string s1) {
	int len=s1.length(),pos;
	bool flag=0;
	string s2;
	for(int i=0; i<len-2; i++)if(s1[i]=='='&&s1[i+1]=='='&&s1[i+2]=='=') {
		flag=1;
		pos=i+3;
		break;
	}
	if(flag==0||pos>len-1)return "[ALERT]Abandoned Message!";
	for(int i=pos; i<len-2; i+=3)s2=s2+Decode1(s1.substr(i,3));
	if(!Check(s2))return "[AlERT]Abandoned Message!";
	return s2;
}

int main() {
	Init();
	string s;
	cin>>s;
	if(s[0]=='+'||s[0]=='-'||s[0]=='*'||s[0]=='=')cout<<Decode(s)<<'\n';
	else cout<<Generate()<<Encode(s)<<'\n';
	system("pause"); 
	return 0;
}
