// from server: 100% by auto
// roc 2008-06 005556d0  unit: RBX::VRunService::?$FactoryProduct  size: 166 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005556d0
//
// 005556d0  8b542404             mov edx, dword ptr [esp + 4]
// 005556d4  83ec10               sub esp, 0x10
// 005556d7  53                   push ebx
// 005556d8  55                   push ebp
// 005556d9  57                   push edi
// 005556da  8bf9                 mov edi, ecx
// 005556dc  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 005556df  8b4104               mov eax, dword ptr [ecx + 4]
// 005556e2  80781500             cmp byte ptr [eax + 0x15], 0
// 005556e6  8bd9                 mov ebx, ecx
// 005556e8  751a                 jne 0x555704
// 005556ea  8b0a                 mov ecx, dword ptr [edx]
// 005556ec  8d642400             lea esp, [esp]
// 005556f0  39480c               cmp dword ptr [eax + 0xc], ecx
// 005556f3  7305                 jae 0x5556fa
// 005556f5  8b4008               mov eax, dword ptr [eax + 8]
// 005556f8  eb04                 jmp 0x5556fe
// 005556fa  8bd8                 mov ebx, eax
// 005556fc  8b00                 mov eax, dword ptr [eax]
// 005556fe  80781500             cmp byte ptr [eax + 0x15], 0
// 00555702  74ec                 je 0x5556f0
// 00555704  8b4718               mov eax, dword ptr [edi + 0x18]
// 00555707  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0055570d  56                   push esi
// 0055570e  8b37                 mov esi, dword ptr [edi]
// 00555710  89442414             mov dword ptr [esp + 0x14], eax
// 00555714  85f6                 test esi, esi
// 00555716  7404                 je 0x55571c
// 00555718  3bf6                 cmp esi, esi
// 0055571a  740c                 je 0x555728
// 0055571c  ffd5                 call ebp
// 0055571e  8b542424             mov edx, dword ptr [esp + 0x24]
// 00555722  8b2d90288000         mov ebp, dword ptr [0x802890]
// 00555728  3b5c2414             cmp ebx, dword ptr [esp + 0x14]
// 0055572c  7407                 je 0x555735
// 0055572e  8b0a                 mov ecx, dword ptr [edx]
// 00555730  3b4b0c               cmp ecx, dword ptr [ebx + 0xc]
// 00555733  7323                 jae 0x555758
// 00555735  8b12                 mov edx, dword ptr [edx]
// 00555737  8d442410             lea eax, [esp + 0x10]
// 0055573b  50                   push eax
// 0055573c  53                   push ebx
// 0055573d  56                   push esi
// 0055573e  8d4c2424             lea ecx, [esp + 0x24]
// 00555742  51                   push ecx
// 00555743  8bcf                 mov ecx, edi
// 00555745  89542420             mov dword ptr [esp + 0x20], edx
// 00555749  c644242400           mov byte ptr [esp + 0x24], 0
// 0055574e  e86deb0000           call 0x5642c0
// 00555753  8b30                 mov esi, dword ptr [eax]
// 00555755  8b5804               mov ebx, dword ptr [eax + 4]
// 00555758  85f6                 test esi, esi
// 0055575a  7516                 jne 0x555772
// 0055575c  ffd5                 call ebp
// 0055575e  3b5e18               cmp ebx, dword ptr [esi + 0x18]
// 00555761  5e                   pop esi
// 00555762  7502                 jne 0x555766
// 00555764  ffd5                 call ebp
// 00555766  5f                   pop edi
// 00555767  5d                   pop ebp
// 00555768  8d4310               lea eax, [ebx + 0x10]
// 0055576b  5b                   pop ebx
// 0055576c  83c410               add esp, 0x10
// 0055576f  c20400               ret 4
// 00555772  8b36                 mov esi, dword ptr [esi]
// 00555774  ebe8                 jmp 0x55575e
// standard library map_ptr<char> (function ??A?$map@PAUK@@DU?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@D@std@@@3@@std@@QAEAADABQAUK@@@Z)

// stl: map_ptr<char>
typedef char E;
#include <map>
struct K; template class std::map<K*, E>;
