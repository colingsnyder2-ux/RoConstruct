// from server: 27% by atomic.potato
struct S_func_00774c60 {
    char pad0[4];
    int m_x;
    int* f();
};

int* S_func_00774c60::f()
{
    return &m_x;
}

struct S_func_007755e0 {
    int* m_begin;
    int m_size;
    int m_capacity;
    void f(int*);
};

void S_func_007755e0::f(int*)
{
}

struct S_func_007757f0 {
    char pad0[24];
    S_func_00774c60* m_object;
    char pad1[24];
    S_func_007755e0* m_container;
    int f(int);
};

int S_func_007757f0::f(int value)
{
    S_func_00774c60* object = m_object;
    S_func_007755e0* container = (S_func_007755e0*)((char*)object + 0x30);
    int* result = object->f();
    *result = ((int*)object)[0x34 / 4];
    container->f(&value);
    return 0;
}
