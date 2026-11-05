// from server: 64% by atomic.potato
extern "C" long __stdcall InterlockedExchange(long volatile *, long);

struct PasteVerb
{
    void *data;
    PasteVerb(void *);
};

PasteVerb::PasteVerb(void *value)
{
    data = value;
    InterlockedExchange((long volatile *)0x0098b310, 1);
}
