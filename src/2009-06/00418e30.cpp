// from server: 100% by auto
// roc 2009-06 00418e30  unit: CRBXHTMLControlSite::XDocHostUIHandler  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00418e30
//
// 00418e30  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00418e34  8b542404             mov edx, dword ptr [esp + 4]
// 00418e38  b810000000           mov eax, 0x10
// 00418e3d  56                   push esi
// 00418e3e  8bff                 mov edi, edi
// 00418e40  8b32                 mov esi, dword ptr [edx]
// 00418e42  3b31                 cmp esi, dword ptr [ecx]
// 00418e44  751b                 jne 0x418e61
// 00418e46  83e804               sub eax, 4
// 00418e49  83c104               add ecx, 4
// 00418e4c  83c204               add edx, 4
// 00418e4f  83f804               cmp eax, 4
// 00418e52  73ec                 jae 0x418e40
// 00418e54  33c0                 xor eax, eax
// 00418e56  33d2                 xor edx, edx
// 00418e58  85c0                 test eax, eax
// 00418e5a  0f94c2               sete dl
// 00418e5d  5e                   pop esi
// 00418e5e  8bc2                 mov eax, edx
// 00418e60  c3                   ret 
// 00418e61  0fb602               movzx eax, byte ptr [edx]
// 00418e64  0fb631               movzx esi, byte ptr [ecx]
// 00418e67  2bc6                 sub eax, esi
// 00418e69  7522                 jne 0x418e8d
// 00418e6b  0fb64201             movzx eax, byte ptr [edx + 1]
// 00418e6f  0fb67101             movzx esi, byte ptr [ecx + 1]
// 00418e73  2bc6                 sub eax, esi
// 00418e75  7516                 jne 0x418e8d
// 00418e77  0fb64202             movzx eax, byte ptr [edx + 2]
// 00418e7b  0fb67102             movzx esi, byte ptr [ecx + 2]
// 00418e7f  2bc6                 sub eax, esi
// 00418e81  750a                 jne 0x418e8d
// 00418e83  0fb64203             movzx eax, byte ptr [edx + 3]
// 00418e87  0fb64903             movzx ecx, byte ptr [ecx + 3]
// 00418e8b  2bc1                 sub eax, ecx
// 00418e8d  c1f81f               sar eax, 0x1f
// 00418e90  83c801               or eax, 1
// 00418e93  33d2                 xor edx, edx
// 00418e95  85c0                 test eax, eax
// 00418e97  0f94c2               sete dl
// 00418e9a  5e                   pop esi
// 00418e9b  8bc2                 mov eax, edx
// 00418e9d  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\cmdtarg.cpp (function _IsEqualGUID)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/cmdtarg.cpp
