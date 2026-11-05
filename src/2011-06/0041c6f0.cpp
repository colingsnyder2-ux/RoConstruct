// from server: 100% by auto
// roc 2011-06 0041c6f0  unit: RBX::VTool::?$FactoryProduct::Creator  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0041c6f0
//
// 0041c6f0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0041c6f4  8b542404             mov edx, dword ptr [esp + 4]
// 0041c6f8  b810000000           mov eax, 0x10
// 0041c6fd  56                   push esi
// 0041c6fe  8bff                 mov edi, edi
// 0041c700  8b32                 mov esi, dword ptr [edx]
// 0041c702  3b31                 cmp esi, dword ptr [ecx]
// 0041c704  751b                 jne 0x41c721
// 0041c706  83e804               sub eax, 4
// 0041c709  83c104               add ecx, 4
// 0041c70c  83c204               add edx, 4
// 0041c70f  83f804               cmp eax, 4
// 0041c712  73ec                 jae 0x41c700
// 0041c714  33c0                 xor eax, eax
// 0041c716  33d2                 xor edx, edx
// 0041c718  85c0                 test eax, eax
// 0041c71a  0f94c2               sete dl
// 0041c71d  5e                   pop esi
// 0041c71e  8bc2                 mov eax, edx
// 0041c720  c3                   ret 
// 0041c721  0fb602               movzx eax, byte ptr [edx]
// 0041c724  0fb631               movzx esi, byte ptr [ecx]
// 0041c727  2bc6                 sub eax, esi
// 0041c729  7522                 jne 0x41c74d
// 0041c72b  0fb64201             movzx eax, byte ptr [edx + 1]
// 0041c72f  0fb67101             movzx esi, byte ptr [ecx + 1]
// 0041c733  2bc6                 sub eax, esi
// 0041c735  7516                 jne 0x41c74d
// 0041c737  0fb64202             movzx eax, byte ptr [edx + 2]
// 0041c73b  0fb67102             movzx esi, byte ptr [ecx + 2]
// 0041c73f  2bc6                 sub eax, esi
// 0041c741  750a                 jne 0x41c74d
// 0041c743  0fb64203             movzx eax, byte ptr [edx + 3]
// 0041c747  0fb64903             movzx ecx, byte ptr [ecx + 3]
// 0041c74b  2bc1                 sub eax, ecx
// 0041c74d  c1f81f               sar eax, 0x1f
// 0041c750  83c801               or eax, 1
// 0041c753  33d2                 xor edx, edx
// 0041c755  85c0                 test eax, eax
// 0041c757  0f94c2               sete dl
// 0041c75a  5e                   pop esi
// 0041c75b  8bc2                 mov eax, edx
// 0041c75d  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\cmdtarg.cpp (function _IsEqualGUID)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/cmdtarg.cpp
