// from server: 18% by atomic.potato
extern "C" int __cdecl Function005d06e0();

struct S
{
    int value;
    int f();
};

int S::f()
{
    return Function005d06e0();
}
