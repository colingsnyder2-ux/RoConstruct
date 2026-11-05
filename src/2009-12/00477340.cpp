// from server: 71% by atomic.potato
typedef unsigned int DWORD;

extern "C" void __stdcall sub_004ffeb0(void* object, void* destination, DWORD value);

struct S
{
    void* f(void* argument);
};

void* S::f(void* argument)
{
    void* result;
    sub_004ffeb0((char*)this + 0x154, argument, 0);
    result = argument;
    return result;
}
