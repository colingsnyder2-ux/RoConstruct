// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 004677f0  unit: DxUserInput  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004677f0
//
// 004677f0  6aff                 push -1
// 004677f2  6868367c00           push 0x7c3668
// 004677f7  64a100000000         mov eax, dword ptr fs:[0]
// 004677fd  50                   push eax
// 004677fe  64892500000000       mov dword ptr fs:[0], esp
// 00467805  83ec08               sub esp, 8
// 00467808  56                   push esi
// 00467809  57                   push edi
// 0046780a  8bf1                 mov esi, ecx
// 0046780c  8d7e34               lea edi, [esi + 0x34]
// 0046780f  57                   push edi
// 00467810  897c240c             mov dword ptr [esp + 0xc], edi
// 00467814  ff15d4228000         call dword ptr [0x8022d4]
// 0046781a  c644240c01           mov byte ptr [esp + 0xc], 1
// 0046781f  8b867c010000         mov eax, dword ptr [esi + 0x17c]
// 00467825  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0046782d  85c0                 test eax, eax
// 0046782f  742a                 je 0x46785b
// 00467831  8a8e91010000         mov cl, byte ptr [esi + 0x191]
// 00467837  388e93010000         cmp byte ptr [esi + 0x193], cl
// 0046783d  741c                 je 0x46785b
// 0046783f  84c9                 test cl, cl
// 00467841  7409                 je 0x46784c
// 00467843  8bce                 mov ecx, esi
// 00467845  e8d6feffff           call 0x467720
// 0046784a  eb0f                 jmp 0x46785b
// 0046784c  8b08                 mov ecx, dword ptr [eax]
// 0046784e  8b5120               mov edx, dword ptr [ecx + 0x20]
// 00467851  50                   push eax
// 00467852  ffd2                 call edx
// 00467854  c6869301000000       mov byte ptr [esi + 0x193], 0
// 0046785b  57                   push edi
// 0046785c  ff15f4218000         call dword ptr [0x8021f4]
// 00467862  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00467866  5f                   pop edi
// 00467867  5e                   pop esi
// 00467868  64890d00000000       mov dword ptr fs:[0], ecx
// 0046786f  83c414               add esp, 0x14
// 00467872  c3                   ret 

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void *);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void *);

struct Lock {
    void *section;
    bool held;
    Lock(void *);
    ~Lock();
};

__forceinline Lock::Lock(void *p) : section(p), held(false) {
    EnterCriticalSection(section);
    held = true;
}

__forceinline Lock::~Lock() {
    if (held)
        LeaveCriticalSection(section);
}

struct Device;

struct DeviceTable {
    char padding[0x20];
    void (__stdcall *releaseInput)(Device *);
};

struct Device {
    DeviceTable *table;
};

struct DxUserInput {
    char storage[0x174];
    Device *device;
    char padding[0x11];
    bool requested;
    char padding2;
    bool active;

    void enableInput();
    void updateInput();
};

void DxUserInput::updateInput() {
    Lock lock(storage + 0x2c);
    if (device && active != requested) {
        if (requested) {
            enableInput();
        } else {
            device->table->releaseInput(device);
            active = false;
        }
    }
}
