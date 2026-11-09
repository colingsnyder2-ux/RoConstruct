// from server: 61% by atomic.potato
extern "C" void __stdcall Dispatch(void* value);

struct P8GuiTextMixin
{
    void SetValue(float value);
};

void P8GuiTextMixin::SetValue(float value)
{
    float* field = (float*)((char*)this + 0x2ec);
    if (*field != value)
    {
        *field = value;
        Dispatch((void*)0xb9751c);
    }
}
