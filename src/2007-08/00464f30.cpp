// from server: 94% by EspClaude
// from server: 53% by colin
// roc 2007-08 00464f30  unit: DxUserInput  size: 464 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00464f30
//
// 00464f30  6aff                 push -1
// 00464f32  6819317400           push 0x743119
// 00464f37  64a100000000         mov eax, dword ptr fs:[0]
// 00464f3d  50                   push eax
// 00464f3e  83ec0c               sub esp, 0xc
// 00464f41  55                   push ebp
// 00464f42  56                   push esi
// 00464f43  57                   push edi
// 00464f44  a188518b00           mov eax, dword ptr [0x8b5188]
// 00464f49  33c4                 xor eax, esp
// 00464f4b  50                   push eax
// 00464f4c  8d44241c             lea eax, [esp + 0x1c]
// 00464f50  64a300000000         mov dword ptr fs:[0], eax
// 00464f56  8bf1                 mov esi, ecx
// 00464f58  89742418             mov dword ptr [esp + 0x18], esi
// 00464f5c  8d6e28               lea ebp, [esi + 0x28]
// 00464f5f  8d7e2c               lea edi, [esi + 0x2c]
// 00464f62  c706dc5b7900         mov dword ptr [esi], 0x795bdc
// 00464f68  c74500d05b7900       mov dword ptr [ebp], 0x795bd0
// 00464f6f  c707c45b7900         mov dword ptr [edi], 0x795bc4
// 00464f75  8b8e94010000         mov ecx, dword ptr [esi + 0x194]
// 00464f7b  85c9                 test ecx, ecx
// 00464f7d  c744242407000000     mov dword ptr [esp + 0x24], 7
// 00464f85  7415                 je 0x464f9c
// 00464f87  e874bdfeff           call 0x450d00
// 00464f8c  85c0                 test eax, eax
// 00464f8e  740c                 je 0x464f9c
// 00464f90  57                   push edi
// 00464f91  8d88e8000000         lea ecx, [eax + 0xe8]
// 00464f97  e894d5fcff           call 0x432530
// 00464f9c  8b8e94010000         mov ecx, dword ptr [esi + 0x194]
// 00464fa2  85c9                 test ecx, ecx
// 00464fa4  7415                 je 0x464fbb
// 00464fa6  e855bdfeff           call 0x450d00
// 00464fab  85c0                 test eax, eax
// 00464fad  740c                 je 0x464fbb
// 00464faf  55                   push ebp
// 00464fb0  8d8818010000         lea ecx, [eax + 0x118]
// 00464fb6  e875d5fcff           call 0x432530
// 00464fbb  8b868c010000         mov eax, dword ptr [esi + 0x18c]
// 00464fc1  85c0                 test eax, eax
// 00464fc3  7424                 je 0x464fe9
// 00464fc5  8b08                 mov ecx, dword ptr [eax]
// 00464fc7  8b5120               mov edx, dword ptr [ecx + 0x20]
// 00464fca  50                   push eax
// 00464fcb  ffd2                 call edx
// 00464fcd  8b868c010000         mov eax, dword ptr [esi + 0x18c]
// 00464fd3  85c0                 test eax, eax
// 00464fd5  7412                 je 0x464fe9
// 00464fd7  8b08                 mov ecx, dword ptr [eax]
// 00464fd9  8b5108               mov edx, dword ptr [ecx + 8]
// 00464fdc  50                   push eax
// 00464fdd  ffd2                 call edx
// 00464fdf  c7868c01000000000000 mov dword ptr [esi + 0x18c], 0
// 00464fe9  8b8690010000         mov eax, dword ptr [esi + 0x190]
// 00464fef  85c0                 test eax, eax
// 00464ff1  7424                 je 0x465017
// 00464ff3  8b08                 mov ecx, dword ptr [eax]
// 00464ff5  8b5120               mov edx, dword ptr [ecx + 0x20]
// 00464ff8  50                   push eax
// 00464ff9  ffd2                 call edx
// 00464ffb  8b8690010000         mov eax, dword ptr [esi + 0x190]
// 00465001  85c0                 test eax, eax
// 00465003  7412                 je 0x465017
// 00465005  8b08                 mov ecx, dword ptr [eax]
// 00465007  8b5108               mov edx, dword ptr [ecx + 8]
// 0046500a  50                   push eax
// 0046500b  ffd2                 call edx
// 0046500d  c7869001000000000000 mov dword ptr [esi + 0x190], 0
// 00465017  83be8801000000       cmp dword ptr [esi + 0x188], 0
// 0046501e  741c                 je 0x46503c
// 00465020  8b8688010000         mov eax, dword ptr [esi + 0x188]
// 00465026  85c0                 test eax, eax
// 00465028  7412                 je 0x46503c
// 0046502a  8b08                 mov ecx, dword ptr [eax]
// 0046502c  8b5108               mov edx, dword ptr [ecx + 8]
// 0046502f  50                   push eax
// 00465030  ffd2                 call edx
// 00465032  c7868801000000000000 mov dword ptr [esi + 0x188], 0
// 0046503c  8b4650               mov eax, dword ptr [esi + 0x50]
// 0046503f  50                   push eax
// 00465040  e8e1ae1c00           call 0x62ff26
// 00465045  8bbe98010000         mov edi, dword ptr [esi + 0x198]
// 0046504b  83c404               add esp, 4
// 0046504e  85ff                 test edi, edi
// 00465050  c644242406           mov byte ptr [esp + 0x24], 6
// 00465055  742a                 je 0x465081
// 00465057  8d4704               lea eax, [edi + 4]
// 0046505a  83c9ff               or ecx, 0xffffffff
// 0046505d  f00fc108             lock xadd dword ptr [eax], ecx
// 00465061  751e                 jne 0x465081
// 00465063  8b17                 mov edx, dword ptr [edi]
// 00465065  8b4204               mov eax, dword ptr [edx + 4]
// 00465068  8bcf                 mov ecx, edi
// 0046506a  ffd0                 call eax
// 0046506c  8d4f08               lea ecx, [edi + 8]
// 0046506f  83caff               or edx, 0xffffffff
// 00465072  f00fc111             lock xadd dword ptr [ecx], edx
// 00465076  7509                 jne 0x465081
// 00465078  8b07                 mov eax, dword ptr [edi]
// 0046507a  8b5008               mov edx, dword ptr [eax + 8]
// 0046507d  8bcf                 mov ecx, edi
// 0046507f  ffd2                 call edx
// 00465081  8b8690010000         mov eax, dword ptr [esi + 0x190]
// 00465087  85c0                 test eax, eax
// 00465089  c644242405           mov byte ptr [esp + 0x24], 5
// 0046508e  7408                 je 0x465098
// 00465090  8b08                 mov ecx, dword ptr [eax]
// 00465092  8b5108               mov edx, dword ptr [ecx + 8]
// 00465095  50                   push eax
// 00465096  ffd2                 call edx
// 00465098  8b868c010000         mov eax, dword ptr [esi + 0x18c]
// 0046509e  85c0                 test eax, eax
// 004650a0  c644242404           mov byte ptr [esp + 0x24], 4
// 004650a5  7408                 je 0x4650af
// 004650a7  8b08                 mov ecx, dword ptr [eax]
// 004650a9  8b5108               mov edx, dword ptr [ecx + 8]
// 004650ac  50                   push eax
// 004650ad  ffd2                 call edx
// 004650af  8b8688010000         mov eax, dword ptr [esi + 0x188]
// 004650b5  85c0                 test eax, eax
// 004650b7  c644242403           mov byte ptr [esp + 0x24], 3
// 004650bc  7408                 je 0x4650c6
// 004650be  8b08                 mov ecx, dword ptr [eax]
// 004650c0  8b5108               mov edx, dword ptr [ecx + 8]
// 004650c3  50                   push eax
// 004650c4  ffd2                 call edx
// 004650c6  8d4634               lea eax, [esi + 0x34]
// 004650c9  50                   push eax
// 004650ca  ff1504d37700         call dword ptr [0x77d304]
// 004650d0  c7462c605b7900       mov dword ptr [esi + 0x2c], 0x795b60
// 004650d7  8bce                 mov ecx, esi
// 004650d9  c74500545b7900       mov dword ptr [ebp], 0x795b54
// 004650e0  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 004650e8  e843e7ffff           call 0x463830
// 004650ed  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004650f1  64890d00000000       mov dword ptr fs:[0], ecx
// 004650f8  59                   pop ecx
// 004650f9  5f                   pop edi
// 004650fa  5e                   pop esi
// 004650fb  5d                   pop ebp
// 004650fc  83c418               add esp, 0x18
// 004650ff  c3                   ret 

// Win32 CRITICAL_SECTION (24 bytes), DeleteCriticalSection called through the IAT.
struct CRITICAL_SECTION { void* DebugInfo; long LockCount; long RecursionCount;
                          void* OwningThread; void* LockSemaphore; unsigned long SpinCount; };
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(CRITICAL_SECTION*);
#include <intrin.h>

// Interfaces called through vtables with push-this (stdcall COM): +8 Release, +0x20 Unacquire.
struct IDeviceLike {
    virtual long __stdcall QueryInterface(const void*, void**) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall GetCapabilities(void*) = 0;
    virtual long __stdcall EnumObjects(void*, void*, unsigned long) = 0;
    virtual long __stdcall GetProperty(const void*, void*) = 0;
    virtual long __stdcall SetProperty(const void*, const void*) = 0;
    virtual long __stdcall Acquire() = 0;
    virtual long __stdcall Unacquire() = 0;
};

template<class T> struct ComPtr {
    T* p;
    ~ComPtr() { if (p) p->Release(); }
};

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
    long use_count_;
    long weak_count_;
};

template<class T> struct shared_ptr {
    T* px;
    sp_counted_base* pn;
    ~shared_ptr() { if (pn != 0) pn->release(); }
    T* get() const { return px; }
    operator bool() const { return px != 0; }
};

struct Mutex {
    CRITICAL_SECTION cs;
    ~Mutex() { DeleteCriticalSection(&cs); }
};

struct ListenerList {
    void remove(void* listener);                   // 0x432530
};

struct InputHost {
    char pad[0xe8];
    ListenerList listenersA;                       // +0xe8
    char pad2[0x118 - 0xe9];
    ListenerList listenersB;                       // +0x118
};

struct Workspace {
    InputHost* getHost();                          // 0x450d00
};

void __cdecl freeBuffer(void* p);                  // 0x62ff26

struct UserInputBase {
    virtual ~UserInputBase();                      // 0x463830
    char pad[0x28 - 4];
};

struct ListenerA { virtual ~ListenerA() {} };     // +0x28
struct ListenerB { virtual ~ListenerB() {} };     // +0x2c

class DxUserInput : public UserInputBase, public ListenerA, public ListenerB {
    int pad30;
    Mutex mutex;                                   // +0x34
    char pad4c[0x50 - 0x4c];
    void* buffer;                                  // +0x50
    char pad54[0x188 - 0x54];
    ComPtr<IDeviceLike> dinput;                    // +0x188
    ComPtr<IDeviceLike> keyboard;                  // +0x18c
    ComPtr<IDeviceLike> mouse;                     // +0x190
    shared_ptr<Workspace> workspace;               // +0x194
public:
    virtual ~DxUserInput();
};

DxUserInput::~DxUserInput()
{
    if (workspace) {
        if (InputHost* host = workspace.get()->getHost())
            host->listenersA.remove(static_cast<ListenerB*>(this));
    }
    if (workspace) {
        if (InputHost* host = workspace.get()->getHost())
            host->listenersB.remove(static_cast<ListenerA*>(this));
    }
    if (keyboard.p) {
        keyboard.p->Unacquire();
        if (keyboard.p) { keyboard.p->Release(); keyboard.p = 0; }
    }
    if (mouse.p) {
        mouse.p->Unacquire();
        if (mouse.p) { mouse.p->Release(); mouse.p = 0; }
    }
    if (dinput.p) {
        IDeviceLike*& d = dinput.p;
        if (d) { d->Release(); d = 0; }
    }
    freeBuffer(buffer);
}
