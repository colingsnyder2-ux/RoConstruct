// from server: 64% by atomic.potato
typedef unsigned char BYTE;

struct S
{
    BYTE f();
};

extern "C" void* __cdecl sub_432620(void*);
extern "C" BYTE call_98ddbc(void*);
extern "C" void call_98dec0(void*);

BYTE S::f()
{
    void* value;
    BYTE result;

    sub_432620(&value);
    result = call_98ddbc(value);
    call_98dec0(&value);
    return result;
}
