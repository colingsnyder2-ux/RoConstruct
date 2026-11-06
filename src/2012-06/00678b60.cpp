// from server: 100% by tajop
struct String {
    void destroy();
    ~String();
    char data[0x1c];
};

extern void (String::*g_stringDtor)();

inline String::~String()
{
    (this->*g_stringDtor)();
}

struct PerfInfo {
    PerfInfo();
    char header[0xc];
    String first;
    int value0;
    int value1;
    String second;
};

int getPerfValue()
{
    return PerfInfo().value1;
}
