#ifndef __STRING_
#define __STRING_
#include "test.h"

class String
{
public:
    String(const char *src = NULL);
    String(const String &other);
    ~String();
    String & operator=(const String &other);
private:
    char *m_data;
};
#endif //__STRING_
