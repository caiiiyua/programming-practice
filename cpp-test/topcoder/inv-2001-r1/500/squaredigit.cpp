#include <iostream>
#include <list>
using namespace std;

class SquareDigits
{
public:
    int smallestResult(int n);
//private:
    int S(int x);
    int T(int n);
    int num;
};

int SquareDigits::smallestResult(int n) {
    for(int i = 0;i <= 199;i++) {
    ;
    }
}

int SquareDigits::S(int x) {
    int s = 0;
    do {
        int tmp = x % 10;
        s += tmp * tmp;
    } while((x=x/10) > 0);

    return s;
}

int SquareDigits::T(int n) {
    int x = n;
    do {
        x = S(x);
    } while(x != num);
}



int main() {
    SquareDigits s;
    cout << "hello squaredigits" << s.S(0) << endl;
}
