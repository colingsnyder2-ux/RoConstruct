// from server: 86% by atomic.potato
extern "C" long __stdcall InterlockedIncrement(long volatile*);

struct PasteVerb
{
    long* value;
    PasteVerb& f(long* p);
};

PasteVerb& PasteVerb::f(long* p)
{
    value = p;
    InterlockedIncrement((long volatile*)(p + 1));
    return *this;
}
