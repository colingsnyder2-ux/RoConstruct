// from server: 77% by atomic.potato
extern "C" int __cdecl sub_7957A0(char* dst, const char* fmt, const char* arg);
extern "C" int __cdecl sub_7A89B2(char* dst, const char* src);

struct S {
    char f(int a, int b);
};

char S::f(int a, int b) {
    char buf[40];
    sub_7957A0(buf, (const char*)0xA42B40, (const char*)b);
    return (char)sub_7A89B2(buf, (const char*)0xB03074);
}
