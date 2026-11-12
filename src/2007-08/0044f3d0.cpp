// from server: 100% by EspClaude
// from server: 40% by colin
// roc 2007-08 0044f3d0  unit: CRobloxDoc  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044f3d0
//
// 0044f3d0  6aff                 push -1
// 0044f3d2  68080b7400           push 0x740b08
// 0044f3d7  64a100000000         mov eax, dword ptr fs:[0]
// 0044f3dd  50                   push eax
// 0044f3de  51                   push ecx
// 0044f3df  56                   push esi
// 0044f3e0  57                   push edi
// 0044f3e1  a188518b00           mov eax, dword ptr [0x8b5188]
// 0044f3e6  33c4                 xor eax, esp
// 0044f3e8  50                   push eax
// 0044f3e9  8d442410             lea eax, [esp + 0x10]
// 0044f3ed  64a300000000         mov dword ptr fs:[0], eax
// 0044f3f3  8bf9                 mov edi, ecx
// 0044f3f5  897c240c             mov dword ptr [esp + 0xc], edi
// 0044f3f9  e85e0b1e00           call 0x62ff5c
// 0044f3fe  8d7754               lea esi, [edi + 0x54]
// 0044f401  8bce                 mov ecx, esi
// 0044f403  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0044f40b  c7072c177900         mov dword ptr [edi], 0x79172c
// 0044f411  e89a411300           call 0x5835b0
// 0044f416  894604               mov dword ptr [esi + 4], eax
// 0044f419  c6401501             mov byte ptr [eax + 0x15], 1
// 0044f41d  8b4604               mov eax, dword ptr [esi + 4]
// 0044f420  894004               mov dword ptr [eax + 4], eax
// 0044f423  8b4604               mov eax, dword ptr [esi + 4]
// 0044f426  8900                 mov dword ptr [eax], eax
// 0044f428  8b4604               mov eax, dword ptr [esi + 4]
// 0044f42b  894008               mov dword ptr [eax + 8], eax
// 0044f42e  c7460800000000       mov dword ptr [esi + 8], 0
// 0044f435  8bc7                 mov eax, edi
// 0044f437  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0044f43b  64890d00000000       mov dword ptr fs:[0], ecx
// 0044f442  59                   pop ecx
// 0044f443  5f                   pop edi
// 0044f444  5e                   pop esi
// 0044f445  83c410               add esp, 0x10
// 0044f448  c3                   ret 

#include <map>

class CDocBase {
public:
    CDocBase();                         // 0x62ff5c
    virtual ~CDocBase();
};

class CRobloxDoc : public CDocBase {
public:
    CRobloxDoc();
    virtual ~CRobloxDoc();
    char pad_0004[0x54 - 0x04];
    std::map<void*, void*> members;     // +0x54; node value 8 bytes (isnil at node+0x15)
};

CRobloxDoc::CRobloxDoc()
{
}
