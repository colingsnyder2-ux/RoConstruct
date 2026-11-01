// from server: 100% by auto
// roc 2007-03 0071bd60  unit: seg_00710000  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0071bd60
//
// 0071bd60  56                   push esi
// 0071bd61  8b742408             mov esi, dword ptr [esp + 8]
// 0071bd65  837e5c00             cmp dword ptr [esi + 0x5c], 0
// 0071bd69  7506                 jne 0x71bd71
// 0071bd6b  33c0                 xor eax, eax
// 0071bd6d  5e                   pop esi
// 0071bd6e  c20c00               ret 0xc
// 0071bd71  837e5400             cmp dword ptr [esi + 0x54], 0
// 0071bd75  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0071bd79  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0071bd7d  57                   push edi
// 0071bd7e  8bf9                 mov edi, ecx
// 0071bd80  7502                 jne 0x71bd84
// 0071bd82  8bf8                 mov edi, eax
// 0071bd84  51                   push ecx
// 0071bd85  50                   push eax
// 0071bd86  8d4640               lea eax, [esi + 0x40]
// 0071bd89  50                   push eax
// 0071bd8a  ff1598ed7700         call dword ptr [0x77ed98]
// 0071bd90  85c0                 test eax, eax
// 0071bd92  7505                 jne 0x71bd99
// 0071bd94  5f                   pop edi
// 0071bd95  5e                   pop esi
// 0071bd96  c20c00               ret 0xc
// 0071bd99  3b7e24               cmp edi, dword ptr [esi + 0x24]
// 0071bd9c  7d0a                 jge 0x71bda8
// 0071bd9e  5f                   pop edi
// 0071bd9f  b83c000000           mov eax, 0x3c
// 0071bda4  5e                   pop esi
// 0071bda5  c20c00               ret 0xc
// 0071bda8  3b7e28               cmp edi, dword ptr [esi + 0x28]
// 0071bdab  7c0a                 jl 0x71bdb7
// 0071bdad  5f                   pop edi
// 0071bdae  b83d000000           mov eax, 0x3d
// 0071bdb3  5e                   pop esi
// 0071bdb4  c20c00               ret 0xc
// 0071bdb7  3b7e34               cmp edi, dword ptr [esi + 0x34]
// 0071bdba  7d0a                 jge 0x71bdc6
// 0071bdbc  5f                   pop edi
// 0071bdbd  b83e000000           mov eax, 0x3e
// 0071bdc2  5e                   pop esi
// 0071bdc3  c20c00               ret 0xc
// 0071bdc6  33c0                 xor eax, eax
// 0071bdc8  3b7e30               cmp edi, dword ptr [esi + 0x30]
// 0071bdcb  5f                   pop edi
// 0071bdcc  0f9cc0               setl al
// 0071bdcf  5e                   pop esi
// 0071bdd0  83c03f               add eax, 0x3f
// 0071bdd3  c20c00               ret 0xc
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectScrollBar.cpp (function ?HitTestScrollBar@CXTPSkinObjectFrame@@IAEHPAUXTP_SKINSCROLLBARPOSINFO@@UtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectScrollBar.cpp
