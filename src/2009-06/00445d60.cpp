// from server: 100% by why2
struct CBrowserDocManager {
    char pad[0x58];
    void* field_58;
    void func_00445d60();
};

void CBrowserDocManager::func_00445d60()
{
    void* p = field_58;
    void* obj = *(void**)((char*)p + 0x2c);
    void** vtbl = *(void***)obj;
    void (__stdcall *fn)(int, int) = (void (__stdcall *)(int, int))vtbl[0x88 / 4];
    fn(0, 1);
}
