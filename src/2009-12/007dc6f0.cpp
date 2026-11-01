// from server: 100% by auto
// roc 2009-12 007dc6f0  unit: RBX::GroupDragTool  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dc6f0
//
// 007dc6f0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007dc6f4  53                   push ebx
// 007dc6f5  56                   push esi
// 007dc6f6  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007dc6fa  8b4618               mov eax, dword ptr [esi + 0x18]
// 007dc6fd  3b461c               cmp eax, dword ptr [esi + 0x1c]
// 007dc700  57                   push edi
// 007dc701  7e0c                 jle 0x7dc70f
// 007dc703  85c0                 test eax, eax
// 007dc705  752f                 jne 0x7dc736
// 007dc707  0fb64632             movzx eax, byte ptr [esi + 0x32]
// 007dc70b  3bc8                 cmp ecx, eax
// 007dc70d  7d23                 jge 0x7dc732
// 007dc70f  8b560c               mov edx, dword ptr [esi + 0xc]
// 007dc712  8b4208               mov eax, dword ptr [edx + 8]
// 007dc715  8b542418             mov edx, dword ptr [esp + 0x18]
// 007dc719  50                   push eax
// 007dc71a  8d4411ff             lea eax, [ecx + edx - 1]
// 007dc71e  c1e011               shl eax, 0x11
// 007dc721  0bc1                 or eax, ecx
// 007dc723  c1e006               shl eax, 6
// 007dc726  83c803               or eax, 3
// 007dc729  50                   push eax
// 007dc72a  e831feffff           call 0x7dc560
// 007dc72f  83c408               add esp, 8
// 007dc732  5f                   pop edi
// 007dc733  5e                   pop esi
// 007dc734  5b                   pop ebx
// 007dc735  c3                   ret 
// 007dc736  8b16                 mov edx, dword ptr [esi]
// 007dc738  8b520c               mov edx, dword ptr [edx + 0xc]
// 007dc73b  8d7c82fc             lea edi, [edx + eax*4 - 4]
// 007dc73f  8b07                 mov eax, dword ptr [edi]
// 007dc741  8bd0                 mov edx, eax
// 007dc743  83e23f               and edx, 0x3f
// 007dc746  80fa03               cmp dl, 3
// 007dc749  75c4                 jne 0x7dc70f
// 007dc74b  8bd8                 mov ebx, eax
// 007dc74d  c1eb06               shr ebx, 6
// 007dc750  8bd0                 mov edx, eax
// 007dc752  81e3ff000000         and ebx, 0xff
// 007dc758  c1ea17               shr edx, 0x17
// 007dc75b  3bd9                 cmp ebx, ecx
// 007dc75d  7fb0                 jg 0x7dc70f
// 007dc75f  8d5a01               lea ebx, [edx + 1]
// 007dc762  3bcb                 cmp ecx, ebx
// 007dc764  7fa9                 jg 0x7dc70f
// 007dc766  8b742418             mov esi, dword ptr [esp + 0x18]
// 007dc76a  8d5c31ff             lea ebx, [ecx + esi - 1]
// 007dc76e  3bda                 cmp ebx, edx
// 007dc770  7ec0                 jle 0x7dc732
// 007dc772  8d4c31ff             lea ecx, [ecx + esi - 1]
// 007dc776  c1e117               shl ecx, 0x17
// 007dc779  25ffff7f00           and eax, 0x7fffff
// 007dc77e  0bc8                 or ecx, eax
// 007dc780  890f                 mov dword ptr [edi], ecx
// 007dc782  5f                   pop edi
// 007dc783  5e                   pop esi
// 007dc784  5b                   pop ebx
// 007dc785  c3                   ret 
// library lua-5.1.2/lcode.c (function _luaK_nil)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lcode.c
