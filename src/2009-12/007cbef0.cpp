// from server: 13% by atomic.potato
struct String {
    void* rep;
    String();
    String(const String&);
    ~String();
    String& operator=(const String&);
};

struct Eq {
    void* field0;
    char pad[8];
    void* fieldC;
    void* field10;
    void* field14;
    String str18;
    Eq(const Eq&);
};

extern "C" void* __stdcall sub_7f3860(int);
extern "C" void* __stdcall sub_98b6e8();
extern "C" void* __stdcall sub_98b69c(void*);
extern "C" void* __stdcall sub_98b6e4(void*);

Eq::Eq(const Eq& other)
{
    void* p = sub_7f3860(4);
    if (p != 0)
        *(void**)p = this;
    else
        p = 0;
    field0 = p;
    fieldC = 0;
    field10 = 0;
    field14 = 0;
    sub_98b6e8();
    sub_98b69c(&str18);
    sub_98b6e4(&str18);
}
