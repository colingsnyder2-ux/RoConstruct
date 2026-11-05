// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_lifetime_007adbe0_b1839fb1d0deb8b6.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <sstream>
#include <stdexcept>

struct Error : std::exception {
    std::string text;
    __forceinline Error(const std::string& s) : text(s) {}
    virtual ~Error() throw() {}
    virtual const char* what() const throw() { return text.c_str(); }
};
struct Failure : Error {
    __forceinline Failure(const std::string& s) : Error(s) {}
};

std::string stringify(double value)
{
    std::ostringstream stream(std::ios::out);
    if ((stream << value).fail()) {
        std::string error("stringify(double)");
        throw Failure(error);
    }
    return stream.str();
}
