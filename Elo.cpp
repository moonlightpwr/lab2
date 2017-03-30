#include"elo.h"

        void Elo:: set_iR(int a,int b){
          Ra = a;
          Rb = b;
        }
        int Elo:: get_Ra(){
          return Ra;
        }
        int Elo::get_Rb(){
          return Rb;
        }
        double Elo:: expect(double a,double b){
          double E;
          E = 1/(1+pow(10,(b-a)/400));
          return E;
        }
        void Elo::set_K(int k){
          K=k;
        }
        int Elo::R(int R,int K,double score,double E){
          double r;
          r=R+K*(score-E);
          if((int)(r-0.5)==(int)r){
            return (int)r+1;
          }else{
            return (int)r;
          }
        }
