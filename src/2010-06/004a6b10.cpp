// from server: 100% by auto
// roc 2010-06 004a6b10  unit: RBX::Reflection::VValue::$$CBV?$vector::V?$shared_ptr::?$holder  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004a6b10
//
// 004a6b10  53                   push ebx
// 004a6b11  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 004a6b17  56                   push esi
// 004a6b18  8bf1                 mov esi, ecx
// 004a6b1a  57                   push edi
// 004a6b1b  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004a6b1e  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 004a6b21  7602                 jbe 0x4a6b25
// 004a6b23  ffd3                 call ebx
// 004a6b25  8b36                 mov esi, dword ptr [esi]
// 004a6b27  85f6                 test esi, esi
// 004a6b29  750f                 jne 0x4a6b3a
// 004a6b2b  ffd3                 call ebx
// 004a6b2d  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 004a6b30  7202                 jb 0x4a6b34
// 004a6b32  ffd3                 call ebx
// 004a6b34  8bc7                 mov eax, edi
// 004a6b36  5f                   pop edi
// 004a6b37  5e                   pop esi
// 004a6b38  5b                   pop ebx
// 004a6b39  c3                   ret 
// 004a6b3a  8b36                 mov esi, dword ptr [esi]
// 004a6b3c  ebef                 jmp 0x4a6b2d
// standard library vector<ptr> (function ?front@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAPAUT@@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
