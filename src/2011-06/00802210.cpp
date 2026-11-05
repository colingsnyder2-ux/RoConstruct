// from server: 38% by atomic.potato
extern "C" void __cdecl call_565bf0(int, int);

struct S {
    void f(int);
};

void S::f(int a)
{
    call_565bf0(*(int*)this, a);
}
