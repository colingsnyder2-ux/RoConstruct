// roc 2012-06 00859dd0  unit: UString_sink::?$stream_buffer  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00859dd0
//
// 00859dd0  6aff                 push -1
// 00859dd2  6892e1ac00           push 0xace192
// 00859dd7  64a100000000         mov eax, dword ptr fs:[0]
// 00859ddd  50                   push eax
// 00859dde  64892500000000       mov dword ptr fs:[0], esp
// 00859de5  83ec20               sub esp, 0x20
// 00859de8  56                   push esi
// 00859de9  681445bd00           push 0xbd4514
// 00859dee  8d4c240c             lea ecx, [esp + 0xc]
// 00859df2  c744240800000000     mov dword ptr [esp + 8], 0
// 00859dfa  ff154826b200         call dword ptr [0xb22648]
// 00859e00  8b742434             mov esi, dword ptr [esp + 0x34]
// 00859e04  8d442408             lea eax, [esp + 8]
// 00859e08  50                   push eax
// 00859e09  8bce                 mov ecx, esi
// 00859e0b  c744243001000000     mov dword ptr [esp + 0x30], 1
// 00859e13  e88822bbff           call 0x40c0a0
// 00859e18  c7065444bd00         mov dword ptr [esi], 0xbd4454
// 00859e1e  8d4c2408             lea ecx, [esp + 8]
// 00859e22  c744240401000000     mov dword ptr [esp + 4], 1
// 00859e2a  c644242c00           mov byte ptr [esp + 0x2c], 0
// 00859e2f  ff153c26b200         call dword ptr [0xb2263c]
// 00859e35  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00859e39  8bc6                 mov eax, esi
// 00859e3b  5e                   pop esi
// 00859e3c  64890d00000000       mov dword ptr fs:[0], ecx
// 00859e43  83c42c               add esp, 0x2c
// 00859e46  c3                   ret 
// copied from an identical function in another client (function ?cant_write@detail@iostreams@boost@@YA?AVfailure@ios_base@std@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1-dll roc_boost_resume_389d0bd197ae56e1.cpp