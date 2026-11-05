// from server: 100% by atomic.potato
struct BasicPartInstance
{
    void setValue(int value);
};

extern "C" void __stdcall ApplyValue(int value);

void BasicPartInstance::setValue(int value)
{
    if (value != *(int*)((char*)this + 0x284))
    {
        *(int*)((char*)this + 0x284) = value;
        ApplyValue(0x00b9428c);
    }
}
