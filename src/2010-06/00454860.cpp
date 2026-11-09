// from server: 73% by atomic.potato
struct CRobloxControlMaterialSelector
{
    void f(int value);
};

extern void G1_func_007AC320();

void CRobloxControlMaterialSelector::f(int value)
{
    if (value == 0)
        *(int*)((char*)this + 0x17c) = -1;
    G1_func_007AC320();
}
