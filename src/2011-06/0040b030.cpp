// from server: 100% by auto
// roc 2011-06 0040b030  unit: VAuthoringSettings::?$FactoryProduct  size: 263 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0040b030
//
// 0040b030  8b442408             mov eax, dword ptr [esp + 8]
// 0040b034  53                   push ebx
// 0040b035  55                   push ebp
// 0040b036  56                   push esi
// 0040b037  8bd9                 mov ebx, ecx
// 0040b039  8b6b04               mov ebp, dword ptr [ebx + 4]
// 0040b03c  57                   push edi
// 0040b03d  8b3b                 mov edi, dword ptr [ebx]
// 0040b03f  85ff                 test edi, edi
// 0040b041  7508                 jne 0x40b04b
// 0040b043  81fd00000080         cmp ebp, 0x80000000
// 0040b049  7432                 je 0x40b07d
// 0040b04b  83ffff               cmp edi, -1
// 0040b04e  7508                 jne 0x40b058
// 0040b050  81fdffffff7f         cmp ebp, 0x7fffffff
// 0040b056  7425                 je 0x40b07d
// 0040b058  83fffe               cmp edi, -2
// 0040b05b  750c                 jne 0x40b069
// 0040b05d  81fdffffff7f         cmp ebp, 0x7fffffff
// 0040b063  0f84b6000000         je 0x40b11f
// 0040b069  8b30                 mov esi, dword ptr [eax]
// 0040b06b  85f6                 test esi, esi
// 0040b06d  740e                 je 0x40b07d
// 0040b06f  83feff               cmp esi, -1
// 0040b072  7409                 je 0x40b07d
// 0040b074  83fefe               cmp esi, -2
// 0040b077  0f858c000000         jne 0x40b109
// 0040b07d  83fffe               cmp edi, -2
// 0040b080  750c                 jne 0x40b08e
// 0040b082  81fdffffff7f         cmp ebp, 0x7fffffff
// 0040b088  0f8491000000         je 0x40b11f
// 0040b08e  8b30                 mov esi, dword ptr [eax]
// 0040b090  83fefe               cmp esi, -2
// 0040b093  0f8486000000         je 0x40b11f
// 0040b099  83ffff               cmp edi, -1
// 0040b09c  750c                 jne 0x40b0aa
// 0040b09e  81fdffffff7f         cmp ebp, 0x7fffffff
// 0040b0a4  7504                 jne 0x40b0aa
// 0040b0a6  85f6                 test esi, esi
// 0040b0a8  7475                 je 0x40b11f
// 0040b0aa  85ff                 test edi, edi
// 0040b0ac  750d                 jne 0x40b0bb
// 0040b0ae  81fd00000080         cmp ebp, 0x80000000
// 0040b0b4  7505                 jne 0x40b0bb
// 0040b0b6  83feff               cmp esi, -1
// 0040b0b9  7464                 je 0x40b11f
// 0040b0bb  e8c0f2ffff           call 0x40a380
// 0040b0c0  84c0                 test al, al
// 0040b0c2  7414                 je 0x40b0d8
// 0040b0c4  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040b0c8  8bcf                 mov ecx, edi
// 0040b0ca  5f                   pop edi
// 0040b0cb  5e                   pop esi
// 0040b0cc  8bd5                 mov edx, ebp
// 0040b0ce  5d                   pop ebp
// 0040b0cf  8908                 mov dword ptr [eax], ecx
// 0040b0d1  895004               mov dword ptr [eax + 4], edx
// 0040b0d4  5b                   pop ebx
// 0040b0d5  c20800               ret 8
// 0040b0d8  83feff               cmp esi, -1
// 0040b0db  7514                 jne 0x40b0f1
// 0040b0dd  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040b0e1  5f                   pop edi
// 0040b0e2  8930                 mov dword ptr [eax], esi
// 0040b0e4  5e                   pop esi
// 0040b0e5  5d                   pop ebp
// 0040b0e6  c74004ffffff7f       mov dword ptr [eax + 4], 0x7fffffff
// 0040b0ed  5b                   pop ebx
// 0040b0ee  c20800               ret 8
// 0040b0f1  85f6                 test esi, esi
// 0040b0f3  7514                 jne 0x40b109
// 0040b0f5  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040b0f9  5f                   pop edi
// 0040b0fa  8930                 mov dword ptr [eax], esi
// 0040b0fc  5e                   pop esi
// 0040b0fd  5d                   pop ebp
// 0040b0fe  c7400400000080       mov dword ptr [eax + 4], 0x80000000
// 0040b105  5b                   pop ebx
// 0040b106  c20800               ret 8
// 0040b109  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040b10d  33c9                 xor ecx, ecx
// 0040b10f  03f7                 add esi, edi
// 0040b111  5f                   pop edi
// 0040b112  8930                 mov dword ptr [eax], esi
// 0040b114  5e                   pop esi
// 0040b115  13cd                 adc ecx, ebp
// 0040b117  5d                   pop ebp
// 0040b118  894804               mov dword ptr [eax + 4], ecx
// 0040b11b  5b                   pop ebx
// 0040b11c  c20800               ret 8
// 0040b11f  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040b123  5f                   pop edi
// 0040b124  5e                   pop esi
// 0040b125  5d                   pop ebp
// 0040b126  c700feffffff         mov dword ptr [eax], 0xfffffffe
// 0040b12c  c74004ffffff7f       mov dword ptr [eax + 4], 0x7fffffff
// 0040b133  5b                   pop ebx
// 0040b134  c20800               ret 8
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??$?HK@?$int_adapter@_J@date_time@boost@@QBE?AV012@ABV?$int_adapter@K@12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
