// from server: 100% by auto
// roc 2012-06 0040c7c0  unit: VAuthoringSettings::?$FactoryProduct  size: 263 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0040c7c0
//
// 0040c7c0  8b442408             mov eax, dword ptr [esp + 8]
// 0040c7c4  53                   push ebx
// 0040c7c5  55                   push ebp
// 0040c7c6  56                   push esi
// 0040c7c7  8bd9                 mov ebx, ecx
// 0040c7c9  8b6b04               mov ebp, dword ptr [ebx + 4]
// 0040c7cc  57                   push edi
// 0040c7cd  8b3b                 mov edi, dword ptr [ebx]
// 0040c7cf  85ff                 test edi, edi
// 0040c7d1  7508                 jne 0x40c7db
// 0040c7d3  81fd00000080         cmp ebp, 0x80000000
// 0040c7d9  7432                 je 0x40c80d
// 0040c7db  83ffff               cmp edi, -1
// 0040c7de  7508                 jne 0x40c7e8
// 0040c7e0  81fdffffff7f         cmp ebp, 0x7fffffff
// 0040c7e6  7425                 je 0x40c80d
// 0040c7e8  83fffe               cmp edi, -2
// 0040c7eb  750c                 jne 0x40c7f9
// 0040c7ed  81fdffffff7f         cmp ebp, 0x7fffffff
// 0040c7f3  0f84b6000000         je 0x40c8af
// 0040c7f9  8b30                 mov esi, dword ptr [eax]
// 0040c7fb  85f6                 test esi, esi
// 0040c7fd  740e                 je 0x40c80d
// 0040c7ff  83feff               cmp esi, -1
// 0040c802  7409                 je 0x40c80d
// 0040c804  83fefe               cmp esi, -2
// 0040c807  0f858c000000         jne 0x40c899
// 0040c80d  83fffe               cmp edi, -2
// 0040c810  750c                 jne 0x40c81e
// 0040c812  81fdffffff7f         cmp ebp, 0x7fffffff
// 0040c818  0f8491000000         je 0x40c8af
// 0040c81e  8b30                 mov esi, dword ptr [eax]
// 0040c820  83fefe               cmp esi, -2
// 0040c823  0f8486000000         je 0x40c8af
// 0040c829  83ffff               cmp edi, -1
// 0040c82c  750c                 jne 0x40c83a
// 0040c82e  81fdffffff7f         cmp ebp, 0x7fffffff
// 0040c834  7504                 jne 0x40c83a
// 0040c836  85f6                 test esi, esi
// 0040c838  7475                 je 0x40c8af
// 0040c83a  85ff                 test edi, edi
// 0040c83c  750d                 jne 0x40c84b
// 0040c83e  81fd00000080         cmp ebp, 0x80000000
// 0040c844  7505                 jne 0x40c84b
// 0040c846  83feff               cmp esi, -1
// 0040c849  7464                 je 0x40c8af
// 0040c84b  e840f2ffff           call 0x40ba90
// 0040c850  84c0                 test al, al
// 0040c852  7414                 je 0x40c868
// 0040c854  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040c858  8bcf                 mov ecx, edi
// 0040c85a  5f                   pop edi
// 0040c85b  5e                   pop esi
// 0040c85c  8bd5                 mov edx, ebp
// 0040c85e  5d                   pop ebp
// 0040c85f  8908                 mov dword ptr [eax], ecx
// 0040c861  895004               mov dword ptr [eax + 4], edx
// 0040c864  5b                   pop ebx
// 0040c865  c20800               ret 8
// 0040c868  83feff               cmp esi, -1
// 0040c86b  7514                 jne 0x40c881
// 0040c86d  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040c871  5f                   pop edi
// 0040c872  8930                 mov dword ptr [eax], esi
// 0040c874  5e                   pop esi
// 0040c875  5d                   pop ebp
// 0040c876  c74004ffffff7f       mov dword ptr [eax + 4], 0x7fffffff
// 0040c87d  5b                   pop ebx
// 0040c87e  c20800               ret 8
// 0040c881  85f6                 test esi, esi
// 0040c883  7514                 jne 0x40c899
// 0040c885  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040c889  5f                   pop edi
// 0040c88a  8930                 mov dword ptr [eax], esi
// 0040c88c  5e                   pop esi
// 0040c88d  5d                   pop ebp
// 0040c88e  c7400400000080       mov dword ptr [eax + 4], 0x80000000
// 0040c895  5b                   pop ebx
// 0040c896  c20800               ret 8
// 0040c899  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040c89d  33c9                 xor ecx, ecx
// 0040c89f  03f7                 add esi, edi
// 0040c8a1  5f                   pop edi
// 0040c8a2  8930                 mov dword ptr [eax], esi
// 0040c8a4  5e                   pop esi
// 0040c8a5  13cd                 adc ecx, ebp
// 0040c8a7  5d                   pop ebp
// 0040c8a8  894804               mov dword ptr [eax + 4], ecx
// 0040c8ab  5b                   pop ebx
// 0040c8ac  c20800               ret 8
// 0040c8af  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040c8b3  5f                   pop edi
// 0040c8b4  5e                   pop esi
// 0040c8b5  5d                   pop ebp
// 0040c8b6  c700feffffff         mov dword ptr [eax], 0xfffffffe
// 0040c8bc  c74004ffffff7f       mov dword ptr [eax + 4], 0x7fffffff
// 0040c8c3  5b                   pop ebx
// 0040c8c4  c20800               ret 8
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??$?HK@?$int_adapter@_J@date_time@boost@@QBE?AV012@ABV?$int_adapter@K@12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
