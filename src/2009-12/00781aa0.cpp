// from server: 92% by atomic.potato
struct S_func_00781aa0 {
    int f();
};

extern "C" void __cdecl sub_007826e0(S_func_00781aa0*);

int S_func_00781aa0::f()
{
    sub_007826e0((S_func_00781aa0*)((char*)this + 8));
    return 0;
}
