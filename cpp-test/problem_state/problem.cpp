#include <iostream>
#include <string>
using namespace std;

class HowEasy
{
public:
    int pointVal(string param0);
private:
    bool checkString(string src);
    string src;
    int words;
    int totalLen;
};

bool HowEasy::checkString(string src) {
    int len = src.length();
    if(len <= 0) {
        cout<<"string is empty\n";
        words = 0;
        totalLen = 0;
        return false;
    }
    words = 0;
    totalLen = 0;
    bool valid = false;
    for(int i = 0;i < len;i++) {
        if(src[i] > 'z'
        || src[i] < 'A'
        || (src[i] < 'a' && src[i] > 'Z')
        ) {
            if(i == len - 1) {
                if(src[len - 1] == '.') {
                    words++;
                    return true;
                }
            }
            if(src[i] == 32 || src[i] == 9) {
                if(valid) {
                    words++;
                }
                continue;
            } else if(src[i] == '\n') {
                continue;
            }
            cout<<"string is invalid\n";
            return false;
        }
        valid = true;
        totalLen++;
    }
    words++;
    return true;
}

int HowEasy::pointVal(string param0) {
    int result = 0;
    int problem = 0;
    if(checkString(param0) == true) {
        cout << "totallen:" << totalLen << " words:" << words << "\n";
        result = totalLen/words;
    }
    if(result <= 3) {
        problem = 250;
    } else if(result == 4 || result == 5) {
        problem =  500;
    } else if(result >= 6) {
        problem =  1000;
    }
    cout << "Problem is " << problem << "\n";
    return problem;
}

int main(int argc, char* argv[]) {
    string src;
    cout << "Please input a string: ";
    getline(cin, src);
    cout << src << "\n";
    HowEasy he;
    he.pointVal(src);
}
