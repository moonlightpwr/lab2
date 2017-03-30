#include<cmath>
using namespace std;
class  Elo{
    public:
        void set_iR(int a,int b);
        int get_Ra();
        int get_Rb();
        double expect(double a,double b);
        void set_K(int k);
        int R(int R,int K,double score,double E);

    private:
    int Ra,Rb; 
    int K;
};
