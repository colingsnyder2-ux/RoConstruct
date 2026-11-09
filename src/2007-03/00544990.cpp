// from server: 100% by auto
// roc 2007-03 00544990  unit: seg_00540000  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00544990
//
// 00544990  53                   push ebx
// 00544991  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00544995  57                   push edi
// 00544996  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0054499a  57                   push edi
// 0054499b  53                   push ebx
// 0054499c  ff1594d27700         call dword ptr [0x77d294]
// 005449a2  85c0                 test eax, eax
// 005449a4  7503                 jne 0x5449a9
// 005449a6  5f                   pop edi
// 005449a7  5b                   pop ebx
// 005449a8  c3                   ret 
// 005449a9  56                   push esi
// 005449aa  50                   push eax
// 005449ab  ff1520d27700         call dword ptr [0x77d220]
// 005449b1  8bf0                 mov esi, eax
// 005449b3  85f6                 test esi, esi
// 005449b5  742d                 je 0x5449e4
// 005449b7  57                   push edi
// 005449b8  53                   push ebx
// 005449b9  ff1598d27700         call dword ptr [0x77d298]
// 005449bf  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005449c3  03c6                 add eax, esi
// 005449c5  83e10f               and ecx, 0xf
// 005449c8  7616                 jbe 0x5449e0
// 005449ca  8d9b00000000         lea ebx, [ebx]
// 005449d0  3bf0                 cmp esi, eax
// 005449d2  7310                 jae 0x5449e4
// 005449d4  83e901               sub ecx, 1
// 005449d7  0fb716               movzx edx, word ptr [esi]
// 005449da  8d745602             lea esi, [esi + edx*2 + 2]
// 005449de  75f0                 jne 0x5449d0
// 005449e0  3bf0                 cmp esi, eax
// 005449e2  7206                 jb 0x5449ea
// 005449e4  5e                   pop esi
// 005449e5  5f                   pop edi
// 005449e6  33c0                 xor eax, eax
// 005449e8  5b                   pop ebx
// 005449e9  c3                   ret 
// 005449ea  668b06               mov ax, word ptr [esi]
// 005449ed  66f7d8               neg ax
// 005449f0  1bc0                 sbb eax, eax
// 005449f2  23c6                 and eax, esi
// 005449f4  5e                   pop esi
// 005449f5  5f                   pop edi
// 005449f6  5b                   pop ebx
// 005449f7  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ?_AtlGetStringResourceImage@ATL@@YAPBUATLSTRINGRESOURCEIMAGE@1@PAUHINSTANCE__@@PAUHRSRC__@@I@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
