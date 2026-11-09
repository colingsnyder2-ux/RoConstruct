// from server: 100% by tester
// roc 2007-03 00705230  unit: seg_00700000  size: 172 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00705230
//
// 00705230  83ec10               sub esp, 0x10
// 00705233  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00705237  8b08                 mov ecx, dword ptr [eax]
// 00705239  8b5004               mov edx, dword ptr [eax + 4]
// 0070523c  56                   push esi
// 0070523d  8b742418             mov esi, dword ptr [esp + 0x18]
// 00705241  894c2404             mov dword ptr [esp + 4], ecx
// 00705245  8b4808               mov ecx, dword ptr [eax + 8]
// 00705248  57                   push edi
// 00705249  8954240c             mov dword ptr [esp + 0xc], edx
// 0070524d  8b500c               mov edx, dword ptr [eax + 0xc]
// 00705250  894c2410             mov dword ptr [esp + 0x10], ecx
// 00705254  6a01                 push 1
// 00705256  8bce                 mov ecx, esi
// 00705258  89542418             mov dword ptr [esp + 0x18], edx
// 0070525c  e83f590300           call 0x73aba0
// 00705261  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00705265  8b4770               mov eax, dword ptr [edi + 0x70]
// 00705268  50                   push eax
// 00705269  8d4c240c             lea ecx, [esp + 0xc]
// 0070526d  51                   push ecx
// 0070526e  8bce                 mov ecx, esi
// 00705270  e8a59af1ff           call 0x61ed1a
// 00705275  80bf8100000000       cmp byte ptr [edi + 0x81], 0
// 0070527c  7534                 jne 0x7052b2
// 0070527e  e81dfdf4ff           call 0x654fa0
// 00705283  6a10                 push 0x10
// 00705285  8bc8                 mov ecx, eax
// 00705287  e824f5f4ff           call 0x6547b0
// 0070528c  8bf8                 mov edi, eax
// 0070528e  e80dfdf4ff           call 0x654fa0
// 00705293  6a14                 push 0x14
// 00705295  8bc8                 mov ecx, eax
// 00705297  e814f5f4ff           call 0x6547b0
// 0070529c  57                   push edi
// 0070529d  50                   push eax
// 0070529e  8d542410             lea edx, [esp + 0x10]
// 007052a2  52                   push edx
// 007052a3  8bce                 mov ecx, esi
// 007052a5  e86a9af1ff           call 0x61ed14
// 007052aa  5f                   pop edi
// 007052ab  5e                   pop esi
// 007052ac  83c410               add esp, 0x10
// 007052af  c20c00               ret 0xc
// 007052b2  8b476c               mov eax, dword ptr [edi + 0x6c]
// 007052b5  f7d8                 neg eax
// 007052b7  50                   push eax
// 007052b8  50                   push eax
// 007052b9  8d442410             lea eax, [esp + 0x10]
// 007052bd  50                   push eax
// 007052be  ff159ced7700         call dword ptr [0x77ed9c]
// 007052c4  8b4f74               mov ecx, dword ptr [edi + 0x74]
// 007052c7  51                   push ecx
// 007052c8  8d54240c             lea edx, [esp + 0xc]
// 007052cc  52                   push edx
// 007052cd  8bce                 mov ecx, esi
// 007052cf  e8469af1ff           call 0x61ed1a
// 007052d4  5f                   pop edi
// 007052d5  5e                   pop esi
// 007052d6  83c410               add esp, 0x10
// 007052d9  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?DrawCaptionBack@CXTCaptionThemeOfficeXP@@MAEXPAVCDC@@PAVCXTCaption@@AAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
