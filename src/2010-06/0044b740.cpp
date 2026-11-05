// from server: 100% by atomic.potato
struct CRenderSettingsItem
{
    int __cdecl Get(void* value);
};

int CRenderSettingsItem::Get(void* value)
{
    return *(void**)((char*)this + 0x0c) == value;
}
