// from server: 100% by auto
// roc 2011-06 0089dd80  unit: CXTPHookManager::CHookSink  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0089dd80
//
// 0089dd80  53                   push ebx
// 0089dd81  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0089dd85  56                   push esi
// 0089dd86  57                   push edi
// 0089dd87  53                   push ebx
// 0089dd88  8bf9                 mov edi, ecx
// 0089dd8a  e8a1ffffff           call 0x89dd30
// 0089dd8f  8bf0                 mov esi, eax
// 0089dd91  85f6                 test esi, esi
// 0089dd93  7413                 je 0x89dda8
// 0089dd95  53                   push ebx
// 0089dd96  8bcf                 mov ecx, edi
// 0089dd98  e8233bf8ff           call 0x8218c0
// 0089dd9d  8b06                 mov eax, dword ptr [esi]
// 0089dd9f  8b5004               mov edx, dword ptr [eax + 4]
// 0089dda2  6a01                 push 1
// 0089dda4  8bce                 mov ecx, esi
// 0089dda6  ffd2                 call edx
// 0089dda8  5f                   pop edi
// 0089dda9  5e                   pop esi
// 0089ddaa  5b                   pop ebx
// 0089ddab  c20400               ret 4
// copied from an identical function in another client (function ?DoRemove@CHookSink@ns_ROCX000026@ns_ROCX0000e9@@QAEXH@Z)

namespace ns_ROCX000026 {
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-11.2.2 Source/CommandBars/XTPControlPopupColor.cpp
}
