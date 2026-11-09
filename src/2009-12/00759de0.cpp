// from server: 35% by atomic.potato
struct P8GuiTextMixin
{
    float GetSetImpl(float value);
};

extern "C" void ApplyValue(P8GuiTextMixin* object, void* value);

float P8GuiTextMixin::GetSetImpl(float value)
{
    if (!(value == *(float*)((char*)this + 0x1c8)))
    {
        *(float*)((char*)this + 0x1c8) = value;
        ApplyValue(this, (void*)0xb97618);
    }
    return value;
}
