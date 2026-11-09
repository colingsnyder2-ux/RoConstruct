// from server: 100% by tajop
namespace std {
template<class T> struct char_traits {};
template<class T> class allocator {};
template<class C, class T, class A> class basic_string {
public:
    basic_string(const basic_string&);
    ~basic_string();
    basic_string& operator+=(const basic_string&);
    basic_string& operator+=(const char*);
    void dtor_impl();
    basic_string& append_str(const basic_string&);
    basic_string& append_cstr(const char*);
    char _buf[28];
};
typedef basic_string<char, char_traits<char>, allocator<char> > string;

typedef void (string::*DtorFn)();
typedef string& (string::*AppStrFn)(const string&);
typedef string& (string::*AppCStrFn)(const char*);
extern DtorFn g_string_dtor;
extern AppStrFn g_string_append_str;
extern AppCStrFn g_string_append_cstr;

template<> inline string::~basic_string() { (this->*g_string_dtor)(); }
template<> inline string& string::operator+=(const string& s) { return (this->*g_string_append_str)(s); }
template<> inline string& string::operator+=(const char* s) { return (this->*g_string_append_cstr)(s); }
}

struct S {
    int a;
    short b;
};

extern const char g_00b52f40[];
std::string func_00744220(const S& s);
std::string func_00743e60(const int& v);

std::string func_00745b90(const S& s)
{
    std::string r = func_00744220(s);
    r += g_00b52f40;
    r += func_00743e60((int)s.b);
    return r;
}
