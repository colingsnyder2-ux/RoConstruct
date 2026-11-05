// from server: 100% by auto
// roc 2012-06 0062e880  unit: G3D::Line  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062e880
//
// 0062e880  64a100000000         mov eax, dword ptr fs:[0]
// 0062e886  6aff                 push -1
// 0062e888  688e46ab00           push 0xab468e
// 0062e88d  50                   push eax
// 0062e88e  64892500000000       mov dword ptr fs:[0], esp
// 0062e895  b801000000           mov eax, 1
// 0062e89a  83ec08               sub esp, 8
// 0062e89d  84051087e200         test byte ptr [0xe28710], al
// 0062e8a3  753d                 jne 0x62e8e2
// 0062e8a5  09051087e200         or dword ptr [0xe28710], eax
// 0062e8ab  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0062e8b3  e8e8d7ffff           call 0x62c0a0
// 0062e8b8  d91c24               fstp dword ptr [esp]
// 0062e8bb  e8e0d7ffff           call 0x62c0a0
// 0062e8c0  d95c2404             fstp dword ptr [esp + 4]
// 0062e8c4  e8d7d7ffff           call 0x62c0a0
// 0062e8c9  d90424               fld dword ptr [esp]
// 0062e8cc  d91d0487e200         fstp dword ptr [0xe28704]
// 0062e8d2  d9442404             fld dword ptr [esp + 4]
// 0062e8d6  d91d0887e200         fstp dword ptr [0xe28708]
// 0062e8dc  d91d0c87e200         fstp dword ptr [0xe2870c]
// 0062e8e2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0062e8e6  b80487e200           mov eax, 0xe28704
// 0062e8eb  64890d00000000       mov dword ptr fs:[0], ecx
// 0062e8f2  83c414               add esp, 0x14
// 0062e8f5  c3                   ret 
// library rbx2016-g3d/AABox.cpp (function ?inf@Vector3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d AABox.cpp
