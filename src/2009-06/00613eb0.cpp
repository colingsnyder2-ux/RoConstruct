// from server: 100% by auto
// roc 2009-06 00613eb0  unit: UString_sink::?$stream_buffer  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00613eb0
//
// 00613eb0  53                   push ebx
// 00613eb1  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 00613eb7  56                   push esi
// 00613eb8  8b31                 mov esi, dword ptr [ecx]
// 00613eba  57                   push edi
// 00613ebb  8b7914               mov edi, dword ptr [ecx + 0x14]
// 00613ebe  85f6                 test esi, esi
// 00613ec0  7502                 jne 0x613ec4
// 00613ec2  ffd3                 call ebx
// 00613ec4  8b7f04               mov edi, dword ptr [edi + 4]
// 00613ec7  85f6                 test esi, esi
// 00613ec9  7404                 je 0x613ecf
// 00613ecb  8b06                 mov eax, dword ptr [esi]
// 00613ecd  eb02                 jmp 0x613ed1
// 00613ecf  33c0                 xor eax, eax
// 00613ed1  3b7814               cmp edi, dword ptr [eax + 0x14]
// 00613ed4  7502                 jne 0x613ed8
// 00613ed6  ffd3                 call ebx
// 00613ed8  85f6                 test esi, esi
// 00613eda  7510                 jne 0x613eec
// 00613edc  ffd3                 call ebx
// 00613ede  3b7e14               cmp edi, dword ptr [esi + 0x14]
// 00613ee1  7502                 jne 0x613ee5
// 00613ee3  ffd3                 call ebx
// 00613ee5  8d4708               lea eax, [edi + 8]
// 00613ee8  5f                   pop edi
// 00613ee9  5e                   pop esi
// 00613eea  5b                   pop ebx
// 00613eeb  c3                   ret 
// 00613eec  8b36                 mov esi, dword ptr [esi]
// 00613eee  ebee                 jmp 0x613ede
// standard library list<ptr> (function ?back@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAPAUT@@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
