// from server: 100% by auto
// roc 2011-06 0040b250  unit: VAuthoringSettings::?$FactoryProduct  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0040b250
//
// 0040b250  8b442404             mov eax, dword ptr [esp + 4]
// 0040b254  56                   push esi
// 0040b255  50                   push eax
// 0040b256  8bf1                 mov esi, ecx
// 0040b258  e883f7ffff           call 0x40a9e0
// 0040b25d  c706a8bfa500         mov dword ptr [esi], 0xa5bfa8
// 0040b263  8bc6                 mov eax, esi
// 0040b265  5e                   pop esi
// 0040b266  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
