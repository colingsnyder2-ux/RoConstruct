// from server: 60% by atomic.potato
struct S
{
    int f();
};

extern "C" int __cdecl func_007f539a(S*);

int S::f()
{
    func_007f539a(this);
    return 0;
}
