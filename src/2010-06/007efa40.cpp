// from server: 100% by auto
// roc 2010-06 007efa40  unit: CXTPToolBar::CControlButtonExpand  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007efa40
//
// 007efa40  56                   push esi
// 007efa41  8bf1                 mov esi, ecx
// 007efa43  837e0800             cmp dword ptr [esi + 8], 0
// 007efa47  7506                 jne 0x7efa4f
// 007efa49  33c0                 xor eax, eax
// 007efa4b  5e                   pop esi
// 007efa4c  c20c00               ret 0xc
// 007efa4f  57                   push edi
// 007efa50  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 007efa54  85ff                 test edi, edi
// 007efa56  742c                 je 0x7efa84
// 007efa58  e8c3ffffff           call 0x7efa20
// 007efa5d  8bc8                 mov ecx, eax
// 007efa5f  8bd7                 mov edx, edi
// 007efa61  c1e910               shr ecx, 0x10
// 007efa64  c1ea10               shr edx, 0x10
// 007efa67  663bd1               cmp dx, cx
// 007efa6a  7707                 ja 0x7efa73
// 007efa6c  7516                 jne 0x7efa84
// 007efa6e  663bf8               cmp di, ax
// 007efa71  7611                 jbe 0x7efa84
// 007efa73  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007efa77  5f                   pop edi
// 007efa78  c70000000000         mov dword ptr [eax], 0
// 007efa7e  33c0                 xor eax, eax
// 007efa80  5e                   pop esi
// 007efa81  c20c00               ret 0xc
// 007efa84  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007efa88  8b5608               mov edx, dword ptr [esi + 8]
// 007efa8b  51                   push ecx
// 007efa8c  52                   push edx
// 007efa8d  ff1590a39e00         call dword ptr [0x9ea390]
// 007efa93  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007efa97  33d2                 xor edx, edx
// 007efa99  85c0                 test eax, eax
// 007efa9b  0f95c2               setne dl
// 007efa9e  5f                   pop edi
// 007efa9f  8901                 mov dword ptr [ecx], eax
// 007efaa1  5e                   pop esi
// 007efaa2  8bc2                 mov eax, edx
// 007efaa4  c20c00               ret 0xc
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetProcAddress@CXTPModuleHandle@@QAEHPAP6GHXZPBDK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
