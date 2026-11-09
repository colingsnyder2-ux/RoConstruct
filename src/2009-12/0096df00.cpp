// from server: 44% by atomic.potato
extern "C" int __cdecl thunk();

struct S
{
    int f();
};

int S::f()
{
    return thunk();
}
