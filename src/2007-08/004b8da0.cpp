// from server: 100% by colin
// roc 2007-08 004b8da0  unit: RakPeer  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004b8da0
//
// 004b8da0  56                   push esi
// 004b8da1  8b742408             mov esi, dword ptr [esp + 8]
// 004b8da5  83fe0a               cmp esi, 0xa
// 004b8da8  7205                 jb 0x4b8daf
// 004b8daa  be09000000           mov esi, 9
// 004b8daf  68a0000000           push 0xa0
// 004b8db4  6a00                 push 0
// 004b8db6  68f0eb8b00           push 0x8bebf0
// 004b8dbb  e8cc7d1700           call 0x630b8c
// 004b8dc0  83c40c               add esp, 0xc
// 004b8dc3  68f0eb8b00           push 0x8bebf0
// 004b8dc8  b9e9ef8b00           mov ecx, 0x8befe9
// 004b8dcd  e89ebb0000           call 0x4c4970
// 004b8dd2  8bc6                 mov eax, esi
// 004b8dd4  c1e004               shl eax, 4
// 004b8dd7  05f0eb8b00           add eax, 0x8bebf0
// 004b8ddc  5e                   pop esi
// 004b8ddd  c20400               ret 4
// copied from an identical function in another client (function ?GetLocalIP@RakPeer@@UAEPBDI@Z)

// from server: 100% by tester
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lang: cpp
// roc-lib: openrbx-raknet RakPeer.cpp