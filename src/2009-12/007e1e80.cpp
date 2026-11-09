// from server: 100% by atomic.potato
extern "C" long __declspec(dllimport) __stdcall InterlockedExchange(long *, long);

struct PasteVerb
{
    long *value;
    void f();
};

void PasteVerb::f()
{
    InterlockedExchange(value, 0);
}
