// from server: 100% by auto
// roc 2009-12 007d1710  unit: seg_007d0000  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d1710
//
// 007d1710  83ec20               sub esp, 0x20
// 007d1713  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 007d1717  8b442424             mov eax, dword ptr [esp + 0x24]
// 007d171b  8b542430             mov edx, dword ptr [esp + 0x30]
// 007d171f  894c2410             mov dword ptr [esp + 0x10], ecx
// 007d1723  8944240c             mov dword ptr [esp + 0xc], eax
// 007d1727  8b442434             mov eax, dword ptr [esp + 0x34]
// 007d172b  8d0c24               lea ecx, [esp]
// 007d172e  51                   push ecx
// 007d172f  89542418             mov dword ptr [esp + 0x18], edx
// 007d1733  8944241c             mov dword ptr [esp + 0x1c], eax
// 007d1737  c744242000000000     mov dword ptr [esp + 0x20], 0
// 007d173f  e8cc380000           call 0x7d5010
// 007d1744  83c404               add esp, 4
// 007d1747  837c241c00           cmp dword ptr [esp + 0x1c], 0
// 007d174c  751c                 jne 0x7d176a
// 007d174e  8b542414             mov edx, dword ptr [esp + 0x14]
// 007d1752  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007d1756  52                   push edx
// 007d1757  6a0c                 push 0xc
// 007d1759  8d442408             lea eax, [esp + 8]
// 007d175d  50                   push eax
// 007d175e  51                   push ecx
// 007d175f  ff542420             call dword ptr [esp + 0x20]
// 007d1763  83c410               add esp, 0x10
// 007d1766  8944241c             mov dword ptr [esp + 0x1c], eax
// 007d176a  8b442428             mov eax, dword ptr [esp + 0x28]
// 007d176e  8d54240c             lea edx, [esp + 0xc]
// 007d1772  52                   push edx
// 007d1773  6a00                 push 0
// 007d1775  50                   push eax
// 007d1776  e825feffff           call 0x7d15a0
// 007d177b  8b442428             mov eax, dword ptr [esp + 0x28]
// 007d177f  83c42c               add esp, 0x2c
// 007d1782  c3                   ret 
// library lua-5.1/ldump.c (function _luaU_dump)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldump.c
