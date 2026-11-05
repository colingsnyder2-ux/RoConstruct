// from server: 65% by atomic.potato
struct S_func_00636ea0 {
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_00636ea0::f()
{
    return &m_x;
}

struct SurfaceGetSet {
    int field0;
    int field1;
    int (__thiscall *callback)(void*, float);
    void method(S_func_00636ea0*, float*);
};

void SurfaceGetSet::method(S_func_00636ea0* value, float* input)
{
    S_func_00636ea0* object = value ? (S_func_00636ea0*)((char*)value - 28) : 0;
    int* result = object->f();
    callback((char*)result + 32, *input);
}
