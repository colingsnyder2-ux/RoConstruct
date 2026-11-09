// from server: 100% by auto
// roc 2008-06 004029d0  unit: VCWorkspace::?$CComContainedObject  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004029d0
//
// 004029d0  8b442404             mov eax, dword ptr [esp + 4]
// 004029d4  56                   push esi
// 004029d5  50                   push eax
// 004029d6  8bf1                 mov esi, ecx
// 004029d8  ff1588288000         call dword ptr [0x802888]
// 004029de  c70604b18000         mov dword ptr [esi], 0x80b104
// 004029e4  8bc6                 mov eax, esi
// 004029e6  5e                   pop esi
// 004029e7  c20400               ret 4
// standard library vector<ptr> (function ??0bad_alloc@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
