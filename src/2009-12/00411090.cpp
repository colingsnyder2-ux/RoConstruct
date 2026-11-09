// from server: 100% by auto
// roc 2009-12 00411090  unit: CChildFrame  size: 358 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00411090
//
// 00411090  51                   push ecx
// 00411091  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00411095  53                   push ebx
// 00411096  8b19                 mov ebx, dword ptr [ecx]
// 00411098  55                   push ebp
// 00411099  8b6904               mov ebp, dword ptr [ecx + 4]
// 0041109c  56                   push esi
// 0041109d  57                   push edi
// 0041109e  894c2410             mov dword ptr [esp + 0x10], ecx
// 004110a2  85db                 test ebx, ebx
// 004110a4  7508                 jne 0x4110ae
// 004110a6  81fd00000080         cmp ebp, 0x80000000
// 004110ac  7451                 je 0x4110ff
// 004110ae  83fbff               cmp ebx, -1
// 004110b1  7508                 jne 0x4110bb
// 004110b3  81fdffffff7f         cmp ebp, 0x7fffffff
// 004110b9  7444                 je 0x4110ff
// 004110bb  83fbfe               cmp ebx, -2
// 004110be  750c                 jne 0x4110cc
// 004110c0  81fdffffff7f         cmp ebp, 0x7fffffff
// 004110c6  0f8411010000         je 0x4111dd
// 004110cc  8b30                 mov esi, dword ptr [eax]
// 004110ce  8b7804               mov edi, dword ptr [eax + 4]
// 004110d1  85f6                 test esi, esi
// 004110d3  7508                 jne 0x4110dd
// 004110d5  81ff00000080         cmp edi, 0x80000000
// 004110db  7422                 je 0x4110ff
// 004110dd  83feff               cmp esi, -1
// 004110e0  7508                 jne 0x4110ea
// 004110e2  81ffffffff7f         cmp edi, 0x7fffffff
// 004110e8  7415                 je 0x4110ff
// 004110ea  83fefe               cmp esi, -2
// 004110ed  0f85d5000000         jne 0x4111c8
// 004110f3  81ffffffff7f         cmp edi, 0x7fffffff
// 004110f9  0f85c9000000         jne 0x4111c8
// 004110ff  83fbfe               cmp ebx, -2
// 00411102  750c                 jne 0x411110
// 00411104  81fdffffff7f         cmp ebp, 0x7fffffff
// 0041110a  0f84cd000000         je 0x4111dd
// 00411110  8b30                 mov esi, dword ptr [eax]
// 00411112  8b7804               mov edi, dword ptr [eax + 4]
// 00411115  83fefe               cmp esi, -2
// 00411118  750c                 jne 0x411126
// 0041111a  81ffffffff7f         cmp edi, 0x7fffffff
// 00411120  0f84b7000000         je 0x4111dd
// 00411126  83fbff               cmp ebx, -1
// 00411129  7514                 jne 0x41113f
// 0041112b  81fdffffff7f         cmp ebp, 0x7fffffff
// 00411131  750c                 jne 0x41113f
// 00411133  3bf3                 cmp esi, ebx
// 00411135  7508                 jne 0x41113f
// 00411137  3bfd                 cmp edi, ebp
// 00411139  0f849e000000         je 0x4111dd
// 0041113f  85db                 test ebx, ebx
// 00411141  7514                 jne 0x411157
// 00411143  81fd00000080         cmp ebp, 0x80000000
// 00411149  750c                 jne 0x411157
// 0041114b  85f6                 test esi, esi
// 0041114d  7508                 jne 0x411157
// 0041114f  3bfd                 cmp edi, ebp
// 00411151  0f8486000000         je 0x4111dd
// 00411157  e894faffff           call 0x410bf0
// 0041115c  84c0                 test al, al
// 0041115e  741a                 je 0x41117a
// 00411160  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00411164  8b11                 mov edx, dword ptr [ecx]
// 00411166  8b442418             mov eax, dword ptr [esp + 0x18]
// 0041116a  8b4904               mov ecx, dword ptr [ecx + 4]
// 0041116d  5f                   pop edi
// 0041116e  5e                   pop esi
// 0041116f  5d                   pop ebp
// 00411170  8910                 mov dword ptr [eax], edx
// 00411172  894804               mov dword ptr [eax + 4], ecx
// 00411175  5b                   pop ebx
// 00411176  59                   pop ecx
// 00411177  c20800               ret 8
// 0041117a  57                   push edi
// 0041117b  56                   push esi
// 0041117c  e82ffaffff           call 0x410bb0
// 00411181  83c408               add esp, 8
// 00411184  84c0                 test al, al
// 00411186  7419                 je 0x4111a1
// 00411188  8b442418             mov eax, dword ptr [esp + 0x18]
// 0041118c  5f                   pop edi
// 0041118d  5e                   pop esi
// 0041118e  5d                   pop ebp
// 0041118f  c70000000000         mov dword ptr [eax], 0
// 00411195  c7400400000080       mov dword ptr [eax + 4], 0x80000000
// 0041119c  5b                   pop ebx
// 0041119d  59                   pop ecx
// 0041119e  c20800               ret 8
// 004111a1  57                   push edi
// 004111a2  56                   push esi
// 004111a3  e828faffff           call 0x410bd0
// 004111a8  83c408               add esp, 8
// 004111ab  84c0                 test al, al
// 004111ad  7419                 je 0x4111c8
// 004111af  8b442418             mov eax, dword ptr [esp + 0x18]
// 004111b3  5f                   pop edi
// 004111b4  5e                   pop esi
// 004111b5  5d                   pop ebp
// 004111b6  c700ffffffff         mov dword ptr [eax], 0xffffffff
// 004111bc  c74004ffffff7f       mov dword ptr [eax + 4], 0x7fffffff
// 004111c3  5b                   pop ebx
// 004111c4  59                   pop ecx
// 004111c5  c20800               ret 8
// 004111c8  8b442418             mov eax, dword ptr [esp + 0x18]
// 004111cc  2bde                 sub ebx, esi
// 004111ce  1bef                 sbb ebp, edi
// 004111d0  5f                   pop edi
// 004111d1  5e                   pop esi
// 004111d2  896804               mov dword ptr [eax + 4], ebp
// 004111d5  5d                   pop ebp
// 004111d6  8918                 mov dword ptr [eax], ebx
// 004111d8  5b                   pop ebx
// 004111d9  59                   pop ecx
// 004111da  c20800               ret 8
// 004111dd  8b442418             mov eax, dword ptr [esp + 0x18]
// 004111e1  5f                   pop edi
// 004111e2  5e                   pop esi
// 004111e3  5d                   pop ebp
// 004111e4  c700feffffff         mov dword ptr [eax], 0xfffffffe
// 004111ea  c74004ffffff7f       mov dword ptr [eax + 4], 0x7fffffff
// 004111f1  5b                   pop ebx
// 004111f2  59                   pop ecx
// 004111f3  c20800               ret 8
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??$?G_J@?$int_adapter@_J@date_time@boost@@QBE?AV012@ABV012@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
