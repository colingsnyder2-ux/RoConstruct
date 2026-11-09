// from server: 100% by auto
// roc 2010-06 00718750  unit: RBX::BlockBlockContact  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00718750
//
// 00718750  8b542408             mov edx, dword ptr [esp + 8]
// 00718754  8bc1                 mov eax, ecx
// 00718756  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0071875a  8908                 mov dword ptr [eax], ecx
// 0071875c  895004               mov dword ptr [eax + 4], edx
// 0071875f  c20800               ret 8
// standard library vector<ptr> (function ??0?$_Revranit@V?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@std@@U?$iterator@Urandom_access_iterator_tag@std@@PAUT@@HPAPAU3@AAPAU3@@2@@std@@QAE@V?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
