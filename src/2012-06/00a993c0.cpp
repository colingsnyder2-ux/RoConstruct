// from server: 53% by atomic.potato
struct String
{
    ~String();
};

extern "C" void __stdcall sub_00983144(void);
extern "C" String* __stdcall imported_destructor(String*);

struct S
{
    void __stdcall f();
};

void __stdcall S::f()
{
    sub_00983144();
    String value;
    imported_destructor(&value);
}
