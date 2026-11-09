// from server: 72% by atomic.potato
extern "C" int* __cdecl f();

struct SurfaceGetSet
{
    char pad0[8];
    void (__thiscall *m_fn)(float, int*);
    void g(int*, float*);
};

void SurfaceGetSet::g(int* a, float* b)
{
    int* p = a ? a - 7 : 0;
    int* q = f();
    m_fn(*b, q + 2);
}
