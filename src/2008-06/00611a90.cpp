// from server: 100% by auto
// roc 2008-06 00611a90  unit: seg_00610000  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00611a90
//
// 00611a90  85c0                 test eax, eax
// 00611a92  7e15                 jle 0x611aa9
// 00611a94  8b510c               mov edx, dword ptr [ecx + 0xc]
// 00611a97  c1e004               shl eax, 4
// 00611a9a  8d4402f0             lea eax, [edx + eax - 0x10]
// 00611a9e  3b4108               cmp eax, dword ptr [ecx + 8]
// 00611aa1  726a                 jb 0x611b0d
// 00611aa3  b880488400           mov eax, 0x844880
// 00611aa8  c3                   ret 
// 00611aa9  3df0d8ffff           cmp eax, 0xffffd8f0
// 00611aae  7e07                 jle 0x611ab7
// 00611ab0  c1e004               shl eax, 4
// 00611ab3  034108               add eax, dword ptr [ecx + 8]
// 00611ab6  c3                   ret 
// 00611ab7  3deed8ffff           cmp eax, 0xffffd8ee
// 00611abc  744c                 je 0x611b0a
// 00611abe  3defd8ffff           cmp eax, 0xffffd8ef
// 00611ac3  742d                 je 0x611af2
// 00611ac5  3df0d8ffff           cmp eax, 0xffffd8f0
// 00611aca  741f                 je 0x611aeb
// 00611acc  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 00611acf  8b5104               mov edx, dword ptr [ecx + 4]
// 00611ad2  8b12                 mov edx, dword ptr [edx]
// 00611ad4  b9eed8ffff           mov ecx, 0xffffd8ee
// 00611ad9  2bc8                 sub ecx, eax
// 00611adb  0fb64207             movzx eax, byte ptr [edx + 7]
// 00611adf  3bc8                 cmp ecx, eax
// 00611ae1  7fc0                 jg 0x611aa3
// 00611ae3  c1e104               shl ecx, 4
// 00611ae6  8d441108             lea eax, [ecx + edx + 8]
// 00611aea  c3                   ret 
// 00611aeb  8b4110               mov eax, dword ptr [ecx + 0x10]
// 00611aee  83c060               add eax, 0x60
// 00611af1  c3                   ret 
// 00611af2  8d4158               lea eax, [ecx + 0x58]
// 00611af5  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 00611af8  8b5104               mov edx, dword ptr [ecx + 4]
// 00611afb  8b0a                 mov ecx, dword ptr [edx]
// 00611afd  8b510c               mov edx, dword ptr [ecx + 0xc]
// 00611b00  8910                 mov dword ptr [eax], edx
// 00611b02  c7400805000000       mov dword ptr [eax + 8], 5
// 00611b09  c3                   ret 
// 00611b0a  8d4148               lea eax, [ecx + 0x48]
// 00611b0d  c3                   ret 
// library lua-5.1/lapi.c (function _index2adr)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
