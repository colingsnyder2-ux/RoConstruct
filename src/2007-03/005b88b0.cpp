// from server: 100% by auto
// roc 2007-03 005b88b0  unit: seg_005b0000  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b88b0
//
// 005b88b0  85c0                 test eax, eax
// 005b88b2  7e15                 jle 0x5b88c9
// 005b88b4  8b510c               mov edx, dword ptr [ecx + 0xc]
// 005b88b7  c1e004               shl eax, 4
// 005b88ba  8d4402f0             lea eax, [edx + eax - 0x10]
// 005b88be  3b4108               cmp eax, dword ptr [ecx + 8]
// 005b88c1  726a                 jb 0x5b892d
// 005b88c3  b8a0007c00           mov eax, 0x7c00a0
// 005b88c8  c3                   ret 
// 005b88c9  3df0d8ffff           cmp eax, 0xffffd8f0
// 005b88ce  7e07                 jle 0x5b88d7
// 005b88d0  c1e004               shl eax, 4
// 005b88d3  034108               add eax, dword ptr [ecx + 8]
// 005b88d6  c3                   ret 
// 005b88d7  3deed8ffff           cmp eax, 0xffffd8ee
// 005b88dc  744c                 je 0x5b892a
// 005b88de  3defd8ffff           cmp eax, 0xffffd8ef
// 005b88e3  742d                 je 0x5b8912
// 005b88e5  3df0d8ffff           cmp eax, 0xffffd8f0
// 005b88ea  741f                 je 0x5b890b
// 005b88ec  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 005b88ef  8b5104               mov edx, dword ptr [ecx + 4]
// 005b88f2  8b12                 mov edx, dword ptr [edx]
// 005b88f4  b9eed8ffff           mov ecx, 0xffffd8ee
// 005b88f9  2bc8                 sub ecx, eax
// 005b88fb  0fb64207             movzx eax, byte ptr [edx + 7]
// 005b88ff  3bc8                 cmp ecx, eax
// 005b8901  7fc0                 jg 0x5b88c3
// 005b8903  c1e104               shl ecx, 4
// 005b8906  8d441108             lea eax, [ecx + edx + 8]
// 005b890a  c3                   ret 
// 005b890b  8b4110               mov eax, dword ptr [ecx + 0x10]
// 005b890e  83c060               add eax, 0x60
// 005b8911  c3                   ret 
// 005b8912  8d4158               lea eax, [ecx + 0x58]
// 005b8915  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 005b8918  8b5104               mov edx, dword ptr [ecx + 4]
// 005b891b  8b0a                 mov ecx, dword ptr [edx]
// 005b891d  8b510c               mov edx, dword ptr [ecx + 0xc]
// 005b8920  8910                 mov dword ptr [eax], edx
// 005b8922  c7400805000000       mov dword ptr [eax + 8], 5
// 005b8929  c3                   ret 
// 005b892a  8d4148               lea eax, [ecx + 0x48]
// 005b892d  c3                   ret 
// library lua-5.1.1/lapi.c (function _index2adr)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
