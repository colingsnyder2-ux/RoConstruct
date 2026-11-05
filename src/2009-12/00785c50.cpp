// from server: 70% by atomic.potato
struct RBX_Unlocked {
    char pad[0x18];
    void* field_18;
    void* method(void* a, void* b);
};

extern "C" void __cdecl func_00785b30(void* a, void* b, void* c);

void* RBX_Unlocked::method(void* a, void* b)
{
    void* p = field_18;
    void* q = 0;
    if (p != 0) {
        q = (char*)p + 0x120;
    } else {
        q = 0;
    }
    func_00785b30(a, b, q);
    return a;
}
