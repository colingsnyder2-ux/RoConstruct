// from server: 100% by EspClaude
// roc 2009-06 00448e30  unit: CRobloxCommandLineInfo  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00448e30
//
// 00448e30  6aff                 push -1
// 00448e32  68b6098500           push 0x8509b6
// 00448e37  64a100000000         mov eax, dword ptr fs:[0]
// 00448e3d  50                   push eax
// 00448e3e  64892500000000       mov dword ptr fs:[0], esp
// 00448e45  51                   push ecx
// 00448e46  56                   push esi
// 00448e47  8bf1                 mov esi, ecx
// 00448e49  6a00                 push 0
// 00448e4b  89742408             mov dword ptr [esp + 8], esi
// 00448e4f  e892082d00           call 0x7196e6
// 00448e54  68c0f68a00           push 0x8af6c0
// 00448e59  8d8ea4000000         lea ecx, [esi + 0xa4]
// 00448e5f  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00448e67  c7060c738b00         mov dword ptr [esi], 0x8b730c
// 00448e6d  e87ecbfdff           call 0x4259f0
// 00448e72  8d8ef0000000         lea ecx, [esi + 0xf0]
// 00448e78  c644241001           mov byte ptr [esp + 0x10], 1
// 00448e7d  ff15c0e48900         call dword ptr [0x89e4c0]
// 00448e83  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00448e87  c7860c01000000000000 mov dword ptr [esi + 0x10c], 0
// 00448e91  8bc6                 mov eax, esi
// 00448e93  5e                   pop esi
// 00448e94  64890d00000000       mov dword ptr fs:[0], ecx
// 00448e9b  83c410               add esp, 0x10
// 00448e9e  c3                   ret 
// copied from an identical function in another client (function ??0CRobloxModule@ns_ROCX000005@@QAE@XZ)

namespace ns_ROCX000005 {
struct Base
{
    unsigned char storage[160];
    Base(int);
    virtual ~Base();
};

struct String
{
    unsigned char storage[28];
    String(const char*);
    ~String();
};

extern void (__thiscall *constructString)(void*);

struct CRobloxModule : Base
{
    String name;
    unsigned char padding[48];
    unsigned char text[28];
    unsigned value;

    CRobloxModule();
    virtual ~CRobloxModule();
};

CRobloxModule::CRobloxModule()
    : Base(0), name("Roblox")
{
    constructString(text);
    value = 0;
}
}
