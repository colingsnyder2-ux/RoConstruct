// from server: 72% by atomic.potato
typedef unsigned long DWORD;

extern "C" void __stdcall sub_7e78e0(void*);

struct S
{
    DWORD value;
    DWORD field4;
    DWORD field8;
    void f();
};

void S::f()
{
    value = 0x9e059c;
    sub_7e78e0((char*)this + 8);
    sub_7e78e0((char*)this + 4);
}
