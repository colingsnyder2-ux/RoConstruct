// from server: 100% by atomic.potato
struct S {
    double f();
};

extern "C" S *__cdecl thunk();

double S::f()
{
    return *(double *)((char *)thunk() + 0x150);
}
