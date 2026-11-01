// from server: 100% by auto
// roc 2009-12 007885f0  unit: RBX::UniversalTool  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007885f0
//
// 007885f0  85c0                 test eax, eax
// 007885f2  7e15                 jle 0x788609
// 007885f4  8b510c               mov edx, dword ptr [ecx + 0xc]
// 007885f7  c1e004               shl eax, 4
// 007885fa  8d4402f0             lea eax, [edx + eax - 0x10]
// 007885fe  3b4108               cmp eax, dword ptr [ecx + 8]
// 00788601  726a                 jb 0x78866d
// 00788603  b828aa9e00           mov eax, 0x9eaa28
// 00788608  c3                   ret 
// 00788609  3df0d8ffff           cmp eax, 0xffffd8f0
// 0078860e  7e07                 jle 0x788617
// 00788610  c1e004               shl eax, 4
// 00788613  034108               add eax, dword ptr [ecx + 8]
// 00788616  c3                   ret 
// 00788617  3deed8ffff           cmp eax, 0xffffd8ee
// 0078861c  744c                 je 0x78866a
// 0078861e  3defd8ffff           cmp eax, 0xffffd8ef
// 00788623  742d                 je 0x788652
// 00788625  3df0d8ffff           cmp eax, 0xffffd8f0
// 0078862a  741f                 je 0x78864b
// 0078862c  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 0078862f  8b5104               mov edx, dword ptr [ecx + 4]
// 00788632  8b12                 mov edx, dword ptr [edx]
// 00788634  b9eed8ffff           mov ecx, 0xffffd8ee
// 00788639  2bc8                 sub ecx, eax
// 0078863b  0fb64207             movzx eax, byte ptr [edx + 7]
// 0078863f  3bc8                 cmp ecx, eax
// 00788641  7fc0                 jg 0x788603
// 00788643  c1e104               shl ecx, 4
// 00788646  8d441108             lea eax, [ecx + edx + 8]
// 0078864a  c3                   ret 
// 0078864b  8b4110               mov eax, dword ptr [ecx + 0x10]
// 0078864e  83c060               add eax, 0x60
// 00788651  c3                   ret 
// 00788652  8d4158               lea eax, [ecx + 0x58]
// 00788655  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 00788658  8b5104               mov edx, dword ptr [ecx + 4]
// 0078865b  8b0a                 mov ecx, dword ptr [edx]
// 0078865d  8b510c               mov edx, dword ptr [ecx + 0xc]
// 00788660  8910                 mov dword ptr [eax], edx
// 00788662  c7400805000000       mov dword ptr [eax + 8], 5
// 00788669  c3                   ret 
// 0078866a  8d4148               lea eax, [ecx + 0x48]
// 0078866d  c3                   ret 
// library lua-5.1/lapi.c (function _index2adr)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
