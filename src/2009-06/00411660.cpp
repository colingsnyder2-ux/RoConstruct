// from server: 100% by auto
// roc 2009-06 00411660  unit: CChildFrame  size: 263 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00411660
//
// 00411660  8b442408             mov eax, dword ptr [esp + 8]
// 00411664  53                   push ebx
// 00411665  55                   push ebp
// 00411666  56                   push esi
// 00411667  8bd9                 mov ebx, ecx
// 00411669  8b6b04               mov ebp, dword ptr [ebx + 4]
// 0041166c  57                   push edi
// 0041166d  8b3b                 mov edi, dword ptr [ebx]
// 0041166f  85ff                 test edi, edi
// 00411671  7508                 jne 0x41167b
// 00411673  81fd00000080         cmp ebp, 0x80000000
// 00411679  7432                 je 0x4116ad
// 0041167b  83ffff               cmp edi, -1
// 0041167e  7508                 jne 0x411688
// 00411680  81fdffffff7f         cmp ebp, 0x7fffffff
// 00411686  7425                 je 0x4116ad
// 00411688  83fffe               cmp edi, -2
// 0041168b  750c                 jne 0x411699
// 0041168d  81fdffffff7f         cmp ebp, 0x7fffffff
// 00411693  0f84b6000000         je 0x41174f
// 00411699  8b30                 mov esi, dword ptr [eax]
// 0041169b  85f6                 test esi, esi
// 0041169d  740e                 je 0x4116ad
// 0041169f  83feff               cmp esi, -1
// 004116a2  7409                 je 0x4116ad
// 004116a4  83fefe               cmp esi, -2
// 004116a7  0f858c000000         jne 0x411739
// 004116ad  83fffe               cmp edi, -2
// 004116b0  750c                 jne 0x4116be
// 004116b2  81fdffffff7f         cmp ebp, 0x7fffffff
// 004116b8  0f8491000000         je 0x41174f
// 004116be  8b30                 mov esi, dword ptr [eax]
// 004116c0  83fefe               cmp esi, -2
// 004116c3  0f8486000000         je 0x41174f
// 004116c9  83ffff               cmp edi, -1
// 004116cc  750c                 jne 0x4116da
// 004116ce  81fdffffff7f         cmp ebp, 0x7fffffff
// 004116d4  7504                 jne 0x4116da
// 004116d6  85f6                 test esi, esi
// 004116d8  7475                 je 0x41174f
// 004116da  85ff                 test edi, edi
// 004116dc  750d                 jne 0x4116eb
// 004116de  81fd00000080         cmp ebp, 0x80000000
// 004116e4  7505                 jne 0x4116eb
// 004116e6  83feff               cmp esi, -1
// 004116e9  7464                 je 0x41174f
// 004116eb  e880f8ffff           call 0x410f70
// 004116f0  84c0                 test al, al
// 004116f2  7414                 je 0x411708
// 004116f4  8b442414             mov eax, dword ptr [esp + 0x14]
// 004116f8  8bcf                 mov ecx, edi
// 004116fa  5f                   pop edi
// 004116fb  5e                   pop esi
// 004116fc  8bd5                 mov edx, ebp
// 004116fe  5d                   pop ebp
// 004116ff  8908                 mov dword ptr [eax], ecx
// 00411701  895004               mov dword ptr [eax + 4], edx
// 00411704  5b                   pop ebx
// 00411705  c20800               ret 8
// 00411708  83feff               cmp esi, -1
// 0041170b  7514                 jne 0x411721
// 0041170d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00411711  5f                   pop edi
// 00411712  8930                 mov dword ptr [eax], esi
// 00411714  5e                   pop esi
// 00411715  5d                   pop ebp
// 00411716  c74004ffffff7f       mov dword ptr [eax + 4], 0x7fffffff
// 0041171d  5b                   pop ebx
// 0041171e  c20800               ret 8
// 00411721  85f6                 test esi, esi
// 00411723  7514                 jne 0x411739
// 00411725  8b442414             mov eax, dword ptr [esp + 0x14]
// 00411729  5f                   pop edi
// 0041172a  8930                 mov dword ptr [eax], esi
// 0041172c  5e                   pop esi
// 0041172d  5d                   pop ebp
// 0041172e  c7400400000080       mov dword ptr [eax + 4], 0x80000000
// 00411735  5b                   pop ebx
// 00411736  c20800               ret 8
// 00411739  8b442414             mov eax, dword ptr [esp + 0x14]
// 0041173d  33c9                 xor ecx, ecx
// 0041173f  03f7                 add esi, edi
// 00411741  5f                   pop edi
// 00411742  8930                 mov dword ptr [eax], esi
// 00411744  5e                   pop esi
// 00411745  13cd                 adc ecx, ebp
// 00411747  5d                   pop ebp
// 00411748  894804               mov dword ptr [eax + 4], ecx
// 0041174b  5b                   pop ebx
// 0041174c  c20800               ret 8
// 0041174f  8b442414             mov eax, dword ptr [esp + 0x14]
// 00411753  5f                   pop edi
// 00411754  5e                   pop esi
// 00411755  5d                   pop ebp
// 00411756  c700feffffff         mov dword ptr [eax], 0xfffffffe
// 0041175c  c74004ffffff7f       mov dword ptr [eax + 4], 0x7fffffff
// 00411763  5b                   pop ebx
// 00411764  c20800               ret 8
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??$?HK@?$int_adapter@_J@date_time@boost@@QBE?AV012@ABV?$int_adapter@K@12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
