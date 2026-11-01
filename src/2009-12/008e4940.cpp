// from server: 100% by auto
// roc 2009-12 008e4940  unit: CXTCaptionThemeOfficeXP  size: 172 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e4940
//
// 008e4940  83ec10               sub esp, 0x10
// 008e4943  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008e4947  8b08                 mov ecx, dword ptr [eax]
// 008e4949  8b5004               mov edx, dword ptr [eax + 4]
// 008e494c  56                   push esi
// 008e494d  8b742418             mov esi, dword ptr [esp + 0x18]
// 008e4951  894c2404             mov dword ptr [esp + 4], ecx
// 008e4955  8b4808               mov ecx, dword ptr [eax + 8]
// 008e4958  57                   push edi
// 008e4959  8954240c             mov dword ptr [esp + 0xc], edx
// 008e495d  8b500c               mov edx, dword ptr [eax + 0xc]
// 008e4960  894c2410             mov dword ptr [esp + 0x10], ecx
// 008e4964  6a01                 push 1
// 008e4966  8bce                 mov ecx, esi
// 008e4968  89542418             mov dword ptr [esp + 0x18], edx
// 008e496c  e81f1b0400           call 0x926490
// 008e4971  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008e4975  8b4770               mov eax, dword ptr [edi + 0x70]
// 008e4978  50                   push eax
// 008e4979  8d4c240c             lea ecx, [esp + 0xc]
// 008e497d  51                   push ecx
// 008e497e  8bce                 mov ecx, esi
// 008e4980  e879fcf0ff           call 0x7f45fe
// 008e4985  80bf8100000000       cmp byte ptr [edi + 0x81], 0
// 008e498c  7534                 jne 0x8e49c2
// 008e498e  e83db0f4ff           call 0x82f9d0
// 008e4993  6a10                 push 0x10
// 008e4995  8bc8                 mov ecx, eax
// 008e4997  e864a7f4ff           call 0x82f100
// 008e499c  8bf8                 mov edi, eax
// 008e499e  e82db0f4ff           call 0x82f9d0
// 008e49a3  6a14                 push 0x14
// 008e49a5  8bc8                 mov ecx, eax
// 008e49a7  e854a7f4ff           call 0x82f100
// 008e49ac  57                   push edi
// 008e49ad  50                   push eax
// 008e49ae  8d542410             lea edx, [esp + 0x10]
// 008e49b2  52                   push edx
// 008e49b3  8bce                 mov ecx, esi
// 008e49b5  e83efcf0ff           call 0x7f45f8
// 008e49ba  5f                   pop edi
// 008e49bb  5e                   pop esi
// 008e49bc  83c410               add esp, 0x10
// 008e49bf  c20c00               ret 0xc
// 008e49c2  8b476c               mov eax, dword ptr [edi + 0x6c]
// 008e49c5  f7d8                 neg eax
// 008e49c7  50                   push eax
// 008e49c8  50                   push eax
// 008e49c9  8d442410             lea eax, [esp + 0x10]
// 008e49cd  50                   push eax
// 008e49ce  ff1558ca9800         call dword ptr [0x98ca58]
// 008e49d4  8b4f74               mov ecx, dword ptr [edi + 0x74]
// 008e49d7  51                   push ecx
// 008e49d8  8d54240c             lea edx, [esp + 0xc]
// 008e49dc  52                   push edx
// 008e49dd  8bce                 mov ecx, esi
// 008e49df  e81afcf0ff           call 0x7f45fe
// 008e49e4  5f                   pop edi
// 008e49e5  5e                   pop esi
// 008e49e6  83c410               add esp, 0x10
// 008e49e9  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?DrawCaptionBack@CXTCaptionThemeOfficeXP@@MAEXPAVCDC@@PAVCXTCaption@@AAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
