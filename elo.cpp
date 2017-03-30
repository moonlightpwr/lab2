#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include"elo.h"

using namespace std;
int main()
{
int K,Ra,Rb;
double Ea,Eb;
double score;
Elo elo;
ofstream outFile("elofile",ios::out);
if(!outFile){
  cerr<<"Failed opening outFile"<<endl;
  exit(1);
}
ifstream inFile("elofile",ios::in);
if(!inFile){
  cerr<<"Failed opening inFile"<<endl;
  exit(1);
}

cout<<"Enter K Ra Rb"<<endl;
cin>>K>>Ra>>Rb;
elo.set_K(K);
cout<<"Enter score(win=1,lose=0,tie=0.5) each line.\n"<<"EOF to finish.\n"<<"?";
outFile<<Ra<<"\t"<<Rb<<"\n";
  while(cin>>score){
    elo.set_iR(Ra,Rb);
    Ra = elo.get_Ra();
    Rb = elo.get_Rb();
    Ea=elo.expect((double)Ra,(double)Rb);
    Eb=elo.expect((double)Rb,(double)Ra);
    
    outFile<<elo.R(Ra,K,score,Ea)<<"\t"<<elo.R(Rb,K,1-score,Eb)<<endl;
    Ra=elo.R(Ra,K,score,Ea);
    Rb=elo.R(Rb,K,1-score,Eb);
    cout<<"?";
    }
    cout<<"\n";
  while(inFile >> Ra >> Rb){
    cout<<Ra<<"\t"<<Rb<<endl;
    }

return 0;

}
