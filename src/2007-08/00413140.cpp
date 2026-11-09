// from server: 100% by auto
// roc 2007-08 00413140  unit: std::runtime_error  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00413140
//
// 00413140  8b01                 mov eax, dword ptr [ecx]
// 00413142  8b542404             mov edx, dword ptr [esp + 4]
// 00413146  83e810               sub eax, 0x10
// 00413149  56                   push esi
// 0041314a  8b7004               mov esi, dword ptr [eax + 4]
// 0041314d  3bf2                 cmp esi, edx
// 0041314f  7e02                 jle 0x413153
// 00413151  8bd6                 mov edx, esi
// 00413153  83780c01             cmp dword ptr [eax + 0xc], 1
// 00413157  5e                   pop esi
// 00413158  7e09                 jle 0x413163
// 0041315a  89542404             mov dword ptr [esp + 4], edx
// 0041315e  e9cdfeffff           jmp 0x413030
// 00413163  8b4008               mov eax, dword ptr [eax + 8]
// 00413166  3bc2                 cmp eax, edx
// 00413168  7d1f                 jge 0x413189
// 0041316a  3d00040000           cmp eax, 0x400
// 0041316f  7e07                 jle 0x413178
// 00413171  0500040000           add eax, 0x400
// 00413176  eb02                 jmp 0x41317a
// 00413178  03c0                 add eax, eax
// 0041317a  3bc2                 cmp eax, edx
// 0041317c  7d02                 jge 0x413180
// 0041317e  8bc2                 mov eax, edx
// 00413180  89442404             mov dword ptr [esp + 4], eax
// 00413184  e927ffffff           jmp 0x4130b0
// 00413189  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ?PrepareWrite2@?$CSimpleStringT@D$0A@@ATL@@AAEXH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
