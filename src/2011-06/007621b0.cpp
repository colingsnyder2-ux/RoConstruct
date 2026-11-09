// from server: 100% by auto
// roc 2011-06 007621b0  unit: seg_00760000  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007621b0
//
// 007621b0  85c0                 test eax, eax
// 007621b2  7e15                 jle 0x7621c9
// 007621b4  8b510c               mov edx, dword ptr [ecx + 0xc]
// 007621b7  c1e004               shl eax, 4
// 007621ba  8d4402f0             lea eax, [edx + eax - 0x10]
// 007621be  3b4108               cmp eax, dword ptr [ecx + 8]
// 007621c1  726a                 jb 0x76222d
// 007621c3  b8b875ab00           mov eax, 0xab75b8
// 007621c8  c3                   ret 
// 007621c9  3df0d8ffff           cmp eax, 0xffffd8f0
// 007621ce  7e07                 jle 0x7621d7
// 007621d0  c1e004               shl eax, 4
// 007621d3  034108               add eax, dword ptr [ecx + 8]
// 007621d6  c3                   ret 
// 007621d7  3deed8ffff           cmp eax, 0xffffd8ee
// 007621dc  744c                 je 0x76222a
// 007621de  3defd8ffff           cmp eax, 0xffffd8ef
// 007621e3  742d                 je 0x762212
// 007621e5  3df0d8ffff           cmp eax, 0xffffd8f0
// 007621ea  741f                 je 0x76220b
// 007621ec  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 007621ef  8b5104               mov edx, dword ptr [ecx + 4]
// 007621f2  8b12                 mov edx, dword ptr [edx]
// 007621f4  b9eed8ffff           mov ecx, 0xffffd8ee
// 007621f9  2bc8                 sub ecx, eax
// 007621fb  0fb64207             movzx eax, byte ptr [edx + 7]
// 007621ff  3bc8                 cmp ecx, eax
// 00762201  7fc0                 jg 0x7621c3
// 00762203  c1e104               shl ecx, 4
// 00762206  8d441108             lea eax, [ecx + edx + 8]
// 0076220a  c3                   ret 
// 0076220b  8b4110               mov eax, dword ptr [ecx + 0x10]
// 0076220e  83c060               add eax, 0x60
// 00762211  c3                   ret 
// 00762212  8d4158               lea eax, [ecx + 0x58]
// 00762215  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 00762218  8b5104               mov edx, dword ptr [ecx + 4]
// 0076221b  8b0a                 mov ecx, dword ptr [edx]
// 0076221d  8b510c               mov edx, dword ptr [ecx + 0xc]
// 00762220  8910                 mov dword ptr [eax], edx
// 00762222  c7400805000000       mov dword ptr [eax + 8], 5
// 00762229  c3                   ret 
// 0076222a  8d4148               lea eax, [ecx + 0x48]
// 0076222d  c3                   ret 
// library lua-5.1/lapi.c (function _index2adr)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
