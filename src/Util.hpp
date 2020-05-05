//
// Util.hpp
// Nathanael Epps
//

#ifndef UTIL
#define UTIL

// #define DEBUG

#include <istream>
#include <string>
using std::string;

#define FNAME std::string(__PRETTY_FUNCTION__)

string readAll(std::istream&);

int randint(int, int);

int stringToInt(string);
string intToString(int);

class MarkovException : public std::exception {
public:
    MarkovException() { }
    
    MarkovException(string, string, int);
    
    virtual const char* what() const noexcept override;

private:
    string reason;
};

#define MakeException(str) MarkovException(str, __FILE__, __LINE__)

#endif
