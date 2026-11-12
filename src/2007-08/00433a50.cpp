// from server: 100% by EspClaude
// from server: 42% by colin
// roc 2007-08 00433a50  unit: RBX::CMarshalWindow  size: 316 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00433a50
//
// 00433a50  6aff                 push -1
// 00433a52  6823df7300           push 0x73df23
// 00433a57  64a100000000         mov eax, dword ptr fs:[0]
// 00433a5d  50                   push eax
// 00433a5e  83ec14               sub esp, 0x14
// 00433a61  53                   push ebx
// 00433a62  55                   push ebp
// 00433a63  56                   push esi
// 00433a64  57                   push edi
// 00433a65  a188518b00           mov eax, dword ptr [0x8b5188]
// 00433a6a  33c4                 xor eax, esp
// 00433a6c  50                   push eax
// 00433a6d  8d442428             lea eax, [esp + 0x28]
// 00433a71  64a300000000         mov dword ptr fs:[0], eax
// 00433a77  8d4c2420             lea ecx, [esp + 0x20]
// 00433a7b  c74424203cb98b00     mov dword ptr [esp + 0x20], 0x8bb93c
// 00433a83  c644242400           mov byte ptr [esp + 0x24], 0
// 00433a88  e8e39dfeff           call 0x41d870
// 00433a8d  c744243000000000     mov dword ptr [esp + 0x30], 0
// 00433a95  ff15c4d27700         call dword ptr [0x77d2c4]
// 00433a9b  8bd8                 mov ebx, eax
// 00433a9d  8d442414             lea eax, [esp + 0x14]
// 00433aa1  50                   push eax
// 00433aa2  8d4c241c             lea ecx, [esp + 0x1c]
// 00433aa6  51                   push ecx
// 00433aa7  b930b98b00           mov ecx, 0x8bb930
// 00433aac  895c241c             mov dword ptr [esp + 0x1c], ebx
// 00433ab0  e80bba0100           call 0x44f4c0
// 00433ab5  8b742418             mov esi, dword ptr [esp + 0x18]
// 00433ab9  85f6                 test esi, esi
// 00433abb  8b2d34b98b00         mov ebp, dword ptr [0x8bb934]
// 00433ac1  7408                 je 0x433acb
// 00433ac3  81fe30b98b00         cmp esi, 0x8bb930
// 00433ac9  7406                 je 0x433ad1
// 00433acb  ff15d8e67700         call dword ptr [0x77e6d8]
// 00433ad1  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00433ad5  3bfd                 cmp edi, ebp
// 00433ad7  744c                 je 0x433b25
// 00433ad9  85f6                 test esi, esi
// 00433adb  8b1dd8e67700         mov ebx, dword ptr [0x77e6d8]
// 00433ae1  7502                 jne 0x433ae5
// 00433ae3  ffd3                 call ebx
// 00433ae5  3b7e04               cmp edi, dword ptr [esi + 4]
// 00433ae8  7502                 jne 0x433aec
// 00433aea  ffd3                 call ebx
// 00433aec  8b4710               mov eax, dword ptr [edi + 0x10]
// 00433aef  83402401             add dword ptr [eax + 0x24], 1
// 00433af3  3b7e04               cmp edi, dword ptr [esi + 4]
// 00433af6  7502                 jne 0x433afa
// 00433af8  ffd3                 call ebx
// 00433afa  807c242400           cmp byte ptr [esp + 0x24], 0
// 00433aff  8b7f10               mov edi, dword ptr [edi + 0x10]
// 00433b02  740b                 je 0x433b0f
// 00433b04  8b542420             mov edx, dword ptr [esp + 0x20]
// 00433b08  52                   push edx
// 00433b09  ff15f8d27700         call dword ptr [0x77d2f8]
// 00433b0f  8bc7                 mov eax, edi
// 00433b11  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00433b15  64890d00000000       mov dword ptr fs:[0], ecx
// 00433b1c  59                   pop ecx
// 00433b1d  5f                   pop edi
// 00433b1e  5e                   pop esi
// 00433b1f  5d                   pop ebp
// 00433b20  5b                   pop ebx
// 00433b21  83c420               add esp, 0x20
// 00433b24  c3                   ret 
// 00433b25  6a44                 push 0x44
// 00433b27  e8cac31f00           call 0x62fef6
// 00433b2c  83c404               add esp, 4
// 00433b2f  89442418             mov dword ptr [esp + 0x18], eax
// 00433b33  85c0                 test eax, eax
// 00433b35  c644243001           mov byte ptr [esp + 0x30], 1
// 00433b3a  740c                 je 0x433b48
// 00433b3c  53                   push ebx
// 00433b3d  8bc8                 mov ecx, eax
// 00433b3f  e8ecfdffff           call 0x433930
// 00433b44  8bf0                 mov esi, eax
// 00433b46  eb02                 jmp 0x433b4a
// 00433b48  33f6                 xor esi, esi
// 00433b4a  8d442414             lea eax, [esp + 0x14]
// 00433b4e  50                   push eax
// 00433b4f  b930b98b00           mov ecx, 0x8bb930
// 00433b54  c644243400           mov byte ptr [esp + 0x34], 0
// 00433b59  e872feffff           call 0x4339d0
// 00433b5e  8930                 mov dword ptr [eax], esi
// 00433b60  83462401             add dword ptr [esi + 0x24], 1
// 00433b64  807c242400           cmp byte ptr [esp + 0x24], 0
// 00433b69  740b                 je 0x433b76
// 00433b6b  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00433b6f  51                   push ecx
// 00433b70  ff15f8d27700         call dword ptr [0x77d2f8]
// 00433b76  8bc6                 mov eax, esi
// 00433b78  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00433b7c  64890d00000000       mov dword ptr fs:[0], ecx
// 00433b83  59                   pop ecx
// 00433b84  5f                   pop edi
// 00433b85  5e                   pop esi
// 00433b86  5d                   pop ebp
// 00433b87  5b                   pop ebx

typedef unsigned long DWORD;
typedef struct _RTL_CRITICAL_SECTION {
    void* DebugInfo;
    long LockCount;
    long RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned long SpinCount;
} CRITICAL_SECTION;
extern "C" __declspec(dllimport) DWORD __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION* section);
#include <map>

// Registry of per-thread marshal windows: std::map<DWORD, CMarshalWindow*> at
// 0x8bb930 (head +4), CRITICAL_SECTION right after it at 0x8bb93c.
// Lock object {CRITICAL_SECTION*, bool locked}: lock() is 0x41d870, the
// destructor leaves the section when locked. Windows are 0x44 bytes, ctor
// 0x433930(DWORD), reference count at +0x24.
namespace RBX {

class CriticalSectionLock {
    CRITICAL_SECTION* section;
    bool locked;
public:
    CriticalSectionLock(CRITICAL_SECTION& cs) : section(&cs), locked(false) { lock(); }
    ~CriticalSectionLock() {
        if (locked)
            LeaveCriticalSection(section);
    }
    void lock();
};

class CMarshalWindow {
    char pad0[0x24];
    int refCount;
    char pad28[0x1c];
public:
    CMarshalWindow(DWORD threadId);
    static CMarshalWindow* getWindow();
private:
    static std::map<DWORD, CMarshalWindow*> windows;
    static CRITICAL_SECTION windowsSection;
};

CMarshalWindow* CMarshalWindow::getWindow()
{
    CriticalSectionLock lock(windowsSection);
    DWORD threadId = GetCurrentThreadId();
    std::map<DWORD, CMarshalWindow*>::iterator it = windows.find(threadId);
    if (it != windows.end()) {
        it->second->refCount++;
        return it->second;
    }
    CMarshalWindow* window = new CMarshalWindow(threadId);
    windows[threadId] = window;
    window->refCount++;
    return window;
}

}
