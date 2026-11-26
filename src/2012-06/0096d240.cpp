// from server: 100% by Xemicl
// roc 2012-06 0096d240  unit: W4_D3DFORMAT::?$EnumDesc  size: 206 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0096d240
//
// 0096d240  6aff                 push -1
// 0096d242  6849aaad00           push 0xadaa49
// 0096d247  64a100000000         mov eax, dword ptr fs:[0]
// 0096d24d  50                   push eax
// 0096d24e  83ec1c               sub esp, 0x1c
// 0096d251  56                   push esi
// 0096d252  a1d027e000           mov eax, dword ptr [0xe027d0]
// 0096d257  33c4                 xor eax, esp
// 0096d259  50                   push eax
// 0096d25a  8d442424             lea eax, [esp + 0x24]
// 0096d25e  64a300000000         mov dword ptr fs:[0], eax
// 0096d264  8b742434             mov esi, dword ptr [esp + 0x34]
// 0096d268  833e01               cmp dword ptr [esi], 1
// 0096d26b  7415                 je 0x96d282
// 0096d26d  32c0                 xor al, al
// 0096d26f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0096d273  64890d00000000       mov dword ptr fs:[0], ecx
// 0096d27a  59                   pop ecx
// 0096d27b  5e                   pop esi
// 0096d27c  83c428               add esp, 0x28
// 0096d27f  c21000               ret 0x10
// 0096d282  8b0da480e500         mov ecx, dword ptr [0xe580a4]
// 0096d288  85c9                 test ecx, ecx
// 0096d28a  746d                 je 0x96d2f9
// 0096d28c  8b01                 mov eax, dword ptr [ecx]
// 0096d28e  8b10                 mov edx, dword ptr [eax]
// 0096d290  ffd2                 call edx
// 0096d292  85c0                 test eax, eax
// 0096d294  7463                 je 0x96d2f9
// 0096d296  8b442440             mov eax, dword ptr [esp + 0x40]
// 0096d29a  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0096d29e  8b542438             mov edx, dword ptr [esp + 0x38]
// 0096d2a2  50                   push eax
// 0096d2a3  51                   push ecx
// 0096d2a4  52                   push edx
// 0096d2a5  8d442414             lea eax, [esp + 0x14]
// 0096d2a9  56                   push esi
// 0096d2aa  50                   push eax
// 0096d2ab  e8f0f9ffff           call 0x96cca0
// 0096d2b0  83c414               add esp, 0x14
// 0096d2b3  83781810             cmp dword ptr [eax + 0x18], 0x10
// 0096d2b7  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0096d2bf  7205                 jb 0x96d2c6
// 0096d2c1  8b7004               mov esi, dword ptr [eax + 4]
// 0096d2c4  eb03                 jmp 0x96d2c9
// 0096d2c6  8d7004               lea esi, [eax + 4]
// 0096d2c9  8b0da480e500         mov ecx, dword ptr [0xe580a4]
// 0096d2cf  85c9                 test ecx, ecx
// 0096d2d1  7408                 je 0x96d2db
// 0096d2d3  8b11                 mov edx, dword ptr [ecx]
// 0096d2d5  8b02                 mov eax, dword ptr [edx]
// 0096d2d7  ffd0                 call eax
// 0096d2d9  eb02                 jmp 0x96d2dd
// 0096d2db  33c0                 xor eax, eax
// 0096d2dd  56                   push esi
// 0096d2de  6a00                 push 0
// 0096d2e0  8bc8                 mov ecx, eax
// 0096d2e2  e809580000           call 0x972af0
// 0096d2e7  8d4c2408             lea ecx, [esp + 8]
// 0096d2eb  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 0096d2f3  ff153c26b200         call dword ptr [0xb2263c]
// 0096d2f9  b001                 mov al, 1
// 0096d2fb  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0096d2ff  64890d00000000       mov dword ptr fs:[0], ecx
// 0096d306  59                   pop ecx
// 0096d307  5e                   pop esi
// 0096d308  83c428               add esp, 0x28
// 0096d30b  c21000               ret 0x10
// copied from an identical function in another client (function ?onEvent@@YG_NPAUInfo@@HHH@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS /EHsc /MD
#include <string>
struct Info { int type; };
class Logger {
public:
    virtual Logger* get();
    void write(int level, const char* msg);
};
extern Logger* gLogger;
static inline Logger* logger() { return gLogger ? gLogger->get() : 0; }
std::string describe(Info* info, int a, int b, int c);
bool __stdcall onEvent(Info* info, int a, int b, int c)
{
    if (info->type != 1)
        return false;
    if (logger())
        logger()->write(0, describe(info, a, b, c).c_str());
    return true;
}