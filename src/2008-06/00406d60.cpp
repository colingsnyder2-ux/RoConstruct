// from server: 100% by auto
// roc 2008-06 00406d60  unit: boost::thread_exception  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00406d60
//
// 00406d60  8b542404             mov edx, dword ptr [esp + 4]
// 00406d64  56                   push esi
// 00406d65  8bf1                 mov esi, ecx
// 00406d67  8b06                 mov eax, dword ptr [esi]
// 00406d69  8b48f0               mov ecx, dword ptr [eax - 0x10]
// 00406d6c  83e810               sub eax, 0x10
// 00406d6f  395008               cmp dword ptr [eax + 8], edx
// 00406d72  7d15                 jge 0x406d89
// 00406d74  85d2                 test edx, edx
// 00406d76  7e11                 jle 0x406d89
// 00406d78  57                   push edi
// 00406d79  8b39                 mov edi, dword ptr [ecx]
// 00406d7b  6a01                 push 1
// 00406d7d  52                   push edx
// 00406d7e  50                   push eax
// 00406d7f  8b4708               mov eax, dword ptr [edi + 8]
// 00406d82  ffd0                 call eax
// 00406d84  5f                   pop edi
// 00406d85  85c0                 test eax, eax
// 00406d87  7505                 jne 0x406d8e
// 00406d89  e822f9ffff           call 0x4066b0
// 00406d8e  83c010               add eax, 0x10
// 00406d91  8906                 mov dword ptr [esi], eax
// 00406d93  5e                   pop esi
// 00406d94  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkey.cpp (function ?Reallocate@?$CSimpleStringT@D$0A@@ATL@@AAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkey.cpp
