// from server: 100% by tester
struct CBrowserDocManager {
    char pad[0x58];
    void* field_58;
    void method();
};

void CBrowserDocManager::method()
{
    void* p = field_58;
    void* q = *(void**)((char*)p + 0x20);
    void** vtbl = *(void***)q;
    void (__stdcall *fn)(int, int) = (void (__stdcall *)(int, int))vtbl[0x88 / 4];
    fn(0, 1);
}
