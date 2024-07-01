/*
*/
#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

class science {
    friend class Complex;  // You might need this.
    friend ostream& operator<<(ostream&, const science &);
    friend istream& operator>>(istream&, science &);
    friend bool operator>(const science& lhs,const science& rhs);
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
};

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

bool operator>(const science& lhs,const science& rhs){
    if(lhs.n > rhs.n)
        return 1;
    else if(lhs.n == rhs.n){
        if(lhs.a > rhs.a){
            return 1;
        }
        else{
            return 0;
        }
    }
    else
        return 0;
}

class Complex {
	friend ostream& operator<<(ostream&, const Complex&);
    friend istream& operator>>(istream&, Complex&);
public:
    /*Apply two kinds of constructor, one is directly input a complex , the other is input a real number and a imagine number*/
	Complex(const Complex& rhs){
        re = rhs.re;
        im = rhs.im;
    }
    Complex(const science& re_ = 0,const science& im_ = 0){
        re = re_;
        im = im_;
    }
	const Complex operator+(const Complex& rhs) const{
        return Complex(re + rhs.re,im + rhs.im);
    }
    const Complex operator-() const{//uniary
        return Complex(science(0,0) - re,science(0,0) - im);
    }
    const Complex operator-(const Complex& rhs) const{
        return Complex(re - rhs.re,im - rhs.im);
    }
    const Complex operator*(const Complex& rhs)const{
        science new_re = re * rhs.re - im * rhs.im,new_im = re * rhs.im + im * rhs.re;
        return Complex(new_re,new_im);
    }
	// ...
private:
	science re;
	science im;
};

ostream& operator<<(ostream& os,const Complex& rhs){
    if(rhs.im > science(0,0))
        os << rhs.re << " + " << rhs.im << "i";
    else
        os << rhs.re << " - " << rhs.im << "i";
    return os;
}

istream& operator>>(istream& is,Complex& rhs){
    is >> rhs.re >> rhs.im;
    return is;
}

class ComplexPolynomial {
public:
	ComplexPolynomial(const Complex& a_,const Complex& b_,const Complex& c_):a{a_},b{b_},c{c_}{}
    ComplexPolynomial():a{0},b{0},c{0}{};
	Complex eval(const Complex& rhs);
private:
	Complex a;
	Complex b;
	Complex c;
};

Complex ComplexPolynomial::eval(const Complex& x){
    return Complex(a * x * x + b * x + c);//Complex operator* is written at line 105
}

int main() {
    Complex a, b, c, x;
	ComplexPolynomial p;
	Complex eval_ans;

	cout << "Enter coefficient a (4 numbers: re.a re.n im.a im.n)" << endl;
	cin >> a;
	cout << "Enter coefficient b (4 numbers: re.a re.n im.a im.n)" << endl;
	cin >> b;
	cout << "Enter coefficient c (4 numbers: re.a re.n im.a im.n)" << endl;
	cin >> c;
	cout << "Enter x (4 numbers: re.a re.n im.a im.n)" << endl;
	cin >> x;

	p = ComplexPolynomial{a, b, c};
	eval_ans = p.eval(x);
    
	cout << "The evaluation answer is " << eval_ans << endl;

    return 0;
}