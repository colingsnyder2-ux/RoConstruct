// from server: 100% by auto
// roc 2010-06 0081dd10  unit: CXTPPropertyGridView  size: 202 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081dd10
//
// 0081dd10  83ec1c               sub esp, 0x1c
// 0081dd13  57                   push edi
// 0081dd14  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0081dd18  894c2404             mov dword ptr [esp + 4], ecx
// 0081dd1c  85ff                 test edi, edi
// 0081dd1e  750c                 jne 0x81dd2c
// 0081dd20  b857000780           mov eax, 0x80070057
// 0081dd25  5f                   pop edi
// 0081dd26  83c41c               add esp, 0x1c
// 0081dd29  c20c00               ret 0xc
// 0081dd2c  56                   push esi
// 0081dd2d  33c0                 xor eax, eax
// 0081dd2f  8d71ac               lea esi, [ecx - 0x54]
// 0081dd32  668907               mov word ptr [edi], ax
// 0081dd35  85f6                 test esi, esi
// 0081dd37  7405                 je 0x81dd3e
// 0081dd39  394620               cmp dword ptr [esi + 0x20], eax
// 0081dd3c  750d                 jne 0x81dd4b
// 0081dd3e  5e                   pop esi
// 0081dd3f  b801000000           mov eax, 1
// 0081dd44  5f                   pop edi
// 0081dd45  83c41c               add esp, 0x1c
// 0081dd48  c20c00               ret 0xc
// 0081dd4b  53                   push ebx
// 0081dd4c  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 0081dd50  55                   push ebp
// 0081dd51  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 0081dd55  56                   push esi
// 0081dd56  8d4c2420             lea ecx, [esp + 0x20]
// 0081dd5a  e85115feff           call 0x7ff2b0
// 0081dd5f  55                   push ebp
// 0081dd60  53                   push ebx
// 0081dd61  50                   push eax
// 0081dd62  ff15e0bb9e00         call dword ptr [0x9ebbe0]
// 0081dd68  85c0                 test eax, eax
// 0081dd6a  750f                 jne 0x81dd7b
// 0081dd6c  5d                   pop ebp
// 0081dd6d  5b                   pop ebx
// 0081dd6e  5e                   pop esi
// 0081dd6f  b801000000           mov eax, 1
// 0081dd74  5f                   pop edi
// 0081dd75  83c41c               add esp, 0x1c
// 0081dd78  c20c00               ret 0xc
// 0081dd7b  8b442410             mov eax, dword ptr [esp + 0x10]
// 0081dd7f  b903000000           mov ecx, 3
// 0081dd84  8d542414             lea edx, [esp + 0x14]
// 0081dd88  66890f               mov word ptr [edi], cx
// 0081dd8b  c7470800000000       mov dword ptr [edi + 8], 0
// 0081dd92  8b48cc               mov ecx, dword ptr [eax - 0x34]
// 0081dd95  52                   push edx
// 0081dd96  51                   push ecx
// 0081dd97  895c241c             mov dword ptr [esp + 0x1c], ebx
// 0081dd9b  896c2420             mov dword ptr [esp + 0x20], ebp
// 0081dd9f  ff1578bc9e00         call dword ptr [0x9ebc78]
// 0081dda5  8b542418             mov edx, dword ptr [esp + 0x18]
// 0081dda9  8b442414             mov eax, dword ptr [esp + 0x14]
// 0081ddad  52                   push edx
// 0081ddae  50                   push eax
// 0081ddaf  8bce                 mov ecx, esi
// 0081ddb1  e8eaecffff           call 0x81caa0
// 0081ddb6  85c0                 test eax, eax
// 0081ddb8  7414                 je 0x81ddce
// 0081ddba  b909000000           mov ecx, 9
// 0081ddbf  66890f               mov word ptr [edi], cx
// 0081ddc2  6a01                 push 1
// 0081ddc4  8bc8                 mov ecx, eax
// 0081ddc6  e8a7ef1500           call 0x97cd72
// 0081ddcb  894708               mov dword ptr [edi + 8], eax
// 0081ddce  5d                   pop ebp
// 0081ddcf  5b                   pop ebx
// 0081ddd0  5e                   pop esi
// 0081ddd1  33c0                 xor eax, eax
// 0081ddd3  5f                   pop edi
// 0081ddd4  83c41c               add esp, 0x1c
// 0081ddd7  c20c00               ret 0xc
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?AccessibleHitTest@CXTPPropertyGridView@@MAEJJJPAUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
