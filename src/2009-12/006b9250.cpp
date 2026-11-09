// from server: 52% by atomic.potato
struct SoundServiceStatsItem
{
    int Update(void* value);
    int fieldD4[53];
};

extern "C" void __cdecl Function0040C080(void*);

int SoundServiceStatsItem::Update(void* value)
{
    int v = *(int*)value;
    if (v != fieldD4[53])
    {
        Function0040C080((void*)0x00B91C50);
        fieldD4[53] = v;
        return 0;
    }
    return 0;
}
