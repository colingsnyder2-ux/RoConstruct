// from server: 100% by auto
// roc 2009-12 0079db40  unit: seg_00790000  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079db40
//
// 0079db40  53                   push ebx
// 0079db41  55                   push ebp
// 0079db42  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 0079db46  56                   push esi
// 0079db47  8bf0                 mov esi, eax
// 0079db49  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0079db4c  57                   push edi
// 0079db4d  85db                 test ebx, ebx
// 0079db4f  7509                 jne 0x79db5a
// 0079db51  85ed                 test ebp, ebp
// 0079db53  7405                 je 0x79db5a
// 0079db55  bb01000000           mov ebx, 1
// 0079db5a  8b4608               mov eax, dword ptr [esi + 8]
// 0079db5d  6840b19e00           push 0x9eb140
// 0079db62  53                   push ebx
// 0079db63  50                   push eax
// 0079db64  e817c2feff           call 0x789d80
// 0079db69  83c40c               add esp, 0xc
// 0079db6c  33ff                 xor edi, edi
// 0079db6e  85db                 test ebx, ebx
// 0079db70  7e10                 jle 0x79db82
// 0079db72  8b442418             mov eax, dword ptr [esp + 0x18]
// 0079db76  8bcd                 mov ecx, ebp
// 0079db78  e843ffffff           call 0x79dac0
// 0079db7d  47                   inc edi
// 0079db7e  3bfb                 cmp edi, ebx
// 0079db80  7cf0                 jl 0x79db72
// 0079db82  5f                   pop edi
// 0079db83  5e                   pop esi
// 0079db84  5d                   pop ebp
// 0079db85  8bc3                 mov eax, ebx
// 0079db87  5b                   pop ebx
// 0079db88  c3                   ret 
// library lua-5.1/lstrlib.c (function _push_captures)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstrlib.c
