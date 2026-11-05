// from server: 57% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

// Global function pointer type
typedef bool (__cdecl *DebugHookFunc)(const char*, int, int);

// Global variables
extern DebugHookFunc g_debugHook;  // at 0xe5809c
extern const char* g_debugString1; // at 0xbabde8
extern int g_debugValue;           // at 0xbabe00

// External functions
extern "C" void __cdecl DebugBreakFunc(const char*); // 0x9723f0

// Forward declaration of the class method at 0x7534f0
struct RefCountedObject {
    virtual void OnRefCountZero() = 0; // at 0x7534f0
    // ref count at offset 0x100

    void AddRef();
};

void RefCountedObject::AddRef() {
    // This is the function at 007535d0
    volatile long* refCount = reinterpret_cast<volatile long*>(reinterpret_cast<char*>(this) + 0x100);
    
    // First check: if *refCount >= 0, skip debug check
    if (*refCount < 0) {
        if (g_debugHook) {
            if (g_debugHook(g_debugString1, g_debugValue, 0xB7)) {
                goto do_increment;
            }
        }
        DebugBreakFunc(g_debugString1);
    }
    
do_increment:
    long oldValue = _InterlockedExchangeAdd(refCount, 1);
    long newValue = oldValue + 1;
    
    if (newValue == 1) {
        this->OnRefCountZero();
    }
    
    // Second check: if *refCount >= 0, return
    if (*refCount < 0) {
        if (g_debugHook) {
            if (g_debugHook(g_debugString1, g_debugValue, 0xBB)) {
                return;
            }
        }
        DebugBreakFunc(g_debugString1);
    }
}
