// from server: 100% by auto
// roc 2009-06 0048ab80  unit: Ogre::RbxManualResourceLoaderChain  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048ab80
//
// 0048ab80  53                   push ebx
// 0048ab81  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0048ab85  55                   push ebp
// 0048ab86  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 0048ab8c  56                   push esi
// 0048ab8d  8bf1                 mov esi, ecx
// 0048ab8f  57                   push edi
// 0048ab90  c70300000000         mov dword ptr [ebx], 0
// 0048ab96  85f6                 test esi, esi
// 0048ab98  740e                 je 0x48aba8
// 0048ab9a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048ab9e  39460c               cmp dword ptr [esi + 0xc], eax
// 0048aba1  7705                 ja 0x48aba8
// 0048aba3  3b4610               cmp eax, dword ptr [esi + 0x10]
// 0048aba6  7606                 jbe 0x48abae
// 0048aba8  ffd5                 call ebp
// 0048abaa  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048abae  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0048abb2  8b0e                 mov ecx, dword ptr [esi]
// 0048abb4  890b                 mov dword ptr [ebx], ecx
// 0048abb6  894304               mov dword ptr [ebx + 4], eax
// 0048abb9  397e0c               cmp dword ptr [esi + 0xc], edi
// 0048abbc  7705                 ja 0x48abc3
// 0048abbe  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0048abc1  7606                 jbe 0x48abc9
// 0048abc3  ffd5                 call ebp
// 0048abc5  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0048abc9  8b03                 mov eax, dword ptr [ebx]
// 0048abcb  8b0e                 mov ecx, dword ptr [esi]
// 0048abcd  85c0                 test eax, eax
// 0048abcf  7404                 je 0x48abd5
// 0048abd1  3bc1                 cmp eax, ecx
// 0048abd3  7402                 je 0x48abd7
// 0048abd5  ffd5                 call ebp
// 0048abd7  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0048abda  3bcf                 cmp ecx, edi
// 0048abdc  741c                 je 0x48abfa
// 0048abde  8b4610               mov eax, dword ptr [esi + 0x10]
// 0048abe1  2bc7                 sub eax, edi
// 0048abe3  8d2c08               lea ebp, [eax + ecx]
// 0048abe6  85c0                 test eax, eax
// 0048abe8  7e0d                 jle 0x48abf7
// 0048abea  50                   push eax
// 0048abeb  57                   push edi
// 0048abec  50                   push eax
// 0048abed  51                   push ecx
// 0048abee  ff155ce98900         call dword ptr [0x89e95c]
// 0048abf4  83c410               add esp, 0x10
// 0048abf7  896e10               mov dword ptr [esi + 0x10], ebp
// 0048abfa  5f                   pop edi
// 0048abfb  5e                   pop esi
// 0048abfc  5d                   pop ebp
// 0048abfd  8bc3                 mov eax, ebx
// 0048abff  5b                   pop ebx
// 0048ac00  c21400               ret 0x14
// standard library vector<char> (function ?erase@?$vector@DV?$allocator@D@std@@@std@@QAE?AV?$_Vector_iterator@DV?$allocator@D@std@@@2@V?$_Vector_const_iterator@DV?$allocator@D@std@@@2@0@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
