// from server: 100% by auto
// roc 2009-06 004033c0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 168 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004033c0
//
// 004033c0  f6058097a30001       test byte ptr [0xa39780], 1
// 004033c7  755d                 jne 0x403426
// 004033c9  830d8097a30001       or dword ptr [0xa39780], 1
// 004033d0  b808000000           mov eax, 8
// 004033d5  66a36497a300         mov word ptr [0xa39764], ax
// 004033db  b908400000           mov ecx, 0x4008
// 004033e0  ba13000000           mov edx, 0x13
// 004033e5  b811000000           mov eax, 0x11
// 004033ea  c7056097a30018cb8a00 mov dword ptr [0xa39760], 0x8acb18
// 004033f4  c7056897a30014cb8a00 mov dword ptr [0xa39768], 0x8acb14
// 004033fe  66890d6c97a300       mov word ptr [0xa3976c], cx
// 00403405  c7057097a30010cb8a00 mov dword ptr [0xa39770], 0x8acb10
// 0040340f  6689157497a300       mov word ptr [0xa39774], dx
// 00403416  c7057897a3000ccb8a00 mov dword ptr [0xa39778], 0x8acb0c
// 00403420  66a37c97a300         mov word ptr [0xa3977c], ax
// 00403426  53                   push ebx
// 00403427  8b1ddce18900         mov ebx, dword ptr [0x89e1dc]
// 0040342d  56                   push esi
// 0040342e  57                   push edi
// 0040342f  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00403433  33f6                 xor esi, esi
// 00403435  8b0cf56097a300       mov ecx, dword ptr [esi*8 + 0xa39760]
// 0040343c  51                   push ecx
// 0040343d  57                   push edi
// 0040343e  ffd3                 call ebx
// 00403440  85c0                 test eax, eax
// 00403442  740c                 je 0x403450
// 00403444  46                   inc esi
// 00403445  83fe04               cmp esi, 4
// 00403448  72eb                 jb 0x403435
// 0040344a  5f                   pop edi
// 0040344b  5e                   pop esi
// 0040344c  33c0                 xor eax, eax
// 0040344e  5b                   pop ebx
// 0040344f  c3                   ret 
// 00403450  668b14f56497a300     mov dx, word ptr [esi*8 + 0xa39764]
// 00403458  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040345c  5f                   pop edi
// 0040345d  5e                   pop esi
// 0040345e  668910               mov word ptr [eax], dx
// 00403461  b801000000           mov eax, 1
// 00403466  5b                   pop ebx
// 00403467  c3                   ret 
// library atl-9.0/atl.cpp (function ?VTFromRegType@CRegParser@ATL@@KAHPBDAAG@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
