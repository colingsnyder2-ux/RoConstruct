// from server: 100% by auto
// roc 2010-06 00419360  unit: CRBXHTMLControlSite::XDocHostUIHandler  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00419360
//
// 00419360  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00419364  8b542404             mov edx, dword ptr [esp + 4]
// 00419368  b810000000           mov eax, 0x10
// 0041936d  56                   push esi
// 0041936e  8bff                 mov edi, edi
// 00419370  8b32                 mov esi, dword ptr [edx]
// 00419372  3b31                 cmp esi, dword ptr [ecx]
// 00419374  751b                 jne 0x419391
// 00419376  83e804               sub eax, 4
// 00419379  83c104               add ecx, 4
// 0041937c  83c204               add edx, 4
// 0041937f  83f804               cmp eax, 4
// 00419382  73ec                 jae 0x419370
// 00419384  33c0                 xor eax, eax
// 00419386  33d2                 xor edx, edx
// 00419388  85c0                 test eax, eax
// 0041938a  0f94c2               sete dl
// 0041938d  5e                   pop esi
// 0041938e  8bc2                 mov eax, edx
// 00419390  c3                   ret 
// 00419391  0fb602               movzx eax, byte ptr [edx]
// 00419394  0fb631               movzx esi, byte ptr [ecx]
// 00419397  2bc6                 sub eax, esi
// 00419399  7522                 jne 0x4193bd
// 0041939b  0fb64201             movzx eax, byte ptr [edx + 1]
// 0041939f  0fb67101             movzx esi, byte ptr [ecx + 1]
// 004193a3  2bc6                 sub eax, esi
// 004193a5  7516                 jne 0x4193bd
// 004193a7  0fb64202             movzx eax, byte ptr [edx + 2]
// 004193ab  0fb67102             movzx esi, byte ptr [ecx + 2]
// 004193af  2bc6                 sub eax, esi
// 004193b1  750a                 jne 0x4193bd
// 004193b3  0fb64203             movzx eax, byte ptr [edx + 3]
// 004193b7  0fb64903             movzx ecx, byte ptr [ecx + 3]
// 004193bb  2bc1                 sub eax, ecx
// 004193bd  c1f81f               sar eax, 0x1f
// 004193c0  83c801               or eax, 1
// 004193c3  33d2                 xor edx, edx
// 004193c5  85c0                 test eax, eax
// 004193c7  0f94c2               sete dl
// 004193ca  5e                   pop esi
// 004193cb  8bc2                 mov eax, edx
// 004193cd  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\cmdtarg.cpp (function _IsEqualGUID)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/cmdtarg.cpp
