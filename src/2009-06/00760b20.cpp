// from server: 100% by auto
// roc 2009-06 00760b20  unit: CXTPToolBar::CControlButtonExpand  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00760b20
//
// 00760b20  56                   push esi
// 00760b21  8bf1                 mov esi, ecx
// 00760b23  837e0800             cmp dword ptr [esi + 8], 0
// 00760b27  7506                 jne 0x760b2f
// 00760b29  33c0                 xor eax, eax
// 00760b2b  5e                   pop esi
// 00760b2c  c20c00               ret 0xc
// 00760b2f  57                   push edi
// 00760b30  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00760b34  85ff                 test edi, edi
// 00760b36  742c                 je 0x760b64
// 00760b38  e8c3ffffff           call 0x760b00
// 00760b3d  8bc8                 mov ecx, eax
// 00760b3f  8bd7                 mov edx, edi
// 00760b41  c1e910               shr ecx, 0x10
// 00760b44  c1ea10               shr edx, 0x10
// 00760b47  663bd1               cmp dx, cx
// 00760b4a  7707                 ja 0x760b53
// 00760b4c  7516                 jne 0x760b64
// 00760b4e  663bf8               cmp di, ax
// 00760b51  7611                 jbe 0x760b64
// 00760b53  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00760b57  5f                   pop edi
// 00760b58  c70000000000         mov dword ptr [eax], 0
// 00760b5e  33c0                 xor eax, eax
// 00760b60  5e                   pop esi
// 00760b61  c20c00               ret 0xc
// 00760b64  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00760b68  8b5608               mov edx, dword ptr [esi + 8]
// 00760b6b  51                   push ecx
// 00760b6c  52                   push edx
// 00760b6d  ff15e8e18900         call dword ptr [0x89e1e8]
// 00760b73  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00760b77  33d2                 xor edx, edx
// 00760b79  85c0                 test eax, eax
// 00760b7b  0f95c2               setne dl
// 00760b7e  5f                   pop edi
// 00760b7f  8901                 mov dword ptr [ecx], eax
// 00760b81  5e                   pop esi
// 00760b82  8bc2                 mov eax, edx
// 00760b84  c20c00               ret 0xc
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetProcAddress@CXTPModuleHandle@@QAEHPAP6GHXZPBDK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
