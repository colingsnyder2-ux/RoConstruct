// from server: 100% by auto
// roc 2008-06 004bfee0  unit: ProfiledRakPeer  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bfee0
//
// 004bfee0  8b442408             mov eax, dword ptr [esp + 8]
// 004bfee4  8b542404             mov edx, dword ptr [esp + 4]
// 004bfee8  6a01                 push 1
// 004bfeea  6a01                 push 1
// 004bfeec  50                   push eax
// 004bfeed  52                   push edx
// 004bfeee  e8edfeffff           call 0x4bfde0
// 004bfef3  85c0                 test eax, eax
// 004bfef5  7503                 jne 0x4bfefa
// 004bfef7  c20800               ret 8
// 004bfefa  53                   push ebx
// 004bfefb  56                   push esi
// 004bfefc  57                   push edi
// 004bfefd  33db                 xor ebx, ebx
// 004bfeff  bfffff0000           mov edi, 0xffff
// 004bff04  33f6                 xor esi, esi
// 004bff06  8d88e4070000         lea ecx, [eax + 0x7e4]
// 004bff0c  8d642400             lea esp, [esp]
// 004bff10  0fb711               movzx edx, word ptr [ecx]
// 004bff13  b8ffff0000           mov eax, 0xffff
// 004bff18  663bd0               cmp dx, ax
// 004bff1b  7415                 je 0x4bff32
// 004bff1d  0fb7d2               movzx edx, dx
// 004bff20  3bd7                 cmp edx, edi
// 004bff22  7d05                 jge 0x4bff29
// 004bff24  8b5904               mov ebx, dword ptr [ecx + 4]
// 004bff27  8bfa                 mov edi, edx
// 004bff29  46                   inc esi
// 004bff2a  83c108               add ecx, 8
// 004bff2d  83fe05               cmp esi, 5
// 004bff30  7cde                 jl 0x4bff10
// 004bff32  5f                   pop edi
// 004bff33  5e                   pop esi
// 004bff34  8bc3                 mov eax, ebx
// 004bff36  5b                   pop ebx
// 004bff37  c20800               ret 8
// library openrbx-raknet/RakPeer.cpp (function ?GetBestClockDifferential@RakPeer@@IBEIUSystemAddress@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
