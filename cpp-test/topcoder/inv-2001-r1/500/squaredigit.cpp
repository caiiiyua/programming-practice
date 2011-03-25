#include <iostream>
#include <vector>
using namespace std;

class SquareDigits
{
public:
    int smallestResult(int n);
private:
    int S(int x);
    bool T(int n);
    int num;
};

int SquareDigits::smallestResult(int n) {
    num = n;
    //for(int i = 0;i <= 199;i++) {
    //    cout << "n is " << i << endl;
    //    if(T(i) == true) return i;
    //}
    int i = 0;
    while(1) {
        if(T(i) == true) return i;
        i++;
    }
    return 0;
}

int SquareDigits::S(int x) {
    int s = 0;
    do {
        int tmp = x % 10;
        s += tmp * tmp;
    } while((x=x/10) > 0);

    return s;
}

bool SquareDigits::T(int n) {
    vector<int> v;
    int x = n;
    do {
        x = S(x);
        if(!v.empty()) {
            for(int i = 0;i < v.size();i++) {
                if(x == v[i]) return false;
            }
        }
        v.push_back(x);
        cout << x << " " << num << endl;
    } while(x != num);
    return true;
}



int main() {
    SquareDigits s;
    int n = 0;
    cin >> n;
    cout << "hello squaredigits: " << s.smallestResult(n) << endl;
}
