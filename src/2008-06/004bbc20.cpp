// from server: 100% by auto
// roc 2008-06 004bbc20  unit: ProfiledRakPeer  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bbc20
//
// 004bbc20  51                   push ecx
// 004bbc21  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004bbc25  8b542408             mov edx, dword ptr [esp + 8]
// 004bbc29  8b8914070000         mov ecx, dword ptr [ecx + 0x714]
// 004bbc2f  50                   push eax
// 004bbc30  52                   push edx
// 004bbc31  8b542418             mov edx, dword ptr [esp + 0x18]
// 004bbc35  6a02                 push 2
// 004bbc37  8d44240c             lea eax, [esp + 0xc]
// 004bbc3b  50                   push eax
// 004bbc3c  c644241000           mov byte ptr [esp + 0x10], 0
// 004bbc41  c644241101           mov byte ptr [esp + 0x11], 1
// 004bbc46  8b0491               mov eax, dword ptr [ecx + edx*4]
// 004bbc49  50                   push eax
// 004bbc4a  b9311d9700           mov ecx, 0x971d31
// 004bbc4f  e8dc2b0100           call 0x4ce830
// 004bbc54  59                   pop ecx
// 004bbc55  c20c00               ret 0xc
// library openrbx-raknet/RakPeer.cpp (function ?SendTTL1@RakPeer@@UAEXPBDGI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
