// from server: 100% by auto
// roc 2007-03 00614cb0  unit: seg_00610000  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00614cb0
//
// 00614cb0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00614cb4  53                   push ebx
// 00614cb5  56                   push esi
// 00614cb6  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00614cba  8b4618               mov eax, dword ptr [esi + 0x18]
// 00614cbd  3b461c               cmp eax, dword ptr [esi + 0x1c]
// 00614cc0  57                   push edi
// 00614cc1  7e54                 jle 0x614d17
// 00614cc3  85c0                 test eax, eax
// 00614cc5  7473                 je 0x614d3a
// 00614cc7  8b16                 mov edx, dword ptr [esi]
// 00614cc9  8b520c               mov edx, dword ptr [edx + 0xc]
// 00614ccc  8d7c82fc             lea edi, [edx + eax*4 - 4]
// 00614cd0  8b07                 mov eax, dword ptr [edi]
// 00614cd2  8bd0                 mov edx, eax
// 00614cd4  83e23f               and edx, 0x3f
// 00614cd7  80fa03               cmp dl, 3
// 00614cda  753b                 jne 0x614d17
// 00614cdc  8bd8                 mov ebx, eax
// 00614cde  c1eb06               shr ebx, 6
// 00614ce1  8bd0                 mov edx, eax
// 00614ce3  81e3ff000000         and ebx, 0xff
// 00614ce9  c1ea17               shr edx, 0x17
// 00614cec  3bd9                 cmp ebx, ecx
// 00614cee  7f27                 jg 0x614d17
// 00614cf0  8d5a01               lea ebx, [edx + 1]
// 00614cf3  3bcb                 cmp ecx, ebx
// 00614cf5  7f20                 jg 0x614d17
// 00614cf7  8b742418             mov esi, dword ptr [esp + 0x18]
// 00614cfb  8d5c31ff             lea ebx, [ecx + esi - 1]
// 00614cff  3bda                 cmp ebx, edx
// 00614d01  7e37                 jle 0x614d3a
// 00614d03  8d4c31ff             lea ecx, [ecx + esi - 1]
// 00614d07  c1e117               shl ecx, 0x17
// 00614d0a  25ffff7f00           and eax, 0x7fffff
// 00614d0f  0bc8                 or ecx, eax
// 00614d11  890f                 mov dword ptr [edi], ecx
// 00614d13  5f                   pop edi
// 00614d14  5e                   pop esi
// 00614d15  5b                   pop ebx
// 00614d16  c3                   ret 
// 00614d17  8b560c               mov edx, dword ptr [esi + 0xc]
// 00614d1a  8b4208               mov eax, dword ptr [edx + 8]
// 00614d1d  8b542418             mov edx, dword ptr [esp + 0x18]
// 00614d21  50                   push eax
// 00614d22  8d4411ff             lea eax, [ecx + edx - 1]
// 00614d26  c1e011               shl eax, 0x11
// 00614d29  0bc1                 or eax, ecx
// 00614d2b  c1e006               shl eax, 6
// 00614d2e  83c803               or eax, 3
// 00614d31  50                   push eax
// 00614d32  e8d9fdffff           call 0x614b10
// 00614d37  83c408               add esp, 8
// 00614d3a  5f                   pop edi
// 00614d3b  5e                   pop esi
// 00614d3c  5b                   pop ebx
// 00614d3d  c3                   ret 
// library lua-5.1.1/lcode.c (function _luaK_nil)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
