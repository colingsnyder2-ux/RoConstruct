// from server: 100% by EspClaude
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
void RakSleep(unsigned int ms);
class RakPeer {
public:
    virtual ~RakPeer();
    volatile bool endThreads;
    volatile bool isMainLoopThreadActive;
    char pad[0x710 - 6];
    int threadSleepTimer;
    bool RunUpdateCycle();
};
unsigned __stdcall UpdateNetworkLoop(void* arguments)
{
    RakPeer* rakPeer = (RakPeer*)arguments;
    rakPeer->isMainLoopThreadActive = true;
    while (rakPeer->endThreads == false)
    {
        rakPeer->RunUpdateCycle();
        if (rakPeer->threadSleepTimer >= 0)
            RakSleep(rakPeer->threadSleepTimer);
    }
    rakPeer->isMainLoopThreadActive = false;
    return 0;
}
