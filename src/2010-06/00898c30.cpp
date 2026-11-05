// from server: 100% by auto
// roc 2010-06 00898c30  unit: CXTCaptionThemeOfficeXP  size: 172 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00898c30
//
// 00898c30  83ec10               sub esp, 0x10
// 00898c33  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00898c37  8b08                 mov ecx, dword ptr [eax]
// 00898c39  8b5004               mov edx, dword ptr [eax + 4]
// 00898c3c  56                   push esi
// 00898c3d  8b742418             mov esi, dword ptr [esp + 0x18]
// 00898c41  894c2404             mov dword ptr [esp + 4], ecx
// 00898c45  8b4808               mov ecx, dword ptr [eax + 8]
// 00898c48  57                   push edi
// 00898c49  8954240c             mov dword ptr [esp + 0xc], edx
// 00898c4d  8b500c               mov edx, dword ptr [eax + 0xc]
// 00898c50  894c2410             mov dword ptr [esp + 0x10], ecx
// 00898c54  6a01                 push 1
// 00898c56  8bce                 mov ecx, esi
// 00898c58  89542418             mov dword ptr [esp + 0x18], edx
// 00898c5c  e853410e00           call 0x97cdb4
// 00898c61  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00898c65  8b4770               mov eax, dword ptr [edi + 0x70]
// 00898c68  50                   push eax
// 00898c69  8d4c240c             lea ecx, [esp + 0xc]
// 00898c6d  51                   push ecx
// 00898c6e  8bce                 mov ecx, esi
// 00898c70  e8c9faf0ff           call 0x7a873e
// 00898c75  80bf8100000000       cmp byte ptr [edi + 0x81], 0
// 00898c7c  7534                 jne 0x898cb2
// 00898c7e  e89daef4ff           call 0x7e3b20
// 00898c83  6a10                 push 0x10
// 00898c85  8bc8                 mov ecx, eax
// 00898c87  e824a6f4ff           call 0x7e32b0
// 00898c8c  8bf8                 mov edi, eax
// 00898c8e  e88daef4ff           call 0x7e3b20
// 00898c93  6a14                 push 0x14
// 00898c95  8bc8                 mov ecx, eax
// 00898c97  e814a6f4ff           call 0x7e32b0
// 00898c9c  57                   push edi
// 00898c9d  50                   push eax
// 00898c9e  8d542410             lea edx, [esp + 0x10]
// 00898ca2  52                   push edx
// 00898ca3  8bce                 mov ecx, esi
// 00898ca5  e88efaf0ff           call 0x7a8738
// 00898caa  5f                   pop edi
// 00898cab  5e                   pop esi
// 00898cac  83c410               add esp, 0x10
// 00898caf  c20c00               ret 0xc
// 00898cb2  8b476c               mov eax, dword ptr [edi + 0x6c]
// 00898cb5  f7d8                 neg eax
// 00898cb7  50                   push eax
// 00898cb8  50                   push eax
// 00898cb9  8d442410             lea eax, [esp + 0x10]
// 00898cbd  50                   push eax
// 00898cbe  ff15dcbb9e00         call dword ptr [0x9ebbdc]
// 00898cc4  8b4f74               mov ecx, dword ptr [edi + 0x74]
// 00898cc7  51                   push ecx
// 00898cc8  8d54240c             lea edx, [esp + 0xc]
// 00898ccc  52                   push edx
// 00898ccd  8bce                 mov ecx, esi
// 00898ccf  e86afaf0ff           call 0x7a873e
// 00898cd4  5f                   pop edi
// 00898cd5  5e                   pop esi
// 00898cd6  83c410               add esp, 0x10
// 00898cd9  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?DrawCaptionBack@CXTCaptionThemeOfficeXP@@MAEXPAVCDC@@PAVCXTCaption@@AAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
