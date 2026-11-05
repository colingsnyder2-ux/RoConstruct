// from server: 100% by atomic.potato
extern "C" void __cdecl sub_5980D0();

struct S
{
    void f();
};

int g_a8fb74;
int g_a8fb68;
int g_a8fb5c;
int g_a8fb50;

void S::f()
{
    *(int*)this = (int)&g_a8fb74;
    *((int*)this + 1) = (int)&g_a8fb68;
    *((int*)this + 6) = (int)&g_a8fb5c;
    *((int*)this + 7) = (int)&g_a8fb50;
    sub_5980D0();
}
