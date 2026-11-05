// from server: 83% by atomic.potato
typedef unsigned int DWORD;

extern "C" void __stdcall sub_009820b4(void *, void *);
extern "C" void __stdcall sub_00698ec0(void *);

struct SoundServiceStatsItem
{
    int f(void *, void *);
};

int SoundServiceStatsItem::f(void *a, void *b)
{
    if (b == 0)
    {
        void *p;
        sub_009820b4(a, &p);
        if (p != 0)
            sub_00698ec0(p);
    }
    return 0;
}
