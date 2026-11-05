// from server: 100% by auto
// roc 2008-06 00405040  unit: VCWorkspace::?$CComObject  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00405040
//
// 00405040  8b442404             mov eax, dword ptr [esp + 4]
// 00405044  56                   push esi
// 00405045  50                   push eax
// 00405046  8bf1                 mov esi, ecx
// 00405048  e8e3feffff           call 0x404f30
// 0040504d  c7061cb18000         mov dword ptr [esi], 0x80b11c
// 00405053  8bc6                 mov eax, esi
// 00405055  5e                   pop esi
// 00405056  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
