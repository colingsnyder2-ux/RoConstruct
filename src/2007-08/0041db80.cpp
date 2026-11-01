// from server: 100% by colin
struct CNameItem {
    void* cs;
    unsigned char owned;
    void Release();
};

extern "C" void (__stdcall *LeaveCriticalSection)(void*);

void CNameItem::Release()
{
    if (owned) {
        LeaveCriticalSection(cs);
        owned = 0;
    }
}
