// roc 2012-06 005c07d0  unit: RakNet::RakPeer  size: 483 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005c07d0
//
// 005c07d0  6aff                 push -1
// 005c07d2  685b0aab00           push 0xab0a5b
// 005c07d7  64a100000000         mov eax, dword ptr fs:[0]
// 005c07dd  50                   push eax
// 005c07de  64892500000000       mov dword ptr fs:[0], esp
// 005c07e5  81ec30010000         sub esp, 0x130
// 005c07eb  53                   push ebx
// 005c07ec  56                   push esi
// 005c07ed  57                   push edi
// 005c07ee  8bf9                 mov edi, ecx
// 005c07f0  6a01                 push 1
// 005c07f2  8d4c242c             lea ecx, [esp + 0x2c]
// 005c07f6  e8d56dfaff           call 0x5675d0
// 005c07fb  6a01                 push 1
// 005c07fd  6a08                 push 8
// 005c07ff  8d442417             lea eax, [esp + 0x17]
// 005c0803  50                   push eax
// 005c0804  8d4c2434             lea ecx, [esp + 0x34]
// 005c0808  c784245001000000000000 mov dword ptr [esp + 0x150], 0
// 005c0813  c644241b15           mov byte ptr [esp + 0x1b], 0x15
// 005c0818  e87375faff           call 0x567d90
// 005c081d  80bc246001000000     cmp byte ptr [esp + 0x160], 0
// 005c0825  6a00                 push 0
// 005c0827  0f84ed000000         je 0x5c091a
// 005c082d  e88e81ffff           call 0x5b89c0
// 005c0832  52                   push edx
// 005c0833  50                   push eax
// 005c0834  6a00                 push 0
// 005c0836  6a00                 push 0
// 005c0838  83ec28               sub esp, 0x28
// 005c083b  8bf4                 mov esi, esp
// 005c083d  8bce                 mov ecx, esi
// 005c083f  8964244c             mov dword ptr [esp + 0x4c], esp
// 005c0843  e89814faff           call 0x561ce0
// 005c0848  8d5e10               lea ebx, [esi + 0x10]
// 005c084b  8bcb                 mov ecx, ebx
// 005c084d  e8de11faff           call 0x561a30
// 005c0852  8b0df815d900         mov ecx, dword ptr [0xd915f8]
// 005c0858  890e                 mov dword ptr [esi], ecx
// 005c085a  8b15fc15d900         mov edx, dword ptr [0xd915fc]
// 005c0860  8d8c2488010000       lea ecx, [esp + 0x188]
// 005c0867  895604               mov dword ptr [esi + 4], edx
// 005c086a  66a10016d900         mov ax, word ptr [0xd91600]
// 005c0870  51                   push ecx
// 005c0871  8bcb                 mov ecx, ebx
// 005c0873  66894608             mov word ptr [esi + 8], ax
// 005c0877  e8940ffaff           call 0x561810
// 005c087c  8b9424a0010000       mov edx, dword ptr [esp + 0x1a0]
// 005c0883  8b8424a4010000       mov eax, dword ptr [esp + 0x1a4]
// 005c088a  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 005c088e  52                   push edx
// 005c088f  8b542474             mov edx, dword ptr [esp + 0x74]
// 005c0893  6a03                 push 3
// 005c0895  50                   push eax
// 005c0896  51                   push ecx
// 005c0897  52                   push edx
// 005c0898  8bcf                 mov ecx, edi
// 005c089a  e821b8ffff           call 0x5bc0c0
// 005c089f  8b8c2450010000       mov ecx, dword ptr [esp + 0x150]
// 005c08a6  8b84244c010000       mov eax, dword ptr [esp + 0x14c]
// 005c08ad  8b942454010000       mov edx, dword ptr [esp + 0x154]
// 005c08b4  894c2418             mov dword ptr [esp + 0x18], ecx
// 005c08b8  8b8c245c010000       mov ecx, dword ptr [esp + 0x15c]
// 005c08bf  89442414             mov dword ptr [esp + 0x14], eax
// 005c08c3  8b842458010000       mov eax, dword ptr [esp + 0x158]
// 005c08ca  894c2424             mov dword ptr [esp + 0x24], ecx
// 005c08ce  684c69e200           push 0xe2694c
// 005c08d3  8d4c2418             lea ecx, [esp + 0x18]
// 005c08d7  89542420             mov dword ptr [esp + 0x20], edx
// 005c08db  89442424             mov dword ptr [esp + 0x24], eax
// 005c08df  e8bc0ffaff           call 0x5618a0
// 005c08e4  84c0                 test al, al
// 005c08e6  7524                 jne 0x5c090c
// 005c08e8  8d542414             lea edx, [esp + 0x14]
// 005c08ec  52                   push edx
// 005c08ed  8bcf                 mov ecx, edi
// 005c08ef  e8acaaffff           call 0x5bb3a0
// 005c08f4  83f8ff               cmp eax, -1
// 005c08f7  7413                 je 0x5c090c
// 005c08f9  8b8f2c020000         mov ecx, dword ptr [edi + 0x22c]
// 005c08ff  69c008120000         imul eax, eax, 0x1208
// 005c0905  03c1                 add eax, ecx
// 005c0907  803801               cmp byte ptr [eax], 1
// 005c090a  7402                 je 0x5c090e
// 005c090c  33c0                 xor eax, eax
// 005c090e  c7800012000001000000 mov dword ptr [eax + 0x1200], 1
// 005c0918  eb6b                 jmp 0x5c0985
// 005c091a  6a01                 push 1
// 005c091c  6a00                 push 0
// 005c091e  83ec28               sub esp, 0x28
// 005c0921  8bf4                 mov esi, esp
// 005c0923  8bce                 mov ecx, esi
// 005c0925  89642444             mov dword ptr [esp + 0x44], esp
// 005c0929  e8b213faff           call 0x561ce0
// 005c092e  8d5e10               lea ebx, [esi + 0x10]
// 005c0931  8bcb                 mov ecx, ebx
// 005c0933  e8f810faff           call 0x561a30
// 005c0938  8b15f815d900         mov edx, dword ptr [0xd915f8]
// 005c093e  8916                 mov dword ptr [esi], edx
// 005c0940  a1fc15d900           mov eax, dword ptr [0xd915fc]
// 005c0945  894604               mov dword ptr [esi + 4], eax
// 005c0948  668b0d0016d900       mov cx, word ptr [0xd91600]
// 005c094f  8d942480010000       lea edx, [esp + 0x180]
// 005c0956  66894e08             mov word ptr [esi + 8], cx
// 005c095a  52                   push edx
// 005c095b  8bcb                 mov ecx, ebx
// 005c095d  e8ae0efaff           call 0x561810
// 005c0962  8b842498010000       mov eax, dword ptr [esp + 0x198]
// 005c0969  8b8c249c010000       mov ecx, dword ptr [esp + 0x19c]
// 005c0970  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 005c0974  50                   push eax
// 005c0975  8b44246c             mov eax, dword ptr [esp + 0x6c]
// 005c0979  6a03                 push 3
// 005c097b  51                   push ecx
// 005c097c  52                   push edx
// 005c097d  50                   push eax
// 005c097e  8bcf                 mov ecx, edi
// 005c0980  e85bf4ffff           call 0x5bfde0
// 005c0985  8d4c2428             lea ecx, [esp + 0x28]
// 005c0989  c7842444010000ffffffff mov dword ptr [esp + 0x144], 0xffffffff
// 005c0994  e8176dfaff           call 0x5676b0
// 005c0999  8b8c243c010000       mov ecx, dword ptr [esp + 0x13c]
// 005c09a0  5f                   pop edi
// 005c09a1  5e                   pop esi
// 005c09a2  64890d00000000       mov dword ptr fs:[0], ecx
// 005c09a9  5b                   pop ebx
// 005c09aa  81c43c010000         add esp, 0x13c
// 005c09b0  c22000               ret 0x20
// copied from an identical function in another client (function ?NotifyAndFlagForShutdown@RakPeer@RakNet@@IAEXUSystemAddress@2@_NEW4PacketPriority@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp