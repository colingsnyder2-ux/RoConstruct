// from server: 100% by auto
// roc 2009-06 00613c10  unit: boost::iostreams::DUoutput::V?$basic_null_device::?$stream_buffer  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00613c10
//
// 00613c10  8b442404             mov eax, dword ptr [esp + 4]
// 00613c14  56                   push esi
// 00613c15  50                   push eax
// 00613c16  8bf1                 mov esi, ecx
// 00613c18  e86358dfff           call 0x409480
// 00613c1d  c706148b8d00         mov dword ptr [esi], 0x8d8b14
// 00613c23  8bc6                 mov eax, esi
// 00613c25  5e                   pop esi
// 00613c26  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
