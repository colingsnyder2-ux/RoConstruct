// from server: 100% by auto
// roc 2009-12 008d9290  unit: CXTColorHex  size: 3251 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d9290
//
// 008d9290  81ecbc000000         sub esp, 0xbc
// 008d9296  53                   push ebx
// 008d9297  8b5968               mov ebx, dword ptr [ecx + 0x68]
// 008d929a  55                   push ebp
// 008d929b  8b696c               mov ebp, dword ptr [ecx + 0x6c]
// 008d929e  56                   push esi
// 008d929f  8b3514b19800         mov esi, dword ptr [0x98b114]
// 008d92a5  57                   push edi
// 008d92a6  8bbc24d0000000       mov edi, dword ptr [esp + 0xd0]
// 008d92ad  83eb02               sub ebx, 2
// 008d92b0  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008d92b8  896c242c             mov dword ptr [esp + 0x2c], ebp
// 008d92bc  8d642400             lea esp, [esp]
// 008d92c0  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 008d92c4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008d92c8  8b5704               mov edx, dword ptr [edi + 4]
// 008d92cb  6a00                 push 0
// 008d92cd  50                   push eax
// 008d92ce  03cb                 add ecx, ebx
// 008d92d0  51                   push ecx
// 008d92d1  52                   push edx
// 008d92d2  ffd6                 call esi
// 008d92d4  8b442410             mov eax, dword ptr [esp + 0x10]
// 008d92d8  ff4c242c             dec dword ptr [esp + 0x2c]
// 008d92dc  40                   inc eax
// 008d92dd  83f803               cmp eax, 3
// 008d92e0  89442410             mov dword ptr [esp + 0x10], eax
// 008d92e4  7cda                 jl 0x8d92c0
// 008d92e6  6a00                 push 0
// 008d92e8  8d45fe               lea eax, [ebp - 2]
// 008d92eb  50                   push eax
// 008d92ec  8d4b03               lea ecx, [ebx + 3]
// 008d92ef  898424b8000000       mov dword ptr [esp + 0xb8], eax
// 008d92f6  8b4704               mov eax, dword ptr [edi + 4]
// 008d92f9  51                   push ecx
// 008d92fa  50                   push eax
// 008d92fb  894c2458             mov dword ptr [esp + 0x58], ecx
// 008d92ff  ffd6                 call esi
// 008d9301  6a00                 push 0
// 008d9303  8d45fd               lea eax, [ebp - 3]
// 008d9306  8d4b04               lea ecx, [ebx + 4]
// 008d9309  50                   push eax
// 008d930a  51                   push ecx
// 008d930b  894c245c             mov dword ptr [esp + 0x5c], ecx
// 008d930f  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d9312  51                   push ecx
// 008d9313  89442434             mov dword ptr [esp + 0x34], eax
// 008d9317  ffd6                 call esi
// 008d9319  8b542424             mov edx, dword ptr [esp + 0x24]
// 008d931d  6a00                 push 0
// 008d931f  8d4305               lea eax, [ebx + 5]
// 008d9322  52                   push edx
// 008d9323  50                   push eax
// 008d9324  89442444             mov dword ptr [esp + 0x44], eax
// 008d9328  8b4704               mov eax, dword ptr [edi + 4]
// 008d932b  50                   push eax
// 008d932c  ffd6                 call esi
// 008d932e  6a00                 push 0
// 008d9330  8d45fc               lea eax, [ebp - 4]
// 008d9333  8d4b06               lea ecx, [ebx + 6]
// 008d9336  50                   push eax
// 008d9337  51                   push ecx
// 008d9338  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 008d933f  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d9342  51                   push ecx
// 008d9343  89442430             mov dword ptr [esp + 0x30], eax
// 008d9347  ffd6                 call esi
// 008d9349  8b542420             mov edx, dword ptr [esp + 0x20]
// 008d934d  6a00                 push 0
// 008d934f  8d4307               lea eax, [ebx + 7]
// 008d9352  52                   push edx
// 008d9353  50                   push eax
// 008d9354  89842484000000       mov dword ptr [esp + 0x84], eax
// 008d935b  8b4704               mov eax, dword ptr [edi + 4]
// 008d935e  50                   push eax
// 008d935f  ffd6                 call esi
// 008d9361  6a00                 push 0
// 008d9363  8d45fb               lea eax, [ebp - 5]
// 008d9366  8d4b08               lea ecx, [ebx + 8]
// 008d9369  50                   push eax
// 008d936a  51                   push ecx
// 008d936b  894c247c             mov dword ptr [esp + 0x7c], ecx
// 008d936f  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d9372  51                   push ecx
// 008d9373  89442438             mov dword ptr [esp + 0x38], eax
// 008d9377  ffd6                 call esi
// 008d9379  8b542428             mov edx, dword ptr [esp + 0x28]
// 008d937d  6a00                 push 0
// 008d937f  8d4309               lea eax, [ebx + 9]
// 008d9382  52                   push edx
// 008d9383  50                   push eax
// 008d9384  89442474             mov dword ptr [esp + 0x74], eax
// 008d9388  8b4704               mov eax, dword ptr [edi + 4]
// 008d938b  50                   push eax
// 008d938c  ffd6                 call esi
// 008d938e  6a00                 push 0
// 008d9390  8d45fa               lea eax, [ebp - 6]
// 008d9393  8d4b0a               lea ecx, [ebx + 0xa]
// 008d9396  50                   push eax
// 008d9397  51                   push ecx
// 008d9398  894c246c             mov dword ptr [esp + 0x6c], ecx
// 008d939c  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d939f  51                   push ecx
// 008d93a0  8944244c             mov dword ptr [esp + 0x4c], eax
// 008d93a4  ffd6                 call esi
// 008d93a6  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 008d93aa  8d430b               lea eax, [ebx + 0xb]
// 008d93ad  89842494000000       mov dword ptr [esp + 0x94], eax
// 008d93b4  6a00                 push 0
// 008d93b6  52                   push edx
// 008d93b7  50                   push eax
// 008d93b8  8b4704               mov eax, dword ptr [edi + 4]
// 008d93bb  50                   push eax
// 008d93bc  ffd6                 call esi
// 008d93be  6a00                 push 0
// 008d93c0  8d45f9               lea eax, [ebp - 7]
// 008d93c3  8d4b0c               lea ecx, [ebx + 0xc]
// 008d93c6  50                   push eax
// 008d93c7  51                   push ecx
// 008d93c8  898c24ac000000       mov dword ptr [esp + 0xac], ecx
// 008d93cf  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d93d2  51                   push ecx
// 008d93d3  89442468             mov dword ptr [esp + 0x68], eax
// 008d93d7  ffd6                 call esi
// 008d93d9  8b542458             mov edx, dword ptr [esp + 0x58]
// 008d93dd  6a00                 push 0
// 008d93df  8d430d               lea eax, [ebx + 0xd]
// 008d93e2  52                   push edx
// 008d93e3  50                   push eax
// 008d93e4  89842498000000       mov dword ptr [esp + 0x98], eax
// 008d93eb  8b4704               mov eax, dword ptr [edi + 4]
// 008d93ee  50                   push eax
// 008d93ef  ffd6                 call esi
// 008d93f1  6a00                 push 0
// 008d93f3  8d45f8               lea eax, [ebp - 8]
// 008d93f6  8d4b0e               lea ecx, [ebx + 0xe]
// 008d93f9  50                   push eax
// 008d93fa  51                   push ecx
// 008d93fb  898c24b4000000       mov dword ptr [esp + 0xb4], ecx
// 008d9402  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d9405  51                   push ecx
// 008d9406  ffd6                 call esi
// 008d9408  8b5704               mov edx, dword ptr [edi + 4]
// 008d940b  6a00                 push 0
// 008d940d  8d45f8               lea eax, [ebp - 8]
// 008d9410  8d4b0f               lea ecx, [ebx + 0xf]
// 008d9413  50                   push eax
// 008d9414  51                   push ecx
// 008d9415  52                   push edx
// 008d9416  898c2494000000       mov dword ptr [esp + 0x94], ecx
// 008d941d  ffd6                 call esi
// 008d941f  6a00                 push 0
// 008d9421  8d45f8               lea eax, [ebp - 8]
// 008d9424  50                   push eax
// 008d9425  8b4704               mov eax, dword ptr [edi + 4]
// 008d9428  8d4b10               lea ecx, [ebx + 0x10]
// 008d942b  51                   push ecx
// 008d942c  50                   push eax
// 008d942d  898c24c4000000       mov dword ptr [esp + 0xc4], ecx
// 008d9434  ffd6                 call esi
// 008d9436  6a00                 push 0
// 008d9438  8d45f8               lea eax, [ebp - 8]
// 008d943b  8d4b11               lea ecx, [ebx + 0x11]
// 008d943e  50                   push eax
// 008d943f  51                   push ecx
// 008d9440  898c2488000000       mov dword ptr [esp + 0x88], ecx
// 008d9447  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d944a  51                   push ecx
// 008d944b  ffd6                 call esi
// 008d944d  8b5704               mov edx, dword ptr [edi + 4]
// 008d9450  6a00                 push 0
// 008d9452  8d45f8               lea eax, [ebp - 8]
// 008d9455  8d4b12               lea ecx, [ebx + 0x12]
// 008d9458  50                   push eax
// 008d9459  51                   push ecx
// 008d945a  52                   push edx
// 008d945b  898c24bc000000       mov dword ptr [esp + 0xbc], ecx
// 008d9462  ffd6                 call esi
// 008d9464  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 008d9468  8b5704               mov edx, dword ptr [edi + 4]
// 008d946b  6a00                 push 0
// 008d946d  8d4313               lea eax, [ebx + 0x13]
// 008d9470  51                   push ecx
// 008d9471  50                   push eax
// 008d9472  52                   push edx
// 008d9473  89842484000000       mov dword ptr [esp + 0x84], eax
// 008d947a  ffd6                 call esi
// 008d947c  8d4314               lea eax, [ebx + 0x14]
// 008d947f  8944245c             mov dword ptr [esp + 0x5c], eax
// 008d9483  6a00                 push 0
// 008d9485  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 008d9489  8b5704               mov edx, dword ptr [edi + 4]
// 008d948c  51                   push ecx
// 008d948d  50                   push eax
// 008d948e  52                   push edx
// 008d948f  ffd6                 call esi
// 008d9491  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 008d9495  8b5704               mov edx, dword ptr [edi + 4]
// 008d9498  6a00                 push 0
// 008d949a  8d4315               lea eax, [ebx + 0x15]
// 008d949d  51                   push ecx
// 008d949e  50                   push eax
// 008d949f  52                   push edx
// 008d94a0  8944247c             mov dword ptr [esp + 0x7c], eax
// 008d94a4  ffd6                 call esi
// 008d94a6  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 008d94aa  8b5704               mov edx, dword ptr [edi + 4]
// 008d94ad  6a00                 push 0
// 008d94af  8d4316               lea eax, [ebx + 0x16]
// 008d94b2  51                   push ecx
// 008d94b3  50                   push eax
// 008d94b4  52                   push edx
// 008d94b5  898424b4000000       mov dword ptr [esp + 0xb4], eax
// 008d94bc  ffd6                 call esi
// 008d94be  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008d94c2  8b5704               mov edx, dword ptr [edi + 4]
// 008d94c5  6a00                 push 0
// 008d94c7  8d4317               lea eax, [ebx + 0x17]
// 008d94ca  51                   push ecx
// 008d94cb  50                   push eax
// 008d94cc  52                   push edx
// 008d94cd  89442474             mov dword ptr [esp + 0x74], eax
// 008d94d1  ffd6                 call esi
// 008d94d3  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008d94d7  8b5704               mov edx, dword ptr [edi + 4]
// 008d94da  6a00                 push 0
// 008d94dc  8d4318               lea eax, [ebx + 0x18]
// 008d94df  51                   push ecx
// 008d94e0  50                   push eax
// 008d94e1  52                   push edx
// 008d94e2  89442464             mov dword ptr [esp + 0x64], eax
// 008d94e6  ffd6                 call esi
// 008d94e8  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008d94ec  8b5704               mov edx, dword ptr [edi + 4]
// 008d94ef  6a00                 push 0
// 008d94f1  8d4319               lea eax, [ebx + 0x19]
// 008d94f4  51                   push ecx
// 008d94f5  50                   push eax
// 008d94f6  52                   push edx
// 008d94f7  898424a8000000       mov dword ptr [esp + 0xa8], eax
// 008d94fe  ffd6                 call esi
// 008d9500  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008d9504  8b5704               mov edx, dword ptr [edi + 4]
// 008d9507  6a00                 push 0
// 008d9509  8d431a               lea eax, [ebx + 0x1a]
// 008d950c  51                   push ecx
// 008d950d  50                   push eax
// 008d950e  52                   push edx
// 008d950f  89842498000000       mov dword ptr [esp + 0x98], eax
// 008d9516  ffd6                 call esi
// 008d9518  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 008d951c  8b5704               mov edx, dword ptr [edi + 4]
// 008d951f  6a00                 push 0
// 008d9521  8d431b               lea eax, [ebx + 0x1b]
// 008d9524  51                   push ecx
// 008d9525  50                   push eax
// 008d9526  52                   push edx
// 008d9527  898424ac000000       mov dword ptr [esp + 0xac], eax
// 008d952e  ffd6                 call esi
// 008d9530  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 008d9534  8b5704               mov edx, dword ptr [edi + 4]
// 008d9537  6a00                 push 0
// 008d9539  8d431c               lea eax, [ebx + 0x1c]
// 008d953c  51                   push ecx
// 008d953d  50                   push eax
// 008d953e  52                   push edx
// 008d953f  898424a0000000       mov dword ptr [esp + 0xa0], eax
// 008d9546  ffd6                 call esi
// 008d9548  8d431d               lea eax, [ebx + 0x1d]
// 008d954b  898424b8000000       mov dword ptr [esp + 0xb8], eax
// 008d9552  6a00                 push 0
// 008d9554  8b8c24b4000000       mov ecx, dword ptr [esp + 0xb4]
// 008d955b  8b5704               mov edx, dword ptr [edi + 4]
// 008d955e  51                   push ecx
// 008d955f  50                   push eax
// 008d9560  52                   push edx
// 008d9561  ffd6                 call esi
// 008d9563  8b8c24b0000000       mov ecx, dword ptr [esp + 0xb0]
// 008d956a  8b5704               mov edx, dword ptr [edi + 4]
// 008d956d  6a00                 push 0
// 008d956f  8d431e               lea eax, [ebx + 0x1e]
// 008d9572  51                   push ecx
// 008d9573  50                   push eax
// 008d9574  52                   push edx
// 008d9575  898424cc000000       mov dword ptr [esp + 0xcc], eax
// 008d957c  ffd6                 call esi
// 008d957e  6a00                 push 0
// 008d9580  8d45ff               lea eax, [ebp - 1]
// 008d9583  50                   push eax
// 008d9584  8d4b1f               lea ecx, [ebx + 0x1f]
// 008d9587  8944244c             mov dword ptr [esp + 0x4c], eax
// 008d958b  8b4704               mov eax, dword ptr [edi + 4]
// 008d958e  51                   push ecx
// 008d958f  50                   push eax
// 008d9590  898c24d0000000       mov dword ptr [esp + 0xd0], ecx
// 008d9597  ffd6                 call esi
// 008d9599  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008d95a1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008d95a5  8b5704               mov edx, dword ptr [edi + 4]
// 008d95a8  6a00                 push 0
// 008d95aa  03cd                 add ecx, ebp
// 008d95ac  51                   push ecx
// 008d95ad  8d4320               lea eax, [ebx + 0x20]
// 008d95b0  50                   push eax
// 008d95b1  52                   push edx
// 008d95b2  ffd6                 call esi
// 008d95b4  8b442410             mov eax, dword ptr [esp + 0x10]
// 008d95b8  40                   inc eax
// 008d95b9  83f811               cmp eax, 0x11
// 008d95bc  89442410             mov dword ptr [esp + 0x10], eax
// 008d95c0  7cdf                 jl 0x8d95a1
// 008d95c2  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d95c5  6a00                 push 0
// 008d95c7  8d4511               lea eax, [ebp + 0x11]
// 008d95ca  50                   push eax
// 008d95cb  8944243c             mov dword ptr [esp + 0x3c], eax
// 008d95cf  8b8424c8000000       mov eax, dword ptr [esp + 0xc8]
// 008d95d6  50                   push eax
// 008d95d7  51                   push ecx
// 008d95d8  ffd6                 call esi
// 008d95da  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 008d95e1  6a00                 push 0
// 008d95e3  8d4512               lea eax, [ebp + 0x12]
// 008d95e6  50                   push eax
// 008d95e7  8944241c             mov dword ptr [esp + 0x1c], eax
// 008d95eb  8b4704               mov eax, dword ptr [edi + 4]
// 008d95ee  52                   push edx
// 008d95ef  50                   push eax
// 008d95f0  ffd6                 call esi
// 008d95f2  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008d95f6  8b9424b8000000       mov edx, dword ptr [esp + 0xb8]
// 008d95fd  8b4704               mov eax, dword ptr [edi + 4]
// 008d9600  6a00                 push 0
// 008d9602  51                   push ecx
// 008d9603  52                   push edx
// 008d9604  50                   push eax
// 008d9605  ffd6                 call esi
// 008d9607  8b8c2490000000       mov ecx, dword ptr [esp + 0x90]
// 008d960e  8b5704               mov edx, dword ptr [edi + 4]
// 008d9611  6a00                 push 0
// 008d9613  8d4513               lea eax, [ebp + 0x13]
// 008d9616  50                   push eax
// 008d9617  51                   push ecx
// 008d9618  52                   push edx
// 008d9619  8944242c             mov dword ptr [esp + 0x2c], eax
// 008d961d  ffd6                 call esi
// 008d961f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008d9623  8b8c249c000000       mov ecx, dword ptr [esp + 0x9c]
// 008d962a  8b5704               mov edx, dword ptr [edi + 4]
// 008d962d  6a00                 push 0
// 008d962f  50                   push eax
// 008d9630  51                   push ecx
// 008d9631  52                   push edx
// 008d9632  ffd6                 call esi
// 008d9634  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d9637  6a00                 push 0
// 008d9639  8d4514               lea eax, [ebp + 0x14]
// 008d963c  50                   push eax
// 008d963d  89442420             mov dword ptr [esp + 0x20], eax
// 008d9641  8b842490000000       mov eax, dword ptr [esp + 0x90]
// 008d9648  50                   push eax
// 008d9649  51                   push ecx
// 008d964a  ffd6                 call esi
// 008d964c  8b542418             mov edx, dword ptr [esp + 0x18]
// 008d9650  8b842498000000       mov eax, dword ptr [esp + 0x98]
// 008d9657  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d965a  6a00                 push 0
// 008d965c  52                   push edx
// 008d965d  50                   push eax
// 008d965e  51                   push ecx
// 008d965f  ffd6                 call esi
// 008d9661  8b542454             mov edx, dword ptr [esp + 0x54]
// 008d9665  6a00                 push 0
// 008d9667  8d4515               lea eax, [ebp + 0x15]
// 008d966a  50                   push eax
// 008d966b  89442438             mov dword ptr [esp + 0x38], eax
// 008d966f  8b4704               mov eax, dword ptr [edi + 4]
// 008d9672  52                   push edx
// 008d9673  50                   push eax
// 008d9674  ffd6                 call esi
// 008d9676  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 008d967a  8b542464             mov edx, dword ptr [esp + 0x64]
// 008d967e  8b4704               mov eax, dword ptr [edi + 4]
// 008d9681  6a00                 push 0
// 008d9683  51                   push ecx
// 008d9684  52                   push edx
// 008d9685  50                   push eax
// 008d9686  ffd6                 call esi
// 008d9688  8d4516               lea eax, [ebp + 0x16]
// 008d968b  6a00                 push 0
// 008d968d  89442450             mov dword ptr [esp + 0x50], eax
// 008d9691  50                   push eax
// 008d9692  8b8c24ac000000       mov ecx, dword ptr [esp + 0xac]
// 008d9699  8b5704               mov edx, dword ptr [edi + 4]
// 008d969c  51                   push ecx
// 008d969d  52                   push edx
// 008d969e  ffd6                 call esi
// 008d96a0  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 008d96a4  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 008d96a8  8b5704               mov edx, dword ptr [edi + 4]
// 008d96ab  6a00                 push 0
// 008d96ad  50                   push eax
// 008d96ae  51                   push ecx
// 008d96af  52                   push edx
// 008d96b0  ffd6                 call esi
// 008d96b2  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d96b5  6a00                 push 0
// 008d96b7  8d4517               lea eax, [ebp + 0x17]
// 008d96ba  50                   push eax
// 008d96bb  89442434             mov dword ptr [esp + 0x34], eax
// 008d96bf  8b442464             mov eax, dword ptr [esp + 0x64]
// 008d96c3  50                   push eax
// 008d96c4  51                   push ecx
// 008d96c5  ffd6                 call esi
// 008d96c7  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 008d96cb  8b442474             mov eax, dword ptr [esp + 0x74]
// 008d96cf  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d96d2  6a00                 push 0
// 008d96d4  52                   push edx
// 008d96d5  50                   push eax
// 008d96d6  51                   push ecx
// 008d96d7  ffd6                 call esi
// 008d96d9  8b9424ac000000       mov edx, dword ptr [esp + 0xac]
// 008d96e0  6a00                 push 0
// 008d96e2  8d4518               lea eax, [ebp + 0x18]
// 008d96e5  50                   push eax
// 008d96e6  8b4704               mov eax, dword ptr [edi + 4]
// 008d96e9  52                   push edx
// 008d96ea  50                   push eax
// 008d96eb  ffd6                 call esi
// 008d96ed  8b4c247c             mov ecx, dword ptr [esp + 0x7c]
// 008d96f1  8b5704               mov edx, dword ptr [edi + 4]
// 008d96f4  6a00                 push 0
// 008d96f6  8d4518               lea eax, [ebp + 0x18]
// 008d96f9  50                   push eax
// 008d96fa  51                   push ecx
// 008d96fb  52                   push edx
// 008d96fc  ffd6                 call esi
// 008d96fe  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d9701  6a00                 push 0
// 008d9703  8d4518               lea eax, [ebp + 0x18]
// 008d9706  50                   push eax
// 008d9707  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 008d970e  50                   push eax
// 008d970f  51                   push ecx
// 008d9710  ffd6                 call esi
// 008d9712  8b942484000000       mov edx, dword ptr [esp + 0x84]
// 008d9719  6a00                 push 0
// 008d971b  8d4518               lea eax, [ebp + 0x18]
// 008d971e  50                   push eax
// 008d971f  8b4704               mov eax, dword ptr [edi + 4]
// 008d9722  52                   push edx
// 008d9723  50                   push eax
// 008d9724  ffd6                 call esi
// 008d9726  8b8c24a8000000       mov ecx, dword ptr [esp + 0xa8]
// 008d972d  8b5704               mov edx, dword ptr [edi + 4]
// 008d9730  6a00                 push 0
// 008d9732  8d4518               lea eax, [ebp + 0x18]
// 008d9735  50                   push eax
// 008d9736  51                   push ecx
// 008d9737  52                   push edx
// 008d9738  ffd6                 call esi
// 008d973a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 008d973e  8b8c248c000000       mov ecx, dword ptr [esp + 0x8c]
// 008d9745  8b5704               mov edx, dword ptr [edi + 4]
// 008d9748  6a00                 push 0
// 008d974a  50                   push eax
// 008d974b  51                   push ecx
// 008d974c  52                   push edx
// 008d974d  ffd6                 call esi
// 008d974f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 008d9753  6a00                 push 0
// 008d9755  50                   push eax
// 008d9756  8b8c24a8000000       mov ecx, dword ptr [esp + 0xa8]
// 008d975d  8b5704               mov edx, dword ptr [edi + 4]
// 008d9760  51                   push ecx
// 008d9761  52                   push edx
// 008d9762  ffd6                 call esi
// 008d9764  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 008d9768  8b8c2494000000       mov ecx, dword ptr [esp + 0x94]
// 008d976f  8b5704               mov edx, dword ptr [edi + 4]
// 008d9772  6a00                 push 0
// 008d9774  50                   push eax
// 008d9775  51                   push ecx
// 008d9776  52                   push edx
// 008d9777  ffd6                 call esi
// 008d9779  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 008d977d  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 008d9781  8b5704               mov edx, dword ptr [edi + 4]
// 008d9784  6a00                 push 0
// 008d9786  50                   push eax
// 008d9787  51                   push ecx
// 008d9788  52                   push edx
// 008d9789  ffd6                 call esi
// 008d978b  8b442430             mov eax, dword ptr [esp + 0x30]
// 008d978f  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 008d9793  8b5704               mov edx, dword ptr [edi + 4]
// 008d9796  6a00                 push 0
// 008d9798  50                   push eax
// 008d9799  51                   push ecx
// 008d979a  52                   push edx
// 008d979b  ffd6                 call esi
// 008d979d  8b442430             mov eax, dword ptr [esp + 0x30]
// 008d97a1  8b4c2470             mov ecx, dword ptr [esp + 0x70]
// 008d97a5  8b5704               mov edx, dword ptr [edi + 4]
// 008d97a8  6a00                 push 0
// 008d97aa  50                   push eax
// 008d97ab  51                   push ecx
// 008d97ac  52                   push edx
// 008d97ad  ffd6                 call esi
// 008d97af  8b442418             mov eax, dword ptr [esp + 0x18]
// 008d97b3  8b4c2478             mov ecx, dword ptr [esp + 0x78]
// 008d97b7  8b5704               mov edx, dword ptr [edi + 4]
// 008d97ba  6a00                 push 0
// 008d97bc  50                   push eax
// 008d97bd  51                   push ecx
// 008d97be  52                   push edx
// 008d97bf  ffd6                 call esi
// 008d97c1  8b442418             mov eax, dword ptr [esp + 0x18]
// 008d97c5  8b8c2480000000       mov ecx, dword ptr [esp + 0x80]
// 008d97cc  8b5704               mov edx, dword ptr [edi + 4]
// 008d97cf  6a00                 push 0
// 008d97d1  50                   push eax
// 008d97d2  51                   push ecx
// 008d97d3  52                   push edx
// 008d97d4  ffd6                 call esi
// 008d97d6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008d97da  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 008d97de  8b5704               mov edx, dword ptr [edi + 4]
// 008d97e1  6a00                 push 0
// 008d97e3  50                   push eax
// 008d97e4  51                   push ecx
// 008d97e5  52                   push edx
// 008d97e6  ffd6                 call esi
// 008d97e8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008d97ec  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 008d97f0  8b5704               mov edx, dword ptr [edi + 4]
// 008d97f3  6a00                 push 0
// 008d97f5  50                   push eax
// 008d97f6  51                   push ecx
// 008d97f7  52                   push edx
// 008d97f8  ffd6                 call esi
// 008d97fa  8b442414             mov eax, dword ptr [esp + 0x14]
// 008d97fe  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 008d9802  8b5704               mov edx, dword ptr [edi + 4]
// 008d9805  6a00                 push 0
// 008d9807  50                   push eax
// 008d9808  51                   push ecx
// 008d9809  52                   push edx
// 008d980a  ffd6                 call esi
// 008d980c  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008d9810  8d4302               lea eax, [ebx + 2]
// 008d9813  898424c8000000       mov dword ptr [esp + 0xc8], eax
// 008d981a  6a00                 push 0
// 008d981c  8b5704               mov edx, dword ptr [edi + 4]
// 008d981f  51                   push ecx
// 008d9820  50                   push eax
// 008d9821  52                   push edx
// 008d9822  ffd6                 call esi
// 008d9824  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 008d9828  8b5704               mov edx, dword ptr [edi + 4]
// 008d982b  6a00                 push 0
// 008d982d  8d4301               lea eax, [ebx + 1]
// 008d9830  51                   push ecx
// 008d9831  50                   push eax
// 008d9832  52                   push edx
// 008d9833  898424d4000000       mov dword ptr [esp + 0xd4], eax
// 008d983a  ffd6                 call esi
// 008d983c  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008d9844  8b442410             mov eax, dword ptr [esp + 0x10]
// 008d9848  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d984b  6a00                 push 0
// 008d984d  03c5                 add eax, ebp
// 008d984f  50                   push eax
// 008d9850  53                   push ebx
// 008d9851  51                   push ecx
// 008d9852  ffd6                 call esi
// 008d9854  8b442410             mov eax, dword ptr [esp + 0x10]
// 008d9858  40                   inc eax
// 008d9859  83f811               cmp eax, 0x11
// 008d985c  89442410             mov dword ptr [esp + 0x10], eax
// 008d9860  7ce2                 jl 0x8d9844
// 008d9862  33db                 xor ebx, ebx
// 008d9864  8b442450             mov eax, dword ptr [esp + 0x50]
// 008d9868  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d986b  6a00                 push 0
// 008d986d  8d542b01             lea edx, [ebx + ebp + 1]
// 008d9871  52                   push edx
// 008d9872  50                   push eax
// 008d9873  51                   push ecx
// 008d9874  ffd6                 call esi
// 008d9876  43                   inc ebx
// 008d9877  83fb0f               cmp ebx, 0xf
// 008d987a  7ce8                 jl 0x8d9864
// 008d987c  8b542438             mov edx, dword ptr [esp + 0x38]
// 008d9880  8b4704               mov eax, dword ptr [edi + 4]
// 008d9883  6a00                 push 0
// 008d9885  8d5d10               lea ebx, [ebp + 0x10]
// 008d9888  53                   push ebx
// 008d9889  52                   push edx
// 008d988a  50                   push eax
// 008d988b  895c2450             mov dword ptr [esp + 0x50], ebx
// 008d988f  ffd6                 call esi
// 008d9891  8b8c2480000000       mov ecx, dword ptr [esp + 0x80]
// 008d9898  8b5704               mov edx, dword ptr [edi + 4]
// 008d989b  6a00                 push 0
// 008d989d  53                   push ebx
// 008d989e  51                   push ecx
// 008d989f  52                   push edx
// 008d98a0  ffd6                 call esi
// 008d98a2  8b442434             mov eax, dword ptr [esp + 0x34]
// 008d98a6  8b4c2478             mov ecx, dword ptr [esp + 0x78]
// 008d98aa  8b5704               mov edx, dword ptr [edi + 4]
// 008d98ad  6a00                 push 0
// 008d98af  50                   push eax
// 008d98b0  51                   push ecx
// 008d98b1  52                   push edx
// 008d98b2  ffd6                 call esi
// 008d98b4  8b442434             mov eax, dword ptr [esp + 0x34]
// 008d98b8  8b4c2470             mov ecx, dword ptr [esp + 0x70]
// 008d98bc  8b5704               mov edx, dword ptr [edi + 4]
// 008d98bf  6a00                 push 0
// 008d98c1  50                   push eax
// 008d98c2  51                   push ecx
// 008d98c3  52                   push edx
// 008d98c4  ffd6                 call esi
// 008d98c6  8b442414             mov eax, dword ptr [esp + 0x14]
// 008d98ca  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 008d98ce  8b5704               mov edx, dword ptr [edi + 4]
// 008d98d1  6a00                 push 0
// 008d98d3  50                   push eax
// 008d98d4  51                   push ecx
// 008d98d5  52                   push edx
// 008d98d6  ffd6                 call esi
// 008d98d8  8b442414             mov eax, dword ptr [esp + 0x14]
// 008d98dc  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 008d98e0  8b5704               mov edx, dword ptr [edi + 4]
// 008d98e3  6a00                 push 0
// 008d98e5  50                   push eax
// 008d98e6  51                   push ecx
// 008d98e7  52                   push edx
// 008d98e8  ffd6                 call esi
// 008d98ea  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008d98ee  8b8c2494000000       mov ecx, dword ptr [esp + 0x94]
// 008d98f5  8b5704               mov edx, dword ptr [edi + 4]
// 008d98f8  6a00                 push 0
// 008d98fa  50                   push eax
// 008d98fb  51                   push ecx
// 008d98fc  52                   push edx
// 008d98fd  ffd6                 call esi
// 008d98ff  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008d9903  8b8c24a0000000       mov ecx, dword ptr [esp + 0xa0]
// 008d990a  8b5704               mov edx, dword ptr [edi + 4]
// 008d990d  6a00                 push 0
// 008d990f  50                   push eax
// 008d9910  51                   push ecx
// 008d9911  52                   push edx
// 008d9912  ffd6                 call esi
// 008d9914  8b442418             mov eax, dword ptr [esp + 0x18]
// 008d9918  8b8c248c000000       mov ecx, dword ptr [esp + 0x8c]
// 008d991f  8b5704               mov edx, dword ptr [edi + 4]
// 008d9922  6a00                 push 0
// 008d9924  50                   push eax
// 008d9925  51                   push ecx
// 008d9926  52                   push edx
// 008d9927  ffd6                 call esi
// 008d9929  8b442418             mov eax, dword ptr [esp + 0x18]
// 008d992d  8b8c24a8000000       mov ecx, dword ptr [esp + 0xa8]
// 008d9934  8b5704               mov edx, dword ptr [edi + 4]
// 008d9937  6a00                 push 0
// 008d9939  50                   push eax
// 008d993a  51                   push ecx
// 008d993b  52                   push edx
// 008d993c  ffd6                 call esi
// 008d993e  6a00                 push 0
// 008d9940  8b442434             mov eax, dword ptr [esp + 0x34]
// 008d9944  8b8c2488000000       mov ecx, dword ptr [esp + 0x88]
// 008d994b  8b5704               mov edx, dword ptr [edi + 4]
// 008d994e  50                   push eax
// 008d994f  51                   push ecx
// 008d9950  52                   push edx
// 008d9951  ffd6                 call esi
// 008d9953  8b442430             mov eax, dword ptr [esp + 0x30]
// 008d9957  8b8c24b4000000       mov ecx, dword ptr [esp + 0xb4]
// 008d995e  8b5704               mov edx, dword ptr [edi + 4]
// 008d9961  6a00                 push 0
// 008d9963  50                   push eax
// 008d9964  51                   push ecx
// 008d9965  52                   push edx
// 008d9966  ffd6                 call esi
// 008d9968  8b442430             mov eax, dword ptr [esp + 0x30]
// 008d996c  8b4c247c             mov ecx, dword ptr [esp + 0x7c]
// 008d9970  8b5704               mov edx, dword ptr [edi + 4]
// 008d9973  6a00                 push 0
// 008d9975  50                   push eax
// 008d9976  51                   push ecx
// 008d9977  52                   push edx
// 008d9978  ffd6                 call esi
// 008d997a  8b442418             mov eax, dword ptr [esp + 0x18]
// 008d997e  8b8c24ac000000       mov ecx, dword ptr [esp + 0xac]
// 008d9985  8b5704               mov edx, dword ptr [edi + 4]
// 008d9988  6a00                 push 0
// 008d998a  50                   push eax
// 008d998b  51                   push ecx
// 008d998c  52                   push edx
// 008d998d  ffd6                 call esi
// 008d998f  8b442418             mov eax, dword ptr [esp + 0x18]
// 008d9993  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 008d9997  8b5704               mov edx, dword ptr [edi + 4]
// 008d999a  6a00                 push 0
// 008d999c  50                   push eax
// 008d999d  51                   push ecx
// 008d999e  52                   push edx
// 008d999f  ffd6                 call esi
// 008d99a1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008d99a5  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 008d99a9  8b5704               mov edx, dword ptr [edi + 4]
// 008d99ac  6a00                 push 0
// 008d99ae  50                   push eax
// 008d99af  51                   push ecx
// 008d99b0  52                   push edx
// 008d99b1  ffd6                 call esi
// 008d99b3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008d99b7  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 008d99bb  8b5704               mov edx, dword ptr [edi + 4]
// 008d99be  6a00                 push 0
// 008d99c0  50                   push eax
// 008d99c1  51                   push ecx
// 008d99c2  52                   push edx
// 008d99c3  ffd6                 call esi
// 008d99c5  8b442414             mov eax, dword ptr [esp + 0x14]
// 008d99c9  8b8c24a4000000       mov ecx, dword ptr [esp + 0xa4]
// 008d99d0  8b5704               mov edx, dword ptr [edi + 4]
// 008d99d3  6a00                 push 0
// 008d99d5  50                   push eax
// 008d99d6  51                   push ecx
// 008d99d7  52                   push edx
// 008d99d8  ffd6                 call esi
// 008d99da  8b442414             mov eax, dword ptr [esp + 0x14]
// 008d99de  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 008d99e2  8b5704               mov edx, dword ptr [edi + 4]
// 008d99e5  6a00                 push 0
// 008d99e7  50                   push eax
// 008d99e8  51                   push ecx
// 008d99e9  52                   push edx
// 008d99ea  ffd6                 call esi
// 008d99ec  8b442434             mov eax, dword ptr [esp + 0x34]
// 008d99f0  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 008d99f4  8b5704               mov edx, dword ptr [edi + 4]
// 008d99f7  6a00                 push 0
// 008d99f9  50                   push eax
// 008d99fa  51                   push ecx
// 008d99fb  52                   push edx
// 008d99fc  ffd6                 call esi
// 008d99fe  8b442434             mov eax, dword ptr [esp + 0x34]
// 008d9a02  6a00                 push 0
// 008d9a04  8b8c249c000000       mov ecx, dword ptr [esp + 0x9c]
// 008d9a0b  8b5704               mov edx, dword ptr [edi + 4]
// 008d9a0e  50                   push eax
// 008d9a0f  51                   push ecx
// 008d9a10  52                   push edx
// 008d9a11  ffd6                 call esi
// 008d9a13  8b842488000000       mov eax, dword ptr [esp + 0x88]
// 008d9a1a  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d9a1d  6a00                 push 0
// 008d9a1f  53                   push ebx
// 008d9a20  50                   push eax
// 008d9a21  51                   push ecx
// 008d9a22  ffd6                 call esi
// 008d9a24  8b94249c000000       mov edx, dword ptr [esp + 0x9c]
// 008d9a2b  8b4704               mov eax, dword ptr [edi + 4]
// 008d9a2e  6a00                 push 0
// 008d9a30  53                   push ebx
// 008d9a31  52                   push edx
// 008d9a32  50                   push eax
// 008d9a33  ffd6                 call esi
// 008d9a35  33db                 xor ebx, ebx
// 008d9a37  eb07                 jmp 0x8d9a40
// 008d9a39  8da42400000000       lea esp, [esp]
// 008d9a40  8b942490000000       mov edx, dword ptr [esp + 0x90]
// 008d9a47  8b4704               mov eax, dword ptr [edi + 4]
// 008d9a4a  6a00                 push 0
// 008d9a4c  8d4c2b01             lea ecx, [ebx + ebp + 1]
// 008d9a50  51                   push ecx
// 008d9a51  52                   push edx
// 008d9a52  50                   push eax
// 008d9a53  ffd6                 call esi
// 008d9a55  43                   inc ebx
// 008d9a56  83fb0f               cmp ebx, 0xf
// 008d9a59  7ce5                 jl 0x8d9a40
// 008d9a5b  8b8c249c000000       mov ecx, dword ptr [esp + 0x9c]
// 008d9a62  8b5704               mov edx, dword ptr [edi + 4]
// 008d9a65  6a00                 push 0
// 008d9a67  55                   push ebp
// 008d9a68  51                   push ecx
// 008d9a69  52                   push edx
// 008d9a6a  ffd6                 call esi
// 008d9a6c  8b842488000000       mov eax, dword ptr [esp + 0x88]
// 008d9a73  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d9a76  6a00                 push 0
// 008d9a78  55                   push ebp
// 008d9a79  50                   push eax
// 008d9a7a  51                   push ecx
// 008d9a7b  ffd6                 call esi
// 008d9a7d  8b5c2444             mov ebx, dword ptr [esp + 0x44]
// 008d9a81  8b942498000000       mov edx, dword ptr [esp + 0x98]
// 008d9a88  8b4704               mov eax, dword ptr [edi + 4]
// 008d9a8b  6a00                 push 0
// 008d9a8d  53                   push ebx
// 008d9a8e  52                   push edx
// 008d9a8f  50                   push eax
// 008d9a90  ffd6                 call esi
// 008d9a92  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 008d9a96  8b5704               mov edx, dword ptr [edi + 4]
// 008d9a99  6a00                 push 0
// 008d9a9b  53                   push ebx
// 008d9a9c  51                   push ecx
// 008d9a9d  52                   push edx
// 008d9a9e  ffd6                 call esi
// 008d9aa0  8b9c24b0000000       mov ebx, dword ptr [esp + 0xb0]
// 008d9aa7  8b442464             mov eax, dword ptr [esp + 0x64]
// 008d9aab  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d9aae  6a00                 push 0
// 008d9ab0  53                   push ebx
// 008d9ab1  50                   push eax
// 008d9ab2  51                   push ecx
// 008d9ab3  ffd6                 call esi
// 008d9ab5  8b9424a4000000       mov edx, dword ptr [esp + 0xa4]
// 008d9abc  8b4704               mov eax, dword ptr [edi + 4]
// 008d9abf  6a00                 push 0
// 008d9ac1  53                   push ebx
// 008d9ac2  52                   push edx
// 008d9ac3  50                   push eax
// 008d9ac4  ffd6                 call esi
// 008d9ac6  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 008d9aca  8b54246c             mov edx, dword ptr [esp + 0x6c]
// 008d9ace  8b4704               mov eax, dword ptr [edi + 4]
// 008d9ad1  6a00                 push 0
// 008d9ad3  51                   push ecx
// 008d9ad4  52                   push edx
// 008d9ad5  50                   push eax
// 008d9ad6  ffd6                 call esi
// 008d9ad8  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 008d9adc  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 008d9ae0  8b4704               mov eax, dword ptr [edi + 4]
// 008d9ae3  6a00                 push 0
// 008d9ae5  51                   push ecx
// 008d9ae6  52                   push edx
// 008d9ae7  50                   push eax
// 008d9ae8  ffd6                 call esi
// 008d9aea  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008d9aee  8b542474             mov edx, dword ptr [esp + 0x74]
// 008d9af2  8b4704               mov eax, dword ptr [edi + 4]
// 008d9af5  6a00                 push 0
// 008d9af7  51                   push ecx
// 008d9af8  52                   push edx
// 008d9af9  50                   push eax
// 008d9afa  ffd6                 call esi
// 008d9afc  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008d9b00  8b9424ac000000       mov edx, dword ptr [esp + 0xac]
// 008d9b07  8b4704               mov eax, dword ptr [edi + 4]
// 008d9b0a  6a00                 push 0
// 008d9b0c  51                   push ecx
// 008d9b0d  52                   push edx
// 008d9b0e  50                   push eax
// 008d9b0f  ffd6                 call esi
// 008d9b11  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008d9b15  8b54247c             mov edx, dword ptr [esp + 0x7c]
// 008d9b19  6a00                 push 0
// 008d9b1b  51                   push ecx
// 008d9b1c  52                   push edx
// 008d9b1d  8b4704               mov eax, dword ptr [edi + 4]
// 008d9b20  50                   push eax
// 008d9b21  ffd6                 call esi
// 008d9b23  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008d9b27  8b9424b4000000       mov edx, dword ptr [esp + 0xb4]
// 008d9b2e  8b4704               mov eax, dword ptr [edi + 4]
// 008d9b31  6a00                 push 0
// 008d9b33  51                   push ecx
// 008d9b34  52                   push edx
// 008d9b35  50                   push eax
// 008d9b36  ffd6                 call esi
// 008d9b38  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008d9b3c  8b942484000000       mov edx, dword ptr [esp + 0x84]
// 008d9b43  8b4704               mov eax, dword ptr [edi + 4]
// 008d9b46  6a00                 push 0
// 008d9b48  51                   push ecx
// 008d9b49  52                   push edx
// 008d9b4a  50                   push eax
// 008d9b4b  ffd6                 call esi
// 008d9b4d  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008d9b51  8b9424a8000000       mov edx, dword ptr [esp + 0xa8]
// 008d9b58  8b4704               mov eax, dword ptr [edi + 4]
// 008d9b5b  6a00                 push 0
// 008d9b5d  51                   push ecx
// 008d9b5e  52                   push edx
// 008d9b5f  50                   push eax
// 008d9b60  ffd6                 call esi
// 008d9b62  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008d9b66  8b94248c000000       mov edx, dword ptr [esp + 0x8c]
// 008d9b6d  8b4704               mov eax, dword ptr [edi + 4]
// 008d9b70  6a00                 push 0
// 008d9b72  51                   push ecx
// 008d9b73  52                   push edx
// 008d9b74  50                   push eax
// 008d9b75  ffd6                 call esi
// 008d9b77  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 008d9b7b  8b9424a0000000       mov edx, dword ptr [esp + 0xa0]
// 008d9b82  8b4704               mov eax, dword ptr [edi + 4]
// 008d9b85  6a00                 push 0
// 008d9b87  51                   push ecx
// 008d9b88  52                   push edx
// 008d9b89  50                   push eax
// 008d9b8a  ffd6                 call esi
// 008d9b8c  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 008d9b90  8b942494000000       mov edx, dword ptr [esp + 0x94]
// 008d9b97  8b4704               mov eax, dword ptr [edi + 4]
// 008d9b9a  6a00                 push 0
// 008d9b9c  51                   push ecx
// 008d9b9d  52                   push edx
// 008d9b9e  50                   push eax
// 008d9b9f  ffd6                 call esi
// 008d9ba1  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 008d9ba5  8b5704               mov edx, dword ptr [edi + 4]
// 008d9ba8  6a00                 push 0
// 008d9baa  53                   push ebx
// 008d9bab  51                   push ecx
// 008d9bac  52                   push edx
// 008d9bad  ffd6                 call esi
// 008d9baf  8b442468             mov eax, dword ptr [esp + 0x68]
// 008d9bb3  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d9bb6  6a00                 push 0
// 008d9bb8  53                   push ebx
// 008d9bb9  50                   push eax
// 008d9bba  51                   push ecx
// 008d9bbb  ffd6                 call esi
// 008d9bbd  8b542444             mov edx, dword ptr [esp + 0x44]
// 008d9bc1  8b442470             mov eax, dword ptr [esp + 0x70]
// 008d9bc5  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d9bc8  6a00                 push 0
// 008d9bca  52                   push edx
// 008d9bcb  50                   push eax
// 008d9bcc  51                   push ecx
// 008d9bcd  ffd6                 call esi
// 008d9bcf  8b542444             mov edx, dword ptr [esp + 0x44]
// 008d9bd3  8b442478             mov eax, dword ptr [esp + 0x78]
// 008d9bd7  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d9bda  6a00                 push 0
// 008d9bdc  52                   push edx
// 008d9bdd  50                   push eax
// 008d9bde  51                   push ecx
// 008d9bdf  ffd6                 call esi
// 008d9be1  8b942480000000       mov edx, dword ptr [esp + 0x80]
// 008d9be8  8b4704               mov eax, dword ptr [edi + 4]
// 008d9beb  6a00                 push 0
// 008d9bed  55                   push ebp
// 008d9bee  52                   push edx
// 008d9bef  50                   push eax
// 008d9bf0  ffd6                 call esi
// 008d9bf2  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 008d9bf6  8b5704               mov edx, dword ptr [edi + 4]
// 008d9bf9  6a00                 push 0
// 008d9bfb  55                   push ebp
// 008d9bfc  51                   push ecx
// 008d9bfd  52                   push edx
// 008d9bfe  ffd6                 call esi
// 008d9c00  896c2410             mov dword ptr [esp + 0x10], ebp
// 008d9c04  c744243811000000     mov dword ptr [esp + 0x38], 0x11
// 008d9c0c  8d642400             lea esp, [esp]
// 008d9c10  8b442410             mov eax, dword ptr [esp + 0x10]
// 008d9c14  8b8c24c4000000       mov ecx, dword ptr [esp + 0xc4]
// 008d9c1b  8b5704               mov edx, dword ptr [edi + 4]
// 008d9c1e  68ffffff00           push 0xffffff
// 008d9c23  50                   push eax
// 008d9c24  51                   push ecx
// 008d9c25  52                   push edx
// 008d9c26  ffd6                 call esi
// 008d9c28  8b442410             mov eax, dword ptr [esp + 0x10]
// 008d9c2c  8b8c24c8000000       mov ecx, dword ptr [esp + 0xc8]
// 008d9c33  8b5704               mov edx, dword ptr [edi + 4]
// 008d9c36  68ffffff00           push 0xffffff
// 008d9c3b  50                   push eax
// 008d9c3c  51                   push ecx
// 008d9c3d  52                   push edx
// 008d9c3e  ffd6                 call esi
// 008d9c40  8b442410             mov eax, dword ptr [esp + 0x10]
// 008d9c44  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 008d9c48  8b5704               mov edx, dword ptr [edi + 4]
// 008d9c4b  68ffffff00           push 0xffffff
// 008d9c50  50                   push eax
// 008d9c51  51                   push ecx
// 008d9c52  52                   push edx
// 008d9c53  ffd6                 call esi
// 008d9c55  b801000000           mov eax, 1
// 008d9c5a  01442410             add dword ptr [esp + 0x10], eax
// 008d9c5e  29442438             sub dword ptr [esp + 0x38], eax
// 008d9c62  75ac                 jne 0x8d9c10
// 008d9c64  8b442450             mov eax, dword ptr [esp + 0x50]
// 008d9c68  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d9c6b  68ffffff00           push 0xffffff
// 008d9c70  55                   push ebp
// 008d9c71  50                   push eax
// 008d9c72  51                   push ecx
// 008d9c73  ffd6                 call esi
// 008d9c75  8b542440             mov edx, dword ptr [esp + 0x40]
// 008d9c79  8b442450             mov eax, dword ptr [esp + 0x50]
// 008d9c7d  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d9c80  68ffffff00           push 0xffffff
// 008d9c85  52                   push edx
// 008d9c86  50                   push eax
// 008d9c87  51                   push ecx
// 008d9c88  ffd6                 call esi
// 008d9c8a  896c2410             mov dword ptr [esp + 0x10], ebp
// 008d9c8e  c744244811000000     mov dword ptr [esp + 0x48], 0x11
// 008d9c96  eb08                 jmp 0x8d9ca0
// 008d9c98  8da42400000000       lea esp, [esp]
// 008d9c9f  90                   nop 
// 008d9ca0  8b542410             mov edx, dword ptr [esp + 0x10]
// 008d9ca4  8b8424b8000000       mov eax, dword ptr [esp + 0xb8]
// 008d9cab  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d9cae  68ffffff00           push 0xffffff
// 008d9cb3  52                   push edx
// 008d9cb4  50                   push eax
// 008d9cb5  51                   push ecx
// 008d9cb6  ffd6                 call esi
// 008d9cb8  8b542410             mov edx, dword ptr [esp + 0x10]
// 008d9cbc  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 008d9cc3  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d9cc6  68ffffff00           push 0xffffff
// 008d9ccb  52                   push edx
// 008d9ccc  50                   push eax
// 008d9ccd  51                   push ecx
// 008d9cce  ffd6                 call esi
// 008d9cd0  8b542410             mov edx, dword ptr [esp + 0x10]
// 008d9cd4  8b8424c0000000       mov eax, dword ptr [esp + 0xc0]
// 008d9cdb  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d9cde  68ffffff00           push 0xffffff
// 008d9ce3  52                   push edx
// 008d9ce4  50                   push eax
// 008d9ce5  51                   push ecx
// 008d9ce6  ffd6                 call esi
// 008d9ce8  b801000000           mov eax, 1
// 008d9ced  01442410             add dword ptr [esp + 0x10], eax
// 008d9cf1  29442448             sub dword ptr [esp + 0x48], eax
// 008d9cf5  75a9                 jne 0x8d9ca0
// 008d9cf7  8b5704               mov edx, dword ptr [edi + 4]
// 008d9cfa  68ffffff00           push 0xffffff
// 008d9cff  55                   push ebp
// 008d9d00  8bac2498000000       mov ebp, dword ptr [esp + 0x98]
// 008d9d07  55                   push ebp
// 008d9d08  52                   push edx
// 008d9d09  ffd6                 call esi
// 008d9d0b  8b442440             mov eax, dword ptr [esp + 0x40]
// 008d9d0f  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d9d12  68ffffff00           push 0xffffff
// 008d9d17  50                   push eax
// 008d9d18  55                   push ebp
// 008d9d19  51                   push ecx
// 008d9d1a  ffd6                 call esi
// 008d9d1c  8b6c2454             mov ebp, dword ptr [esp + 0x54]
// 008d9d20  c744244005000000     mov dword ptr [esp + 0x40], 5
// 008d9d28  eb06                 jmp 0x8d9d30
// 008d9d2a  8d9b00000000         lea ebx, [ebx]
// 008d9d30  8b542444             mov edx, dword ptr [esp + 0x44]
// 008d9d34  68ffffff00           push 0xffffff
// 008d9d39  52                   push edx
// 008d9d3a  8d45ea               lea eax, [ebp - 0x16]
// 008d9d3d  50                   push eax
// 008d9d3e  8b4704               mov eax, dword ptr [edi + 4]
// 008d9d41  50                   push eax
// 008d9d42  ffd6                 call esi
// 008d9d44  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d9d47  68ffffff00           push 0xffffff
// 008d9d4c  53                   push ebx
// 008d9d4d  8d45ec               lea eax, [ebp - 0x14]
// 008d9d50  50                   push eax
// 008d9d51  51                   push ecx
// 008d9d52  ffd6                 call esi
// 008d9d54  8b542424             mov edx, dword ptr [esp + 0x24]
// 008d9d58  68ffffff00           push 0xffffff
// 008d9d5d  52                   push edx
// 008d9d5e  8d45ee               lea eax, [ebp - 0x12]
// 008d9d61  50                   push eax
// 008d9d62  8b4704               mov eax, dword ptr [edi + 4]
// 008d9d65  50                   push eax
// 008d9d66  ffd6                 call esi
// 008d9d68  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008d9d6c  8b5704               mov edx, dword ptr [edi + 4]
// 008d9d6f  68ffffff00           push 0xffffff
// 008d9d74  51                   push ecx
// 008d9d75  8d45f0               lea eax, [ebp - 0x10]
// 008d9d78  50                   push eax
// 008d9d79  52                   push edx
// 008d9d7a  ffd6                 call esi
// 008d9d7c  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008d9d80  8b5704               mov edx, dword ptr [edi + 4]
// 008d9d83  68ffffff00           push 0xffffff
// 008d9d88  51                   push ecx
// 008d9d89  8d45f2               lea eax, [ebp - 0xe]
// 008d9d8c  50                   push eax
// 008d9d8d  52                   push edx
// 008d9d8e  ffd6                 call esi
// 008d9d90  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 008d9d94  8b5704               mov edx, dword ptr [edi + 4]
// 008d9d97  68ffffff00           push 0xffffff
// 008d9d9c  51                   push ecx
// 008d9d9d  8d45f4               lea eax, [ebp - 0xc]
// 008d9da0  50                   push eax
// 008d9da1  52                   push edx
// 008d9da2  ffd6                 call esi
// 008d9da4  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 008d9da8  8b5704               mov edx, dword ptr [edi + 4]
// 008d9dab  68ffffff00           push 0xffffff
// 008d9db0  51                   push ecx
// 008d9db1  8d45f8               lea eax, [ebp - 8]
// 008d9db4  50                   push eax
// 008d9db5  52                   push edx
// 008d9db6  ffd6                 call esi
// 008d9db8  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 008d9dbc  8b5704               mov edx, dword ptr [edi + 4]
// 008d9dbf  68ffffff00           push 0xffffff
// 008d9dc4  51                   push ecx
// 008d9dc5  8d45f6               lea eax, [ebp - 0xa]
// 008d9dc8  50                   push eax
// 008d9dc9  52                   push edx
// 008d9dca  ffd6                 call esi
// 008d9dcc  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008d9dd0  8b5704               mov edx, dword ptr [edi + 4]
// 008d9dd3  68ffffff00           push 0xffffff
// 008d9dd8  51                   push ecx
// 008d9dd9  8d45fa               lea eax, [ebp - 6]
// 008d9ddc  50                   push eax
// 008d9ddd  52                   push edx
// 008d9dde  ffd6                 call esi
// 008d9de0  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008d9de4  8b5704               mov edx, dword ptr [edi + 4]
// 008d9de7  68ffffff00           push 0xffffff
// 008d9dec  51                   push ecx
// 008d9ded  8d45fc               lea eax, [ebp - 4]
// 008d9df0  50                   push eax
// 008d9df1  52                   push edx
// 008d9df2  ffd6                 call esi
// 008d9df4  8d45fe               lea eax, [ebp - 2]
// 008d9df7  68ffffff00           push 0xffffff
// 008d9dfc  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008d9e00  8b5704               mov edx, dword ptr [edi + 4]
// 008d9e03  51                   push ecx
// 008d9e04  50                   push eax
// 008d9e05  52                   push edx
// 008d9e06  ffd6                 call esi
// 008d9e08  8b4704               mov eax, dword ptr [edi + 4]
// 008d9e0b  68ffffff00           push 0xffffff
// 008d9e10  53                   push ebx
// 008d9e11  55                   push ebp
// 008d9e12  50                   push eax
// 008d9e13  ffd6                 call esi
// 008d9e15  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 008d9e19  8b5704               mov edx, dword ptr [edi + 4]
// 008d9e1c  68ffffff00           push 0xffffff
// 008d9e21  51                   push ecx
// 008d9e22  8d4502               lea eax, [ebp + 2]
// 008d9e25  50                   push eax
// 008d9e26  52                   push edx
// 008d9e27  ffd6                 call esi
// 008d9e29  8b442434             mov eax, dword ptr [esp + 0x34]
// 008d9e2d  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d9e30  68ffffff00           push 0xffffff
// 008d9e35  50                   push eax
// 008d9e36  8d4502               lea eax, [ebp + 2]
// 008d9e39  50                   push eax
// 008d9e3a  51                   push ecx
// 008d9e3b  ffd6                 call esi
// 008d9e3d  8b542414             mov edx, dword ptr [esp + 0x14]
// 008d9e41  8b4704               mov eax, dword ptr [edi + 4]
// 008d9e44  68ffffff00           push 0xffffff
// 008d9e49  52                   push edx
// 008d9e4a  55                   push ebp
// 008d9e4b  50                   push eax
// 008d9e4c  ffd6                 call esi
// 008d9e4e  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 008d9e52  8b5704               mov edx, dword ptr [edi + 4]
// 008d9e55  68ffffff00           push 0xffffff
// 008d9e5a  51                   push ecx
// 008d9e5b  8d45fe               lea eax, [ebp - 2]
// 008d9e5e  50                   push eax
// 008d9e5f  52                   push edx
// 008d9e60  ffd6                 call esi
// 008d9e62  8b442418             mov eax, dword ptr [esp + 0x18]
// 008d9e66  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d9e69  68ffffff00           push 0xffffff
// 008d9e6e  50                   push eax
// 008d9e6f  8d45fc               lea eax, [ebp - 4]
// 008d9e72  50                   push eax
// 008d9e73  51                   push ecx
// 008d9e74  ffd6                 call esi
// 008d9e76  8b542430             mov edx, dword ptr [esp + 0x30]
// 008d9e7a  68ffffff00           push 0xffffff
// 008d9e7f  52                   push edx
// 008d9e80  8d45fa               lea eax, [ebp - 6]
// 008d9e83  50                   push eax
// 008d9e84  8b4704               mov eax, dword ptr [edi + 4]
// 008d9e87  50                   push eax
// 008d9e88  ffd6                 call esi
// 008d9e8a  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 008d9e8e  8b5704               mov edx, dword ptr [edi + 4]
// 008d9e91  68ffffff00           push 0xffffff
// 008d9e96  51                   push ecx
// 008d9e97  8d45f6               lea eax, [ebp - 0xa]
// 008d9e9a  50                   push eax
// 008d9e9b  52                   push edx
// 008d9e9c  ffd6                 call esi
// 008d9e9e  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 008d9ea2  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d9ea5  68ffffff00           push 0xffffff
// 008d9eaa  50                   push eax
// 008d9eab  8d45f8               lea eax, [ebp - 8]
// 008d9eae  50                   push eax
// 008d9eaf  51                   push ecx
// 008d9eb0  ffd6                 call esi
// 008d9eb2  8b54244c             mov edx, dword ptr [esp + 0x4c]
// 008d9eb6  68ffffff00           push 0xffffff
// 008d9ebb  8d45f4               lea eax, [ebp - 0xc]
// 008d9ebe  52                   push edx
// 008d9ebf  50                   push eax
// 008d9ec0  8b4704               mov eax, dword ptr [edi + 4]
// 008d9ec3  50                   push eax
// 008d9ec4  ffd6                 call esi
// 008d9ec6  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 008d9eca  8b5704               mov edx, dword ptr [edi + 4]
// 008d9ecd  68ffffff00           push 0xffffff
// 008d9ed2  51                   push ecx
// 008d9ed3  8d45f2               lea eax, [ebp - 0xe]
// 008d9ed6  50                   push eax
// 008d9ed7  52                   push edx
// 008d9ed8  ffd6                 call esi
// 008d9eda  8b442418             mov eax, dword ptr [esp + 0x18]
// 008d9ede  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d9ee1  68ffffff00           push 0xffffff
// 008d9ee6  50                   push eax
// 008d9ee7  8d45f0               lea eax, [ebp - 0x10]
// 008d9eea  50                   push eax
// 008d9eeb  51                   push ecx
// 008d9eec  ffd6                 call esi
// 008d9eee  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 008d9ef2  68ffffff00           push 0xffffff
// 008d9ef7  52                   push edx
// 008d9ef8  8d45ee               lea eax, [ebp - 0x12]
// 008d9efb  50                   push eax
// 008d9efc  8b4704               mov eax, dword ptr [edi + 4]
// 008d9eff  50                   push eax
// 008d9f00  ffd6                 call esi
// 008d9f02  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008d9f06  8b5704               mov edx, dword ptr [edi + 4]
// 008d9f09  68ffffff00           push 0xffffff
// 008d9f0e  51                   push ecx
// 008d9f0f  8d45ec               lea eax, [ebp - 0x14]
// 008d9f12  50                   push eax
// 008d9f13  52                   push edx
// 008d9f14  ffd6                 call esi
// 008d9f16  8b442434             mov eax, dword ptr [esp + 0x34]
// 008d9f1a  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d9f1d  68ffffff00           push 0xffffff
// 008d9f22  50                   push eax
// 008d9f23  8d45ea               lea eax, [ebp - 0x16]
// 008d9f26  50                   push eax
// 008d9f27  51                   push ecx
// 008d9f28  ffd6                 call esi
// 008d9f2a  45                   inc ebp
// 008d9f2b  836c244001           sub dword ptr [esp + 0x40], 1
// 008d9f30  0f85fafdffff         jne 0x8d9d30
// 008d9f36  5f                   pop edi
// 008d9f37  5e                   pop esi
// 008d9f38  5d                   pop ebp
// 008d9f39  5b                   pop ebx
// 008d9f3a  81c4bc000000         add esp, 0xbc
// 008d9f40  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?DrawLargeSelectCell@CXTColorHex@@IAEXPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp
