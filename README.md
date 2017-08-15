#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

struct BigInteger {
    static const int BASE = 100000000;
    static const int WIDTH = 8;
    vector<int> s;

    BigInteger(long long num = 0) { *this = num; }
    BigInteger operator = (long long num) {
        s.clear();
        do {
            s.push_back(num % BASE);
            num /= BASE;
        } while(num > 0);
        return *this;
    }
    BigInteger operator = (const string& str) {
        s.clear();
        int x, len = (str.length() - 1) / WIDTH + 1;
        for(int i = 0; i < len; i++) {
            int end = str.length() - i*WIDTH;
            int start = max(0, end - WIDTH);
            sscanf(str.substr(start,end-start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return *this;
    }

    BigInteger operator + (const BigInteger& b) const {
        BigInteger c;
        c.s.clear();
        for(int i = 0, g = 0; ; i++) {
            if(g == 0 && i >= s.size() && i >= b.s.size()) break;
            int x = g;
            if(i < s.size()) x += s[i];
            if(i < b.s.size()) x += b.s[i];
            c.s.push_back(x % BASE);
            g = x / BASE;
        }
        return c;
    }
    BigInteger operator - (const BigInteger& b) {
        BigInteger c;
        c.s.clear();
        for(int i = 0, g = 0; ; i++) {
            if(g == 0 && i >= s.size() && i >= b.s.size()) break;
            int x = g;
            if(i < s.size()) x += s[i];
            if(i < b.s.size()) x -= b.s[i];
            if(x < 0) { x += BASE; s[i+1] -= 1; }
            c.s.push_back(x % BASE);
            g = x / BASE;
        }
        return c;
    }
    BigInteger operator * (BigInteger b) const{
        BigInteger c = 0;
        for(; b > 0; b -= 1)
            c += *this;
        return c;
    }
    BigInteger operator / (const BigInteger& b) {
        BigInteger n, c = *this;
        for( ; c >= b; n = n + 1)
            c -= b;
        return n;
    }

    BigInteger operator += (const BigInteger& b) { return *this = *this + b; }
    BigInteger operator -= (const BigInteger& b) { return *this = *this - b; }
    BigInteger operator *= (const BigInteger& b) { return *this = *this * b; }
    BigInteger operator /= (const BigInteger& b) { return *this = *this / b; }

    bool operator < (const BigInteger& b) const {
        if(s.size() != b.s.size()) return s.size() < b.s.size();
        for(int i = s.size()-1; i >= 0; i--)
            if(s[i] != b.s[i]) return s[i] < b.s[i];
        return false;
    }
    bool operator > (const BigInteger& b) const { return (b < *this); }
    bool operator <= (const BigInteger& b) const { return !(*this > b); }
    bool operator >= (const BigInteger& b) const { return !(*this < b); }
    bool operator == (const BigInteger& b) const { return !(b < *this) && !(*this < b); }
    bool operator != (const BigInteger& b) const { return (*this < b) || (*this > b); }
};

ostream& operator << (ostream& out, const BigInteger& x) {
    out << x.s.back();
    for(int i = x.s.size()-2; i >= 0; i--) {
        char buf[20];
        sprintf(buf, "%08d", x.s[i]);
        out << buf;  //for(int j = 0; j < strlen(buf); j++) out << buf[j]; //
    }
    return out;
}
istream& operator >> (istream& in, BigInteger& x) {
    string str;
    if(!(in >> str)) return in;
    x = str;
    return in;
}

int main() {
    BigInteger a, b, c, d, e, f, g, h;
    a = 10; b = "123";
    c = a + b; d = a - b;
    e = a * b; f = b / a;  h = b;
    g = ( a == b );
    a += a;
    cout << a << "\n" << b << "\n" << c << "\n" << d << "\n" << e << "\n" << f << "\n" << g << "\n" << h;
    return 0;
}
