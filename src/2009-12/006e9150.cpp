// from server: 36% by atomic.potato
extern "C" void __cdecl Notify(void*);

struct EventDesc
{
    void Set(float*);
};

void EventDesc::Set(float* value)
{
    if (value[0] != *(float*)((char*)this + 456))
    {
        *(float*)((char*)this + 456) = value[0];
        Notify((void*)0x00B937E0);
    }
}
