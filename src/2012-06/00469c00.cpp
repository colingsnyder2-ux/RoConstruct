// from server: 100% by tester
struct CRenderSettingsItem
{
    int __cdecl Get(void* value);
};

int CRenderSettingsItem::Get(void* value)
{
    return *(void**)((char*)this + 0x14) == value;
}