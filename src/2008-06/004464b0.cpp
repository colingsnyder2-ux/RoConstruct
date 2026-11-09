// from server: 100% by auto
// roc 2008-06 004464b0  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004464b0
//
// 004464b0  83ec08               sub esp, 8
// 004464b3  53                   push ebx
// 004464b4  55                   push ebp
// 004464b5  56                   push esi
// 004464b6  8bf1                 mov esi, ecx
// 004464b8  8b4610               mov eax, dword ptr [esi + 0x10]
// 004464bb  57                   push edi
// 004464bc  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004464bf  8bc8                 mov ecx, eax
// 004464c1  2bcf                 sub ecx, edi
// 004464c3  f7c1fcffffff         test ecx, 0xfffffffc
// 004464c9  7504                 jne 0x4464cf
// 004464cb  33db                 xor ebx, ebx
// 004464cd  eb27                 jmp 0x4464f6
// 004464cf  3bf8                 cmp edi, eax
// 004464d1  7606                 jbe 0x4464d9
// 004464d3  ff1590288000         call dword ptr [0x802890]
// 004464d9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004464dd  8b06                 mov eax, dword ptr [esi]
// 004464df  85c9                 test ecx, ecx
// 004464e1  7404                 je 0x4464e7
// 004464e3  3bc8                 cmp ecx, eax
// 004464e5  7406                 je 0x4464ed
// 004464e7  ff1590288000         call dword ptr [0x802890]
// 004464ed  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004464f1  2bdf                 sub ebx, edi
// 004464f3  c1fb02               sar ebx, 2
// 004464f6  8b542428             mov edx, dword ptr [esp + 0x28]
// 004464fa  8b442424             mov eax, dword ptr [esp + 0x24]
// 004464fe  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00446502  52                   push edx
// 00446503  6a01                 push 1
// 00446505  50                   push eax
// 00446506  51                   push ecx
// 00446507  8bce                 mov ecx, esi
// 00446509  e882fdffff           call 0x446290
// 0044650e  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00446511  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00446514  7606                 jbe 0x44651c
// 00446516  ff1590288000         call dword ptr [0x802890]
// 0044651c  8b36                 mov esi, dword ptr [esi]
// 0044651e  8bee                 mov ebp, esi
// 00446520  897c2414             mov dword ptr [esp + 0x14], edi
// 00446524  85f6                 test esi, esi
// 00446526  7518                 jne 0x446540
// 00446528  ff1590288000         call dword ptr [0x802890]
// 0044652e  33c0                 xor eax, eax
// 00446530  8d3c9f               lea edi, [edi + ebx*4]
// 00446533  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00446536  7713                 ja 0x44654b
// 00446538  85f6                 test esi, esi
// 0044653a  7408                 je 0x446544
// 0044653c  8b36                 mov esi, dword ptr [esi]
// 0044653e  eb06                 jmp 0x446546
// 00446540  8b06                 mov eax, dword ptr [esi]
// 00446542  ebec                 jmp 0x446530
// 00446544  33f6                 xor esi, esi
// 00446546  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 00446549  7306                 jae 0x446551
// 0044654b  ff1590288000         call dword ptr [0x802890]
// 00446551  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00446555  897804               mov dword ptr [eax + 4], edi
// 00446558  5f                   pop edi
// 00446559  5e                   pop esi
// 0044655a  8928                 mov dword ptr [eax], ebp
// 0044655c  5d                   pop ebp
// 0044655d  5b                   pop ebx
// 0044655e  83c408               add esp, 8
// 00446561  c21000               ret 0x10
// standard library vector<ptr> (function ?insert@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@ABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
