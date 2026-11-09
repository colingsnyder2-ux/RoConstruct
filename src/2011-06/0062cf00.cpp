// from server: 15% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl function_0061b200();
extern "C" void __cdecl function_0062c4d0();
extern "C" void __cdecl function_0062cdb0();
extern "C" void __cdecl function_00467440();
extern "C" void __cdecl function_0077e650();

struct S
{
    void f();
};

void S::f()
{
    function_0061b200();
    function_0062c4d0();
    function_0062cdb0();
    function_00467440();
    function_0077e650();
}
