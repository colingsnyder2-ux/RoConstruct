// from server: 74% by atomic.potato
extern "C" void __cdecl f00809ff8(void *, void *);

struct SoundServiceStatsItem
{
    void f005a4e40();
    int f005a4e90(void *, void *);
};

void SoundServiceStatsItem::f005a4e40()
{
}

int SoundServiceStatsItem::f005a4e90(void *a, void *b)
{
    if (b == 0)
    {
        f00809ff8(a, &b);
        if (b != 0)
            f005a4e40();
    }
    return 0;
}
