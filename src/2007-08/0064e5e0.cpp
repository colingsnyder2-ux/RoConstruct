// from server: 100% by colin
struct CXTPImageManager {
    char pad[0xb4];
    void* field_b4;
    void* get();
};

void* helper_64dfd0();

void* CXTPImageManager::get()
{
    void* p = field_b4;
    if (p != 0)
        return *(void**)((char*)p + 0x40);
    return helper_64dfd0();
}
