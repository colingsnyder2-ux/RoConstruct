// from server: 100% by auto
// roc 2010-06 00411370  unit: CChildFrame  size: 358 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00411370
//
// 00411370  51                   push ecx
// 00411371  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00411375  53                   push ebx
// 00411376  8b19                 mov ebx, dword ptr [ecx]
// 00411378  55                   push ebp
// 00411379  8b6904               mov ebp, dword ptr [ecx + 4]
// 0041137c  56                   push esi
// 0041137d  57                   push edi
// 0041137e  894c2410             mov dword ptr [esp + 0x10], ecx
// 00411382  85db                 test ebx, ebx
// 00411384  7508                 jne 0x41138e
// 00411386  81fd00000080         cmp ebp, 0x80000000
// 0041138c  7451                 je 0x4113df
// 0041138e  83fbff               cmp ebx, -1
// 00411391  7508                 jne 0x41139b
// 00411393  81fdffffff7f         cmp ebp, 0x7fffffff
// 00411399  7444                 je 0x4113df
// 0041139b  83fbfe               cmp ebx, -2
// 0041139e  750c                 jne 0x4113ac
// 004113a0  81fdffffff7f         cmp ebp, 0x7fffffff
// 004113a6  0f8411010000         je 0x4114bd
// 004113ac  8b30                 mov esi, dword ptr [eax]
// 004113ae  8b7804               mov edi, dword ptr [eax + 4]
// 004113b1  85f6                 test esi, esi
// 004113b3  7508                 jne 0x4113bd
// 004113b5  81ff00000080         cmp edi, 0x80000000
// 004113bb  7422                 je 0x4113df
// 004113bd  83feff               cmp esi, -1
// 004113c0  7508                 jne 0x4113ca
// 004113c2  81ffffffff7f         cmp edi, 0x7fffffff
// 004113c8  7415                 je 0x4113df
// 004113ca  83fefe               cmp esi, -2
// 004113cd  0f85d5000000         jne 0x4114a8
// 004113d3  81ffffffff7f         cmp edi, 0x7fffffff
// 004113d9  0f85c9000000         jne 0x4114a8
// 004113df  83fbfe               cmp ebx, -2
// 004113e2  750c                 jne 0x4113f0
// 004113e4  81fdffffff7f         cmp ebp, 0x7fffffff
// 004113ea  0f84cd000000         je 0x4114bd
// 004113f0  8b30                 mov esi, dword ptr [eax]
// 004113f2  8b7804               mov edi, dword ptr [eax + 4]
// 004113f5  83fefe               cmp esi, -2
// 004113f8  750c                 jne 0x411406
// 004113fa  81ffffffff7f         cmp edi, 0x7fffffff
// 00411400  0f84b7000000         je 0x4114bd
// 00411406  83fbff               cmp ebx, -1
// 00411409  7514                 jne 0x41141f
// 0041140b  81fdffffff7f         cmp ebp, 0x7fffffff
// 00411411  750c                 jne 0x41141f
// 00411413  3bf3                 cmp esi, ebx
// 00411415  7508                 jne 0x41141f
// 00411417  3bfd                 cmp edi, ebp
// 00411419  0f849e000000         je 0x4114bd
// 0041141f  85db                 test ebx, ebx
// 00411421  7514                 jne 0x411437
// 00411423  81fd00000080         cmp ebp, 0x80000000
// 00411429  750c                 jne 0x411437
// 0041142b  85f6                 test esi, esi
// 0041142d  7508                 jne 0x411437
// 0041142f  3bfd                 cmp edi, ebp
// 00411431  0f8486000000         je 0x4114bd
// 00411437  e884faffff           call 0x410ec0
// 0041143c  84c0                 test al, al
// 0041143e  741a                 je 0x41145a
// 00411440  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00411444  8b11                 mov edx, dword ptr [ecx]
// 00411446  8b442418             mov eax, dword ptr [esp + 0x18]
// 0041144a  8b4904               mov ecx, dword ptr [ecx + 4]
// 0041144d  5f                   pop edi
// 0041144e  5e                   pop esi
// 0041144f  5d                   pop ebp
// 00411450  8910                 mov dword ptr [eax], edx
// 00411452  894804               mov dword ptr [eax + 4], ecx
// 00411455  5b                   pop ebx
// 00411456  59                   pop ecx
// 00411457  c20800               ret 8
// 0041145a  57                   push edi
// 0041145b  56                   push esi
// 0041145c  e81ffaffff           call 0x410e80
// 00411461  83c408               add esp, 8
// 00411464  84c0                 test al, al
// 00411466  7419                 je 0x411481
// 00411468  8b442418             mov eax, dword ptr [esp + 0x18]
// 0041146c  5f                   pop edi
// 0041146d  5e                   pop esi
// 0041146e  5d                   pop ebp
// 0041146f  c70000000000         mov dword ptr [eax], 0
// 00411475  c7400400000080       mov dword ptr [eax + 4], 0x80000000
// 0041147c  5b                   pop ebx
// 0041147d  59                   pop ecx
// 0041147e  c20800               ret 8
// 00411481  57                   push edi
// 00411482  56                   push esi
// 00411483  e818faffff           call 0x410ea0
// 00411488  83c408               add esp, 8
// 0041148b  84c0                 test al, al
// 0041148d  7419                 je 0x4114a8
// 0041148f  8b442418             mov eax, dword ptr [esp + 0x18]
// 00411493  5f                   pop edi
// 00411494  5e                   pop esi
// 00411495  5d                   pop ebp
// 00411496  c700ffffffff         mov dword ptr [eax], 0xffffffff
// 0041149c  c74004ffffff7f       mov dword ptr [eax + 4], 0x7fffffff
// 004114a3  5b                   pop ebx
// 004114a4  59                   pop ecx
// 004114a5  c20800               ret 8
// 004114a8  8b442418             mov eax, dword ptr [esp + 0x18]
// 004114ac  2bde                 sub ebx, esi
// 004114ae  1bef                 sbb ebp, edi
// 004114b0  5f                   pop edi
// 004114b1  5e                   pop esi
// 004114b2  896804               mov dword ptr [eax + 4], ebp
// 004114b5  5d                   pop ebp
// 004114b6  8918                 mov dword ptr [eax], ebx
// 004114b8  5b                   pop ebx
// 004114b9  59                   pop ecx
// 004114ba  c20800               ret 8
// 004114bd  8b442418             mov eax, dword ptr [esp + 0x18]
// 004114c1  5f                   pop edi
// 004114c2  5e                   pop esi
// 004114c3  5d                   pop ebp
// 004114c4  c700feffffff         mov dword ptr [eax], 0xfffffffe
// 004114ca  c74004ffffff7f       mov dword ptr [eax + 4], 0x7fffffff
// 004114d1  5b                   pop ebx
// 004114d2  59                   pop ecx
// 004114d3  c20800               ret 8
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??$?G_J@?$int_adapter@_J@date_time@boost@@QBE?AV012@ABV012@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
