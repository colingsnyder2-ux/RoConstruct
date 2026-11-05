// from server: 100% by auto
// roc 2008-06 0067fc70  unit: Ogre::RbxEntity  size: 196 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0067fc70
//
// 0067fc70  83ec18               sub esp, 0x18
// 0067fc73  53                   push ebx
// 0067fc74  55                   push ebp
// 0067fc75  56                   push esi
// 0067fc76  8bf1                 mov esi, ecx
// 0067fc78  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0067fc7b  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 0067fc7e  8bcb                 mov ecx, ebx
// 0067fc80  2bcd                 sub ecx, ebp
// 0067fc82  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0067fc87  f7e9                 imul ecx
// 0067fc89  d1fa                 sar edx, 1
// 0067fc8b  8bc2                 mov eax, edx
// 0067fc8d  c1e81f               shr eax, 0x1f
// 0067fc90  57                   push edi
// 0067fc91  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0067fc95  03c2                 add eax, edx
// 0067fc97  3bf8                 cmp edi, eax
// 0067fc99  763d                 jbe 0x67fcd8
// 0067fc9b  3beb                 cmp ebp, ebx
// 0067fc9d  7606                 jbe 0x67fca5
// 0067fc9f  ff1590288000         call dword ptr [0x802890]
// 0067fca5  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0067fca8  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 0067fcab  8b2e                 mov ebp, dword ptr [esi]
// 0067fcad  8d442430             lea eax, [esp + 0x30]
// 0067fcb1  50                   push eax
// 0067fcb2  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0067fcb7  f7e9                 imul ecx
// 0067fcb9  d1fa                 sar edx, 1
// 0067fcbb  8bca                 mov ecx, edx
// 0067fcbd  c1e91f               shr ecx, 0x1f
// 0067fcc0  03ca                 add ecx, edx
// 0067fcc2  2bf9                 sub edi, ecx
// 0067fcc4  57                   push edi
// 0067fcc5  53                   push ebx
// 0067fcc6  55                   push ebp
// 0067fcc7  8bce                 mov ecx, esi
// 0067fcc9  e8f2dee5ff           call 0x4ddbc0
// 0067fcce  5f                   pop edi
// 0067fccf  5e                   pop esi
// 0067fcd0  5d                   pop ebp
// 0067fcd1  5b                   pop ebx
// 0067fcd2  83c418               add esp, 0x18
// 0067fcd5  c21000               ret 0x10
// 0067fcd8  7350                 jae 0x67fd2a
// 0067fcda  3beb                 cmp ebp, ebx
// 0067fcdc  7606                 jbe 0x67fce4
// 0067fcde  ff1590288000         call dword ptr [0x802890]
// 0067fce4  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 0067fce7  8b16                 mov edx, dword ptr [esi]
// 0067fce9  89542418             mov dword ptr [esp + 0x18], edx
// 0067fced  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 0067fcf0  7606                 jbe 0x67fcf8
// 0067fcf2  ff1590288000         call dword ptr [0x802890]
// 0067fcf8  8b06                 mov eax, dword ptr [esi]
// 0067fcfa  57                   push edi
// 0067fcfb  8d4c2424             lea ecx, [esp + 0x24]
// 0067fcff  51                   push ecx
// 0067fd00  8d4c2418             lea ecx, [esp + 0x18]
// 0067fd04  89442418             mov dword ptr [esp + 0x18], eax
// 0067fd08  896c241c             mov dword ptr [esp + 0x1c], ebp
// 0067fd0c  e8bf030100           call 0x6900d0
// 0067fd11  8b542418             mov edx, dword ptr [esp + 0x18]
// 0067fd15  8b4804               mov ecx, dword ptr [eax + 4]
// 0067fd18  53                   push ebx
// 0067fd19  52                   push edx
// 0067fd1a  8b10                 mov edx, dword ptr [eax]
// 0067fd1c  51                   push ecx
// 0067fd1d  52                   push edx
// 0067fd1e  8d442428             lea eax, [esp + 0x28]
// 0067fd22  50                   push eax
// 0067fd23  8bce                 mov ecx, esi
// 0067fd25  e856fdffff           call 0x67fa80
// 0067fd2a  5f                   pop edi
// 0067fd2b  5e                   pop esi
// 0067fd2c  5d                   pop ebp
// 0067fd2d  5b                   pop ebx
// 0067fd2e  83c418               add esp, 0x18
// 0067fd31  c21000               ret 0x10
// standard library vector<pod12> (function ?resize@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXIUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
