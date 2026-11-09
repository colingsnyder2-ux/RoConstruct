// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* cs);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs);
struct CS { char data[0x18]; };
extern bool g_lockEnabled;
extern CS g_lock;
__forceinline void lockGlobals() { if (g_lockEnabled) EnterCriticalSection(&g_lock); }
__forceinline void unlockGlobals() { if (g_lockEnabled) LeaveCriticalSection(&g_lock); }
struct Context;
struct Device {
    long init(Context* ctx, void* arg);
};
struct Globals {
    Context* context;
    int pad4;
    Device* device;
    char pad[0x258 - 0xc];
    void* setting;
    char rest[0xb98 - 0x25c];
    Globals() throw();
    ~Globals();
};
__forceinline Globals& globals() { static Globals g; return g; }
Context* getContext();
Device* createDevice();
__forceinline Device* getStoredDevice() { Globals& g = globals(); lockGlobals(); Device* d = g.device; unlockGlobals(); return d; }
__forceinline void setStoredDevice(Device* d) { Globals& g = globals(); lockGlobals(); g.device = d; unlockGlobals(); }
__forceinline void* getSetting() { Globals& g = globals(); lockGlobals(); void* s = g.setting; unlockGlobals(); return s; }
Device* getDevice(bool reinit)
{
    Device* d = getStoredDevice();
    Device* result = d;
    if (d == 0) {
        result = createDevice();
        setStoredDevice(result);
    }
    if (d == 0 || reinit) {
        Context* ctx = getContext();
        void* s = getSetting();
        result->init(ctx, s);
    }
    return result;
}
