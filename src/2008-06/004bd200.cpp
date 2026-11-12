// from server: 100% by auto
// roc 2008-06 004bd200  unit: ProfiledRakPeer  size: 330 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bd200
//
// 004bd200  64a100000000         mov eax, dword ptr fs:[0]
// 004bd206  6aff                 push -1
// 004bd208  681b937c00           push 0x7c931b
// 004bd20d  50                   push eax
// 004bd20e  64892500000000       mov dword ptr fs:[0], esp
// 004bd215  81ec24010000         sub esp, 0x124
// 004bd21b  53                   push ebx
// 004bd21c  8b9c2438010000       mov ebx, dword ptr [esp + 0x138]
// 004bd223  56                   push esi
// 004bd224  33f6                 xor esi, esi
// 004bd226  57                   push edi
// 004bd227  8bf9                 mov edi, ecx
// 004bd229  3bde                 cmp ebx, esi
// 004bd22b  0f84ff000000         je 0x4bd330
// 004bd231  8a03                 mov al, byte ptr [ebx]
// 004bd233  3c30                 cmp al, 0x30
// 004bd235  7c04                 jl 0x4bd23b
// 004bd237  3c32                 cmp al, 0x32
// 004bd239  7e0d                 jle 0x4bd248
// 004bd23b  53                   push ebx
// 004bd23c  b9311d9700           mov ecx, 0x971d31
// 004bd241  e83a140100           call 0x4ce680
// 004bd246  8bd8                 mov ebx, eax
// 004bd248  55                   push ebp
// 004bd249  53                   push ebx
// 004bd24a  8d4c241c             lea ecx, [esp + 0x1c]
// 004bd24e  e8cdc6feff           call 0x4a9920
// 004bd253  8bac2448010000       mov ebp, dword ptr [esp + 0x148]
// 004bd25a  6a05                 push 5
// 004bd25c  8d4c2424             lea ecx, [esp + 0x24]
// 004bd260  66896c2420           mov word ptr [esp + 0x20], bp
// 004bd265  e8567efeff           call 0x4a50c0
// 004bd26a  80bc244c01000000     cmp byte ptr [esp + 0x14c], 0
// 004bd272  6a01                 push 1
// 004bd274  89b42440010000       mov dword ptr [esp + 0x140], esi
// 004bd27b  6a08                 push 8
// 004bd27d  740c                 je 0x4bd28b
// 004bd27f  8d442418             lea eax, [esp + 0x18]
// 004bd283  c644241802           mov byte ptr [esp + 0x18], 2
// 004bd288  50                   push eax
// 004bd289  eb0a                 jmp 0x4bd295
// 004bd28b  8d4c2418             lea ecx, [esp + 0x18]
// 004bd28f  c644241801           mov byte ptr [esp + 0x18], 1
// 004bd294  51                   push ecx
// 004bd295  8d4c242c             lea ecx, [esp + 0x2c]
// 004bd299  e86283feff           call 0x4a5600
// 004bd29e  e86dc60000           call 0x4c9910
// 004bd2a3  6a01                 push 1
// 004bd2a5  6a20                 push 0x20
// 004bd2a7  8d54241c             lea edx, [esp + 0x1c]
// 004bd2ab  52                   push edx
// 004bd2ac  8d4c242c             lea ecx, [esp + 0x2c]
// 004bd2b0  89442420             mov dword ptr [esp + 0x20], eax
// 004bd2b4  e84783feff           call 0x4a5600
// 004bd2b9  39b7ac020000         cmp dword ptr [edi + 0x2ac], esi
// 004bd2bf  762d                 jbe 0x4bd2ee
// 004bd2c1  8b87a8020000         mov eax, dword ptr [edi + 0x2a8]
// 004bd2c7  8b0cb0               mov ecx, dword ptr [eax + esi*4]
// 004bd2ca  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004bd2ce  8b11                 mov edx, dword ptr [ecx]
// 004bd2d0  8b5220               mov edx, dword ptr [edx + 0x20]
// 004bd2d3  50                   push eax
// 004bd2d4  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004bd2d8  50                   push eax
// 004bd2d9  8b442428             mov eax, dword ptr [esp + 0x28]
// 004bd2dd  50                   push eax
// 004bd2de  8b442438             mov eax, dword ptr [esp + 0x38]
// 004bd2e2  50                   push eax
// 004bd2e3  ffd2                 call edx
// 004bd2e5  46                   inc esi
// 004bd2e6  3bb7ac020000         cmp esi, dword ptr [edi + 0x2ac]
// 004bd2ec  72d3                 jb 0x4bd2c1
// 004bd2ee  8b442420             mov eax, dword ptr [esp + 0x20]
// 004bd2f2  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004bd2f6  8b9714070000         mov edx, dword ptr [edi + 0x714]
// 004bd2fc  55                   push ebp
// 004bd2fd  83c007               add eax, 7
// 004bd300  53                   push ebx
// 004bd301  c1f803               sar eax, 3
// 004bd304  50                   push eax
// 004bd305  8b84245c010000       mov eax, dword ptr [esp + 0x15c]
// 004bd30c  51                   push ecx
// 004bd30d  8b0c82               mov ecx, dword ptr [edx + eax*4]
// 004bd310  51                   push ecx
// 004bd311  b9311d9700           mov ecx, 0x971d31
// 004bd316  e8e5140100           call 0x4ce800
// 004bd31b  8d4c2420             lea ecx, [esp + 0x20]
// 004bd31f  c784243c010000ffffffff mov dword ptr [esp + 0x13c], 0xffffffff
// 004bd32a  e8717efeff           call 0x4a51a0
// 004bd32f  5d                   pop ebp
// 004bd330  8b8c2430010000       mov ecx, dword ptr [esp + 0x130]
// 004bd337  5f                   pop edi
// 004bd338  5e                   pop esi
// 004bd339  5b                   pop ebx
// 004bd33a  64890d00000000       mov dword ptr fs:[0], ecx
// 004bd341  81c430010000         add esp, 0x130
// 004bd347  c21000               ret 0x10
// library openrbx-raknet/RakPeer.cpp (function ?Ping@RakPeer@@UAEXPBDG_NI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
