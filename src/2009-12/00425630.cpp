// from server: 61% by atomic.potato
extern "C" unsigned long __stdcall GetCurrentThreadId();
extern "C" void __cdecl Function423580(void *);
extern "C" void *__cdecl Function425140();

struct MainLogManager
{
    int field_0;
    unsigned long field_C;
    void f();
};

void MainLogManager::f()
{
    unsigned long id = GetCurrentThreadId();
    if (id == field_C)
        Function423580((char *)this + 4);
    else
        Function423580(Function425140());
}
