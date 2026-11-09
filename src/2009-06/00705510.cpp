// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <exception>
#include <stdarg.h>
namespace G3D { std::string vformat(const char* fmt, va_list argPtr); }
namespace RBX {
class runtime_error : public std::exception {
    std::string msg;
public:
    runtime_error(const std::string& m);
    virtual ~runtime_error() throw();
    static runtime_error format(const char* fmt, ...);
};
runtime_error runtime_error::format(const char* fmt, ...)
{
    va_list argList;
    va_start(argList, fmt);
    std::string s = G3D::vformat(fmt, argList);
    return runtime_error(s);
}
}
