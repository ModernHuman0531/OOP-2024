/*Lab5
Write a class of science that contains the operator +,-,*,/,<< and >>
version two with better code:
Will use the fuction below:
floor(double number), will let number 無條件進位;
pow(double/int x,double/int y),x is 底數,y is 指數, will return the value of x^y
fabs(number) , will return the absolute value of number 
Key point to think: Use the fuction log10 to test if the a is smaller than 1 or bigger than 10, if bigger than ten, the log10 will work, to return value = k, new n = k + n, and new a = a / pow(10,k); 
*/
#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

#define DEBUG

class science{
private:
	double a;   
	int n;
public:
	science():a(0), n(0) {}
	science(double a_) : a(a_), n(0) {}
    science(double a_, int n_){
        int k = 0;
        if(a_ == 0){
            k = 0; 
            k = floor(log10(fabs(a_)));
        }
        n = n_ + k;
        a = a_ / pow(10,k);
	}
	friend ostream& operator<<(ostream&os, const science &sci);//the << and >> can not be overloading but it is still needed to able access the data member ,so it  must be member function
	friend istream& operator>>(istream&is, science &sci);
  // ------------- Write Your Code Here ------------- //
    const science operator+(const science& rhs)const{
        int k = n - rhs.n;
        return science(pow(10,k) * a + rhs.a,rhs.n);//temporery object just to return the value, but is still call the constructor to change into ideal format
    }
    const science operator-(const science& rhs)const{
        int k = n - rhs.n;
        return science(pow(10,k) * a - rhs.a,rhs.n);
    }
    const science operator*(const science& rhs)const{
        return science(a * rhs.a,n + rhs.n);
    }
    const science operator/(const science& rhs)const{
        return science(a / rhs.a , n - rhs.n);
    }
  // ------------------------------------------------ //
};

// ------------- Write Your Code Here ------------- //

#ifdef DEBUG
ostream& operator<<(ostream& os,const science& rhs){//friend do not need to be written in function declaration, and friend function is not member function
    os << rhs.a << "*" <<  "10^" << rhs.n;//can print the result in the way i want
    return os;
}

istream& operator>>(istream& is,science& rhs){
    int n,k;
    double a;

    is >> a >> n;
    if(a == 0){
        k = 0;
    }
    else{
        k = floor(log10(fabs(a)));
    }
    rhs.a = a / pow(10,k);
    rhs.n = n + k;
    return is;
}
#endif
// ------------------------------------------------ //

int main(){
	science v, t, w;
	char op;
	while(1){
		cout << "Please enter an expression:" << endl << endl;
        cin >> v;
		cin >> op;
		if( op != '+' && op != '-' && op != '*' && op != '/' ) break;

		cin >> t;
		if(cin.fail()) break;

		switch(op){
			case '+':  w = v + t; break;
			case '-':  w = v - t; break;
			case '*':  w = v * t; break;
			case '/':  w = v / t; break;
		}
		cout << v << ' ' << op << ' ' << t << " = " << w << endl << endl;
	}
	return 0;
}