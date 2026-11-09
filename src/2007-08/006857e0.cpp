// from server: 100% by tajop
struct CNameItem {
    void __cdecl construct(const char* name, int value, int index);
};

void CNameItem::construct(const char* name, int value, int index)
{
    void** vtbl = *(void***)this;
    void (__thiscall *fn)(void*, const char*, int, int, int) = (void (__thiscall *)(void*, const char*, int, int, int))vtbl[0x58/4];
    fn(this, name, 5, value, 0);
}
