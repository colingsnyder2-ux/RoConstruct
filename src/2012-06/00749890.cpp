// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
#include <exception>
#include <string.h>
const char* skip(const char*, bool);
struct ScopedChars {
    char* p;
    explicit ScopedChars(char* q) : p(q) {}
    ~ScopedChars() { delete[] p; }
};
const char* parseToken(const char* text, const std::string& key, bool required) {
    try {
        const char* s = skip(text, required);
        if (*s == '%') {
            int i = 1;
            while (s[i] != 0 && s[i] != '%' && i < 20) ++i;
            if (s[i] == '%') {
                ScopedChars buf(new char[i]);
                strncpy(buf.p, s + 1, i - 1);
                buf.p[i - 1] = 0;
                const char* r = s + i + 1;
                if (buf.p != key) throw std::exception();
                return r;
            }
        }
        if (required) throw std::exception();
        return s;
    } catch (...) {
    }
    throw std::exception();
}
