// from server: 100% by tajop
namespace std {
class string {
public:
    ~string();
    string& operator=(const char* s);
    string& operator+=(const string& s);
    string& operator+=(const char* s);
    const char* c_str() const;
    bool empty() const { return _Mysize == 0; }
private:
    int _Alval;
    char _Bx[16];
    unsigned int _Mysize;
    unsigned int _Myres;
};

extern void (string::*string_dtor)();
extern string& (string::*string_assign_cstr)(const char*);
extern string& (string::*string_append_str)(const string&);
extern string& (string::*string_append_cstr)(const char*);
extern const char* (string::*string_c_str)() const;

inline string::~string() { (this->*string_dtor)(); }
inline string& string::operator=(const char* s) { return (this->*string_assign_cstr)(s); }
inline string& string::operator+=(const string& s) { return (this->*string_append_str)(s); }
inline string& string::operator+=(const char* s) { return (this->*string_append_cstr)(s); }
inline const char* string::c_str() const { return (this->*string_c_str)(); }
}

namespace boost {
namespace system {

struct error_category;

struct error_code {
    typedef void (*unspecified_bool_type)();
    static void unspecified_bool_true() {}
    operator unspecified_bool_type() const {
        return m_val == 0 ? 0 : unspecified_bool_true;
    }
    std::string message() const;
    int m_val;
    const error_category* m_cat;
};

struct system_error {
    const char* what() const throw();
    char m_exception[0xc];
    std::string m_str;
    error_code m_error_code;
    mutable std::string m_what;
};

const char* system_error::what() const throw() {
    if (m_what.empty()) {
        try {
            m_what = m_str.c_str();
            if (m_error_code) {
                if (!m_what.empty())
                    m_what += ": ";
                m_what += m_error_code.message();
            }
        } catch (...) {
            return m_str.c_str();
        }
    }
    return m_what.c_str();
}

}
}
