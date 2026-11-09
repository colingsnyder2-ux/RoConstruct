// from server: 47% by colin
struct SignalDesc
{
    void init();
};

static int g_initFlag;
static char g_signalStorage[1];

extern "C" void* __cdecl sub_418690(const char*);
extern "C" void __cdecl sub_570c00(void*, void*);
extern "C" void __cdecl sub_630d23(void*);

void SignalDesc::init()
{
    if (!(g_initFlag & 1))
    {
        g_initFlag |= 1;
        sub_570c00(g_signalStorage, sub_418690("NetworkReplicator"));
        sub_630d23((void*)0x778940);
    }
}
