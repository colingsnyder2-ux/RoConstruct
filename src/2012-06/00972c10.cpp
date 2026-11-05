// from server: 100% by tajop
typedef char* va_list;

extern int (__cdecl *p_vscprintf)(const char* fmt, va_list args);
extern int (__cdecl *p_vsnprintf_s)(char* buf, unsigned int size, unsigned int count, const char* fmt, va_list args);

void* __cdecl operator new[](unsigned int size);
void __cdecl operator delete[](void* p) throw();

namespace std {
struct string {
    char storage[28];
    string(const char* s);
    string(const string& other);
    ~string();
    void construct(const char* s);
    void copy(const string& other);
    void destroy();
};
}

extern void (std::string::*p_string_ctor)(const char* s);
extern void (std::string::*p_string_copy)(const std::string& other);
extern void (std::string::*p_string_dtor)();

inline std::string::string(const char* s) { (this->*p_string_ctor)(s); }
inline std::string::string(const std::string& other) { (this->*p_string_copy)(other); }
inline std::string::~string() { (this->*p_string_dtor)(); }

struct scoped_array {
    char* ptr;
    scoped_array() : ptr(0) {}
    explicit scoped_array(char* p) : ptr(p) {}
    ~scoped_array() { delete[] ptr; }
    void swap(scoped_array& other) { char* tmp = other.ptr; other.ptr = ptr; ptr = tmp; }
    void reset(char* p) { scoped_array(p).swap(*this); }
    char* get() const { return ptr; }
};

std::string vformat(const char* fmt, va_list args)
{
    if (!fmt)
        return std::string("");

    char stackBuffer[161];
    int len = p_vscprintf(fmt, args);
    if (len < 161) {
        p_vsnprintf_s(stackBuffer, 161, 161, fmt, args);
        return std::string(stackBuffer);
    }

    scoped_array heapBuffer;
    if (len > 1000000)
        len = 1000000;
    heapBuffer.reset(new char[len + 1]);
    p_vsnprintf_s(heapBuffer.get(), len + 1, len, fmt, args);
    std::string result(heapBuffer.get());
    return result;
}
