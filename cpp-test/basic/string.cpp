#include "string.h"
#include <string.h>

String::String(const char *src) {
    if(src == NULL) {
        return;
    }
    int len = strlen(src);
    m_data = new char[len];
    strncpy(m_data, src, len);
    cout<<"This is 1st constructor "<<src<<"len is "<<len<<"\n";
}

String::String(const String &other) {
    if(other.m_data == NULL) {
        return;
    }
    int len = strlen(other.m_data);
    m_data = new char[len];
    strncpy(m_data, other.m_data, len);
    cout<<"This is 2nd constructor "<<other.m_data<<"len is "<<len<<"\n";
}

String::~String() {
    if(m_data != NULL) {
        delete [] m_data;
        m_data = NULL;
    }
    cout<<"This is deconstructor\n";
}

String & String::operator=(const String &other) {
    if(other.m_data == NULL) {
        return *this;
    }
    int len = strlen(other.m_data);
    strncpy(m_data, other.m_data, len);
    cout<<"This is override operator '=' "<<"len is "<<len<<"\n";
    return *this;
}
