// from server: 70% by atomic.potato
struct RBX_Unlocked {
    char pad[0x18];
    void* field18;
    void* method(int, int);
};

void* RBX_Unlocked::method(int a, int b)
{
    void* p = field18;
    if (p) {
        p = (char*)p + 0x120;
    } else {
        p = 0;
    }
    extern void func_00785c10(void*, int, int);
    func_00785c10(p, a, b);
    return (void*)a;
}
