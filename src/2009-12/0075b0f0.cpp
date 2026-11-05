// from server: 61% by atomic.potato
extern "C" void __stdcall SetValue(void*);

struct P8GuiTextMixin
{
    void GetSetImpl(float value);
};

void P8GuiTextMixin::GetSetImpl(float value)
{
    float* field = (float*)((char*)this + 0x1c8);
    if (*field != value)
    {
        *field = value;
        SetValue((void*)0xb97714);
    }
}
