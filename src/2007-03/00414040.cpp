// from server: 100% by auto
// roc 2007-03 00414040  unit: seg_00410000  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00414040
//
// 00414040  8b01                 mov eax, dword ptr [ecx]
// 00414042  8b542404             mov edx, dword ptr [esp + 4]
// 00414046  83e810               sub eax, 0x10
// 00414049  56                   push esi
// 0041404a  8b7004               mov esi, dword ptr [eax + 4]
// 0041404d  3bf2                 cmp esi, edx
// 0041404f  7e02                 jle 0x414053
// 00414051  8bd6                 mov edx, esi
// 00414053  83780c01             cmp dword ptr [eax + 0xc], 1
// 00414057  5e                   pop esi
// 00414058  7e09                 jle 0x414063
// 0041405a  89542404             mov dword ptr [esp + 4], edx
// 0041405e  e9cdfeffff           jmp 0x413f30
// 00414063  8b4008               mov eax, dword ptr [eax + 8]
// 00414066  3bc2                 cmp eax, edx
// 00414068  7d1f                 jge 0x414089
// 0041406a  3d00040000           cmp eax, 0x400
// 0041406f  7e07                 jle 0x414078
// 00414071  0500040000           add eax, 0x400
// 00414076  eb02                 jmp 0x41407a
// 00414078  03c0                 add eax, eax
// 0041407a  3bc2                 cmp eax, edx
// 0041407c  7d02                 jge 0x414080
// 0041407e  8bc2                 mov eax, edx
// 00414080  89442404             mov dword ptr [esp + 4], eax
// 00414084  e927ffffff           jmp 0x413fb0
// 00414089  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ?PrepareWrite2@?$CSimpleStringT@D$0A@@ATL@@AAEXH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
