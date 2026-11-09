// from server: 63% by Intel
// roc-repair: genuine WinNT.h definitions (no SDK shipped)
typedef unsigned long DWORD;
// Global variables
char g_initialized = 0;  // 0xe2f9c8
DWORD g_marker = 0;      // 0xe2f9bc
DWORD g_unk1 = 0;        // 0xe2f9c0
DWORD g_unk2 = 0;        // 0xe2f9c4

// External function
extern "C" void __stdcall InitializeSomething(DWORD arg);

// The class
struct SlotWrapper {
    void* marker;  // 0
    void* data;    // 4
    
    SlotWrapper* Connect(void* callable);
};

SlotWrapper* SlotWrapper::Connect(void* callable) {
    if (!g_initialized) {
        g_initialized = 1;
        InitializeSomething(0xB16B90);
        g_marker = 0xDA45B8;
        g_unk2 = 0x5708D0;
        g_unk1 = 0x59A790;
    }
    
    if (marker == (void*)0xE2F9BC) {
        // Direct assignment
        data = *(void**)callable;
        return this;
    }
    
    if (marker != 0) {
        // Call cleanup function
        typedef void (__thiscall *CleanupFunc)(void*);
        CleanupFunc cleanup = (CleanupFunc)*(DWORD*)((DWORD)marker + 4);
        cleanup(&data);
        marker = 0;
    }
    
    // Assign new callable
    data = *(void**)callable;
    marker = (void*)0xE2F9BC;
    return this;
}
