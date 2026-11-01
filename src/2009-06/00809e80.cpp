// from server: 100% by auto
// roc 2009-06 00809e80  unit: CXTCaptionThemeOfficeXP  size: 172 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00809e80
//
// 00809e80  83ec10               sub esp, 0x10
// 00809e83  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00809e87  8b08                 mov ecx, dword ptr [eax]
// 00809e89  8b5004               mov edx, dword ptr [eax + 4]
// 00809e8c  56                   push esi
// 00809e8d  8b742418             mov esi, dword ptr [esp + 0x18]
// 00809e91  894c2404             mov dword ptr [esp + 4], ecx
// 00809e95  8b4808               mov ecx, dword ptr [eax + 8]
// 00809e98  57                   push edi
// 00809e99  8954240c             mov dword ptr [esp + 0xc], edx
// 00809e9d  8b500c               mov edx, dword ptr [eax + 0xc]
// 00809ea0  894c2410             mov dword ptr [esp + 0x10], ecx
// 00809ea4  6a01                 push 1
// 00809ea6  8bce                 mov ecx, esi
// 00809ea8  89542418             mov dword ptr [esp + 0x18], edx
// 00809eac  e855200400           call 0x84bf06
// 00809eb1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00809eb5  8b4770               mov eax, dword ptr [edi + 0x70]
// 00809eb8  50                   push eax
// 00809eb9  8d4c240c             lea ecx, [esp + 0xc]
// 00809ebd  51                   push ecx
// 00809ebe  8bce                 mov ecx, esi
// 00809ec0  e80bf9f0ff           call 0x7197d0
// 00809ec5  80bf8100000000       cmp byte ptr [edi + 0x81], 0
// 00809ecc  7534                 jne 0x809f02
// 00809ece  e84dacf4ff           call 0x754b20
// 00809ed3  6a10                 push 0x10
// 00809ed5  8bc8                 mov ecx, eax
// 00809ed7  e8c4a3f4ff           call 0x7542a0
// 00809edc  8bf8                 mov edi, eax
// 00809ede  e83dacf4ff           call 0x754b20
// 00809ee3  6a14                 push 0x14
// 00809ee5  8bc8                 mov ecx, eax
// 00809ee7  e8b4a3f4ff           call 0x7542a0
// 00809eec  57                   push edi
// 00809eed  50                   push eax
// 00809eee  8d542410             lea edx, [esp + 0x10]
// 00809ef2  52                   push edx
// 00809ef3  8bce                 mov ecx, esi
// 00809ef5  e8d0f8f0ff           call 0x7197ca
// 00809efa  5f                   pop edi
// 00809efb  5e                   pop esi
// 00809efc  83c410               add esp, 0x10
// 00809eff  c20c00               ret 0xc
// 00809f02  8b476c               mov eax, dword ptr [edi + 0x6c]
// 00809f05  f7d8                 neg eax
// 00809f07  50                   push eax
// 00809f08  50                   push eax
// 00809f09  8d442410             lea eax, [esp + 0x10]
// 00809f0d  50                   push eax
// 00809f0e  ff15bced8900         call dword ptr [0x89edbc]
// 00809f14  8b4f74               mov ecx, dword ptr [edi + 0x74]
// 00809f17  51                   push ecx
// 00809f18  8d54240c             lea edx, [esp + 0xc]
// 00809f1c  52                   push edx
// 00809f1d  8bce                 mov ecx, esi
// 00809f1f  e8acf8f0ff           call 0x7197d0
// 00809f24  5f                   pop edi
// 00809f25  5e                   pop esi
// 00809f26  83c410               add esp, 0x10
// 00809f29  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?DrawCaptionBack@CXTCaptionThemeOfficeXP@@MAEXPAVCDC@@PAVCXTCaption@@AAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
