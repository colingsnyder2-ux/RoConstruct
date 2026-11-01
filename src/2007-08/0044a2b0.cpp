// from server: 100% by Yeetserama
// roc 2007-08 0044a2b0  unit: CRobloxModule  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044a2b0
//
// 0044a2b0  6aff                 push -1
// 0044a2b2  68c6fd7300           push 0x73fdc6
// 0044a2b7  64a100000000         mov eax, dword ptr fs:[0]
// 0044a2bd  50                   push eax
// 0044a2be  51                   push ecx
// 0044a2bf  56                   push esi
// 0044a2c0  a188518b00           mov eax, dword ptr [0x8b5188]
// 0044a2c5  33c4                 xor eax, esp
// 0044a2c7  50                   push eax
// 0044a2c8  8d44240c             lea eax, [esp + 0xc]
// 0044a2cc  64a300000000         mov dword ptr fs:[0], eax
// 0044a2d2  8bf1                 mov esi, ecx
// 0044a2d4  89742408             mov dword ptr [esp + 8], esi
// 0044a2d8  6a00                 push 0
// 0044a2da  e8e7641e00           call 0x6307c6
// 0044a2df  685c517800           push 0x78515c
// 0044a2e4  8d8ea4000000         lea ecx, [esi + 0xa4]
// 0044a2ea  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0044a2f2  c70694077900         mov dword ptr [esi], 0x790794
// 0044a2f8  e873f9fdff           call 0x429c70
// 0044a2fd  8d8ef0000000         lea ecx, [esi + 0xf0]
// 0044a303  c644241401           mov byte ptr [esp + 0x14], 1
// 0044a308  ff15a4e67700         call dword ptr [0x77e6a4]
// 0044a30e  c7860c01000000000000 mov dword ptr [esi + 0x10c], 0
// 0044a318  8bc6                 mov eax, esi
// 0044a31a  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0044a31e  64890d00000000       mov dword ptr fs:[0], ecx
// 0044a325  59                   pop ecx
// 0044a326  5e                   pop esi
// 0044a327  83c410               add esp, 0x10
// 0044a32a  c3                   ret 
// copied from an identical function in another client (function ??0CRobloxModule@ns_ROCX000004@@QAE@XZ)

namespace ns_ROCX000004 {
// from server: 100% by king_originala
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
