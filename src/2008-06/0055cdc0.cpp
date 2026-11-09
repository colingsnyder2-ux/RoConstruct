// from server: 100% by auto
// roc 2008-06 0055cdc0  unit: RBX::MD5HasherImpl  size: 263 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055cdc0
//
// 0055cdc0  8b442408             mov eax, dword ptr [esp + 8]
// 0055cdc4  53                   push ebx
// 0055cdc5  55                   push ebp
// 0055cdc6  56                   push esi
// 0055cdc7  8bd9                 mov ebx, ecx
// 0055cdc9  8b6b04               mov ebp, dword ptr [ebx + 4]
// 0055cdcc  57                   push edi
// 0055cdcd  8b3b                 mov edi, dword ptr [ebx]
// 0055cdcf  85ff                 test edi, edi
// 0055cdd1  7508                 jne 0x55cddb
// 0055cdd3  81fd00000080         cmp ebp, 0x80000000
// 0055cdd9  7432                 je 0x55ce0d
// 0055cddb  83ffff               cmp edi, -1
// 0055cdde  7508                 jne 0x55cde8
// 0055cde0  81fdffffff7f         cmp ebp, 0x7fffffff
// 0055cde6  7425                 je 0x55ce0d
// 0055cde8  83fffe               cmp edi, -2
// 0055cdeb  750c                 jne 0x55cdf9
// 0055cded  81fdffffff7f         cmp ebp, 0x7fffffff
// 0055cdf3  0f84b6000000         je 0x55ceaf
// 0055cdf9  8b30                 mov esi, dword ptr [eax]
// 0055cdfb  85f6                 test esi, esi
// 0055cdfd  740e                 je 0x55ce0d
// 0055cdff  83feff               cmp esi, -1
// 0055ce02  7409                 je 0x55ce0d
// 0055ce04  83fefe               cmp esi, -2
// 0055ce07  0f858c000000         jne 0x55ce99
// 0055ce0d  83fffe               cmp edi, -2
// 0055ce10  750c                 jne 0x55ce1e
// 0055ce12  81fdffffff7f         cmp ebp, 0x7fffffff
// 0055ce18  0f8491000000         je 0x55ceaf
// 0055ce1e  8b30                 mov esi, dword ptr [eax]
// 0055ce20  83fefe               cmp esi, -2
// 0055ce23  0f8486000000         je 0x55ceaf
// 0055ce29  83ffff               cmp edi, -1
// 0055ce2c  750c                 jne 0x55ce3a
// 0055ce2e  81fdffffff7f         cmp ebp, 0x7fffffff
// 0055ce34  7504                 jne 0x55ce3a
// 0055ce36  85f6                 test esi, esi
// 0055ce38  7475                 je 0x55ceaf
// 0055ce3a  85ff                 test edi, edi
// 0055ce3c  750d                 jne 0x55ce4b
// 0055ce3e  81fd00000080         cmp ebp, 0x80000000
// 0055ce44  7505                 jne 0x55ce4b
// 0055ce46  83feff               cmp esi, -1
// 0055ce49  7464                 je 0x55ceaf
// 0055ce4b  e8f0f2ffff           call 0x55c140
// 0055ce50  84c0                 test al, al
// 0055ce52  7414                 je 0x55ce68
// 0055ce54  8b442414             mov eax, dword ptr [esp + 0x14]
// 0055ce58  8bcf                 mov ecx, edi
// 0055ce5a  5f                   pop edi
// 0055ce5b  5e                   pop esi
// 0055ce5c  8bd5                 mov edx, ebp
// 0055ce5e  5d                   pop ebp
// 0055ce5f  8908                 mov dword ptr [eax], ecx
// 0055ce61  895004               mov dword ptr [eax + 4], edx
// 0055ce64  5b                   pop ebx
// 0055ce65  c20800               ret 8
// 0055ce68  83feff               cmp esi, -1
// 0055ce6b  7514                 jne 0x55ce81
// 0055ce6d  8b442414             mov eax, dword ptr [esp + 0x14]
// 0055ce71  5f                   pop edi
// 0055ce72  8930                 mov dword ptr [eax], esi
// 0055ce74  5e                   pop esi
// 0055ce75  5d                   pop ebp
// 0055ce76  c74004ffffff7f       mov dword ptr [eax + 4], 0x7fffffff
// 0055ce7d  5b                   pop ebx
// 0055ce7e  c20800               ret 8
// 0055ce81  85f6                 test esi, esi
// 0055ce83  7514                 jne 0x55ce99
// 0055ce85  8b442414             mov eax, dword ptr [esp + 0x14]
// 0055ce89  5f                   pop edi
// 0055ce8a  8930                 mov dword ptr [eax], esi
// 0055ce8c  5e                   pop esi
// 0055ce8d  5d                   pop ebp
// 0055ce8e  c7400400000080       mov dword ptr [eax + 4], 0x80000000
// 0055ce95  5b                   pop ebx
// 0055ce96  c20800               ret 8
// 0055ce99  8b442414             mov eax, dword ptr [esp + 0x14]
// 0055ce9d  33c9                 xor ecx, ecx
// 0055ce9f  03f7                 add esi, edi
// 0055cea1  5f                   pop edi
// 0055cea2  8930                 mov dword ptr [eax], esi
// 0055cea4  5e                   pop esi
// 0055cea5  13cd                 adc ecx, ebp
// 0055cea7  5d                   pop ebp
// 0055cea8  894804               mov dword ptr [eax + 4], ecx
// 0055ceab  5b                   pop ebx
// 0055ceac  c20800               ret 8
// 0055ceaf  8b442414             mov eax, dword ptr [esp + 0x14]
// 0055ceb3  5f                   pop edi
// 0055ceb4  5e                   pop esi
// 0055ceb5  5d                   pop ebp
// 0055ceb6  c700feffffff         mov dword ptr [eax], 0xfffffffe
// 0055cebc  c74004ffffff7f       mov dword ptr [eax + 4], 0x7fffffff
// 0055cec3  5b                   pop ebx
// 0055cec4  c20800               ret 8
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??$?HK@?$int_adapter@_J@date_time@boost@@QBE?AV012@ABV?$int_adapter@K@12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
