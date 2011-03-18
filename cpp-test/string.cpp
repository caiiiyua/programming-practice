#include "string.h"

String::String(const char *src) {
    if(src == NULL) {
        return;
    }
    cout<<"This is 1st constructor "<<src<<"\n";
}

String::String(const String &other) {
    if(other.m_data == NULL) {
        return;
    }
    cout<<"This is 2nd constructor\n";
}

String::~String() {
    cout<<"This is deconstructor\n";
}

String & String::operator=(const String &other) {
    cout<<"This is override operator '='\n";
    return *this;
}
