// from server: 100% by auto
// roc 2009-06 00712590  unit: W4_D3DFORMAT::?$EnumDesc  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00712590
//
// 00712590  8b542404             mov edx, dword ptr [esp + 4]
// 00712594  83ec10               sub esp, 0x10
// 00712597  53                   push ebx
// 00712598  55                   push ebp
// 00712599  57                   push edi
// 0071259a  8bf9                 mov edi, ecx
// 0071259c  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0071259f  8b4104               mov eax, dword ptr [ecx + 4]
// 007125a2  80781500             cmp byte ptr [eax + 0x15], 0
// 007125a6  8bd9                 mov ebx, ecx
// 007125a8  751a                 jne 0x7125c4
// 007125aa  8b0a                 mov ecx, dword ptr [edx]
// 007125ac  8d642400             lea esp, [esp]
// 007125b0  39480c               cmp dword ptr [eax + 0xc], ecx
// 007125b3  7305                 jae 0x7125ba
// 007125b5  8b4008               mov eax, dword ptr [eax + 8]
// 007125b8  eb04                 jmp 0x7125be
// 007125ba  8bd8                 mov ebx, eax
// 007125bc  8b00                 mov eax, dword ptr [eax]
// 007125be  80781500             cmp byte ptr [eax + 0x15], 0
// 007125c2  74ec                 je 0x7125b0
// 007125c4  8b4718               mov eax, dword ptr [edi + 0x18]
// 007125c7  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 007125cd  56                   push esi
// 007125ce  8b37                 mov esi, dword ptr [edi]
// 007125d0  89442414             mov dword ptr [esp + 0x14], eax
// 007125d4  85f6                 test esi, esi
// 007125d6  7404                 je 0x7125dc
// 007125d8  3bf6                 cmp esi, esi
// 007125da  740c                 je 0x7125e8
// 007125dc  ffd5                 call ebp
// 007125de  8b542424             mov edx, dword ptr [esp + 0x24]
// 007125e2  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 007125e8  3b5c2414             cmp ebx, dword ptr [esp + 0x14]
// 007125ec  7407                 je 0x7125f5
// 007125ee  8b0a                 mov ecx, dword ptr [edx]
// 007125f0  3b4b0c               cmp ecx, dword ptr [ebx + 0xc]
// 007125f3  7326                 jae 0x71261b
// 007125f5  8b12                 mov edx, dword ptr [edx]
// 007125f7  8d442410             lea eax, [esp + 0x10]
// 007125fb  50                   push eax
// 007125fc  53                   push ebx
// 007125fd  56                   push esi
// 007125fe  8d4c2424             lea ecx, [esp + 0x24]
// 00712602  51                   push ecx
// 00712603  8bcf                 mov ecx, edi
// 00712605  89542420             mov dword ptr [esp + 0x20], edx
// 00712609  c744242400000000     mov dword ptr [esp + 0x24], 0
// 00712611  e89afdffff           call 0x7123b0
// 00712616  8b30                 mov esi, dword ptr [eax]
// 00712618  8b5804               mov ebx, dword ptr [eax + 4]
// 0071261b  85f6                 test esi, esi
// 0071261d  7516                 jne 0x712635
// 0071261f  ffd5                 call ebp
// 00712621  3b5e18               cmp ebx, dword ptr [esi + 0x18]
// 00712624  5e                   pop esi
// 00712625  7502                 jne 0x712629
// 00712627  ffd5                 call ebp
// 00712629  5f                   pop edi
// 0071262a  5d                   pop ebp
// 0071262b  8d4310               lea eax, [ebx + 0x10]
// 0071262e  5b                   pop ebx
// 0071262f  83c410               add esp, 0x10
// 00712632  c20400               ret 4
// 00712635  8b36                 mov esi, dword ptr [esi]
// 00712637  ebe8                 jmp 0x712621
// standard library map_ptr<ptr> (function ??A?$map@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@@std@@QAEAAPAUT@@ABQAUK@@@Z)

// stl: map_ptr<ptr>
struct T; typedef T* E;
#include <map>
struct K; template class std::map<K*, E>;
