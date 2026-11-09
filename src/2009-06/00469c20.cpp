// from server: 100% by EspClaude
// roc 2009-06 00469c20  unit: DxUserInput  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00469c20
//
// 00469c20  6aff                 push -1
// 00469c22  681b328500           push 0x85321b
// 00469c27  64a100000000         mov eax, dword ptr fs:[0]
// 00469c2d  50                   push eax
// 00469c2e  64892500000000       mov dword ptr fs:[0], esp
// 00469c35  51                   push ecx
// 00469c36  56                   push esi
// 00469c37  8bf1                 mov esi, ecx
// 00469c39  89742404             mov dword ptr [esp + 4], esi
// 00469c3d  8b4624               mov eax, dword ptr [esi + 0x24]
// 00469c40  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00469c48  85c0                 test eax, eax
// 00469c4a  742c                 je 0x469c78
// 00469c4c  83c004               add eax, 4
// 00469c4f  50                   push eax
// 00469c50  ff15a4e18900         call dword ptr [0x89e1a4]
// 00469c56  85c0                 test eax, eax
// 00469c58  7517                 jne 0x469c71
// 00469c5a  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 00469c5d  e81eb1fdff           call 0x444d80
// 00469c62  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 00469c65  85c9                 test ecx, ecx
// 00469c67  7408                 je 0x469c71
// 00469c69  8b01                 mov eax, dword ptr [ecx]
// 00469c6b  8b10                 mov edx, dword ptr [eax]
// 00469c6d  6a01                 push 1
// 00469c6f  ffd2                 call edx
// 00469c71  c7462400000000       mov dword ptr [esi + 0x24], 0
// 00469c78  8d4e04               lea ecx, [esi + 4]
// 00469c7b  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00469c83  ff15c4e48900         call dword ptr [0x89e4c4]
// 00469c89  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00469c8d  5e                   pop esi
// 00469c8e  64890d00000000       mov dword ptr fs:[0], ecx
// 00469c95  83c410               add esp, 0x10
// 00469c98  c3                   ret 
// copied from an identical function in another client (function ??1S_func_00467770@ns_ROCX000004@@QAE@XZ)

namespace ns_ROCX000004 {
extern "C" long (__stdcall *InterlockedDecrement)(volatile long *);

typedef void (__thiscall *StringDestructor)(void *);
extern StringDestructor destroyString;

struct StringStorage {
    char storage[32];
    ~StringStorage() { destroyString(this); }
};

struct Control {
    virtual ~Control();
    volatile long references;
    void dispose();
};

struct S_func_00467770 {
    char pad0[4];
    StringStorage text;
    Control *control;

    ~S_func_00467770();
};

S_func_00467770::~S_func_00467770()
{
    if (control) {
        if (InterlockedDecrement(&control->references) == 0) {
            control->dispose();
            if (control)
                delete control;
        }
        control = 0;
    }
}
}
