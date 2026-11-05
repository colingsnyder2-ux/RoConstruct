// from server: 100% by auto
// roc 2007-08 0042a8d0  unit: CLuaHtmlView  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042a8d0
//
// 0042a8d0  8b442408             mov eax, dword ptr [esp + 8]
// 0042a8d4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0042a8d8  56                   push esi
// 0042a8d9  57                   push edi
// 0042a8da  be10000000           mov esi, 0x10
// 0042a8df  90                   nop 
// 0042a8e0  8b11                 mov edx, dword ptr [ecx]
// 0042a8e2  3b10                 cmp edx, dword ptr [eax]
// 0042a8e4  7512                 jne 0x42a8f8
// 0042a8e6  83ee04               sub esi, 4
// 0042a8e9  83c004               add eax, 4
// 0042a8ec  83c104               add ecx, 4
// 0042a8ef  83fe04               cmp esi, 4
// 0042a8f2  73ec                 jae 0x42a8e0
// 0042a8f4  85f6                 test esi, esi
// 0042a8f6  7467                 je 0x42a95f
// 0042a8f8  0fb611               movzx edx, byte ptr [ecx]
// 0042a8fb  0fb638               movzx edi, byte ptr [eax]
// 0042a8fe  2bd7                 sub edx, edi
// 0042a900  7545                 jne 0x42a947
// 0042a902  83ee01               sub esi, 1
// 0042a905  83c001               add eax, 1
// 0042a908  83c101               add ecx, 1
// 0042a90b  85f6                 test esi, esi
// 0042a90d  7450                 je 0x42a95f
// 0042a90f  0fb611               movzx edx, byte ptr [ecx]
// 0042a912  0fb638               movzx edi, byte ptr [eax]
// 0042a915  2bd7                 sub edx, edi
// 0042a917  752e                 jne 0x42a947
// 0042a919  83ee01               sub esi, 1
// 0042a91c  83c001               add eax, 1
// 0042a91f  83c101               add ecx, 1
// 0042a922  85f6                 test esi, esi
// 0042a924  7439                 je 0x42a95f
// 0042a926  0fb611               movzx edx, byte ptr [ecx]
// 0042a929  0fb638               movzx edi, byte ptr [eax]
// 0042a92c  2bd7                 sub edx, edi
// 0042a92e  7517                 jne 0x42a947
// 0042a930  83ee01               sub esi, 1
// 0042a933  83c001               add eax, 1
// 0042a936  83c101               add ecx, 1
// 0042a939  85f6                 test esi, esi
// 0042a93b  7422                 je 0x42a95f
// 0042a93d  0fb611               movzx edx, byte ptr [ecx]
// 0042a940  0fb600               movzx eax, byte ptr [eax]
// 0042a943  2bd0                 sub edx, eax
// 0042a945  7418                 je 0x42a95f
// 0042a947  85d2                 test edx, edx
// 0042a949  b801000000           mov eax, 1
// 0042a94e  7f11                 jg 0x42a961
// 0042a950  83c8ff               or eax, 0xffffffff
// 0042a953  33c9                 xor ecx, ecx
// 0042a955  85c0                 test eax, eax
// 0042a957  0f94c1               sete cl
// 0042a95a  5f                   pop edi
// 0042a95b  5e                   pop esi
// 0042a95c  8bc1                 mov eax, ecx
// 0042a95e  c3                   ret 
// 0042a95f  33c0                 xor eax, eax
// 0042a961  33c9                 xor ecx, ecx
// 0042a963  85c0                 test eax, eax
// 0042a965  0f94c1               sete cl
// 0042a968  5f                   pop edi
// 0042a969  5e                   pop esi
// 0042a96a  8bc1                 mov eax, ecx
// 0042a96c  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\cmdtarg.cpp (function _IsEqualGUID)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/cmdtarg.cpp
