// from server: 100% by auto
// roc 2012-06 00831940  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00831940
//
// 00831940  85c0                 test eax, eax
// 00831942  7e15                 jle 0x831959
// 00831944  8b510c               mov edx, dword ptr [ecx + 0xc]
// 00831947  c1e004               shl eax, 4
// 0083194a  8d4402f0             lea eax, [edx + eax - 0x10]
// 0083194e  3b4108               cmp eax, dword ptr [ecx + 8]
// 00831951  726a                 jb 0x8319bd
// 00831953  b8202dbd00           mov eax, 0xbd2d20
// 00831958  c3                   ret 
// 00831959  3df0d8ffff           cmp eax, 0xffffd8f0
// 0083195e  7e07                 jle 0x831967
// 00831960  c1e004               shl eax, 4
// 00831963  034108               add eax, dword ptr [ecx + 8]
// 00831966  c3                   ret 
// 00831967  3deed8ffff           cmp eax, 0xffffd8ee
// 0083196c  744c                 je 0x8319ba
// 0083196e  3defd8ffff           cmp eax, 0xffffd8ef
// 00831973  742d                 je 0x8319a2
// 00831975  3df0d8ffff           cmp eax, 0xffffd8f0
// 0083197a  741f                 je 0x83199b
// 0083197c  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 0083197f  8b5104               mov edx, dword ptr [ecx + 4]
// 00831982  8b12                 mov edx, dword ptr [edx]
// 00831984  b9eed8ffff           mov ecx, 0xffffd8ee
// 00831989  2bc8                 sub ecx, eax
// 0083198b  0fb64207             movzx eax, byte ptr [edx + 7]
// 0083198f  3bc8                 cmp ecx, eax
// 00831991  7fc0                 jg 0x831953
// 00831993  c1e104               shl ecx, 4
// 00831996  8d441108             lea eax, [ecx + edx + 8]
// 0083199a  c3                   ret 
// 0083199b  8b4110               mov eax, dword ptr [ecx + 0x10]
// 0083199e  83c060               add eax, 0x60
// 008319a1  c3                   ret 
// 008319a2  8d4158               lea eax, [ecx + 0x58]
// 008319a5  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 008319a8  8b5104               mov edx, dword ptr [ecx + 4]
// 008319ab  8b0a                 mov ecx, dword ptr [edx]
// 008319ad  8b510c               mov edx, dword ptr [ecx + 0xc]
// 008319b0  8910                 mov dword ptr [eax], edx
// 008319b2  c7400805000000       mov dword ptr [eax + 8], 5
// 008319b9  c3                   ret 
// 008319ba  8d4148               lea eax, [ecx + 0x48]
// 008319bd  c3                   ret 
// library lua-5.1/lapi.c (function _index2adr)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
