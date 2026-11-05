// from server: 100% by auto
// roc 2009-06 00708cc0  unit: boost::detail::thread_data_base  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00708cc0
//
// 00708cc0  8b442404             mov eax, dword ptr [esp + 4]
// 00708cc4  56                   push esi
// 00708cc5  8bf1                 mov esi, ecx
// 00708cc7  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00708ccb  8906                 mov dword ptr [esi], eax
// 00708ccd  8b442410             mov eax, dword ptr [esp + 0x10]
// 00708cd1  894e04               mov dword ptr [esi + 4], ecx
// 00708cd4  894608               mov dword ptr [esi + 8], eax
// 00708cd7  85c0                 test eax, eax
// 00708cd9  7410                 je 0x708ceb
// 00708cdb  83c004               add eax, 4
// 00708cde  ba01000000           mov edx, 1
// 00708ce3  f00fc110             lock xadd dword ptr [eax], edx
// 00708ce7  8b442410             mov eax, dword ptr [esp + 0x10]
// 00708ceb  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00708cef  8b542418             mov edx, dword ptr [esp + 0x18]
// 00708cf3  894e0c               mov dword ptr [esi + 0xc], ecx
// 00708cf6  895610               mov dword ptr [esi + 0x10], edx
// 00708cf9  85c0                 test eax, eax
// 00708cfb  7434                 je 0x708d31
// 00708cfd  57                   push edi
// 00708cfe  8bf8                 mov edi, eax
// 00708d00  83c004               add eax, 4
// 00708d03  83c9ff               or ecx, 0xffffffff
// 00708d06  f00fc108             lock xadd dword ptr [eax], ecx
// 00708d0a  751e                 jne 0x708d2a
// 00708d0c  8b17                 mov edx, dword ptr [edi]
// 00708d0e  8b4204               mov eax, dword ptr [edx + 4]
// 00708d11  8bcf                 mov ecx, edi
// 00708d13  ffd0                 call eax
// 00708d15  8d4f08               lea ecx, [edi + 8]
// 00708d18  83caff               or edx, 0xffffffff
// 00708d1b  f00fc111             lock xadd dword ptr [ecx], edx
// 00708d1f  7509                 jne 0x708d2a
// 00708d21  8b07                 mov eax, dword ptr [edi]
// 00708d23  8b5008               mov edx, dword ptr [eax + 8]
// 00708d26  8bcf                 mov ecx, edi
// 00708d28  ffd2                 call edx
// 00708d2a  5f                   pop edi
// 00708d2b  8bc6                 mov eax, esi
// 00708d2d  5e                   pop esi
// 00708d2e  c21400               ret 0x14
// 00708d31  8bc6                 mov eax, esi
// 00708d33  5e                   pop esi
// 00708d34  c21400               ret 0x14
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??0tss_data_node@detail@boost@@QAE@PBXV?$shared_ptr@Utss_cleanup_function@detail@boost@@@2@PAXPAU012@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
