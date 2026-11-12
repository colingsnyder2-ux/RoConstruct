// from server: 100% by EspClaude
// from server: 45% by colin
// roc 2007-08 00464e10  unit: DxUserInput  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00464e10
// 00464e10  6aff                 push -1
// 00464e12  68882e7400           push 0x742e88
// 00464e17  64a100000000         mov eax, dword ptr fs:[0]
// 00464e1d  50                   push eax
// 00464e1e  83ec08               sub esp, 8
// 00464e21  56                   push esi
// 00464e22  a188518b00           mov eax, dword ptr [0x8b5188]
// 00464e27  33c4                 xor eax, esp
// 00464e29  50                   push eax
// 00464e2a  8d442410             lea eax, [esp + 0x10]
// 00464e2e  64a300000000         mov dword ptr fs:[0], eax
// 00464e34  8bf1                 mov esi, ecx
// 00464e36  8d4608               lea eax, [esi + 8]
// 00464e39  8d4c2408             lea ecx, [esp + 8]
// 00464e3d  89442408             mov dword ptr [esp + 8], eax
// 00464e41  c644240c00           mov byte ptr [esp + 0xc], 0
// 00464e46  e8258afbff           call 0x41d870
// 00464e4b  807e3c00             cmp byte ptr [esi + 0x3c], 0
// 00464e4f  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00464e57  7408                 je 0x464e61
// 00464e59  8d4ed4               lea ecx, [esi - 0x2c]
// 00464e5c  e8bffbffff           call 0x464a20
// 00464e61  8b8664010000         mov eax, dword ptr [esi + 0x164]
// 00464e67  85c0                 test eax, eax
// 00464e69  7411                 je 0x464e7c
// 00464e6b  8b08                 mov ecx, dword ptr [eax]
// 00464e6d  8d564f               lea edx, [esi + 0x4f]
// 00464e70  52                   push edx
// 00464e71  6800010000           push 0x100
// 00464e76  50                   push eax
// 00464e77  8b4124               mov eax, dword ptr [ecx + 0x24]
// 00464e7a  ffd0                 call eax
// 00464e7c  807e4d00             cmp byte ptr [esi + 0x4d], 0
// 00464e80  7408                 je 0x464e8a
// 00464e82  8d4ed4               lea ecx, [esi - 0x2c]
// 00464e85  e8a6eeffff           call 0x463d30
// 00464e8a  807c240c00           cmp byte ptr [esp + 0xc], 0
// 00464e8f  740b                 je 0x464e9c
// 00464e91  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00464e95  51                   push ecx
// 00464e96  ff15f8d27700         call dword ptr [0x77d2f8]
// 00464e9c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00464ea0  64890d00000000       mov dword ptr fs:[0], ecx
// 00464ea7  59                   pop ecx
// 00464ea8  5e                   pop esi
// 00464ea9  83c414               add esp, 0x14
// 00464eac  c20c00               ret 0xc

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

struct CritSec { int raw[6]; };

struct ScopedLock {
    CritSec* m;
    bool locked;
    ScopedLock(CritSec& cs) : m(&cs), locked(false) { lock(); }
    ~ScopedLock() { if (locked) LeaveCriticalSection(m); }
    void lock();
};

struct IInputDevice {
    virtual long __stdcall f0() = 0;
    virtual long __stdcall f1() = 0;
    virtual long __stdcall f2() = 0;
    virtual long __stdcall f3() = 0;
    virtual long __stdcall f4() = 0;
    virtual long __stdcall f5() = 0;
    virtual long __stdcall f6() = 0;
    virtual long __stdcall f7() = 0;
    virtual long __stdcall f8() = 0;
    virtual long __stdcall GetDeviceState(unsigned long cb, void* data) = 0;
};

struct DxUserInput {
    void acquire();   // 0x464a20
    void process();   // 0x463d30
};

struct DxUserInputListener {
    char pad0[8];
    CritSec mutex;          // +0x08
    char pad1[0x3c - 0x20];
    bool active;            // +0x3c
    char pad2[0x4d - 0x3d];
    bool pending;           // +0x4d
    char pad3;
    unsigned char keys[0x100]; // +0x4f
    char pad4[0x164 - 0x14f];
    IInputDevice* device;   // +0x164
    void onEvent(int a, int b, int c);
};

void DxUserInputListener::onEvent(int, int, int)
{
    ScopedLock lock(mutex);
    if (active)
        ((DxUserInput*)((char*)this - 0x2c))->acquire();
    IInputDevice* d = device;
    if (d)
        d->GetDeviceState(0x100, keys);
    if (pending)
        ((DxUserInput*)((char*)this - 0x2c))->process();
}
