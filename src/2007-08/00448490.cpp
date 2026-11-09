// from server: 100% by tester
// roc 2007-03 00447b10  unit: seg_00440000  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00447b10
//
// 00447b10  85f6                 test esi, esi
// 00447b12  7503                 jne 0x447b17
// 00447b14  33c0                 xor eax, eax
// 00447b16  c3                   ret 
// 00447b17  66833e00             cmp word ptr [esi], 0
// 00447b1b  8bc6                 mov eax, esi
// 00447b1d  8bce                 mov ecx, esi
// 00447b1f  7425                 je 0x447b46
// 00447b21  0fb711               movzx edx, word ptr [ecx]
// 00447b24  6685d2               test dx, dx
// 00447b27  7403                 je 0x447b2c
// 00447b29  83c102               add ecx, 2
// 00447b2c  6683fa5c             cmp dx, 0x5c
// 00447b30  740c                 je 0x447b3e
// 00447b32  6683fa2f             cmp dx, 0x2f
// 00447b36  7406                 je 0x447b3e
// 00447b38  6683fa3a             cmp dx, 0x3a
// 00447b3c  7502                 jne 0x447b40
// 00447b3e  8bc1                 mov eax, ecx
// 00447b40  66833900             cmp word ptr [ecx], 0
// 00447b44  75db                 jne 0x447b21
// 00447b46  2bc6                 sub eax, esi
// 00447b48  d1f8                 sar eax, 1
// 00447b4a  c3                   ret 
// library atl-8.0/atl.cpp (function ?AtlGetDirLen@ATL@@YGIPB_W@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
