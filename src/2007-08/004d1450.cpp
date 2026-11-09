// from server: 100% by colin
struct PartChunk
{
    void func_004d1160();
    void func_004d1250();
    void dispatch(void* arg);
};

void PartChunk::dispatch(void* arg)
{
    unsigned int v = (unsigned int)arg;
    if (v == 0x8c65a0)
    {
        func_004d1160();
        return;
    }
    if (v == 0x8c2724 || v == 0x8c2708 || v == 0x8c2740)
    {
        func_004d1250();
    }
}
