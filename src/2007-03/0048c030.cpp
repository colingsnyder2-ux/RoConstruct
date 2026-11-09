// from server: 100% by auto
// roc 2007-03 0048c030  unit: seg_00480000  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0048c030
//
// 0048c030  56                   push esi
// 0048c031  8bf1                 mov esi, ecx
// 0048c033  833e00               cmp dword ptr [esi], 0
// 0048c036  57                   push edi
// 0048c037  8b3d44e97700         mov edi, dword ptr [0x77e944]
// 0048c03d  7502                 jne 0x48c041
// 0048c03f  ffd7                 call edi
// 0048c041  8b4604               mov eax, dword ptr [esi + 4]
// 0048c044  8b4004               mov eax, dword ptr [eax + 4]
// 0048c047  8b0e                 mov ecx, dword ptr [esi]
// 0048c049  894604               mov dword ptr [esi + 4], eax
// 0048c04c  3b4104               cmp eax, dword ptr [ecx + 4]
// 0048c04f  7502                 jne 0x48c053
// 0048c051  ffd7                 call edi
// 0048c053  5f                   pop edi
// 0048c054  8bc6                 mov eax, esi
// 0048c056  5e                   pop esi
// 0048c057  c3                   ret 
// standard library list<ptr> (function ??F?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAV012@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
