// from server: 100% by auto
// roc 2008-06 0048b970  unit: boost::any::placeholder  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0048b970
//
// 0048b970  53                   push ebx
// 0048b971  8b1d90288000         mov ebx, dword ptr [0x802890]
// 0048b977  56                   push esi
// 0048b978  8bf1                 mov esi, ecx
// 0048b97a  57                   push edi
// 0048b97b  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0048b97e  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0048b981  7602                 jbe 0x48b985
// 0048b983  ffd3                 call ebx
// 0048b985  8b36                 mov esi, dword ptr [esi]
// 0048b987  85f6                 test esi, esi
// 0048b989  750f                 jne 0x48b99a
// 0048b98b  ffd3                 call ebx
// 0048b98d  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0048b990  7202                 jb 0x48b994
// 0048b992  ffd3                 call ebx
// 0048b994  8bc7                 mov eax, edi
// 0048b996  5f                   pop edi
// 0048b997  5e                   pop esi
// 0048b998  5b                   pop ebx
// 0048b999  c3                   ret 
// 0048b99a  8b36                 mov esi, dword ptr [esi]
// 0048b99c  ebef                 jmp 0x48b98d
// standard library vector<ptr> (function ?front@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAPAUT@@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
