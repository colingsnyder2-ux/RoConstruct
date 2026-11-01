// from server: 100% by auto
// roc 2007-03 00685ee0  unit: seg_00680000  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00685ee0
//
// 00685ee0  56                   push esi
// 00685ee1  8bf1                 mov esi, ecx
// 00685ee3  837e0800             cmp dword ptr [esi + 8], 0
// 00685ee7  7506                 jne 0x685eef
// 00685ee9  33c0                 xor eax, eax
// 00685eeb  5e                   pop esi
// 00685eec  c20c00               ret 0xc
// 00685eef  57                   push edi
// 00685ef0  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00685ef4  85ff                 test edi, edi
// 00685ef6  742c                 je 0x685f24
// 00685ef8  e8c3ffffff           call 0x685ec0
// 00685efd  8bc8                 mov ecx, eax
// 00685eff  8bd7                 mov edx, edi
// 00685f01  c1e910               shr ecx, 0x10
// 00685f04  c1ea10               shr edx, 0x10
// 00685f07  663bd1               cmp dx, cx
// 00685f0a  7707                 ja 0x685f13
// 00685f0c  7516                 jne 0x685f24
// 00685f0e  663bf8               cmp di, ax
// 00685f11  7611                 jbe 0x685f24
// 00685f13  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00685f17  5f                   pop edi
// 00685f18  c70000000000         mov dword ptr [eax], 0
// 00685f1e  33c0                 xor eax, eax
// 00685f20  5e                   pop esi
// 00685f21  c20c00               ret 0xc
// 00685f24  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00685f28  8b5608               mov edx, dword ptr [esi + 8]
// 00685f2b  51                   push ecx
// 00685f2c  52                   push edx
// 00685f2d  ff1544d27700         call dword ptr [0x77d244]
// 00685f33  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00685f37  33d2                 xor edx, edx
// 00685f39  85c0                 test eax, eax
// 00685f3b  0f95c2               setne dl
// 00685f3e  5f                   pop edi
// 00685f3f  8901                 mov dword ptr [ecx], eax
// 00685f41  5e                   pop esi
// 00685f42  8bc2                 mov eax, edx
// 00685f44  c20c00               ret 0xc
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetProcAddress@CXTPModuleHandle@@QAEHPAP6GHXZPBDK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
