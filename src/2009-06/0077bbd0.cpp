// from server: 100% by auto
// roc 2009-06 0077bbd0  unit: CXTPTabClientWnd  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077bbd0
//
// 0077bbd0  56                   push esi
// 0077bbd1  8bf1                 mov esi, ecx
// 0077bbd3  83beb400000000       cmp dword ptr [esi + 0xb4], 0
// 0077bbda  57                   push edi
// 0077bbdb  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0077bbdf  7455                 je 0x77bc36
// 0077bbe1  8b4704               mov eax, dword ptr [edi + 4]
// 0077bbe4  3d01020000           cmp eax, 0x201
// 0077bbe9  741c                 je 0x77bc07
// 0077bbeb  3d04020000           cmp eax, 0x204
// 0077bbf0  7415                 je 0x77bc07
// 0077bbf2  3d07020000           cmp eax, 0x207
// 0077bbf7  740e                 je 0x77bc07
// 0077bbf9  3d03020000           cmp eax, 0x203
// 0077bbfe  7407                 je 0x77bc07
// 0077bc00  3d06020000           cmp eax, 0x206
// 0077bc05  752f                 jne 0x77bc36
// 0077bc07  8b0f                 mov ecx, dword ptr [edi]
// 0077bc09  3b4e20               cmp ecx, dword ptr [esi + 0x20]
// 0077bc0c  7528                 jne 0x77bc36
// 0077bc0e  8b570c               mov edx, dword ptr [edi + 0xc]
// 0077bc11  8b8e84000000         mov ecx, dword ptr [esi + 0x84]
// 0077bc17  52                   push edx
// 0077bc18  8b5120               mov edx, dword ptr [ecx + 0x20]
// 0077bc1b  50                   push eax
// 0077bc1c  6868280000           push 0x2868
// 0077bc21  52                   push edx
// 0077bc22  ff1590ee8900         call dword ptr [0x89ee90]
// 0077bc28  85c0                 test eax, eax
// 0077bc2a  740a                 je 0x77bc36
// 0077bc2c  5f                   pop edi
// 0077bc2d  b801000000           mov eax, 1
// 0077bc32  5e                   pop esi
// 0077bc33  c20400               ret 4
// 0077bc36  57                   push edi
// 0077bc37  8bce                 mov ecx, esi
// 0077bc39  e8fad3f9ff           call 0x719038
// 0077bc3e  5f                   pop edi
// 0077bc3f  5e                   pop esi
// 0077bc40  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?PreTranslateMessage@CXTPTabClientWnd@@MAEHPAUtagMSG@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
