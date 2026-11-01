// from server: 100% by auto
// roc 2009-12 006678e0  unit: VThreadLogManager::?$thread_specific_ptr::PAUdelete_data::?$sp_counted_impl_pd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006678e0
//
// 006678e0  56                   push esi
// 006678e1  8b742408             mov esi, dword ptr [esp + 8]
// 006678e5  85f6                 test esi, esi
// 006678e7  7418                 je 0x667901
// 006678e9  8d4e04               lea ecx, [esi + 4]
// 006678ec  e8efff1700           call 0x7e78e0
// 006678f1  8bce                 mov ecx, esi
// 006678f3  e8e8ff1700           call 0x7e78e0
// 006678f8  56                   push esi
// 006678f9  e85cbf1800           call 0x7f385a
// 006678fe  83c404               add esp, 4
// 00667901  5e                   pop esi
// 00667902  c3                   ret 
// library raknet-4.081/FileListTransfer.cpp (function ??$OP_DELETE@UFileToPush@FileListTransfer@RakNet@@@RakNet@@YAXPAUFileToPush@FileListTransfer@0@PBDI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: raknet-4.081 FileListTransfer.cpp
