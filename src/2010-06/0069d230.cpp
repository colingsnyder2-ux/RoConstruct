// from server: 50% by atomic.potato
struct S_func_00636ea0 {
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_00636ea0::f()
{
    return &m_x;
}

extern "C" int* __cdecl call_00636ea0(int*);

struct SurfaceGetSet {
    char pad0[8];
    int (*m_function)(int*);
    int method(int* value, int* object);
};

int SurfaceGetSet::method(int* value, int* object)
{
    int* result = call_00636ea0(value ? (int*)((char*)value - 0x1c) : 0);
    int edx = *object;
    return m_function(result);
}
