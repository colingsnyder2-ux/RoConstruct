// from server: 100% by EspClaude
// roc 2009-06 00498270  unit: VThreadLogManager::?$thread_specific_ptr::delete_data  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00498270
//
// 00498270  6aff                 push -1
// 00498272  6878678500           push 0x856778
// 00498277  64a100000000         mov eax, dword ptr fs:[0]
// 0049827d  50                   push eax
// 0049827e  64892500000000       mov dword ptr fs:[0], esp
// 00498285  51                   push ecx
// 00498286  56                   push esi
// 00498287  57                   push edi
// 00498288  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0049828c  8b07                 mov eax, dword ptr [edi]
// 0049828e  8bf1                 mov esi, ecx
// 00498290  8d4f04               lea ecx, [edi + 4]
// 00498293  51                   push ecx
// 00498294  8d4e04               lea ecx, [esi + 4]
// 00498297  8974240c             mov dword ptr [esp + 0xc], esi
// 0049829b  8906                 mov dword ptr [esi], eax
// 0049829d  ff15b8e48900         call dword ptr [0x89e4b8]
// 004982a3  8d5720               lea edx, [edi + 0x20]
// 004982a6  52                   push edx
// 004982a7  8d4e20               lea ecx, [esi + 0x20]
// 004982aa  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004982b2  ff15b8e48900         call dword ptr [0x89e4b8]
// 004982b8  8d473c               lea eax, [edi + 0x3c]
// 004982bb  50                   push eax
// 004982bc  8d4e3c               lea ecx, [esi + 0x3c]
// 004982bf  c644241801           mov byte ptr [esp + 0x18], 1
// 004982c4  ff15b8e48900         call dword ptr [0x89e4b8]
// 004982ca  8b4f58               mov ecx, dword ptr [edi + 0x58]
// 004982cd  894e58               mov dword ptr [esi + 0x58], ecx
// 004982d0  8b575c               mov edx, dword ptr [edi + 0x5c]
// 004982d3  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004982d7  89565c               mov dword ptr [esi + 0x5c], edx
// 004982da  5f                   pop edi
// 004982db  8bc6                 mov eax, esi
// 004982dd  5e                   pop esi
// 004982de  64890d00000000       mov dword ptr fs:[0], ecx
// 004982e5  83c410               add esp, 0x10
// 004982e8  c20400               ret 4
// copied from an identical function in another client (function ??0FileInfo@Ogre@@QAE@ABU01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.9-dll OgreBillboardSet.cpp