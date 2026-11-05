// from server: 100% by auto
// roc 2009-06 00472fc0  unit: RBX::LDraw2Lua::LDrawParser  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00472fc0
//
// 00472fc0  83ec08               sub esp, 8
// 00472fc3  53                   push ebx
// 00472fc4  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00472fc8  56                   push esi
// 00472fc9  8bf1                 mov esi, ecx
// 00472fcb  8b4610               mov eax, dword ptr [esi + 0x10]
// 00472fce  57                   push edi
// 00472fcf  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00472fd2  8bc8                 mov ecx, eax
// 00472fd4  2bcf                 sub ecx, edi
// 00472fd6  c1f902               sar ecx, 2
// 00472fd9  3bcb                 cmp ecx, ebx
// 00472fdb  7705                 ja 0x472fe2
// 00472fdd  e83eef2600           call 0x6e1f20
// 00472fe2  3bf8                 cmp edi, eax
// 00472fe4  7606                 jbe 0x472fec
// 00472fe6  ff15ace98900         call dword ptr [0x89e9ac]
// 00472fec  8b36                 mov esi, dword ptr [esi]
// 00472fee  55                   push ebp
// 00472fef  8bee                 mov ebp, esi
// 00472ff1  897c2414             mov dword ptr [esp + 0x14], edi
// 00472ff5  85f6                 test esi, esi
// 00472ff7  7518                 jne 0x473011
// 00472ff9  ff15ace98900         call dword ptr [0x89e9ac]
// 00472fff  33c0                 xor eax, eax
// 00473001  8d3c9f               lea edi, [edi + ebx*4]
// 00473004  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00473007  7713                 ja 0x47301c
// 00473009  85f6                 test esi, esi
// 0047300b  7408                 je 0x473015
// 0047300d  8b36                 mov esi, dword ptr [esi]
// 0047300f  eb06                 jmp 0x473017
// 00473011  8b06                 mov eax, dword ptr [esi]
// 00473013  ebec                 jmp 0x473001
// 00473015  33f6                 xor esi, esi
// 00473017  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0047301a  730a                 jae 0x473026
// 0047301c  8b35ace98900         mov esi, dword ptr [0x89e9ac]
// 00473022  ffd6                 call esi
// 00473024  eb06                 jmp 0x47302c
// 00473026  8b35ace98900         mov esi, dword ptr [0x89e9ac]
// 0047302c  85ed                 test ebp, ebp
// 0047302e  7517                 jne 0x473047
// 00473030  ffd6                 call esi
// 00473032  33c0                 xor eax, eax
// 00473034  5d                   pop ebp
// 00473035  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00473038  7202                 jb 0x47303c
// 0047303a  ffd6                 call esi
// 0047303c  8bc7                 mov eax, edi
// 0047303e  5f                   pop edi
// 0047303f  5e                   pop esi
// 00473040  5b                   pop ebx
// 00473041  83c408               add esp, 8
// 00473044  c20400               ret 4
// 00473047  8b4500               mov eax, dword ptr [ebp]
// 0047304a  ebe8                 jmp 0x473034
// standard library vector<ptr> (function ?at@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBEABQAUT@@I@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
