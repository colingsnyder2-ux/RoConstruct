// from server: 100% by auto
// roc 2011-06 007f8b80  unit: RBX::Log  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007f8b80
//
// 007f8b80  8b542408             mov edx, dword ptr [esp + 8]
// 007f8b84  8bc1                 mov eax, ecx
// 007f8b86  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007f8b8a  8908                 mov dword ptr [eax], ecx
// 007f8b8c  895004               mov dword ptr [eax + 4], edx
// 007f8b8f  c20800               ret 8
// standard library vector<ptr> (function ??0?$_Revranit@V?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@std@@U?$iterator@Urandom_access_iterator_tag@std@@PAUT@@HPAPAU3@AAPAU3@@2@@std@@QAE@V?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
