// from server: 100% by atomic.potato
struct P8GuiTextMixin
{
    void SetValue(void* value);
};

extern "C" void __stdcall UpdateValue(void* value);

void P8GuiTextMixin::SetValue(void* value)
{
    void** field = (void**)((char*)this + 0x1d0);
    if (*field != value)
    {
        *field = value;
        UpdateValue((void*)0xb977c0);
    }
}
