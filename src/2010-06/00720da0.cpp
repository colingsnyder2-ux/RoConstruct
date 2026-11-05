// from server: 100% by auto
// roc 2010-06 00720da0  unit: RBX::UniversalTool  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00720da0
//
// 00720da0  85c0                 test eax, eax
// 00720da2  7e15                 jle 0x720db9
// 00720da4  8b510c               mov edx, dword ptr [ecx + 0xc]
// 00720da7  c1e004               shl eax, 4
// 00720daa  8d4402f0             lea eax, [edx + eax - 0x10]
// 00720dae  3b4108               cmp eax, dword ptr [ecx + 8]
// 00720db1  726a                 jb 0x720e1d
// 00720db3  b878dca400           mov eax, 0xa4dc78
// 00720db8  c3                   ret 
// 00720db9  3df0d8ffff           cmp eax, 0xffffd8f0
// 00720dbe  7e07                 jle 0x720dc7
// 00720dc0  c1e004               shl eax, 4
// 00720dc3  034108               add eax, dword ptr [ecx + 8]
// 00720dc6  c3                   ret 
// 00720dc7  3deed8ffff           cmp eax, 0xffffd8ee
// 00720dcc  744c                 je 0x720e1a
// 00720dce  3defd8ffff           cmp eax, 0xffffd8ef
// 00720dd3  742d                 je 0x720e02
// 00720dd5  3df0d8ffff           cmp eax, 0xffffd8f0
// 00720dda  741f                 je 0x720dfb
// 00720ddc  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 00720ddf  8b5104               mov edx, dword ptr [ecx + 4]
// 00720de2  8b12                 mov edx, dword ptr [edx]
// 00720de4  b9eed8ffff           mov ecx, 0xffffd8ee
// 00720de9  2bc8                 sub ecx, eax
// 00720deb  0fb64207             movzx eax, byte ptr [edx + 7]
// 00720def  3bc8                 cmp ecx, eax
// 00720df1  7fc0                 jg 0x720db3
// 00720df3  c1e104               shl ecx, 4
// 00720df6  8d441108             lea eax, [ecx + edx + 8]
// 00720dfa  c3                   ret 
// 00720dfb  8b4110               mov eax, dword ptr [ecx + 0x10]
// 00720dfe  83c060               add eax, 0x60
// 00720e01  c3                   ret 
// 00720e02  8d4158               lea eax, [ecx + 0x58]
// 00720e05  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 00720e08  8b5104               mov edx, dword ptr [ecx + 4]
// 00720e0b  8b0a                 mov ecx, dword ptr [edx]
// 00720e0d  8b510c               mov edx, dword ptr [ecx + 0xc]
// 00720e10  8910                 mov dword ptr [eax], edx
// 00720e12  c7400805000000       mov dword ptr [eax + 8], 5
// 00720e19  c3                   ret 
// 00720e1a  8d4148               lea eax, [ecx + 0x48]
// 00720e1d  c3                   ret 
// library lua-5.1/lapi.c (function _index2adr)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
