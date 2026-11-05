// roc 2012-06 006d4260  unit: boost::io::Vtoo_few_args::?$error_info_injector  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006d4260
//
// 006d4260  56                   push esi
// 006d4261  8b742408             mov esi, dword ptr [esp + 8]
// 006d4265  85f6                 test esi, esi
// 006d4267  7418                 je 0x6d4281
// 006d4269  8d4e04               lea ecx, [esi + 4]
// 006d426c  e8ef7a2a00           call 0x97bd60
// 006d4271  8bce                 mov ecx, esi
// 006d4273  e8e87a2a00           call 0x97bd60
// 006d4278  56                   push esi
// 006d4279  e896de2a00           call 0x982114
// 006d427e  83c404               add esp, 4
// 006d4281  5e                   pop esi
// 006d4282  c3                   ret 
// copied from an identical function in another client (function ??$OP_DELETE@UFileToPush@FileListTransfer@RakNet@@@RakNet@@YAXPAUFileToPush@FileListTransfer@0@PBDI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: raknet-4.081 FileListTransfer.cpp