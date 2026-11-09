// from server: 100% by atomic.potato
typedef unsigned long DWORD;

extern "C" void __fastcall Function_004c72b0(void*);
extern "C" void __cdecl Function_007a799a(void*);

struct S
{
    void f();
    void* value;
};

void S::f()
{
    void* value = this->value;
    if (value)
    {
        Function_004c72b0(value);
        Function_007a799a(value);
        this->value = 0;
    }
}
