// from server: 100% by auto
// roc 2007-03 006aef00  unit: seg_006a0000  size: 189 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006aef00
//
// 006aef00  33c0                 xor eax, eax
// 006aef02  837c241c05           cmp dword ptr [esp + 0x1c], 5
// 006aef07  0f95c0               setne al
// 006aef0a  837c241802           cmp dword ptr [esp + 0x18], 2
// 006aef0f  8d44002c             lea eax, [eax + eax + 0x2c]
// 006aef13  752a                 jne 0x6aef3f
// 006aef15  837c240c00           cmp dword ptr [esp + 0xc], 0
// 006aef1a  750e                 jne 0x6aef2a
// 006aef1c  b823000000           mov eax, 0x23
// 006aef21  50                   push eax
// 006aef22  e87932f8ff           call 0x6321a0
// 006aef27  c21c00               ret 0x1c
// 006aef2a  33c0                 xor eax, eax
// 006aef2c  39442404             cmp dword ptr [esp + 4], eax
// 006aef30  0f95c0               setne al
// 006aef33  83c02c               add eax, 0x2c
// 006aef36  50                   push eax
// 006aef37  e86432f8ff           call 0x6321a0
// 006aef3c  c21c00               ret 0x1c
// 006aef3f  837c240c00           cmp dword ptr [esp + 0xc], 0
// 006aef44  750e                 jne 0x6aef54
// 006aef46  b83c000000           mov eax, 0x3c
// 006aef4b  50                   push eax
// 006aef4c  e84f32f8ff           call 0x6321a0
// 006aef51  c21c00               ret 0x1c
// 006aef54  837c241400           cmp dword ptr [esp + 0x14], 0
// 006aef59  740e                 je 0x6aef69
// 006aef5b  b82e000000           mov eax, 0x2e
// 006aef60  50                   push eax
// 006aef61  e83a32f8ff           call 0x6321a0
// 006aef66  c21c00               ret 0x1c
// 006aef69  8b542408             mov edx, dword ptr [esp + 8]
// 006aef6d  56                   push esi
// 006aef6e  8b742408             mov esi, dword ptr [esp + 8]
// 006aef72  57                   push edi
// 006aef73  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 006aef77  85ff                 test edi, edi
// 006aef79  7408                 je 0x6aef83
// 006aef7b  85f6                 test esi, esi
// 006aef7d  7504                 jne 0x6aef83
// 006aef7f  85d2                 test edx, edx
// 006aef81  742a                 je 0x6aefad
// 006aef83  83fa02               cmp edx, 2
// 006aef86  7411                 je 0x6aef99
// 006aef88  83fa03               cmp edx, 3
// 006aef8b  740c                 je 0x6aef99
// 006aef8d  85f6                 test esi, esi
// 006aef8f  7418                 je 0x6aefa9
// 006aef91  85d2                 test edx, edx
// 006aef93  7504                 jne 0x6aef99
// 006aef95  85ff                 test edi, edi
// 006aef97  7414                 je 0x6aefad
// 006aef99  b82f000000           mov eax, 0x2f
// 006aef9e  5f                   pop edi
// 006aef9f  5e                   pop esi
// 006aefa0  50                   push eax
// 006aefa1  e8fa31f8ff           call 0x6321a0
// 006aefa6  c21c00               ret 0x1c
// 006aefa9  85d2                 test edx, edx
// 006aefab  74f1                 je 0x6aef9e
// 006aefad  5f                   pop edi
// 006aefae  b82d000000           mov eax, 0x2d
// 006aefb3  5e                   pop esi
// 006aefb4  50                   push eax
// 006aefb5  e8e631f8ff           call 0x6321a0
// 006aefba  c21c00               ret 0x1c
// library xtp-15.2.1/Source\CommandBars\XTPOfficeTheme.cpp (function ?GetRectangleTextColor@CXTPOfficeTheme@@UAEKHHHHHW4XTPBarType@@W4XTPBarPosition@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPOfficeTheme.cpp
