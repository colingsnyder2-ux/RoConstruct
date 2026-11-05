// from server: 100% by king_originala
struct Peer;
typedef void (__thiscall *PeerCall)(Peer *);

struct Peer {
    PeerCall *vtable;
    volatile bool stopped;
    volatile bool running;
    unsigned char padding[0x70A];
    int period;
};

extern "C" {
    extern void * (__stdcall *CreateWaitableTimerA)(void *, int, const char *);
    extern int (__stdcall *SetWaitableTimer)(
        void *, const __int64 *, int, void *, void *, int);
}

extern unsigned long __cdecl get_file_attributes(const char *);

unsigned long __stdcall worker(Peer *peer)
{
    if (peer->period <= 0)
        peer->period = 1;

    void *timer = CreateWaitableTimerA(0, 0, 0);
    __int64 due = (int)(peer->period * -10000);
    SetWaitableTimer(timer, &due, peer->period, 0, 0, 0);

    peer->running = true;
    while (!peer->stopped) {
        peer->vtable[0x45](peer);
        get_file_attributes((const char *)peer->period);
    }
    peer->running = false;
    return 0;
}
