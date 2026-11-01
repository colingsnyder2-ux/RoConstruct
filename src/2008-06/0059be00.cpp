// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 0059be00  unit: RBX::PartInstance  size: 328 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0059be00
//
// 0059be00  55                   push ebp
// 0059be01  8bec                 mov ebp, esp
// 0059be03  6aff                 push -1
// 0059be05  6810267d00           push 0x7d2610
// 0059be0a  64a100000000         mov eax, dword ptr fs:[0]
// 0059be10  50                   push eax
// 0059be11  64892500000000       mov dword ptr fs:[0], esp
// 0059be18  83ec14               sub esp, 0x14
// 0059be1b  53                   push ebx
// 0059be1c  56                   push esi
// 0059be1d  8bf1                 mov esi, ecx
// 0059be1f  8b560c               mov edx, dword ptr [esi + 0xc]
// 0059be22  57                   push edi
// 0059be23  8965f0               mov dword ptr [ebp - 0x10], esp
// 0059be26  8975e8               mov dword ptr [ebp - 0x18], esi
// 0059be29  85d2                 test edx, edx
// 0059be2b  7504                 jne 0x59be31
// 0059be2d  33ff                 xor edi, edi
// 0059be2f  eb08                 jmp 0x59be39
// 0059be31  8b7e14               mov edi, dword ptr [esi + 0x14]
// 0059be34  2bfa                 sub edi, edx
// 0059be36  c1ff03               sar edi, 3
// 0059be39  8b5d10               mov ebx, dword ptr [ebp + 0x10]
// 0059be3c  85db                 test ebx, ebx
// 0059be3e  0f8475020000         je 0x59c0b9
// 0059be44  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0059be47  8bc1                 mov eax, ecx
// 0059be49  2bc2                 sub eax, edx
// 0059be4b  c1f803               sar eax, 3
// 0059be4e  baffffff1f           mov edx, 0x1fffffff
// 0059be53  2bd0                 sub edx, eax
// 0059be55  3bd3                 cmp edx, ebx
// 0059be57  7305                 jae 0x59be5e
// 0059be59  e8e2aef2ff           call 0x4c6d40
// 0059be5e  03c3                 add eax, ebx
// 0059be60  3bf8                 cmp edi, eax
// 0059be62  0f8302010000         jae 0x59bf6a
// 0059be68  8bcf                 mov ecx, edi
// 0059be6a  d1e9                 shr ecx, 1
// 0059be6c  baffffff1f           mov edx, 0x1fffffff
// 0059be71  2bd1                 sub edx, ecx
// 0059be73  3bd7                 cmp edx, edi
// 0059be75  7304                 jae 0x59be7b
// 0059be77  33ff                 xor edi, edi
// 0059be79  eb02                 jmp 0x59be7d
// 0059be7b  03f9                 add edi, ecx
// 0059be7d  3bf8                 cmp edi, eax
// 0059be7f  7302                 jae 0x59be83
// 0059be81  8bf8                 mov edi, eax
// 0059be83  6a00                 push 0
// 0059be85  57                   push edi
// 0059be86  e8b53e0d00           call 0x66fd40
// 0059be8b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0059be8e  c645e400             mov byte ptr [ebp - 0x1c], 0
// 0059be92  8b55e4               mov edx, dword ptr [ebp - 0x1c]
// 0059be95  52                   push edx
// 0059be96  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0059be99  52                   push edx
// 0059be9a  8d5608               lea edx, [esi + 8]
// 0059be9d  52                   push edx
// 0059be9e  50                   push eax
// 0059be9f  8945ec               mov dword ptr [ebp - 0x14], eax
// 0059bea2  894510               mov dword ptr [ebp + 0x10], eax
// 0059bea5  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0059bea8  50                   push eax
// 0059bea9  51                   push ecx
// 0059beaa  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0059beb1  e8eaeaffff           call 0x59a9a0
// 0059beb6  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 0059beb9  83c420               add esp, 0x20
// 0059bebc  51                   push ecx
// 0059bebd  53                   push ebx
// 0059bebe  50                   push eax
// 0059bebf  8bce                 mov ecx, esi
// 0059bec1  894510               mov dword ptr [ebp + 0x10], eax
// 0059bec4  e867faffff           call 0x59b930
// 0059bec9  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0059becc  c6451400             mov byte ptr [ebp + 0x14], 0
// 0059bed0  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0059bed3  52                   push edx
// 0059bed4  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0059bed7  52                   push edx
// 0059bed8  8d5608               lea edx, [esi + 8]
// 0059bedb  52                   push edx
// 0059bedc  50                   push eax
// 0059bedd  894510               mov dword ptr [ebp + 0x10], eax
// 0059bee0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0059bee3  51                   push ecx
// 0059bee4  50                   push eax
// 0059bee5  e8b6eaffff           call 0x59a9a0
// 0059beea  8b460c               mov eax, dword ptr [esi + 0xc]
// 0059beed  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0059bef0  2bc8                 sub ecx, eax
// 0059bef2  c1f903               sar ecx, 3
// 0059bef5  83c418               add esp, 0x18
// 0059bef8  03d9                 add ebx, ecx
// 0059befa  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 0059bf01  85c0                 test eax, eax
// 0059bf03  741e                 je 0x59bf23
// 0059bf05  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0059bf08  52                   push edx
// 0059bf09  8d4e08               lea ecx, [esi + 8]
// 0059bf0c  51                   push ecx
// 0059bf0d  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0059bf10  51                   push ecx
// 0059bf11  50                   push eax
// 0059bf12  e87944ffff           call 0x590390
// 0059bf17  8b560c               mov edx, dword ptr [esi + 0xc]
// 0059bf1a  52                   push edx
// 0059bf1b  e85a471000           call 0x6a067a
// 0059bf20  83c414               add esp, 0x14
// 0059bf23  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 0059bf26  8d0cf8               lea ecx, [eax + edi*8]
// 0059bf29  8d14d8               lea edx, [eax + ebx*8]
// 0059bf2c  894e14               mov dword ptr [esi + 0x14], ecx
// 0059bf2f  895610               mov dword ptr [esi + 0x10], edx
// 0059bf32  89460c               mov dword ptr [esi + 0xc], eax
// 0059bf35  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0059bf38  64890d00000000       mov dword ptr fs:[0], ecx
// 0059bf3f  5f                   pop edi
// 0059bf40  5e                   pop esi
// 0059bf41  5b                   pop ebx
// 0059bf42  8be5                 mov esp, ebp
// 0059bf44  5d                   pop ebp
// 0059bf45  c21000               ret 0x10
// library templates-boost-1_34_1/vector_wp.cpp (function ?_Insert_n@?$vector@V?$weak_ptr@UT@@@boost@@V?$allocator@V?$weak_ptr@UT@@@boost@@@std@@@std@@IAEXV?$_Vector_const_iterator@V?$weak_ptr@UT@@@boost@@V?$allocator@V?$weak_ptr@UT@@@boost@@@std@@@2@IABV?$weak_ptr@UT@@@boost@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 vector_wp.cpp
