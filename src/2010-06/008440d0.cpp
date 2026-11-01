// from server: 100% by auto
// roc 2010-06 008440d0  unit: CXTPShortcutManager  size: 215 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008440d0
//
// 008440d0  83ec10               sub esp, 0x10
// 008440d3  56                   push esi
// 008440d4  57                   push edi
// 008440d5  8bf1                 mov esi, ecx
// 008440d7  33ff                 xor edi, edi
// 008440d9  897e08               mov dword ptr [esi + 8], edi
// 008440dc  e87d3ef6ff           call 0x7a7f5e
// 008440e1  b07f                 mov al, 0x7f
// 008440e3  88442408             mov byte ptr [esp + 8], al
// 008440e7  88442409             mov byte ptr [esp + 9], al
// 008440eb  8844240a             mov byte ptr [esp + 0xa], al
// 008440ef  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008440f3  897c240c             mov dword ptr [esp + 0xc], edi
// 008440f7  3bc7                 cmp eax, edi
// 008440f9  750a                 jne 0x844105
// 008440fb  5f                   pop edi
// 008440fc  33c0                 xor eax, eax
// 008440fe  5e                   pop esi
// 008440ff  83c410               add esp, 0x10
// 00844102  c20400               ret 4
// 00844105  53                   push ebx
// 00844106  8d4c240c             lea ecx, [esp + 0xc]
// 0084410a  51                   push ecx
// 0084410b  8d542424             lea edx, [esp + 0x24]
// 0084410f  52                   push edx
// 00844110  8d4c2420             lea ecx, [esp + 0x20]
// 00844114  51                   push ecx
// 00844115  8d542420             lea edx, [esp + 0x20]
// 00844119  52                   push edx
// 0084411a  8d4c2420             lea ecx, [esp + 0x20]
// 0084411e  51                   push ecx
// 0084411f  50                   push eax
// 00844120  e83bfcffff           call 0x843d60
// 00844125  83c418               add esp, 0x18
// 00844128  85c0                 test eax, eax
// 0084412a  751d                 jne 0x844149
// 0084412c  8b442410             mov eax, dword ptr [esp + 0x10]
// 00844130  3bc7                 cmp eax, edi
// 00844132  740a                 je 0x84413e
// 00844134  50                   push eax
// 00844135  ff1508aa9e00         call dword ptr [0x9eaa08]
// 0084413b  83c404               add esp, 4
// 0084413e  5b                   pop ebx
// 0084413f  5f                   pop edi
// 00844140  33c0                 xor eax, eax
// 00844142  5e                   pop esi
// 00844143  83c410               add esp, 0x10
// 00844146  c20400               ret 4
// 00844149  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0084414d  3bdf                 cmp ebx, edi
// 0084414f  74ed                 je 0x84413e
// 00844151  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00844155  8b442414             mov eax, dword ptr [esp + 0x14]
// 00844159  55                   push ebp
// 0084415a  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0084415e  55                   push ebp
// 0084415f  51                   push ecx
// 00844160  50                   push eax
// 00844161  53                   push ebx
// 00844162  8bce                 mov ecx, esi
// 00844164  e8b7faffff           call 0x843c20
// 00844169  53                   push ebx
// 0084416a  8bf8                 mov edi, eax
// 0084416c  ff1508aa9e00         call dword ptr [0x9eaa08]
// 00844172  83c404               add esp, 4
// 00844175  85ff                 test edi, edi
// 00844177  750c                 jne 0x844185
// 00844179  5d                   pop ebp
// 0084417a  5b                   pop ebx
// 0084417b  5f                   pop edi
// 0084417c  33c0                 xor eax, eax
// 0084417e  5e                   pop esi
// 0084417f  83c410               add esp, 0x10
// 00844182  c20400               ret 4
// 00844185  33d2                 xor edx, edx
// 00844187  83fd04               cmp ebp, 4
// 0084418a  0f94c2               sete dl
// 0084418d  57                   push edi
// 0084418e  8bce                 mov ecx, esi
// 00844190  895608               mov dword ptr [esi + 8], edx
// 00844193  e8d23df6ff           call 0x7a7f6a
// 00844198  5d                   pop ebp
// 00844199  5b                   pop ebx
// 0084419a  5f                   pop edi
// 0084419b  b801000000           mov eax, 1
// 008441a0  5e                   pop esi
// 008441a1  83c410               add esp, 0x10
// 008441a4  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\GraphicLibrary\XTPGraphicBitmapPng.cpp (function ?LoadFromFile@CXTPGraphicBitmapPng@@QAEHPAVCFile@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/GraphicLibrary/XTPGraphicBitmapPng.cpp
