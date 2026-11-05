// from server: 83% by atomic.potato
extern "C" int __cdecl GeometryCall(int);
extern "C" void SleepStageCall(void *, int);

struct SleepStage
{
    int f(int);
};

int SleepStage::f(int arg)
{
    int i = 2;
    while (i != 0)
    {
        int value = GeometryCall(*(int *)(arg + 0x10));
        SleepStageCall(this, value);
        --i;
    }
    return 0;
}
