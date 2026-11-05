// from server: 100% by auto
// roc 2007-08 00535d30  unit: std::logic_error  size: 263 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00535d30
//
// 00535d30  8b442408             mov eax, dword ptr [esp + 8]
// 00535d34  53                   push ebx
// 00535d35  55                   push ebp
// 00535d36  56                   push esi
// 00535d37  8bd9                 mov ebx, ecx
// 00535d39  8b6b04               mov ebp, dword ptr [ebx + 4]
// 00535d3c  57                   push edi
// 00535d3d  8b3b                 mov edi, dword ptr [ebx]
// 00535d3f  85ff                 test edi, edi
// 00535d41  7508                 jne 0x535d4b
// 00535d43  81fd00000080         cmp ebp, 0x80000000
// 00535d49  7432                 je 0x535d7d
// 00535d4b  83ffff               cmp edi, -1
// 00535d4e  7508                 jne 0x535d58
// 00535d50  81fdffffff7f         cmp ebp, 0x7fffffff
// 00535d56  7425                 je 0x535d7d
// 00535d58  83fffe               cmp edi, -2
// 00535d5b  750c                 jne 0x535d69
// 00535d5d  81fdffffff7f         cmp ebp, 0x7fffffff
// 00535d63  0f84b6000000         je 0x535e1f
// 00535d69  8b30                 mov esi, dword ptr [eax]
// 00535d6b  85f6                 test esi, esi
// 00535d6d  740e                 je 0x535d7d
// 00535d6f  83feff               cmp esi, -1
// 00535d72  7409                 je 0x535d7d
// 00535d74  83fefe               cmp esi, -2
// 00535d77  0f858c000000         jne 0x535e09
// 00535d7d  83fffe               cmp edi, -2
// 00535d80  750c                 jne 0x535d8e
// 00535d82  81fdffffff7f         cmp ebp, 0x7fffffff
// 00535d88  0f8491000000         je 0x535e1f
// 00535d8e  8b30                 mov esi, dword ptr [eax]
// 00535d90  83fefe               cmp esi, -2
// 00535d93  0f8486000000         je 0x535e1f
// 00535d99  83ffff               cmp edi, -1
// 00535d9c  750c                 jne 0x535daa
// 00535d9e  81fdffffff7f         cmp ebp, 0x7fffffff
// 00535da4  7504                 jne 0x535daa
// 00535da6  85f6                 test esi, esi
// 00535da8  7475                 je 0x535e1f
// 00535daa  85ff                 test edi, edi
// 00535dac  750d                 jne 0x535dbb
// 00535dae  81fd00000080         cmp ebp, 0x80000000
// 00535db4  7505                 jne 0x535dbb
// 00535db6  83feff               cmp esi, -1
// 00535db9  7464                 je 0x535e1f
// 00535dbb  e850e8ffff           call 0x534610
// 00535dc0  84c0                 test al, al
// 00535dc2  7414                 je 0x535dd8
// 00535dc4  8b442414             mov eax, dword ptr [esp + 0x14]
// 00535dc8  8bcf                 mov ecx, edi
// 00535dca  5f                   pop edi
// 00535dcb  5e                   pop esi
// 00535dcc  8bd5                 mov edx, ebp
// 00535dce  5d                   pop ebp
// 00535dcf  8908                 mov dword ptr [eax], ecx
// 00535dd1  895004               mov dword ptr [eax + 4], edx
// 00535dd4  5b                   pop ebx
// 00535dd5  c20800               ret 8
// 00535dd8  83feff               cmp esi, -1
// 00535ddb  7514                 jne 0x535df1
// 00535ddd  8b442414             mov eax, dword ptr [esp + 0x14]
// 00535de1  5f                   pop edi
// 00535de2  8930                 mov dword ptr [eax], esi
// 00535de4  5e                   pop esi
// 00535de5  5d                   pop ebp
// 00535de6  c74004ffffff7f       mov dword ptr [eax + 4], 0x7fffffff
// 00535ded  5b                   pop ebx
// 00535dee  c20800               ret 8
// 00535df1  85f6                 test esi, esi
// 00535df3  7514                 jne 0x535e09
// 00535df5  8b442414             mov eax, dword ptr [esp + 0x14]
// 00535df9  5f                   pop edi
// 00535dfa  8930                 mov dword ptr [eax], esi
// 00535dfc  5e                   pop esi
// 00535dfd  5d                   pop ebp
// 00535dfe  c7400400000080       mov dword ptr [eax + 4], 0x80000000
// 00535e05  5b                   pop ebx
// 00535e06  c20800               ret 8
// 00535e09  8b442414             mov eax, dword ptr [esp + 0x14]
// 00535e0d  33c9                 xor ecx, ecx
// 00535e0f  03f7                 add esi, edi
// 00535e11  5f                   pop edi
// 00535e12  8930                 mov dword ptr [eax], esi
// 00535e14  5e                   pop esi
// 00535e15  13cd                 adc ecx, ebp
// 00535e17  5d                   pop ebp
// 00535e18  894804               mov dword ptr [eax + 4], ecx
// 00535e1b  5b                   pop ebx
// 00535e1c  c20800               ret 8
// 00535e1f  8b442414             mov eax, dword ptr [esp + 0x14]
// 00535e23  5f                   pop edi
// 00535e24  5e                   pop esi
// 00535e25  5d                   pop ebp
// 00535e26  c700feffffff         mov dword ptr [eax], 0xfffffffe
// 00535e2c  c74004ffffff7f       mov dword ptr [eax + 4], 0x7fffffff
// 00535e33  5b                   pop ebx
// 00535e34  c20800               ret 8
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??$?HK@?$int_adapter@_J@date_time@boost@@QBE?AV012@ABV?$int_adapter@K@12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
