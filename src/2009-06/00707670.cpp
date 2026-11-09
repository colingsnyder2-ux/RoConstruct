// from server: 100% by auto
// roc 2009-06 00707670  unit: std::D::DU?$char_traits::V?$basic_string::?$thread_specific_ptr::delete_data  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00707670
//
// 00707670  83ec08               sub esp, 8
// 00707673  56                   push esi
// 00707674  8b742410             mov esi, dword ptr [esp + 0x10]
// 00707678  83c8ff               or eax, 0xffffffff
// 0070767b  894608               mov dword ptr [esi + 8], eax
// 0070767e  89460c               mov dword ptr [esi + 0xc], eax
// 00707681  b8feffffff           mov eax, 0xfffffffe
// 00707686  89442404             mov dword ptr [esp + 4], eax
// 0070768a  89442410             mov dword ptr [esp + 0x10], eax
// 0070768e  8d442404             lea eax, [esp + 4]
// 00707692  50                   push eax
// 00707693  8d542414             lea edx, [esp + 0x14]
// 00707697  8d4e18               lea ecx, [esi + 0x18]
// 0070769a  52                   push edx
// 0070769b  c70600000000         mov dword ptr [esi], 0
// 007076a1  c6461001             mov byte ptr [esi + 0x10], 1
// 007076a5  c7442410ffffff7f     mov dword ptr [esp + 0x10], 0x7fffffff
// 007076ad  e8aea1d0ff           call 0x411860
// 007076b2  8bc6                 mov eax, esi
// 007076b4  5e                   pop esi
// 007076b5  83c408               add esp, 8
// 007076b8  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?sentinel@timeout@detail@boost@@SA?AU123@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
