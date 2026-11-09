// from server: 100% by auto
// roc 2010-06 00403870  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00403870
//
// 00403870  33c0                 xor eax, eax
// 00403872  66898126120000       mov word ptr [ecx + 0x1226], ax
// 00403879  c78128120000ffffffff mov dword ptr [ecx + 0x1228], 0xffffffff
// 00403883  89812c120000         mov dword ptr [ecx + 0x122c], eax
// 00403889  898130120000         mov dword ptr [ecx + 0x1230], eax
// 0040388f  898134120000         mov dword ptr [ecx + 0x1234], eax
// 00403895  89813c120000         mov dword ptr [ecx + 0x123c], eax
// 0040389b  898138120000         mov dword ptr [ecx + 0x1238], eax
// 004038a1  898140120000         mov dword ptr [ecx + 0x1240], eax
// 004038a7  8801                 mov byte ptr [ecx], al
// 004038a9  884121               mov byte ptr [ecx + 0x21], al
// 004038ac  888122010000         mov byte ptr [ecx + 0x122], al
// 004038b2  8881a3010000         mov byte ptr [ecx + 0x1a3], al
// 004038b8  888124020000         mov byte ptr [ecx + 0x224], al
// 004038be  8881250a0000         mov byte ptr [ecx + 0xa25], al
// 004038c4  c3                   ret 
// copied from an identical function in another client (function ?Init@VCContent_CComAggObject@ns_ROCX00000f@ns_ROCX0000ab@@QAEXXZ)

namespace ns_ROCX00000f {
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-11.2.2 Source/CommandBars/XTPControlComboBox.cpp
}
