// from server: 100% by auto
// roc 2008-06 004c1d30  unit: ProfiledRakPeer  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c1d30
//
// 004c1d30  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004c1d34  8b542408             mov edx, dword ptr [esp + 8]
// 004c1d38  6a01                 push 1
// 004c1d3a  6a00                 push 0
// 004c1d3c  50                   push eax
// 004c1d3d  52                   push edx
// 004c1d3e  e89de0ffff           call 0x4bfde0
// 004c1d43  85c0                 test eax, eax
// 004c1d45  740d                 je 0x4c1d54
// 004c1d47  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004c1d4b  51                   push ecx
// 004c1d4c  8d4818               lea ecx, [eax + 0x18]
// 004c1d4f  e89ccc0000           call 0x4ce9f0
// 004c1d54  c20c00               ret 0xc
// library openrbx-raknet/RakPeer.cpp (function ?SetTimeoutTime@RakPeer@@UAEXIUSystemAddress@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
