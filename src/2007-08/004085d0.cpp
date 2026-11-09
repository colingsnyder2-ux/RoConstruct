// from server: 100% by EspClaude
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
struct AppObj {
    bool query();
};
extern AppObj theApp;

long __stdcall get_Value(void* self, short* out)
{
    *out = theApp.query() ? -1 : 0;
    return 0;
}
