// from server: 100% by auto
// roc 2008-06 004bc670  unit: ProfiledRakPeer  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bc670
//
// 004bc670  8b442404             mov eax, dword ptr [esp + 4]
// 004bc674  33d2                 xor edx, edx
// 004bc676  83c008               add eax, 8
// 004bc679  56                   push esi
// 004bc67a  8d9b00000000         lea ebx, [ebx]
// 004bc680  8b48f8               mov ecx, dword ptr [eax - 8]
// 004bc683  8d71ff               lea esi, [ecx - 1]
// 004bc686  8970f8               mov dword ptr [eax - 8], esi
// 004bc689  85c9                 test ecx, ecx
// 004bc68b  7530                 jne 0x4bc6bd
// 004bc68d  8b48fc               mov ecx, dword ptr [eax - 4]
// 004bc690  8d71ff               lea esi, [ecx - 1]
// 004bc693  8970fc               mov dword ptr [eax - 4], esi
// 004bc696  85c9                 test ecx, ecx
// 004bc698  7523                 jne 0x4bc6bd
// 004bc69a  8b08                 mov ecx, dword ptr [eax]
// 004bc69c  8d71ff               lea esi, [ecx - 1]
// 004bc69f  8930                 mov dword ptr [eax], esi
// 004bc6a1  85c9                 test ecx, ecx
// 004bc6a3  7518                 jne 0x4bc6bd
// 004bc6a5  8b4804               mov ecx, dword ptr [eax + 4]
// 004bc6a8  8d71ff               lea esi, [ecx - 1]
// 004bc6ab  897004               mov dword ptr [eax + 4], esi
// 004bc6ae  85c9                 test ecx, ecx
// 004bc6b0  750b                 jne 0x4bc6bd
// 004bc6b2  83c204               add edx, 4
// 004bc6b5  83c010               add eax, 0x10
// 004bc6b8  83fa10               cmp edx, 0x10
// 004bc6bb  72c3                 jb 0x4bc680
// 004bc6bd  5e                   pop esi
// 004bc6be  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$decrement@$$BY0BA@I@big@@YAXAAY0BA@I@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
