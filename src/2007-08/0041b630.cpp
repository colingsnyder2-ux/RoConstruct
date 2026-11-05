// from server: 100% by auto
// roc 2007-08 0041b630  unit: VDHTMLWindow::?$SignalDesc  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041b630
//
// 0041b630  8b4104               mov eax, dword ptr [ecx + 4]
// 0041b633  85c0                 test eax, eax
// 0041b635  7501                 jne 0x41b638
// 0041b637  c3                   ret 
// 0041b638  8b4908               mov ecx, dword ptr [ecx + 8]
// 0041b63b  2bc8                 sub ecx, eax
// 0041b63d  b893244992           mov eax, 0x92492493
// 0041b642  f7e9                 imul ecx
// 0041b644  03d1                 add edx, ecx
// 0041b646  c1fa04               sar edx, 4
// 0041b649  8bc2                 mov eax, edx
// 0041b64b  c1e81f               shr eax, 0x1f
// 0041b64e  03c2                 add eax, edx
// 0041b650  c3                   ret 
// standard library vector<string> (function ?size@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QBEIXZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
