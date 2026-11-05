// from server: 100% by colin
namespace ns_ROCX000000 {
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
}
