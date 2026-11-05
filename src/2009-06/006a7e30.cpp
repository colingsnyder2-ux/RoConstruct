// from server: 100% by why2
struct S_func_006a7e30 {
    char pad0[0x14];
    int* m_p;
    int* f();
};

int* S_func_006a7e30::f()
{
    int* p = m_p;
    int a = *(int*)((char*)p + 4);
    int b = *(int*)((char*)p + 0x28);
    return (int*)(b + (a + a * 2) * 2);
}
