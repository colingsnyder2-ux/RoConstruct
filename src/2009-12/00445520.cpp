// from server: 100% by auto
// roc 2009-12 00445520  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00445520
//
// 00445520  8b542404             mov edx, dword ptr [esp + 4]
// 00445524  83ec10               sub esp, 0x10
// 00445527  53                   push ebx
// 00445528  55                   push ebp
// 00445529  57                   push edi
// 0044552a  8bf9                 mov edi, ecx
// 0044552c  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0044552f  8b4104               mov eax, dword ptr [ecx + 4]
// 00445532  80781500             cmp byte ptr [eax + 0x15], 0
// 00445536  8bd9                 mov ebx, ecx
// 00445538  751a                 jne 0x445554
// 0044553a  8b0a                 mov ecx, dword ptr [edx]
// 0044553c  8d642400             lea esp, [esp]
// 00445540  39480c               cmp dword ptr [eax + 0xc], ecx
// 00445543  7305                 jae 0x44554a
// 00445545  8b4008               mov eax, dword ptr [eax + 8]
// 00445548  eb04                 jmp 0x44554e
// 0044554a  8bd8                 mov ebx, eax
// 0044554c  8b00                 mov eax, dword ptr [eax]
// 0044554e  80781500             cmp byte ptr [eax + 0x15], 0
// 00445552  74ec                 je 0x445540
// 00445554  8b4718               mov eax, dword ptr [edi + 0x18]
// 00445557  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 0044555d  56                   push esi
// 0044555e  8b37                 mov esi, dword ptr [edi]
// 00445560  89442414             mov dword ptr [esp + 0x14], eax
// 00445564  85f6                 test esi, esi
// 00445566  7404                 je 0x44556c
// 00445568  3bf6                 cmp esi, esi
// 0044556a  740c                 je 0x445578
// 0044556c  ffd5                 call ebp
// 0044556e  8b542424             mov edx, dword ptr [esp + 0x24]
// 00445572  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 00445578  3b5c2414             cmp ebx, dword ptr [esp + 0x14]
// 0044557c  7407                 je 0x445585
// 0044557e  8b0a                 mov ecx, dword ptr [edx]
// 00445580  3b4b0c               cmp ecx, dword ptr [ebx + 0xc]
// 00445583  7326                 jae 0x4455ab
// 00445585  8b12                 mov edx, dword ptr [edx]
// 00445587  8d442410             lea eax, [esp + 0x10]
// 0044558b  50                   push eax
// 0044558c  53                   push ebx
// 0044558d  56                   push esi
// 0044558e  8d4c2424             lea ecx, [esp + 0x24]
// 00445592  51                   push ecx
// 00445593  8bcf                 mov ecx, edi
// 00445595  89542420             mov dword ptr [esp + 0x20], edx
// 00445599  c744242400000000     mov dword ptr [esp + 0x24], 0
// 004455a1  e8aafcffff           call 0x445250
// 004455a6  8b30                 mov esi, dword ptr [eax]
// 004455a8  8b5804               mov ebx, dword ptr [eax + 4]
// 004455ab  85f6                 test esi, esi
// 004455ad  7516                 jne 0x4455c5
// 004455af  ffd5                 call ebp
// 004455b1  3b5e18               cmp ebx, dword ptr [esi + 0x18]
// 004455b4  5e                   pop esi
// 004455b5  7502                 jne 0x4455b9
// 004455b7  ffd5                 call ebp
// 004455b9  5f                   pop edi
// 004455ba  5d                   pop ebp
// 004455bb  8d4310               lea eax, [ebx + 0x10]
// 004455be  5b                   pop ebx
// 004455bf  83c410               add esp, 0x10
// 004455c2  c20400               ret 4
// 004455c5  8b36                 mov esi, dword ptr [esi]
// 004455c7  ebe8                 jmp 0x4455b1
// standard library map_ptr<ptr> (function ??A?$map@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@@std@@QAEAAPAUT@@ABQAUK@@@Z)

// stl: map_ptr<ptr>
struct T; typedef T* E;
#include <map>
struct K; template class std::map<K*, E>;
