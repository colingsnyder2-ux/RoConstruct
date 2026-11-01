// from server: 100% by auto
// roc 2009-12 00411200  unit: CChildFrame  size: 263 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00411200
//
// 00411200  8b442408             mov eax, dword ptr [esp + 8]
// 00411204  53                   push ebx
// 00411205  55                   push ebp
// 00411206  56                   push esi
// 00411207  8bd9                 mov ebx, ecx
// 00411209  8b6b04               mov ebp, dword ptr [ebx + 4]
// 0041120c  57                   push edi
// 0041120d  8b3b                 mov edi, dword ptr [ebx]
// 0041120f  85ff                 test edi, edi
// 00411211  7508                 jne 0x41121b
// 00411213  81fd00000080         cmp ebp, 0x80000000
// 00411219  7432                 je 0x41124d
// 0041121b  83ffff               cmp edi, -1
// 0041121e  7508                 jne 0x411228
// 00411220  81fdffffff7f         cmp ebp, 0x7fffffff
// 00411226  7425                 je 0x41124d
// 00411228  83fffe               cmp edi, -2
// 0041122b  750c                 jne 0x411239
// 0041122d  81fdffffff7f         cmp ebp, 0x7fffffff
// 00411233  0f84b6000000         je 0x4112ef
// 00411239  8b30                 mov esi, dword ptr [eax]
// 0041123b  85f6                 test esi, esi
// 0041123d  740e                 je 0x41124d
// 0041123f  83feff               cmp esi, -1
// 00411242  7409                 je 0x41124d
// 00411244  83fefe               cmp esi, -2
// 00411247  0f858c000000         jne 0x4112d9
// 0041124d  83fffe               cmp edi, -2
// 00411250  750c                 jne 0x41125e
// 00411252  81fdffffff7f         cmp ebp, 0x7fffffff
// 00411258  0f8491000000         je 0x4112ef
// 0041125e  8b30                 mov esi, dword ptr [eax]
// 00411260  83fefe               cmp esi, -2
// 00411263  0f8486000000         je 0x4112ef
// 00411269  83ffff               cmp edi, -1
// 0041126c  750c                 jne 0x41127a
// 0041126e  81fdffffff7f         cmp ebp, 0x7fffffff
// 00411274  7504                 jne 0x41127a
// 00411276  85f6                 test esi, esi
// 00411278  7475                 je 0x4112ef
// 0041127a  85ff                 test edi, edi
// 0041127c  750d                 jne 0x41128b
// 0041127e  81fd00000080         cmp ebp, 0x80000000
// 00411284  7505                 jne 0x41128b
// 00411286  83feff               cmp esi, -1
// 00411289  7464                 je 0x4112ef
// 0041128b  e860f9ffff           call 0x410bf0
// 00411290  84c0                 test al, al
// 00411292  7414                 je 0x4112a8
// 00411294  8b442414             mov eax, dword ptr [esp + 0x14]
// 00411298  8bcf                 mov ecx, edi
// 0041129a  5f                   pop edi
// 0041129b  5e                   pop esi
// 0041129c  8bd5                 mov edx, ebp
// 0041129e  5d                   pop ebp
// 0041129f  8908                 mov dword ptr [eax], ecx
// 004112a1  895004               mov dword ptr [eax + 4], edx
// 004112a4  5b                   pop ebx
// 004112a5  c20800               ret 8
// 004112a8  83feff               cmp esi, -1
// 004112ab  7514                 jne 0x4112c1
// 004112ad  8b442414             mov eax, dword ptr [esp + 0x14]
// 004112b1  5f                   pop edi
// 004112b2  8930                 mov dword ptr [eax], esi
// 004112b4  5e                   pop esi
// 004112b5  5d                   pop ebp
// 004112b6  c74004ffffff7f       mov dword ptr [eax + 4], 0x7fffffff
// 004112bd  5b                   pop ebx
// 004112be  c20800               ret 8
// 004112c1  85f6                 test esi, esi
// 004112c3  7514                 jne 0x4112d9
// 004112c5  8b442414             mov eax, dword ptr [esp + 0x14]
// 004112c9  5f                   pop edi
// 004112ca  8930                 mov dword ptr [eax], esi
// 004112cc  5e                   pop esi
// 004112cd  5d                   pop ebp
// 004112ce  c7400400000080       mov dword ptr [eax + 4], 0x80000000
// 004112d5  5b                   pop ebx
// 004112d6  c20800               ret 8
// 004112d9  8b442414             mov eax, dword ptr [esp + 0x14]
// 004112dd  33c9                 xor ecx, ecx
// 004112df  03f7                 add esi, edi
// 004112e1  5f                   pop edi
// 004112e2  8930                 mov dword ptr [eax], esi
// 004112e4  5e                   pop esi
// 004112e5  13cd                 adc ecx, ebp
// 004112e7  5d                   pop ebp
// 004112e8  894804               mov dword ptr [eax + 4], ecx
// 004112eb  5b                   pop ebx
// 004112ec  c20800               ret 8
// 004112ef  8b442414             mov eax, dword ptr [esp + 0x14]
// 004112f3  5f                   pop edi
// 004112f4  5e                   pop esi
// 004112f5  5d                   pop ebp
// 004112f6  c700feffffff         mov dword ptr [eax], 0xfffffffe
// 004112fc  c74004ffffff7f       mov dword ptr [eax + 4], 0x7fffffff
// 00411303  5b                   pop ebx
// 00411304  c20800               ret 8
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??$?HK@?$int_adapter@_J@date_time@boost@@QBE?AV012@ABV?$int_adapter@K@12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
