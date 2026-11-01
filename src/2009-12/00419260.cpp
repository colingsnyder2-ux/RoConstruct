// from server: 100% by auto
// roc 2009-12 00419260  unit: CRBXHTMLControlSite::XDocHostUIHandler  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00419260
//
// 00419260  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00419264  8b542404             mov edx, dword ptr [esp + 4]
// 00419268  b810000000           mov eax, 0x10
// 0041926d  56                   push esi
// 0041926e  8bff                 mov edi, edi
// 00419270  8b32                 mov esi, dword ptr [edx]
// 00419272  3b31                 cmp esi, dword ptr [ecx]
// 00419274  751b                 jne 0x419291
// 00419276  83e804               sub eax, 4
// 00419279  83c104               add ecx, 4
// 0041927c  83c204               add edx, 4
// 0041927f  83f804               cmp eax, 4
// 00419282  73ec                 jae 0x419270
// 00419284  33c0                 xor eax, eax
// 00419286  33d2                 xor edx, edx
// 00419288  85c0                 test eax, eax
// 0041928a  0f94c2               sete dl
// 0041928d  5e                   pop esi
// 0041928e  8bc2                 mov eax, edx
// 00419290  c3                   ret 
// 00419291  0fb602               movzx eax, byte ptr [edx]
// 00419294  0fb631               movzx esi, byte ptr [ecx]
// 00419297  2bc6                 sub eax, esi
// 00419299  7522                 jne 0x4192bd
// 0041929b  0fb64201             movzx eax, byte ptr [edx + 1]
// 0041929f  0fb67101             movzx esi, byte ptr [ecx + 1]
// 004192a3  2bc6                 sub eax, esi
// 004192a5  7516                 jne 0x4192bd
// 004192a7  0fb64202             movzx eax, byte ptr [edx + 2]
// 004192ab  0fb67102             movzx esi, byte ptr [ecx + 2]
// 004192af  2bc6                 sub eax, esi
// 004192b1  750a                 jne 0x4192bd
// 004192b3  0fb64203             movzx eax, byte ptr [edx + 3]
// 004192b7  0fb64903             movzx ecx, byte ptr [ecx + 3]
// 004192bb  2bc1                 sub eax, ecx
// 004192bd  c1f81f               sar eax, 0x1f
// 004192c0  83c801               or eax, 1
// 004192c3  33d2                 xor edx, edx
// 004192c5  85c0                 test eax, eax
// 004192c7  0f94c2               sete dl
// 004192ca  5e                   pop esi
// 004192cb  8bc2                 mov eax, edx
// 004192cd  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\cmdtarg.cpp (function _IsEqualGUID)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/cmdtarg.cpp
