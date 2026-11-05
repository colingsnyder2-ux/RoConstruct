// from server: 100% by auto
// roc 2007-08 00535840  unit: std::logic_error  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00535840
//
// 00535840  8b442404             mov eax, dword ptr [esp + 4]
// 00535844  56                   push esi
// 00535845  50                   push eax
// 00535846  8bf1                 mov esi, ecx
// 00535848  e843e4ecff           call 0x403c90
// 0053584d  c70630567a00         mov dword ptr [esi], 0x7a5630
// 00535853  8bc6                 mov eax, esi
// 00535855  5e                   pop esi
// 00535856  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
