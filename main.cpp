#include <iostream>
#include <numeric>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;

class Rational{
public:
    Rational() {
        one=0;
        two=1;
    };
    Rational(int numerator,int denominator){
        if (denominator==0){
            throw invalid_argument("invalid_argument");
        } else {
            while (gcd(numerator, denominator) != 1) {
                k = gcd(numerator, denominator);
                numerator /= k;
                denominator /= k;
            }
            if (denominator < 0 && numerator < 0) {
                one = -numerator;
                two = -denominator;
            } else if (denominator < 0) {
                one = -numerator;
                two = -denominator;
            } else {
                one = numerator;
                two = denominator;
            }
        }
    };
    int Numerator() const {
        return one;
    };
    int Denominator() const {
        return two;
    };

private:
    int one,two,k;
};

bool operator==(const Rational& r1,const Rational& r2){
    if ((r1.Denominator()==r2.Denominator())&&(r1.Numerator()==r2.Numerator())){
        return true;
    } else {
        return false;
    }
}

Rational operator+(const Rational& r1,const Rational& r2){
    if (r1.Denominator()==r2.Denominator()) {
        return Rational(r1.Numerator() + r2.Numerator(), r1.Denominator() );
    } else {
        return Rational(r1.Numerator()*r2.Denominator()+r2.Numerator()*r1.Denominator(),r1.Denominator()*r2.Denominator());
    }
}

Rational operator-(const Rational& r1,const Rational& r2){
    if (r1.Denominator()==r2.Denominator()) {
        return Rational(r1.Numerator() - r2.Numerator(), r1.Denominator() );
    } else {
        return Rational(r1.Numerator()*r2.Denominator()-r2.Numerator()*r1.Denominator(),r1.Denominator()*r2.Denominator());
    }
}

Rational operator*(const Rational& r1,const Rational& r2){
    return Rational(r1.Numerator()*r2.Numerator(),r1.Denominator()*r2.Denominator());
}

Rational operator/(const Rational& r1,const Rational& r2) {
    if (r2.Numerator() == 0 || r2.Denominator() == 0) {
        throw domain_error("domain_error");
    } else {
        return Rational(r1.Numerator() * r2.Denominator(), r1.Denominator() * r2.Numerator());
    }
}

ostream& operator<<(ostream& stream,const Rational& r){
    stream<<r.Numerator()<<"/"<<r.Denominator();
    return stream;
}

istream& operator>>(istream& stream,Rational& r) {
    int n = 0, m = 1;
    char c;
    stream >> n;
    stream>>c;
    if (c!='/'){
        return stream;
    }
    stream >> m;
    if (stream) {
        r = Rational(n, m);
        return stream;
    } else {
        return stream;
    }
}

bool operator>(Rational r1,Rational r2){
    return ((r1.Numerator()/(double)r1.Denominator())>(double(r2.Numerator())/(double)r2.Denominator()));
}

bool operator<(Rational r1,Rational r2){
    return ((r1.Numerator()/(double)r1.Denominator())<((r2.Numerator()/(double)r2.Denominator())));
}

int main() {
   int a1,a2,b1,b2;
   cout<<"Enter the numerator of the first number:"<<endl;
   cin>>a1;
   cout<<"Enter the denominator of the first number:"<<endl;
   cin>>a2;
   Rational a{a1,a2};
   cout<<"Enter the numerator of the second number:"<<endl;
   cin>>b1;
   cout<<"Enter the denominator of the first number:"<<endl;
   cin>>b2;
   Rational b{b1,b2};
   cout<<"Enter the number of operation you want to perform:"<<endl;
   cout<<"1: sum"<<endl;
   cout<<"2: difference"<<endl;
   cout<<"3: multiplication"<<endl;
   cout<<"4: division"<<endl;
   cout<<"5: comparison"<<endl;
   cout<<"6: reduction"<<endl;
   int c;
   cin>>c;
   if (c==1){
       cout<<a+b<<endl;
   } else if (c==2){
       cout<<a-b<<endl;
   }else if (c==3){
       cout<<a*b<<endl;
   }else if (c==4){
       cout<<a/b<<endl;
   }else if (c==5){
       if (a<b){
           cout<<a<<"<"<<b<<endl;
       } else if (a==b){
           cout<<a<<"="<<b<<endl;
       } else {
           cout<<a<<">"<<b<<endl;
       }
   }else if (c==6){
       cout<<a<<" "<<b<<endl;
   }
   return 0;
}
