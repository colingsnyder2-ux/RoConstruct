// from server: 100% by auto
// roc 2011-06 00404260  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00404260
//
// 00404260  33c0                 xor eax, eax
// 00404262  66898126120000       mov word ptr [ecx + 0x1226], ax
// 00404269  c78128120000ffffffff mov dword ptr [ecx + 0x1228], 0xffffffff
// 00404273  89812c120000         mov dword ptr [ecx + 0x122c], eax
// 00404279  898130120000         mov dword ptr [ecx + 0x1230], eax
// 0040427f  898134120000         mov dword ptr [ecx + 0x1234], eax
// 00404285  89813c120000         mov dword ptr [ecx + 0x123c], eax
// 0040428b  898138120000         mov dword ptr [ecx + 0x1238], eax
// 00404291  898140120000         mov dword ptr [ecx + 0x1240], eax
// 00404297  8801                 mov byte ptr [ecx], al
// 00404299  884121               mov byte ptr [ecx + 0x21], al
// 0040429c  888122010000         mov byte ptr [ecx + 0x122], al
// 004042a2  8881a3010000         mov byte ptr [ecx + 0x1a3], al
// 004042a8  888124020000         mov byte ptr [ecx + 0x224], al
// 004042ae  8881250a0000         mov byte ptr [ecx + 0xa25], al
// 004042b4  c3                   ret 
// copied from an identical function in another client (function ?Init@VCContent_CComAggObject@ns_ROCX00000e@ns_ROCX0000f9@@QAEXXZ)

namespace ns_ROCX00000e {
// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lstring.c
}
