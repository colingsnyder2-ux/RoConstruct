// from server: 100% by auto
// roc 2009-06 007095e0  unit: boost::detail::thread_data_base  size: 262 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007095e0
//
// 007095e0  83ec10               sub esp, 0x10
// 007095e3  56                   push esi
// 007095e4  8bf1                 mov esi, ecx
// 007095e6  8b4608               mov eax, dword ptr [esi + 8]
// 007095e9  23460c               and eax, dword ptr [esi + 0xc]
// 007095ec  83f8ff               cmp eax, -1
// 007095ef  7515                 jne 0x709606
// 007095f1  8b442418             mov eax, dword ptr [esp + 0x18]
// 007095f5  c60001               mov byte ptr [eax], 1
// 007095f8  c74004feffffff       mov dword ptr [eax + 4], 0xfffffffe
// 007095ff  5e                   pop esi
// 00709600  83c410               add esp, 0x10
// 00709603  c20400               ret 4
// 00709606  807e1000             cmp byte ptr [esi + 0x10], 0
// 0070960a  7453                 je 0x70965f
// 0070960c  57                   push edi
// 0070960d  ff1518e28900         call dword ptr [0x89e218]
// 00709613  2b06                 sub eax, dword ptr [esi]
// 00709615  8b4e08               mov ecx, dword ptr [esi + 8]
// 00709618  8bf8                 mov edi, eax
// 0070961a  8b460c               mov eax, dword ptr [esi + 0xc]
// 0070961d  33d2                 xor edx, edx
// 0070961f  3bd0                 cmp edx, eax
// 00709621  771a                 ja 0x70963d
// 00709623  7204                 jb 0x709629
// 00709625  3bf9                 cmp edi, ecx
// 00709627  7314                 jae 0x70963d
// 00709629  2bcf                 sub ecx, edi
// 0070962b  1bc2                 sbb eax, edx
// 0070962d  85c0                 test eax, eax
// 0070962f  7705                 ja 0x709636
// 00709631  83f9fe               cmp ecx, -2
// 00709634  760d                 jbe 0x709643
// 00709636  ba01000000           mov edx, 1
// 0070963b  eb08                 jmp 0x709645
// 0070963d  33c9                 xor ecx, ecx
// 0070963f  894c2414             mov dword ptr [esp + 0x14], ecx
// 00709643  33d2                 xor edx, edx
// 00709645  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00709649  8810                 mov byte ptr [eax], dl
// 0070964b  5f                   pop edi
// 0070964c  84d2                 test dl, dl
// 0070964e  7405                 je 0x709655
// 00709650  b9feffffff           mov ecx, 0xfffffffe
// 00709655  894804               mov dword ptr [eax + 4], ecx
// 00709658  5e                   pop esi
// 00709659  83c410               add esp, 0x10
// 0070965c  c20400               ret 4
// 0070965f  8d4c2404             lea ecx, [esp + 4]
// 00709663  68802c4100           push 0x412c80
// 00709668  51                   push ecx
// 00709669  e86298d0ff           call 0x412ed0
// 0070966e  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 00709671  8b5618               mov edx, dword ptr [esi + 0x18]
// 00709674  8d4618               lea eax, [esi + 0x18]
// 00709677  8b742410             mov esi, dword ptr [esp + 0x10]
// 0070967b  83c408               add esp, 8
// 0070967e  3bf1                 cmp esi, ecx
// 00709680  7c1f                 jl 0x7096a1
// 00709682  7f08                 jg 0x70968c
// 00709684  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00709688  3bca                 cmp ecx, edx
// 0070968a  7215                 jb 0x7096a1
// 0070968c  8b442418             mov eax, dword ptr [esp + 0x18]
// 00709690  c60000               mov byte ptr [eax], 0
// 00709693  c7400400000000       mov dword ptr [eax + 4], 0
// 0070969a  5e                   pop esi
// 0070969b  83c410               add esp, 0x10
// 0070969e  c20400               ret 4
// 007096a1  8d542404             lea edx, [esp + 4]
// 007096a5  52                   push edx
// 007096a6  50                   push eax
// 007096a7  8d442414             lea eax, [esp + 0x14]
// 007096ab  50                   push eax
// 007096ac  e8df85d0ff           call 0x411c90
// 007096b1  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007096b5  8b542418             mov edx, dword ptr [esp + 0x18]
// 007096b9  83c40c               add esp, 0xc
// 007096bc  6a00                 push 0
// 007096be  68e8030000           push 0x3e8
// 007096c3  51                   push ecx
// 007096c4  52                   push edx
// 007096c5  e8a6060100           call 0x719d70
// 007096ca  8b742418             mov esi, dword ptr [esp + 0x18]
// 007096ce  83c001               add eax, 1
// 007096d1  83d200               adc edx, 0
// 007096d4  52                   push edx
// 007096d5  50                   push eax
// 007096d6  8bce                 mov ecx, esi
// 007096d8  e863f3ffff           call 0x708a40
// 007096dd  8bc6                 mov eax, esi
// 007096df  5e                   pop esi
// 007096e0  83c410               add esp, 0x10
// 007096e3  c20400               ret 4
// library boost-1.40.0/libs\thread\src\win32\thread.cpp (function ?remaining_milliseconds@timeout@detail@boost@@QBE?AUremaining_time@123@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/thread/src/win32/thread.cpp
