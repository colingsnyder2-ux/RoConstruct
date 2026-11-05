// from server: 100% by auto
// roc 2011-06 005428c0  unit: G3D::Sphere  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005428c0
//
// 005428c0  64a100000000         mov eax, dword ptr fs:[0]
// 005428c6  6aff                 push -1
// 005428c8  68beec9d00           push 0x9decbe
// 005428cd  50                   push eax
// 005428ce  64892500000000       mov dword ptr fs:[0], esp
// 005428d5  b801000000           mov eax, 1
// 005428da  83ec08               sub esp, 8
// 005428dd  840558a3cb00         test byte ptr [0xcba358], al
// 005428e3  753d                 jne 0x542922
// 005428e5  090558a3cb00         or dword ptr [0xcba358], eax
// 005428eb  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005428f3  e838050000           call 0x542e30
// 005428f8  d91c24               fstp dword ptr [esp]
// 005428fb  e830050000           call 0x542e30
// 00542900  d95c2404             fstp dword ptr [esp + 4]
// 00542904  e827050000           call 0x542e30
// 00542909  d90424               fld dword ptr [esp]
// 0054290c  d91d4ca3cb00         fstp dword ptr [0xcba34c]
// 00542912  d9442404             fld dword ptr [esp + 4]
// 00542916  d91d50a3cb00         fstp dword ptr [0xcba350]
// 0054291c  d91d54a3cb00         fstp dword ptr [0xcba354]
// 00542922  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00542926  b84ca3cb00           mov eax, 0xcba34c
// 0054292b  64890d00000000       mov dword ptr fs:[0], ecx
// 00542932  83c414               add esp, 0x14
// 00542935  c3                   ret 
// library rbx2016-g3d/AABox.cpp (function ?inf@Vector3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d AABox.cpp
