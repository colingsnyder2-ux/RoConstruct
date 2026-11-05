// from server: 100% by auto
// roc 2010-06 004114e0  unit: CChildFrame  size: 263 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004114e0
//
// 004114e0  8b442408             mov eax, dword ptr [esp + 8]
// 004114e4  53                   push ebx
// 004114e5  55                   push ebp
// 004114e6  56                   push esi
// 004114e7  8bd9                 mov ebx, ecx
// 004114e9  8b6b04               mov ebp, dword ptr [ebx + 4]
// 004114ec  57                   push edi
// 004114ed  8b3b                 mov edi, dword ptr [ebx]
// 004114ef  85ff                 test edi, edi
// 004114f1  7508                 jne 0x4114fb
// 004114f3  81fd00000080         cmp ebp, 0x80000000
// 004114f9  7432                 je 0x41152d
// 004114fb  83ffff               cmp edi, -1
// 004114fe  7508                 jne 0x411508
// 00411500  81fdffffff7f         cmp ebp, 0x7fffffff
// 00411506  7425                 je 0x41152d
// 00411508  83fffe               cmp edi, -2
// 0041150b  750c                 jne 0x411519
// 0041150d  81fdffffff7f         cmp ebp, 0x7fffffff
// 00411513  0f84b6000000         je 0x4115cf
// 00411519  8b30                 mov esi, dword ptr [eax]
// 0041151b  85f6                 test esi, esi
// 0041151d  740e                 je 0x41152d
// 0041151f  83feff               cmp esi, -1
// 00411522  7409                 je 0x41152d
// 00411524  83fefe               cmp esi, -2
// 00411527  0f858c000000         jne 0x4115b9
// 0041152d  83fffe               cmp edi, -2
// 00411530  750c                 jne 0x41153e
// 00411532  81fdffffff7f         cmp ebp, 0x7fffffff
// 00411538  0f8491000000         je 0x4115cf
// 0041153e  8b30                 mov esi, dword ptr [eax]
// 00411540  83fefe               cmp esi, -2
// 00411543  0f8486000000         je 0x4115cf
// 00411549  83ffff               cmp edi, -1
// 0041154c  750c                 jne 0x41155a
// 0041154e  81fdffffff7f         cmp ebp, 0x7fffffff
// 00411554  7504                 jne 0x41155a
// 00411556  85f6                 test esi, esi
// 00411558  7475                 je 0x4115cf
// 0041155a  85ff                 test edi, edi
// 0041155c  750d                 jne 0x41156b
// 0041155e  81fd00000080         cmp ebp, 0x80000000
// 00411564  7505                 jne 0x41156b
// 00411566  83feff               cmp esi, -1
// 00411569  7464                 je 0x4115cf
// 0041156b  e850f9ffff           call 0x410ec0
// 00411570  84c0                 test al, al
// 00411572  7414                 je 0x411588
// 00411574  8b442414             mov eax, dword ptr [esp + 0x14]
// 00411578  8bcf                 mov ecx, edi
// 0041157a  5f                   pop edi
// 0041157b  5e                   pop esi
// 0041157c  8bd5                 mov edx, ebp
// 0041157e  5d                   pop ebp
// 0041157f  8908                 mov dword ptr [eax], ecx
// 00411581  895004               mov dword ptr [eax + 4], edx
// 00411584  5b                   pop ebx
// 00411585  c20800               ret 8
// 00411588  83feff               cmp esi, -1
// 0041158b  7514                 jne 0x4115a1
// 0041158d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00411591  5f                   pop edi
// 00411592  8930                 mov dword ptr [eax], esi
// 00411594  5e                   pop esi
// 00411595  5d                   pop ebp
// 00411596  c74004ffffff7f       mov dword ptr [eax + 4], 0x7fffffff
// 0041159d  5b                   pop ebx
// 0041159e  c20800               ret 8
// 004115a1  85f6                 test esi, esi
// 004115a3  7514                 jne 0x4115b9
// 004115a5  8b442414             mov eax, dword ptr [esp + 0x14]
// 004115a9  5f                   pop edi
// 004115aa  8930                 mov dword ptr [eax], esi
// 004115ac  5e                   pop esi
// 004115ad  5d                   pop ebp
// 004115ae  c7400400000080       mov dword ptr [eax + 4], 0x80000000
// 004115b5  5b                   pop ebx
// 004115b6  c20800               ret 8
// 004115b9  8b442414             mov eax, dword ptr [esp + 0x14]
// 004115bd  33c9                 xor ecx, ecx
// 004115bf  03f7                 add esi, edi
// 004115c1  5f                   pop edi
// 004115c2  8930                 mov dword ptr [eax], esi
// 004115c4  5e                   pop esi
// 004115c5  13cd                 adc ecx, ebp
// 004115c7  5d                   pop ebp
// 004115c8  894804               mov dword ptr [eax + 4], ecx
// 004115cb  5b                   pop ebx
// 004115cc  c20800               ret 8
// 004115cf  8b442414             mov eax, dword ptr [esp + 0x14]
// 004115d3  5f                   pop edi
// 004115d4  5e                   pop esi
// 004115d5  5d                   pop ebp
// 004115d6  c700feffffff         mov dword ptr [eax], 0xfffffffe
// 004115dc  c74004ffffff7f       mov dword ptr [eax + 4], 0x7fffffff
// 004115e3  5b                   pop ebx
// 004115e4  c20800               ret 8
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??$?HK@?$int_adapter@_J@date_time@boost@@QBE?AV012@ABV?$int_adapter@K@12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
