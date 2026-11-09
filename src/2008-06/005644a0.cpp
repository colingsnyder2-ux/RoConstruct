// from server: 100% by auto
// roc 2008-06 005644a0  unit: RBX::Reflection::N::?$TypedPropertyDescriptor  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005644a0
//
// 005644a0  8b542404             mov edx, dword ptr [esp + 4]
// 005644a4  83ec10               sub esp, 0x10
// 005644a7  53                   push ebx
// 005644a8  55                   push ebp
// 005644a9  57                   push edi
// 005644aa  8bf9                 mov edi, ecx
// 005644ac  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 005644af  8b4104               mov eax, dword ptr [ecx + 4]
// 005644b2  80781500             cmp byte ptr [eax + 0x15], 0
// 005644b6  8bd9                 mov ebx, ecx
// 005644b8  751a                 jne 0x5644d4
// 005644ba  8b0a                 mov ecx, dword ptr [edx]
// 005644bc  8d642400             lea esp, [esp]
// 005644c0  39480c               cmp dword ptr [eax + 0xc], ecx
// 005644c3  7305                 jae 0x5644ca
// 005644c5  8b4008               mov eax, dword ptr [eax + 8]
// 005644c8  eb04                 jmp 0x5644ce
// 005644ca  8bd8                 mov ebx, eax
// 005644cc  8b00                 mov eax, dword ptr [eax]
// 005644ce  80781500             cmp byte ptr [eax + 0x15], 0
// 005644d2  74ec                 je 0x5644c0
// 005644d4  8b4718               mov eax, dword ptr [edi + 0x18]
// 005644d7  8b2d90288000         mov ebp, dword ptr [0x802890]
// 005644dd  56                   push esi
// 005644de  8b37                 mov esi, dword ptr [edi]
// 005644e0  89442414             mov dword ptr [esp + 0x14], eax
// 005644e4  85f6                 test esi, esi
// 005644e6  7404                 je 0x5644ec
// 005644e8  3bf6                 cmp esi, esi
// 005644ea  740c                 je 0x5644f8
// 005644ec  ffd5                 call ebp
// 005644ee  8b542424             mov edx, dword ptr [esp + 0x24]
// 005644f2  8b2d90288000         mov ebp, dword ptr [0x802890]
// 005644f8  3b5c2414             cmp ebx, dword ptr [esp + 0x14]
// 005644fc  7407                 je 0x564505
// 005644fe  8b0a                 mov ecx, dword ptr [edx]
// 00564500  3b4b0c               cmp ecx, dword ptr [ebx + 0xc]
// 00564503  7326                 jae 0x56452b
// 00564505  8b12                 mov edx, dword ptr [edx]
// 00564507  8d442410             lea eax, [esp + 0x10]
// 0056450b  50                   push eax
// 0056450c  53                   push ebx
// 0056450d  56                   push esi
// 0056450e  8d4c2424             lea ecx, [esp + 0x24]
// 00564512  51                   push ecx
// 00564513  8bcf                 mov ecx, edi
// 00564515  89542420             mov dword ptr [esp + 0x20], edx
// 00564519  c744242400000000     mov dword ptr [esp + 0x24], 0
// 00564521  e89afdffff           call 0x5642c0
// 00564526  8b30                 mov esi, dword ptr [eax]
// 00564528  8b5804               mov ebx, dword ptr [eax + 4]
// 0056452b  85f6                 test esi, esi
// 0056452d  7516                 jne 0x564545
// 0056452f  ffd5                 call ebp
// 00564531  3b5e18               cmp ebx, dword ptr [esi + 0x18]
// 00564534  5e                   pop esi
// 00564535  7502                 jne 0x564539
// 00564537  ffd5                 call ebp
// 00564539  5f                   pop edi
// 0056453a  5d                   pop ebp
// 0056453b  8d4310               lea eax, [ebx + 0x10]
// 0056453e  5b                   pop ebx
// 0056453f  83c410               add esp, 0x10
// 00564542  c20400               ret 4
// 00564545  8b36                 mov esi, dword ptr [esi]
// 00564547  ebe8                 jmp 0x564531
// standard library map_ptr<ptr> (function ??A?$map@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@@std@@QAEAAPAUT@@ABQAUK@@@Z)

// stl: map_ptr<ptr>
struct T; typedef T* E;
#include <map>
struct K; template class std::map<K*, E>;
