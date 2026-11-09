// from server: 100% by auto
// roc 2007-08 0040ad20  unit: VCSecureHtmlView::?$CXTPCommandBarsSiteBase  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040ad20
//
// 0040ad20  6aff                 push -1
// 0040ad22  68917b7400           push 0x747b91
// 0040ad27  64a100000000         mov eax, dword ptr fs:[0]
// 0040ad2d  50                   push eax
// 0040ad2e  51                   push ecx
// 0040ad2f  a188518b00           mov eax, dword ptr [0x8b5188]
// 0040ad34  33c4                 xor eax, esp
// 0040ad36  50                   push eax
// 0040ad37  8d442408             lea eax, [esp + 8]
// 0040ad3b  64a300000000         mov dword ptr fs:[0], eax
// 0040ad41  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0040ad45  894c2418             mov dword ptr [esp + 0x18], ecx
// 0040ad49  894c2404             mov dword ptr [esp + 4], ecx
// 0040ad4d  85c9                 test ecx, ecx
// 0040ad4f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0040ad57  740b                 je 0x40ad64
// 0040ad59  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0040ad5d  50                   push eax
// 0040ad5e  ff159ce67700         call dword ptr [0x77e69c]
// 0040ad64  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0040ad68  64890d00000000       mov dword ptr fs:[0], ecx
// 0040ad6f  59                   pop ecx
// 0040ad70  83c410               add esp, 0x10
// 0040ad73  c3                   ret 
// standard library vector<string> (function ??$_Construct@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@YAXPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@ABV10@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
