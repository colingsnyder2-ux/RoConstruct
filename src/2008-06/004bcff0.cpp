// from server: 100% by auto
// roc 2008-06 004bcff0  unit: ProfiledRakPeer  size: 353 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bcff0
//
// 004bcff0  83ec10               sub esp, 0x10
// 004bcff3  55                   push ebp
// 004bcff4  8be9                 mov ebp, ecx
// 004bcff6  896c2410             mov dword ptr [esp + 0x10], ebp
// 004bcffa  e811c90000           call 0x4c9910
// 004bcfff  8944240c             mov dword ptr [esp + 0xc], eax
// 004bd003  8b442418             mov eax, dword ptr [esp + 0x18]
// 004bd007  85c0                 test eax, eax
// 004bd009  0f843b010000         je 0x4bd14a
// 004bd00f  803800               cmp byte ptr [eax], 0
// 004bd012  0f8432010000         je 0x4bd14a
// 004bd018  8d5001               lea edx, [eax + 1]
// 004bd01b  eb03                 jmp 0x4bd020
// 004bd01d  8d4900               lea ecx, [ecx]
// 004bd020  8a08                 mov cl, byte ptr [eax]
// 004bd022  40                   inc eax
// 004bd023  84c9                 test cl, cl
// 004bd025  75f9                 jne 0x4bd020
// 004bd027  2bc2                 sub eax, edx
// 004bd029  83f80f               cmp eax, 0xf
// 004bd02c  0f8718010000         ja 0x4bd14a
// 004bd032  56                   push esi
// 004bd033  57                   push edi
// 004bd034  8dbd84020000         lea edi, [ebp + 0x284]
// 004bd03a  8bcf                 mov ecx, edi
// 004bd03c  33f6                 xor esi, esi
// 004bd03e  897c2410             mov dword ptr [esp + 0x10], edi
// 004bd042  e8496f0100           call 0x4d3f90
// 004bd047  8bada0020000         mov ebp, dword ptr [ebp + 0x2a0]
// 004bd04d  85ed                 test ebp, ebp
// 004bd04f  764c                 jbe 0x4bd09d
// 004bd051  8b442418             mov eax, dword ptr [esp + 0x18]
// 004bd055  8bb89c020000         mov edi, dword ptr [eax + 0x29c]
// 004bd05b  897c240c             mov dword ptr [esp + 0xc], edi
// 004bd05f  90                   nop 
// 004bd060  8b0f                 mov ecx, dword ptr [edi]
// 004bd062  8b09                 mov ecx, dword ptr [ecx]
// 004bd064  8b442420             mov eax, dword ptr [esp + 0x20]
// 004bd068  8a10                 mov dl, byte ptr [eax]
// 004bd06a  3a11                 cmp dl, byte ptr [ecx]
// 004bd06c  751a                 jne 0x4bd088
// 004bd06e  84d2                 test dl, dl
// 004bd070  7412                 je 0x4bd084
// 004bd072  8a5001               mov dl, byte ptr [eax + 1]
// 004bd075  3a5101               cmp dl, byte ptr [ecx + 1]
// 004bd078  750e                 jne 0x4bd088
// 004bd07a  83c002               add eax, 2
// 004bd07d  83c102               add ecx, 2
// 004bd080  84d2                 test dl, dl
// 004bd082  75e4                 jne 0x4bd068
// 004bd084  33c0                 xor eax, eax
// 004bd086  eb05                 jmp 0x4bd08d
// 004bd088  1bc0                 sbb eax, eax
// 004bd08a  83d8ff               sbb eax, -1
// 004bd08d  85c0                 test eax, eax
// 004bd08f  7435                 je 0x4bd0c6
// 004bd091  46                   inc esi
// 004bd092  83c704               add edi, 4
// 004bd095  3bf5                 cmp esi, ebp
// 004bd097  72c7                 jb 0x4bd060
// 004bd099  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004bd09d  8bcf                 mov ecx, edi
// 004bd09f  e8fc6e0100           call 0x4d3fa0
// 004bd0a4  6a08                 push 8
// 004bd0a6  e875381e00           call 0x6a0920
// 004bd0ab  6a10                 push 0x10
// 004bd0ad  8bf0                 mov esi, eax
// 004bd0af  e86c381e00           call 0x6a0920
// 004bd0b4  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004bd0b8  83c408               add esp, 8
// 004bd0bb  8906                 mov dword ptr [esi], eax
// 004bd0bd  85c9                 test ecx, ecx
// 004bd0bf  754b                 jne 0x4bd10c
// 004bd0c1  894e04               mov dword ptr [esi + 4], ecx
// 004bd0c4  eb4f                 jmp 0x4bd115
// 004bd0c6  8b442424             mov eax, dword ptr [esp + 0x24]
// 004bd0ca  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004bd0ce  85c0                 test eax, eax
// 004bd0d0  751c                 jne 0x4bd0ee
// 004bd0d2  8b04b2               mov eax, dword ptr [edx + esi*4]
// 004bd0d5  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004bd0d9  c7400400000000       mov dword ptr [eax + 4], 0
// 004bd0e0  e8bb6e0100           call 0x4d3fa0
// 004bd0e5  5f                   pop edi
// 004bd0e6  5e                   pop esi
// 004bd0e7  5d                   pop ebp
// 004bd0e8  83c410               add esp, 0x10
// 004bd0eb  c20800               ret 8
// 004bd0ee  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004bd0f2  03c8                 add ecx, eax
// 004bd0f4  8b04b2               mov eax, dword ptr [edx + esi*4]
// 004bd0f7  894804               mov dword ptr [eax + 4], ecx
// 004bd0fa  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004bd0fe  e89d6e0100           call 0x4d3fa0
// 004bd103  5f                   pop edi
// 004bd104  5e                   pop esi
// 004bd105  5d                   pop ebp
// 004bd106  83c410               add esp, 0x10
// 004bd109  c20800               ret 8
// 004bd10c  8b542414             mov edx, dword ptr [esp + 0x14]
// 004bd110  03d1                 add edx, ecx
// 004bd112  895604               mov dword ptr [esi + 4], edx
// 004bd115  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004bd119  8bd0                 mov edx, eax
// 004bd11b  eb03                 jmp 0x4bd120
// 004bd11d  8d4900               lea ecx, [ecx]
// 004bd120  8a01                 mov al, byte ptr [ecx]
// 004bd122  8802                 mov byte ptr [edx], al
// 004bd124  41                   inc ecx
// 004bd125  42                   inc edx
// 004bd126  84c0                 test al, al
// 004bd128  75f6                 jne 0x4bd120
// 004bd12a  8bcf                 mov ecx, edi
// 004bd12c  e85f6e0100           call 0x4d3f90
// 004bd131  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004bd135  56                   push esi
// 004bd136  81c19c020000         add ecx, 0x29c
// 004bd13c  e8dfefffff           call 0x4bc120
// 004bd141  8bcf                 mov ecx, edi
// 004bd143  e8586e0100           call 0x4d3fa0
// 004bd148  5f                   pop edi
// 004bd149  5e                   pop esi
// 004bd14a  5d                   pop ebp
// 004bd14b  83c410               add esp, 0x10
// 004bd14e  c20800               ret 8
// library openrbx-raknet/RakPeer.cpp (function ?AddToBanList@RakPeer@@UAEXPBDI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
