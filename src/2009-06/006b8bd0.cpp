// from server: 100% by auto
// roc 2009-06 006b8bd0  unit: RBX::UniversalTool  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b8bd0
//
// 006b8bd0  85c0                 test eax, eax
// 006b8bd2  7e15                 jle 0x6b8be9
// 006b8bd4  8b510c               mov edx, dword ptr [ecx + 0xc]
// 006b8bd7  c1e004               shl eax, 4
// 006b8bda  8d4402f0             lea eax, [edx + eax - 0x10]
// 006b8bde  3b4108               cmp eax, dword ptr [ecx + 8]
// 006b8be1  726a                 jb 0x6b8c4d
// 006b8be3  b878c38e00           mov eax, 0x8ec378
// 006b8be8  c3                   ret 
// 006b8be9  3df0d8ffff           cmp eax, 0xffffd8f0
// 006b8bee  7e07                 jle 0x6b8bf7
// 006b8bf0  c1e004               shl eax, 4
// 006b8bf3  034108               add eax, dword ptr [ecx + 8]
// 006b8bf6  c3                   ret 
// 006b8bf7  3deed8ffff           cmp eax, 0xffffd8ee
// 006b8bfc  744c                 je 0x6b8c4a
// 006b8bfe  3defd8ffff           cmp eax, 0xffffd8ef
// 006b8c03  742d                 je 0x6b8c32
// 006b8c05  3df0d8ffff           cmp eax, 0xffffd8f0
// 006b8c0a  741f                 je 0x6b8c2b
// 006b8c0c  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 006b8c0f  8b5104               mov edx, dword ptr [ecx + 4]
// 006b8c12  8b12                 mov edx, dword ptr [edx]
// 006b8c14  b9eed8ffff           mov ecx, 0xffffd8ee
// 006b8c19  2bc8                 sub ecx, eax
// 006b8c1b  0fb64207             movzx eax, byte ptr [edx + 7]
// 006b8c1f  3bc8                 cmp ecx, eax
// 006b8c21  7fc0                 jg 0x6b8be3
// 006b8c23  c1e104               shl ecx, 4
// 006b8c26  8d441108             lea eax, [ecx + edx + 8]
// 006b8c2a  c3                   ret 
// 006b8c2b  8b4110               mov eax, dword ptr [ecx + 0x10]
// 006b8c2e  83c060               add eax, 0x60
// 006b8c31  c3                   ret 
// 006b8c32  8d4158               lea eax, [ecx + 0x58]
// 006b8c35  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 006b8c38  8b5104               mov edx, dword ptr [ecx + 4]
// 006b8c3b  8b0a                 mov ecx, dword ptr [edx]
// 006b8c3d  8b510c               mov edx, dword ptr [ecx + 0xc]
// 006b8c40  8910                 mov dword ptr [eax], edx
// 006b8c42  c7400805000000       mov dword ptr [eax + 8], 5
// 006b8c49  c3                   ret 
// 006b8c4a  8d4148               lea eax, [ecx + 0x48]
// 006b8c4d  c3                   ret 
// library lua-5.1/lapi.c (function _index2adr)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
