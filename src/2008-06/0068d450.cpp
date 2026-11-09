// from server: 100% by auto
// roc 2008-06 0068d450  unit: Ogre::VShadowCameraSetup::?$SharedPtr  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068d450
//
// 0068d450  53                   push ebx
// 0068d451  8b1d90288000         mov ebx, dword ptr [0x802890]
// 0068d457  56                   push esi
// 0068d458  8bf1                 mov esi, ecx
// 0068d45a  8b06                 mov eax, dword ptr [esi]
// 0068d45c  57                   push edi
// 0068d45d  85c0                 test eax, eax
// 0068d45f  7508                 jne 0x68d469
// 0068d461  ffd3                 call ebx
// 0068d463  8b06                 mov eax, dword ptr [esi]
// 0068d465  85c0                 test eax, eax
// 0068d467  7404                 je 0x68d46d
// 0068d469  8b10                 mov edx, dword ptr [eax]
// 0068d46b  eb02                 jmp 0x68d46f
// 0068d46d  33d2                 xor edx, edx
// 0068d46f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0068d473  8d3c49               lea edi, [ecx + ecx*2]
// 0068d476  8b4e04               mov ecx, dword ptr [esi + 4]
// 0068d479  03ff                 add edi, edi
// 0068d47b  03ff                 add edi, edi
// 0068d47d  03ff                 add edi, edi
// 0068d47f  03cf                 add ecx, edi
// 0068d481  3b4a10               cmp ecx, dword ptr [edx + 0x10]
// 0068d484  770f                 ja 0x68d495
// 0068d486  85c0                 test eax, eax
// 0068d488  7404                 je 0x68d48e
// 0068d48a  8b00                 mov eax, dword ptr [eax]
// 0068d48c  eb02                 jmp 0x68d490
// 0068d48e  33c0                 xor eax, eax
// 0068d490  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 0068d493  7302                 jae 0x68d497
// 0068d495  ffd3                 call ebx
// 0068d497  017e04               add dword ptr [esi + 4], edi
// 0068d49a  5f                   pop edi
// 0068d49b  8bc6                 mov eax, esi
// 0068d49d  5e                   pop esi
// 0068d49e  5b                   pop ebx
// 0068d49f  c20400               ret 4
// standard library vector<pod24> (function ??Y?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@std@@QAEAAV01@H@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
