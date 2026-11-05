// from server: 100% by auto
// roc 2008-06 005f29b0  unit: boost::iostreams::DUoutput::V?$basic_null_device::?$stream_buffer  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005f29b0
//
// 005f29b0  8b442404             mov eax, dword ptr [esp + 4]
// 005f29b4  56                   push esi
// 005f29b5  50                   push eax
// 005f29b6  8bf1                 mov esi, ecx
// 005f29b8  e8d374e1ff           call 0x409e90
// 005f29bd  c70654088400         mov dword ptr [esi], 0x840854
// 005f29c3  8bc6                 mov eax, esi
// 005f29c5  5e                   pop esi
// 005f29c6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
