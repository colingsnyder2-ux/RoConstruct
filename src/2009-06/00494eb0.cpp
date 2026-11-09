// from server: 100% by auto
// roc 2009-06 00494eb0  unit: Ogre::RbxMaterialAdapter  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00494eb0
//
// 00494eb0  53                   push ebx
// 00494eb1  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 00494eb7  56                   push esi
// 00494eb8  8bf1                 mov esi, ecx
// 00494eba  8b06                 mov eax, dword ptr [esi]
// 00494ebc  8b4e04               mov ecx, dword ptr [esi + 4]
// 00494ebf  57                   push edi
// 00494ec0  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00494ec4  8907                 mov dword ptr [edi], eax
// 00494ec6  894f04               mov dword ptr [edi + 4], ecx
// 00494ec9  85c0                 test eax, eax
// 00494ecb  7508                 jne 0x494ed5
// 00494ecd  ffd3                 call ebx
// 00494ecf  8b06                 mov eax, dword ptr [esi]
// 00494ed1  85c0                 test eax, eax
// 00494ed3  7404                 je 0x494ed9
// 00494ed5  8b00                 mov eax, dword ptr [eax]
// 00494ed7  eb02                 jmp 0x494edb
// 00494ed9  33c0                 xor eax, eax
// 00494edb  8b5604               mov edx, dword ptr [esi + 4]
// 00494ede  3b5014               cmp edx, dword ptr [eax + 0x14]
// 00494ee1  7502                 jne 0x494ee5
// 00494ee3  ffd3                 call ebx
// 00494ee5  8b4604               mov eax, dword ptr [esi + 4]
// 00494ee8  8b08                 mov ecx, dword ptr [eax]
// 00494eea  8bc7                 mov eax, edi
// 00494eec  5f                   pop edi
// 00494eed  894e04               mov dword ptr [esi + 4], ecx
// 00494ef0  5e                   pop esi
// 00494ef1  5b                   pop ebx
// 00494ef2  c20800               ret 8
// standard library list<ptr> (function ??E?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV012@H@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
