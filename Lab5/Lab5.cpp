/*Lab5
Write a class of science that contains the operator +,-,*,/,<< and >>
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
    science(double a_, int n_):a{a_},n{n_}{
	}
	friend ostream& operator<<(ostream&os, const science &sci);//the << and >> can not be overloading but it is still needed to able access the data member ,so it  must be member function
	friend istream& operator>>(istream&is, science &sci);
  // ------------- Write Your Code Here ------------- //
    const science operator+(const science& rhs)const;//member function way, write const at the return type is to ensure it wont be put at the left side of '='
    const science operator-(const science& rhs)const;
    const science operator*(const science& rhs)const;
    const science operator/(const science& rhs)const;
  // ------------------------------------------------ //
};

// ------------- Write Your Code Here ------------- //
const science science::operator+(const science &rhs)const{
    science result{rhs};
    while(n != result.n){
        if(n > result.n){//only modify the result
            result.a /= 10;
            ++result.n;
        }
        else if(n < result.n){
            result.a *= 10;
            --result.n;
        }
    }
    result.a += a;
    while(result.a >10 ||(result.a < 1 && result.a > 0)){
        if(result.a > 10){
            result.a /= 10;
            ++result.n;
        }
        else if((result.a < 1) && (result.a > 0)){
            result.a *= 10;
            --result.n;
        }
    }
    return result;
}

const science science::operator-(const science& rhs)const{
    science result{rhs};
    while(n != result.n){
        if(result.n < n){
            result.a /= 10;
            ++result.n;
        }
        else if(result.n > n){
            result.a *= 10;
            --result.n;
        }
    }
        result.a = a - result.a;
        while(result.a >10 ||(result.a < 1 && result.a > 0)){
            if(result.a > 10){
                result.a /= 10;
                ++result.n;
            }
            else if((result.a < 1) && (result.a > 0)){
                result.a *= 10;
                --result.n;
            }
        }        
        return result;//use copiy constructer to return the value
}

const science science::operator*(const science& rhs)const{
    science result{rhs};
    result.a *= a;
    result.n += n;
    while(result.a >10 ||(result.a < 1 && result.a > 0)){
        if(result.a > 10){
            result.a /= 10;
            ++result.n;
        }
        else if((result.a < 1) && (result.a > 0)){
            result.a *=10;
            --result.n;
        }
    }
    return result;
}

const science science::operator/(const science& rhs)const{
    science result{rhs};
    result.a = a / result.a;
    result.n = n - result.n;
    while(result.a >10 ||(result.a < 1 && result.a > 0)){
        if(result.a > 10){
            result.a /= 10;
            ++result.n;
        }
        else if((result.a < 1) && (result.a > 0)){
            result.a *=10;
            --result.n;
        }
    }
    return result;
}
#ifdef DEBUG
ostream& operator<<(ostream& os,const science& rhs){//friend do not need to be written in function declaration, and friend function is not member function
    os << rhs.a << "*" <<  "10^" << rhs.n;//can print the result in the way i want
    return os;
}

istream& operator>>(istream& is,science& rhs){
    is >> rhs.a >> rhs.n;
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