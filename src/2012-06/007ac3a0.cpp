// from server: 65% by atomic.potato
extern "C" void __stdcall EventDescUpdate();

struct EventDesc
{
    float value;
    void setValue(float);
};

void EventDesc::setValue(float value)
{
    if (value != *(float*)((char*)this + 0x1b4))
    {
        *(float*)((char*)this + 0x1b4) = value;
        EventDescUpdate();
    }
}
