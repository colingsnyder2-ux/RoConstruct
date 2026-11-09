// from server: 100% by auto
// roc 2009-06 004b0ab0  unit: G3D::Shader  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004b0ab0
//
// 004b0ab0  53                   push ebx
// 004b0ab1  56                   push esi
// 004b0ab2  8bf1                 mov esi, ecx
// 004b0ab4  33db                 xor ebx, ebx
// 004b0ab6  57                   push edi
// 004b0ab7  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 004b0aba  7434                 je 0x4b0af0
// 004b0abc  83cfff               or edi, 0xffffffff
// 004b0abf  90                   nop 
// 004b0ac0  8b461c               mov eax, dword ptr [esi + 0x1c]
// 004b0ac3  3bc3                 cmp eax, ebx
// 004b0ac5  7424                 je 0x4b0aeb
// 004b0ac7  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004b0aca  8d4408ff             lea eax, [eax + ecx - 1]
// 004b0ace  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 004b0ad1  3bc8                 cmp ecx, eax
// 004b0ad3  7702                 ja 0x4b0ad7
// 004b0ad5  2bc1                 sub eax, ecx
// 004b0ad7  8b5610               mov edx, dword ptr [esi + 0x10]
// 004b0ada  8b0c82               mov ecx, dword ptr [edx + eax*4]
// 004b0add  ff15c4e48900         call dword ptr [0x89e4c4]
// 004b0ae3  017e1c               add dword ptr [esi + 0x1c], edi
// 004b0ae6  7503                 jne 0x4b0aeb
// 004b0ae8  895e18               mov dword ptr [esi + 0x18], ebx
// 004b0aeb  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 004b0aee  75d0                 jne 0x4b0ac0
// 004b0af0  8b7e14               mov edi, dword ptr [esi + 0x14]
// 004b0af3  3bfb                 cmp edi, ebx
// 004b0af5  761b                 jbe 0x4b0b12
// 004b0af7  8b4610               mov eax, dword ptr [esi + 0x10]
// 004b0afa  4f                   dec edi
// 004b0afb  391cb8               cmp dword ptr [eax + edi*4], ebx
// 004b0afe  8d04b8               lea eax, [eax + edi*4]
// 004b0b01  740b                 je 0x4b0b0e
// 004b0b03  8b08                 mov ecx, dword ptr [eax]
// 004b0b05  51                   push ecx
// 004b0b06  e8277f2600           call 0x718a32
// 004b0b0b  83c404               add esp, 4
// 004b0b0e  3bfb                 cmp edi, ebx
// 004b0b10  77e5                 ja 0x4b0af7
// 004b0b12  8b4610               mov eax, dword ptr [esi + 0x10]
// 004b0b15  3bc3                 cmp eax, ebx
// 004b0b17  7409                 je 0x4b0b22
// 004b0b19  50                   push eax
// 004b0b1a  e8137f2600           call 0x718a32
// 004b0b1f  83c404               add esp, 4
// 004b0b22  5f                   pop edi
// 004b0b23  895e10               mov dword ptr [esi + 0x10], ebx
// 004b0b26  895e14               mov dword ptr [esi + 0x14], ebx
// 004b0b29  5e                   pop esi
// 004b0b2a  5b                   pop ebx
// 004b0b2b  c3                   ret 
// standard library deque<string> (function ?_Tidy@?$deque@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXXZ)

// stl: deque<string>
#include <string>
typedef std::string E;
#include <deque>
template class std::deque<E>;
