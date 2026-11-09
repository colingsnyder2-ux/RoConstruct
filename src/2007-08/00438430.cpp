// from server: 55% by colin
struct CStandardOutputView {
    char pad[0x110];
    void sub_4381a0(const char*, const char*);
    void sub_438430(const char*, const char*, const char*, const char*, int, int);
};

struct String {
    char data[0x1c];
    String();
    ~String();
    const char* c_str() const;
};

extern "C" void* __stdcall sub_77e6a8(const char*, const char*);
extern "C" void __stdcall sub_77e6ac(String*);

void CStandardOutputView::sub_438430(const char* a, const char* b, const char* c, const char* d, int e, int f)
{
    String s;
    sub_77e6a8(c, d);
    sub_4381a0(s.c_str(), a);
    sub_77e6ac(&s);
}
