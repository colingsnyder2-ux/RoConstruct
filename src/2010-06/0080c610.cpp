// from server: 100% by auto
// roc 2010-06 0080c610  unit: CXTPTabClientWnd  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080c610
//
// 0080c610  53                   push ebx
// 0080c611  56                   push esi
// 0080c612  57                   push edi
// 0080c613  8bf9                 mov edi, ecx
// 0080c615  33f6                 xor esi, esi
// 0080c617  e864dfffff           call 0x80a580
// 0080c61c  85c0                 test eax, eax
// 0080c61e  7e1c                 jle 0x80c63c
// 0080c620  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0080c624  56                   push esi
// 0080c625  8bcf                 mov ecx, edi
// 0080c627  e894eeffff           call 0x80b4c0
// 0080c62c  3bc3                 cmp eax, ebx
// 0080c62e  7415                 je 0x80c645
// 0080c630  8bcf                 mov ecx, edi
// 0080c632  46                   inc esi
// 0080c633  e848dfffff           call 0x80a580
// 0080c638  3bf0                 cmp esi, eax
// 0080c63a  7ce8                 jl 0x80c624
// 0080c63c  5f                   pop edi
// 0080c63d  5e                   pop esi
// 0080c63e  83c8ff               or eax, 0xffffffff
// 0080c641  5b                   pop ebx
// 0080c642  c20400               ret 4
// 0080c645  5f                   pop edi
// 0080c646  8bc6                 mov eax, esi
// 0080c648  5e                   pop esi
// 0080c649  5b                   pop ebx
// 0080c64a  c20400               ret 4
// copied from an identical function in another client (function ?FindTabIndex@CXTPTabClientWnd@ns_ROCX000007@ns_ROCX0000bf@@QAEHH@Z)

namespace ns_ROCX000007 {
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarRecurrencePattern.cpp
}
