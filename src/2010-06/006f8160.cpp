// from server: 86% by atomic.potato
struct VGuiBase {
    void* vtable;
    char pad[4];
    int field8;
    int fieldC;
    bool init(int a, int b);
};

bool func_006f7750(int* p);

bool VGuiBase::init(int a, int b)
{
    int local[2];
    local[0] = a;
    local[1] = b;
    if (!func_006f7750(local))
    {
        if (this != 0)
        {
            field8 = local[0];
            fieldC = local[1];
        }
        vtable = (void*)0xbde760;
        return true;
    }
    vtable = 0;
    return false;
}
