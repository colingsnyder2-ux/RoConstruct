// from server: 100% by tester
extern unsigned long g_7852a8;
extern unsigned long g_7852ac;
extern unsigned long g_7852b0;
extern unsigned long g_7852b4;

struct CProxy_IAppEvents {
    long __stdcall GetWorkspace(void** out);
};

long __stdcall CProxy_IAppEvents::GetWorkspace(void** out) {
    if (out == 0) {
        return (long)0x80004003;
    }
    out[0] = (void*)g_7852a8;
    out[1] = (void*)g_7852ac;
    out[2] = (void*)g_7852b0;
    out[3] = (void*)g_7852b4;
    return 0;
}
