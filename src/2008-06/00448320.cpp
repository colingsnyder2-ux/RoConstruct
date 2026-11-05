// from server: 100% by auto
// roc 2008-06 00448320  unit: VCRenderSettings::?$FactoryProduct  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00448320
//
// 00448320  56                   push esi
// 00448321  8bf1                 mov esi, ecx
// 00448323  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00448326  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 00448329  b893244992           mov eax, 0x92492493
// 0044832e  f7e9                 imul ecx
// 00448330  03d1                 add edx, ecx
// 00448332  c1fa04               sar edx, 4
// 00448335  8bc2                 mov eax, edx
// 00448337  c1e81f               shr eax, 0x1f
// 0044833a  57                   push edi
// 0044833b  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0044833f  03c2                 add eax, edx
// 00448341  3bf8                 cmp edi, eax
// 00448343  7206                 jb 0x44834b
// 00448345  ff1590288000         call dword ptr [0x802890]
// 0044834b  8b560c               mov edx, dword ptr [esi + 0xc]
// 0044834e  8d0cfd00000000       lea ecx, [edi*8]
// 00448355  2bcf                 sub ecx, edi
// 00448357  5f                   pop edi
// 00448358  8d048a               lea eax, [edx + ecx*4]
// 0044835b  5e                   pop esi
// 0044835c  c20400               ret 4
// standard library vector<string> (function ??A?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QBEABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@I@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
