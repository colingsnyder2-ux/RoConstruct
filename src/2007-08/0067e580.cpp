// from server: 100% by colin
struct CXTPControlRecentFileList {
    void* sub_67E510();
    void* Method(void*);
};

void* CXTPControlRecentFileList::Method(void* a2)
{
    void* p = sub_67E510();
    (*(void (__thiscall**)(void*, void*, void*))(*(int*)p + 0xe0))(p, this, a2);
    return p;
}
