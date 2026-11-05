// from server: 100% by auto
// roc 2008-06 0042ad40  unit: RBX::Reflection::$$A6AXPBVPropertyDescriptor::V?$function::?$holder  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042ad40
//
// 0042ad40  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0042ad44  8b542404             mov edx, dword ptr [esp + 4]
// 0042ad48  b810000000           mov eax, 0x10
// 0042ad4d  56                   push esi
// 0042ad4e  8bff                 mov edi, edi
// 0042ad50  8b32                 mov esi, dword ptr [edx]
// 0042ad52  3b31                 cmp esi, dword ptr [ecx]
// 0042ad54  751b                 jne 0x42ad71
// 0042ad56  83e804               sub eax, 4
// 0042ad59  83c104               add ecx, 4
// 0042ad5c  83c204               add edx, 4
// 0042ad5f  83f804               cmp eax, 4
// 0042ad62  73ec                 jae 0x42ad50
// 0042ad64  33c0                 xor eax, eax
// 0042ad66  33d2                 xor edx, edx
// 0042ad68  85c0                 test eax, eax
// 0042ad6a  0f94c2               sete dl
// 0042ad6d  5e                   pop esi
// 0042ad6e  8bc2                 mov eax, edx
// 0042ad70  c3                   ret 
// 0042ad71  0fb602               movzx eax, byte ptr [edx]
// 0042ad74  0fb631               movzx esi, byte ptr [ecx]
// 0042ad77  2bc6                 sub eax, esi
// 0042ad79  7522                 jne 0x42ad9d
// 0042ad7b  0fb64201             movzx eax, byte ptr [edx + 1]
// 0042ad7f  0fb67101             movzx esi, byte ptr [ecx + 1]
// 0042ad83  2bc6                 sub eax, esi
// 0042ad85  7516                 jne 0x42ad9d
// 0042ad87  0fb64202             movzx eax, byte ptr [edx + 2]
// 0042ad8b  0fb67102             movzx esi, byte ptr [ecx + 2]
// 0042ad8f  2bc6                 sub eax, esi
// 0042ad91  750a                 jne 0x42ad9d
// 0042ad93  0fb64203             movzx eax, byte ptr [edx + 3]
// 0042ad97  0fb64903             movzx ecx, byte ptr [ecx + 3]
// 0042ad9b  2bc1                 sub eax, ecx
// 0042ad9d  c1f81f               sar eax, 0x1f
// 0042ada0  83c801               or eax, 1
// 0042ada3  33d2                 xor edx, edx
// 0042ada5  85c0                 test eax, eax
// 0042ada7  0f94c2               sete dl
// 0042adaa  5e                   pop esi
// 0042adab  8bc2                 mov eax, edx
// 0042adad  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\cmdtarg.cpp (function _IsEqualGUID)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/cmdtarg.cpp
