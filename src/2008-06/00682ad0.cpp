// from server: 100% by auto
// roc 2008-06 00682ad0  unit: Ogre::RbxSceneNode  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00682ad0
//
// 00682ad0  53                   push ebx
// 00682ad1  8b1d90288000         mov ebx, dword ptr [0x802890]
// 00682ad7  56                   push esi
// 00682ad8  8bf1                 mov esi, ecx
// 00682ada  8b06                 mov eax, dword ptr [esi]
// 00682adc  8b4e04               mov ecx, dword ptr [esi + 4]
// 00682adf  57                   push edi
// 00682ae0  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00682ae4  8907                 mov dword ptr [edi], eax
// 00682ae6  894f04               mov dword ptr [edi + 4], ecx
// 00682ae9  85c0                 test eax, eax
// 00682aeb  7508                 jne 0x682af5
// 00682aed  ffd3                 call ebx
// 00682aef  8b06                 mov eax, dword ptr [esi]
// 00682af1  85c0                 test eax, eax
// 00682af3  7404                 je 0x682af9
// 00682af5  8b00                 mov eax, dword ptr [eax]
// 00682af7  eb02                 jmp 0x682afb
// 00682af9  33c0                 xor eax, eax
// 00682afb  8b5604               mov edx, dword ptr [esi + 4]
// 00682afe  3b5014               cmp edx, dword ptr [eax + 0x14]
// 00682b01  7502                 jne 0x682b05
// 00682b03  ffd3                 call ebx
// 00682b05  8b4604               mov eax, dword ptr [esi + 4]
// 00682b08  8b08                 mov ecx, dword ptr [eax]
// 00682b0a  8bc7                 mov eax, edi
// 00682b0c  5f                   pop edi
// 00682b0d  894e04               mov dword ptr [esi + 4], ecx
// 00682b10  5e                   pop esi
// 00682b11  5b                   pop ebx
// 00682b12  c20800               ret 8
// standard library list<ptr> (function ??E?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV012@H@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
