// from server: 100% by auto
// roc 2009-12 00403820  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00403820
//
// 00403820  33c0                 xor eax, eax
// 00403822  66898126120000       mov word ptr [ecx + 0x1226], ax
// 00403829  c78128120000ffffffff mov dword ptr [ecx + 0x1228], 0xffffffff
// 00403833  89812c120000         mov dword ptr [ecx + 0x122c], eax
// 00403839  898130120000         mov dword ptr [ecx + 0x1230], eax
// 0040383f  898134120000         mov dword ptr [ecx + 0x1234], eax
// 00403845  89813c120000         mov dword ptr [ecx + 0x123c], eax
// 0040384b  898138120000         mov dword ptr [ecx + 0x1238], eax
// 00403851  898140120000         mov dword ptr [ecx + 0x1240], eax
// 00403857  8801                 mov byte ptr [ecx], al
// 00403859  884121               mov byte ptr [ecx + 0x21], al
// 0040385c  888122010000         mov byte ptr [ecx + 0x122], al
// 00403862  8881a3010000         mov byte ptr [ecx + 0x1a3], al
// 00403868  888124020000         mov byte ptr [ecx + 0x224], al
// 0040386e  8881250a0000         mov byte ptr [ecx + 0xa25], al
// 00403874  c3                   ret 
// copied from an identical function in another client (function ?Init@VCContent_CComAggObject@ns_ROCX00000f@ns_ROCX000064@@QAEXXZ)

namespace ns_ROCX00000f {
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-11.2.2 Source/PropertyGrid/XTPPropertyGridItemColor.cpp
}
