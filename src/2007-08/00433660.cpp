// from server: 100% by EspClaude
// from server: 50% by colin
// roc 2007-08 00433660  unit: RBX::CMarshalWindow  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00433660
//
// 00433660  6aff                 push -1
// 00433662  68882e7400           push 0x742e88
// 00433667  64a100000000         mov eax, dword ptr fs:[0]
// 0043366d  50                   push eax
// 0043366e  83ec08               sub esp, 8
// 00433671  56                   push esi
// 00433672  a188518b00           mov eax, dword ptr [0x8b5188]
// 00433677  33c4                 xor eax, esp
// 00433679  50                   push eax
// 0043367a  8d442410             lea eax, [esp + 0x10]
// 0043367e  64a300000000         mov dword ptr fs:[0], eax
// 00433684  8d4c2408             lea ecx, [esp + 8]
// 00433688  c74424083cb98b00     mov dword ptr [esp + 8], 0x8bb93c
// 00433690  c644240c00           mov byte ptr [esp + 0xc], 0
// 00433695  e8d6a1feff           call 0x41d870
// 0043369a  8b742420             mov esi, dword ptr [esp + 0x20]
// 0043369e  834624ff             add dword ptr [esi + 0x24], -1
// 004336a2  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004336aa  7518                 jne 0x4336c4
// 004336ac  8d4628               lea eax, [esi + 0x28]
// 004336af  50                   push eax
// 004336b0  b930b98b00           mov ecx, 0x8bb930
// 004336b5  e8663bfdff           call 0x407220
// 004336ba  8b4e04               mov ecx, dword ptr [esi + 4]
// 004336bd  51                   push ecx
// 004336be  ff1524ec7700         call dword ptr [0x77ec24]
// 004336c4  807c240c00           cmp byte ptr [esp + 0xc], 0
// 004336c9  740b                 je 0x4336d6
// 004336cb  8b542408             mov edx, dword ptr [esp + 8]
// 004336cf  52                   push edx
// 004336d0  ff15f8d27700         call dword ptr [0x77d2f8]
// 004336d6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004336da  64890d00000000       mov dword ptr fs:[0], ecx
// 004336e1  59                   pop ecx
// 004336e2  5e                   pop esi
// 004336e3  83c414               add esp, 0x14
// 004336e6  c3                   ret 

// Codegen analog rewritten from the target: a scoped critical-section lock on the
// global at 0x8bb93c (inline ctor stores {&cs, false} then calls out-of-line lock(),
// inline dtor calls LeaveCriticalSection through the IAT), a refcount at +0x24,
// erase(&field_28) on the global container at 0x8bb930 and an IAT call on the handle at +4.
struct _RTL_CRITICAL_SECTION;
struct HWND__;
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(_RTL_CRITICAL_SECTION* cs);
extern "C" __declspec(dllimport) int __stdcall DestroyWindow(HWND__* hWnd);

namespace RBX {

class ScopedCriticalSection {
    _RTL_CRITICAL_SECTION* cs;
    bool locked;
public:
    ScopedCriticalSection(_RTL_CRITICAL_SECTION& c) : cs(&c), locked(false) { lock(); }
    ~ScopedCriticalSection() { if (locked) LeaveCriticalSection(cs); }
    void lock();                                            // 0x41d870
};

class WindowRegistry {
public:
    unsigned int erase(const int& key);                     // 0x407220
};

extern WindowRegistry windows;                              // 0x8bb930
extern _RTL_CRITICAL_SECTION windowsLock;                   // 0x8bb93c

class CMarshalWindow {
public:
    void* vfptr;
    HWND__* hWnd;            // +0x04
    char pad8[0x24 - 0x8];
    int refCount;            // +0x24
    int key;                 // +0x28

    static void release(CMarshalWindow* window);
};

void CMarshalWindow::release(CMarshalWindow* window)
{
    ScopedCriticalSection lock(windowsLock);
    if (--window->refCount == 0) {
        windows.erase(window->key);
        DestroyWindow(window->hWnd);
    }
}

}
