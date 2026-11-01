// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" __declspec(dllimport) long __stdcall InterlockedExchange(long volatile* target, long value);
struct Target { char pad[0x2dc]; long busy; };
Target* lookupTarget(void* ctx);
struct BusyGuard {
    Target* t;
    BusyGuard(void* ctx) : t(lookupTarget(ctx)) { InterlockedExchange(&t->busy, 1); }
    ~BusyGuard() { InterlockedExchange(&t->busy, 0); }
};
struct Inner { void run(); };
struct Mid { char pad[0xd8]; Inner* inner; };
class C {
public:
    int onCommand(int arg);
private:
    char pad[0x1d0];
    Mid* mid;
    void* ctx;
};
int C::onCommand(int)
{
    BusyGuard guard(ctx);
    mid->inner->run();
    return 1;
}
