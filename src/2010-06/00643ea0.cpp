// from server: 100% by atomic.potato
extern "C" void __cdecl FinishKeyframeSequenceProvider();

struct KeyframeSequenceProvider
{
    int v0;
    int v1;
    int v2;
    int v3;
    int v4;
    int v5;
    int v6;
    int v7;

    void Set();
};

void KeyframeSequenceProvider::Set()
{
    v0 = 0x00a37114;
    v1 = 0x00a37108;
    v6 = 0x00a370fc;
    v7 = 0x00a370f0;
    FinishKeyframeSequenceProvider();
}
