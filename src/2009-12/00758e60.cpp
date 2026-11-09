// from server: 100% by atomic.potato
extern "C" void __stdcall NotifyChanged(int);

struct P8GuiTextMixin
{
    int value;
    void SetValue(int);
};

void P8GuiTextMixin::SetValue(int value)
{
    if (*(int*)((char*)this + 0x2f8) == value)
        return;
    *(int*)((char*)this + 0x2f8) = value;
    NotifyChanged(0xb975a0);
}
