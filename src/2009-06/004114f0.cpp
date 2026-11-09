// from server: 100% by auto
// roc 2009-06 004114f0  unit: CChildFrame  size: 358 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004114f0
//
// 004114f0  51                   push ecx
// 004114f1  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004114f5  53                   push ebx
// 004114f6  8b19                 mov ebx, dword ptr [ecx]
// 004114f8  55                   push ebp
// 004114f9  8b6904               mov ebp, dword ptr [ecx + 4]
// 004114fc  56                   push esi
// 004114fd  57                   push edi
// 004114fe  894c2410             mov dword ptr [esp + 0x10], ecx
// 00411502  85db                 test ebx, ebx
// 00411504  7508                 jne 0x41150e
// 00411506  81fd00000080         cmp ebp, 0x80000000
// 0041150c  7451                 je 0x41155f
// 0041150e  83fbff               cmp ebx, -1
// 00411511  7508                 jne 0x41151b
// 00411513  81fdffffff7f         cmp ebp, 0x7fffffff
// 00411519  7444                 je 0x41155f
// 0041151b  83fbfe               cmp ebx, -2
// 0041151e  750c                 jne 0x41152c
// 00411520  81fdffffff7f         cmp ebp, 0x7fffffff
// 00411526  0f8411010000         je 0x41163d
// 0041152c  8b30                 mov esi, dword ptr [eax]
// 0041152e  8b7804               mov edi, dword ptr [eax + 4]
// 00411531  85f6                 test esi, esi
// 00411533  7508                 jne 0x41153d
// 00411535  81ff00000080         cmp edi, 0x80000000
// 0041153b  7422                 je 0x41155f
// 0041153d  83feff               cmp esi, -1
// 00411540  7508                 jne 0x41154a
// 00411542  81ffffffff7f         cmp edi, 0x7fffffff
// 00411548  7415                 je 0x41155f
// 0041154a  83fefe               cmp esi, -2
// 0041154d  0f85d5000000         jne 0x411628
// 00411553  81ffffffff7f         cmp edi, 0x7fffffff
// 00411559  0f85c9000000         jne 0x411628
// 0041155f  83fbfe               cmp ebx, -2
// 00411562  750c                 jne 0x411570
// 00411564  81fdffffff7f         cmp ebp, 0x7fffffff
// 0041156a  0f84cd000000         je 0x41163d
// 00411570  8b30                 mov esi, dword ptr [eax]
// 00411572  8b7804               mov edi, dword ptr [eax + 4]
// 00411575  83fefe               cmp esi, -2
// 00411578  750c                 jne 0x411586
// 0041157a  81ffffffff7f         cmp edi, 0x7fffffff
// 00411580  0f84b7000000         je 0x41163d
// 00411586  83fbff               cmp ebx, -1
// 00411589  7514                 jne 0x41159f
// 0041158b  81fdffffff7f         cmp ebp, 0x7fffffff
// 00411591  750c                 jne 0x41159f
// 00411593  3bf3                 cmp esi, ebx
// 00411595  7508                 jne 0x41159f
// 00411597  3bfd                 cmp edi, ebp
// 00411599  0f849e000000         je 0x41163d
// 0041159f  85db                 test ebx, ebx
// 004115a1  7514                 jne 0x4115b7
// 004115a3  81fd00000080         cmp ebp, 0x80000000
// 004115a9  750c                 jne 0x4115b7
// 004115ab  85f6                 test esi, esi
// 004115ad  7508                 jne 0x4115b7
// 004115af  3bfd                 cmp edi, ebp
// 004115b1  0f8486000000         je 0x41163d
// 004115b7  e8b4f9ffff           call 0x410f70
// 004115bc  84c0                 test al, al
// 004115be  741a                 je 0x4115da
// 004115c0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004115c4  8b11                 mov edx, dword ptr [ecx]
// 004115c6  8b442418             mov eax, dword ptr [esp + 0x18]
// 004115ca  8b4904               mov ecx, dword ptr [ecx + 4]
// 004115cd  5f                   pop edi
// 004115ce  5e                   pop esi
// 004115cf  5d                   pop ebp
// 004115d0  8910                 mov dword ptr [eax], edx
// 004115d2  894804               mov dword ptr [eax + 4], ecx
// 004115d5  5b                   pop ebx
// 004115d6  59                   pop ecx
// 004115d7  c20800               ret 8
// 004115da  57                   push edi
// 004115db  56                   push esi
// 004115dc  e84ff9ffff           call 0x410f30
// 004115e1  83c408               add esp, 8
// 004115e4  84c0                 test al, al
// 004115e6  7419                 je 0x411601
// 004115e8  8b442418             mov eax, dword ptr [esp + 0x18]
// 004115ec  5f                   pop edi
// 004115ed  5e                   pop esi
// 004115ee  5d                   pop ebp
// 004115ef  c70000000000         mov dword ptr [eax], 0
// 004115f5  c7400400000080       mov dword ptr [eax + 4], 0x80000000
// 004115fc  5b                   pop ebx
// 004115fd  59                   pop ecx
// 004115fe  c20800               ret 8
// 00411601  57                   push edi
// 00411602  56                   push esi
// 00411603  e848f9ffff           call 0x410f50
// 00411608  83c408               add esp, 8
// 0041160b  84c0                 test al, al
// 0041160d  7419                 je 0x411628
// 0041160f  8b442418             mov eax, dword ptr [esp + 0x18]
// 00411613  5f                   pop edi
// 00411614  5e                   pop esi
// 00411615  5d                   pop ebp
// 00411616  c700ffffffff         mov dword ptr [eax], 0xffffffff
// 0041161c  c74004ffffff7f       mov dword ptr [eax + 4], 0x7fffffff
// 00411623  5b                   pop ebx
// 00411624  59                   pop ecx
// 00411625  c20800               ret 8
// 00411628  8b442418             mov eax, dword ptr [esp + 0x18]
// 0041162c  2bde                 sub ebx, esi
// 0041162e  1bef                 sbb ebp, edi
// 00411630  5f                   pop edi
// 00411631  5e                   pop esi
// 00411632  896804               mov dword ptr [eax + 4], ebp
// 00411635  5d                   pop ebp
// 00411636  8918                 mov dword ptr [eax], ebx
// 00411638  5b                   pop ebx
// 00411639  59                   pop ecx
// 0041163a  c20800               ret 8
// 0041163d  8b442418             mov eax, dword ptr [esp + 0x18]
// 00411641  5f                   pop edi
// 00411642  5e                   pop esi
// 00411643  5d                   pop ebp
// 00411644  c700feffffff         mov dword ptr [eax], 0xfffffffe
// 0041164a  c74004ffffff7f       mov dword ptr [eax + 4], 0x7fffffff
// 00411651  5b                   pop ebx
// 00411652  59                   pop ecx
// 00411653  c20800               ret 8
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??$?G_J@?$int_adapter@_J@date_time@boost@@QBE?AV012@ABV012@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
