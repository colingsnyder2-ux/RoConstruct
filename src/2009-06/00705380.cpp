// from server: 100% by colin
namespace ns_ROCX00001c {
// from server: 100% by atomic.potato
extern "C" long __declspec(dllimport) __stdcall InterlockedExchange(long *, long);

struct PasteVerb
{
    unsigned char enabled;
    long *value;
    void f();
};

void PasteVerb::f()
{
    if (!enabled)
    {
        value[1] = 0x448ee0;
        InterlockedExchange(value, 0);
    }
}
}
