// from server: 100% by atomic.potato
extern "C" long __declspec(dllimport) __stdcall InterlockedDecrement(long *);

struct PasteVerb
{
    long *value;
    long f();
};

long PasteVerb::f()
{
    return InterlockedDecrement(value + 1);
}
