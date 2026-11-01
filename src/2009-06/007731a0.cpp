// from server: 100% by auto
// roc 2009-06 007731a0  unit: CXTPPropertyGrid  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007731a0
//
// 007731a0  53                   push ebx
// 007731a1  8b1d98ee8900         mov ebx, dword ptr [0x89ee98]
// 007731a7  56                   push esi
// 007731a8  57                   push edi
// 007731a9  8bf9                 mov edi, ecx
// 007731ab  8b4720               mov eax, dword ptr [edi + 0x20]
// 007731ae  50                   push eax
// 007731af  ffd3                 call ebx
// 007731b1  50                   push eax
// 007731b2  e84b5bfaff           call 0x718d02
// 007731b7  8bf0                 mov esi, eax
// 007731b9  85f6                 test esi, esi
// 007731bb  7453                 je 0x773210
// 007731bd  8bce                 mov ecx, esi
// 007731bf  e81e8d0d00           call 0x84bee2
// 007731c4  a900000100           test eax, 0x10000
// 007731c9  741c                 je 0x7731e7
// 007731cb  8bce                 mov ecx, esi
// 007731cd  e80a8d0d00           call 0x84bedc
// 007731d2  a900000040           test eax, 0x40000000
// 007731d7  740e                 je 0x7731e7
// 007731d9  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 007731dc  51                   push ecx
// 007731dd  ffd3                 call ebx
// 007731df  50                   push eax
// 007731e0  e81d5bfaff           call 0x718d02
// 007731e5  8bf0                 mov esi, eax
// 007731e7  8b542410             mov edx, dword ptr [esp + 0x10]
// 007731eb  8b4720               mov eax, dword ptr [edi + 0x20]
// 007731ee  52                   push edx
// 007731ef  50                   push eax
// 007731f0  8b4620               mov eax, dword ptr [esi + 0x20]
// 007731f3  50                   push eax
// 007731f4  ff15f8ee8900         call dword ptr [0x89eef8]
// 007731fa  50                   push eax
// 007731fb  e8025bfaff           call 0x718d02
// 00773200  8bc8                 mov ecx, eax
// 00773202  2bc7                 sub eax, edi
// 00773204  f7d8                 neg eax
// 00773206  5f                   pop edi
// 00773207  1bc0                 sbb eax, eax
// 00773209  5e                   pop esi
// 0077320a  23c1                 and eax, ecx
// 0077320c  5b                   pop ebx
// 0077320d  c20400               ret 4
// 00773210  5f                   pop edi
// 00773211  5e                   pop esi
// 00773212  33c0                 xor eax, eax
// 00773214  5b                   pop ebx
// 00773215  c20400               ret 4
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?GetNextGridTabItem@CXTPPropertyGrid@@AAEPAVCWnd@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
