// from server: 100% by auto
// roc 2012-06 0040c5e0  unit: VAuthoringSettings::?$FactoryProduct  size: 358 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0040c5e0
//
// 0040c5e0  51                   push ecx
// 0040c5e1  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0040c5e5  53                   push ebx
// 0040c5e6  8b19                 mov ebx, dword ptr [ecx]
// 0040c5e8  55                   push ebp
// 0040c5e9  8b6904               mov ebp, dword ptr [ecx + 4]
// 0040c5ec  56                   push esi
// 0040c5ed  57                   push edi
// 0040c5ee  894c2410             mov dword ptr [esp + 0x10], ecx
// 0040c5f2  85db                 test ebx, ebx
// 0040c5f4  7508                 jne 0x40c5fe
// 0040c5f6  81fd00000080         cmp ebp, 0x80000000
// 0040c5fc  7451                 je 0x40c64f
// 0040c5fe  83fbff               cmp ebx, -1
// 0040c601  7508                 jne 0x40c60b
// 0040c603  81fdffffff7f         cmp ebp, 0x7fffffff
// 0040c609  7444                 je 0x40c64f
// 0040c60b  83fbfe               cmp ebx, -2
// 0040c60e  750c                 jne 0x40c61c
// 0040c610  81fdffffff7f         cmp ebp, 0x7fffffff
// 0040c616  0f8411010000         je 0x40c72d
// 0040c61c  8b30                 mov esi, dword ptr [eax]
// 0040c61e  8b7804               mov edi, dword ptr [eax + 4]
// 0040c621  85f6                 test esi, esi
// 0040c623  7508                 jne 0x40c62d
// 0040c625  81ff00000080         cmp edi, 0x80000000
// 0040c62b  7422                 je 0x40c64f
// 0040c62d  83feff               cmp esi, -1
// 0040c630  7508                 jne 0x40c63a
// 0040c632  81ffffffff7f         cmp edi, 0x7fffffff
// 0040c638  7415                 je 0x40c64f
// 0040c63a  83fefe               cmp esi, -2
// 0040c63d  0f85d5000000         jne 0x40c718
// 0040c643  81ffffffff7f         cmp edi, 0x7fffffff
// 0040c649  0f85c9000000         jne 0x40c718
// 0040c64f  83fbfe               cmp ebx, -2
// 0040c652  750c                 jne 0x40c660
// 0040c654  81fdffffff7f         cmp ebp, 0x7fffffff
// 0040c65a  0f84cd000000         je 0x40c72d
// 0040c660  8b30                 mov esi, dword ptr [eax]
// 0040c662  8b7804               mov edi, dword ptr [eax + 4]
// 0040c665  83fefe               cmp esi, -2
// 0040c668  750c                 jne 0x40c676
// 0040c66a  81ffffffff7f         cmp edi, 0x7fffffff
// 0040c670  0f84b7000000         je 0x40c72d
// 0040c676  83fbff               cmp ebx, -1
// 0040c679  7514                 jne 0x40c68f
// 0040c67b  81fdffffff7f         cmp ebp, 0x7fffffff
// 0040c681  750c                 jne 0x40c68f
// 0040c683  3bf3                 cmp esi, ebx
// 0040c685  7508                 jne 0x40c68f
// 0040c687  3bfd                 cmp edi, ebp
// 0040c689  0f849e000000         je 0x40c72d
// 0040c68f  85db                 test ebx, ebx
// 0040c691  7514                 jne 0x40c6a7
// 0040c693  81fd00000080         cmp ebp, 0x80000000
// 0040c699  750c                 jne 0x40c6a7
// 0040c69b  85f6                 test esi, esi
// 0040c69d  7508                 jne 0x40c6a7
// 0040c69f  3bfd                 cmp edi, ebp
// 0040c6a1  0f8486000000         je 0x40c72d
// 0040c6a7  e8e4f3ffff           call 0x40ba90
// 0040c6ac  84c0                 test al, al
// 0040c6ae  741a                 je 0x40c6ca
// 0040c6b0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0040c6b4  8b11                 mov edx, dword ptr [ecx]
// 0040c6b6  8b442418             mov eax, dword ptr [esp + 0x18]
// 0040c6ba  8b4904               mov ecx, dword ptr [ecx + 4]
// 0040c6bd  5f                   pop edi
// 0040c6be  5e                   pop esi
// 0040c6bf  5d                   pop ebp
// 0040c6c0  8910                 mov dword ptr [eax], edx
// 0040c6c2  894804               mov dword ptr [eax + 4], ecx
// 0040c6c5  5b                   pop ebx
// 0040c6c6  59                   pop ecx
// 0040c6c7  c20800               ret 8
// 0040c6ca  57                   push edi
// 0040c6cb  56                   push esi
// 0040c6cc  e87ff3ffff           call 0x40ba50
// 0040c6d1  83c408               add esp, 8
// 0040c6d4  84c0                 test al, al
// 0040c6d6  7419                 je 0x40c6f1
// 0040c6d8  8b442418             mov eax, dword ptr [esp + 0x18]
// 0040c6dc  5f                   pop edi
// 0040c6dd  5e                   pop esi
// 0040c6de  5d                   pop ebp
// 0040c6df  c70000000000         mov dword ptr [eax], 0
// 0040c6e5  c7400400000080       mov dword ptr [eax + 4], 0x80000000
// 0040c6ec  5b                   pop ebx
// 0040c6ed  59                   pop ecx
// 0040c6ee  c20800               ret 8
// 0040c6f1  57                   push edi
// 0040c6f2  56                   push esi
// 0040c6f3  e878f3ffff           call 0x40ba70
// 0040c6f8  83c408               add esp, 8
// 0040c6fb  84c0                 test al, al
// 0040c6fd  7419                 je 0x40c718
// 0040c6ff  8b442418             mov eax, dword ptr [esp + 0x18]
// 0040c703  5f                   pop edi
// 0040c704  5e                   pop esi
// 0040c705  5d                   pop ebp
// 0040c706  c700ffffffff         mov dword ptr [eax], 0xffffffff
// 0040c70c  c74004ffffff7f       mov dword ptr [eax + 4], 0x7fffffff
// 0040c713  5b                   pop ebx
// 0040c714  59                   pop ecx
// 0040c715  c20800               ret 8
// 0040c718  8b442418             mov eax, dword ptr [esp + 0x18]
// 0040c71c  2bde                 sub ebx, esi
// 0040c71e  1bef                 sbb ebp, edi
// 0040c720  5f                   pop edi
// 0040c721  5e                   pop esi
// 0040c722  896804               mov dword ptr [eax + 4], ebp
// 0040c725  5d                   pop ebp
// 0040c726  8918                 mov dword ptr [eax], ebx
// 0040c728  5b                   pop ebx
// 0040c729  59                   pop ecx
// 0040c72a  c20800               ret 8
// 0040c72d  8b442418             mov eax, dword ptr [esp + 0x18]
// 0040c731  5f                   pop edi
// 0040c732  5e                   pop esi
// 0040c733  5d                   pop ebp
// 0040c734  c700feffffff         mov dword ptr [eax], 0xfffffffe
// 0040c73a  c74004ffffff7f       mov dword ptr [eax + 4], 0x7fffffff
// 0040c741  5b                   pop ebx
// 0040c742  59                   pop ecx
// 0040c743  c20800               ret 8
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??$?G_J@?$int_adapter@_J@date_time@boost@@QBE?AV012@ABV012@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
