// from server: 100% by auto
// roc 2009-06 007095a0  unit: boost::detail::thread_data_base  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007095a0
//
// 007095a0  56                   push esi
// 007095a1  8bf1                 mov esi, ecx
// 007095a3  ff1518e28900         call dword ptr [0x89e218]
// 007095a9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007095ad  8906                 mov dword ptr [esi], eax
// 007095af  8b442408             mov eax, dword ptr [esp + 8]
// 007095b3  8d5618               lea edx, [esi + 0x18]
// 007095b6  68802c4100           push 0x412c80
// 007095bb  52                   push edx
// 007095bc  894608               mov dword ptr [esi + 8], eax
// 007095bf  894e0c               mov dword ptr [esi + 0xc], ecx
// 007095c2  c6461001             mov byte ptr [esi + 0x10], 1
// 007095c6  e80599d0ff           call 0x412ed0
// 007095cb  83c408               add esp, 8
// 007095ce  8bc6                 mov eax, esi
// 007095d0  5e                   pop esi
// 007095d1  c20800               ret 8
// library boost-1.40.0/libs\thread\src\win32\thread.cpp (function ??0timeout@detail@boost@@QAE@_K@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/thread/src/win32/thread.cpp
