// from server: 100% by colin
// from server: 95% by atomic.potato
extern "C" int __cdecl g();

struct S {
    int f();
};

int S::f()
{
    *(int*)this = 0x9caf64;
    *((int*)this + 1) = 0x9caf58;
    *((int*)this + 6) = 0x9caf4c;
    *((int*)this + 7) = 0x9caf44;
    return g();
}