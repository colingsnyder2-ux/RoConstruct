// from server: 100% by auto
// roc 2009-12 0083b8f0  unit: CXTPToolBar::CControlButtonExpand  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083b8f0
//
// 0083b8f0  56                   push esi
// 0083b8f1  8bf1                 mov esi, ecx
// 0083b8f3  837e0800             cmp dword ptr [esi + 8], 0
// 0083b8f7  7506                 jne 0x83b8ff
// 0083b8f9  33c0                 xor eax, eax
// 0083b8fb  5e                   pop esi
// 0083b8fc  c20c00               ret 0xc
// 0083b8ff  57                   push edi
// 0083b900  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0083b904  85ff                 test edi, edi
// 0083b906  742c                 je 0x83b934
// 0083b908  e8c3ffffff           call 0x83b8d0
// 0083b90d  8bc8                 mov ecx, eax
// 0083b90f  8bd7                 mov edx, edi
// 0083b911  c1e910               shr ecx, 0x10
// 0083b914  c1ea10               shr edx, 0x10
// 0083b917  663bd1               cmp dx, cx
// 0083b91a  7707                 ja 0x83b923
// 0083b91c  7516                 jne 0x83b934
// 0083b91e  663bf8               cmp di, ax
// 0083b921  7611                 jbe 0x83b934
// 0083b923  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0083b927  5f                   pop edi
// 0083b928  c70000000000         mov dword ptr [eax], 0
// 0083b92e  33c0                 xor eax, eax
// 0083b930  5e                   pop esi
// 0083b931  c20c00               ret 0xc
// 0083b934  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0083b938  8b5608               mov edx, dword ptr [esi + 8]
// 0083b93b  51                   push ecx
// 0083b93c  52                   push edx
// 0083b93d  ff1520b29800         call dword ptr [0x98b220]
// 0083b943  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0083b947  33d2                 xor edx, edx
// 0083b949  85c0                 test eax, eax
// 0083b94b  0f95c2               setne dl
// 0083b94e  5f                   pop edi
// 0083b94f  8901                 mov dword ptr [ecx], eax
// 0083b951  5e                   pop esi
// 0083b952  8bc2                 mov eax, edx
// 0083b954  c20c00               ret 0xc
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetProcAddress@CXTPModuleHandle@@QAEHPAP6GHXZPBDK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
