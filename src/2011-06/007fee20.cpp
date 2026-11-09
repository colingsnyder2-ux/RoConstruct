// from server: 100% by atomic.potato
extern "C" unsigned long __cdecl get_current_directory(wchar_t *, unsigned long);

struct S
{
    void f();
};

void S::f()
{
    get_current_directory((wchar_t *)*(unsigned long *)this, 0);
}
