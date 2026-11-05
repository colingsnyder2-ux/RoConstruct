// from server: 100% by auto
// roc 2011-06 008e60f0  unit: CXTColorHex  size: 3251 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008e60f0
//
// 008e60f0  81ecbc000000         sub esp, 0xbc
// 008e60f6  53                   push ebx
// 008e60f7  8b5968               mov ebx, dword ptr [ecx + 0x68]
// 008e60fa  55                   push ebp
// 008e60fb  8b696c               mov ebp, dword ptr [ecx + 0x6c]
// 008e60fe  56                   push esi
// 008e60ff  8b350c01a400         mov esi, dword ptr [0xa4010c]
// 008e6105  57                   push edi
// 008e6106  8bbc24d0000000       mov edi, dword ptr [esp + 0xd0]
// 008e610d  83eb02               sub ebx, 2
// 008e6110  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008e6118  896c242c             mov dword ptr [esp + 0x2c], ebp
// 008e611c  8d642400             lea esp, [esp]
// 008e6120  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 008e6124  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008e6128  8b5704               mov edx, dword ptr [edi + 4]
// 008e612b  6a00                 push 0
// 008e612d  50                   push eax
// 008e612e  03cb                 add ecx, ebx
// 008e6130  51                   push ecx
// 008e6131  52                   push edx
// 008e6132  ffd6                 call esi
// 008e6134  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e6138  ff4c242c             dec dword ptr [esp + 0x2c]
// 008e613c  40                   inc eax
// 008e613d  83f803               cmp eax, 3
// 008e6140  89442410             mov dword ptr [esp + 0x10], eax
// 008e6144  7cda                 jl 0x8e6120
// 008e6146  6a00                 push 0
// 008e6148  8d45fe               lea eax, [ebp - 2]
// 008e614b  50                   push eax
// 008e614c  8d4b03               lea ecx, [ebx + 3]
// 008e614f  898424b8000000       mov dword ptr [esp + 0xb8], eax
// 008e6156  8b4704               mov eax, dword ptr [edi + 4]
// 008e6159  51                   push ecx
// 008e615a  50                   push eax
// 008e615b  894c2458             mov dword ptr [esp + 0x58], ecx
// 008e615f  ffd6                 call esi
// 008e6161  6a00                 push 0
// 008e6163  8d45fd               lea eax, [ebp - 3]
// 008e6166  8d4b04               lea ecx, [ebx + 4]
// 008e6169  50                   push eax
// 008e616a  51                   push ecx
// 008e616b  894c245c             mov dword ptr [esp + 0x5c], ecx
// 008e616f  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6172  51                   push ecx
// 008e6173  89442434             mov dword ptr [esp + 0x34], eax
// 008e6177  ffd6                 call esi
// 008e6179  8b542424             mov edx, dword ptr [esp + 0x24]
// 008e617d  6a00                 push 0
// 008e617f  8d4305               lea eax, [ebx + 5]
// 008e6182  52                   push edx
// 008e6183  50                   push eax
// 008e6184  89442444             mov dword ptr [esp + 0x44], eax
// 008e6188  8b4704               mov eax, dword ptr [edi + 4]
// 008e618b  50                   push eax
// 008e618c  ffd6                 call esi
// 008e618e  6a00                 push 0
// 008e6190  8d45fc               lea eax, [ebp - 4]
// 008e6193  8d4b06               lea ecx, [ebx + 6]
// 008e6196  50                   push eax
// 008e6197  51                   push ecx
// 008e6198  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 008e619f  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e61a2  51                   push ecx
// 008e61a3  89442430             mov dword ptr [esp + 0x30], eax
// 008e61a7  ffd6                 call esi
// 008e61a9  8b542420             mov edx, dword ptr [esp + 0x20]
// 008e61ad  6a00                 push 0
// 008e61af  8d4307               lea eax, [ebx + 7]
// 008e61b2  52                   push edx
// 008e61b3  50                   push eax
// 008e61b4  89842484000000       mov dword ptr [esp + 0x84], eax
// 008e61bb  8b4704               mov eax, dword ptr [edi + 4]
// 008e61be  50                   push eax
// 008e61bf  ffd6                 call esi
// 008e61c1  6a00                 push 0
// 008e61c3  8d45fb               lea eax, [ebp - 5]
// 008e61c6  8d4b08               lea ecx, [ebx + 8]
// 008e61c9  50                   push eax
// 008e61ca  51                   push ecx
// 008e61cb  894c247c             mov dword ptr [esp + 0x7c], ecx
// 008e61cf  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e61d2  51                   push ecx
// 008e61d3  89442438             mov dword ptr [esp + 0x38], eax
// 008e61d7  ffd6                 call esi
// 008e61d9  8b542428             mov edx, dword ptr [esp + 0x28]
// 008e61dd  6a00                 push 0
// 008e61df  8d4309               lea eax, [ebx + 9]
// 008e61e2  52                   push edx
// 008e61e3  50                   push eax
// 008e61e4  89442474             mov dword ptr [esp + 0x74], eax
// 008e61e8  8b4704               mov eax, dword ptr [edi + 4]
// 008e61eb  50                   push eax
// 008e61ec  ffd6                 call esi
// 008e61ee  6a00                 push 0
// 008e61f0  8d45fa               lea eax, [ebp - 6]
// 008e61f3  8d4b0a               lea ecx, [ebx + 0xa]
// 008e61f6  50                   push eax
// 008e61f7  51                   push ecx
// 008e61f8  894c246c             mov dword ptr [esp + 0x6c], ecx
// 008e61fc  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e61ff  51                   push ecx
// 008e6200  8944244c             mov dword ptr [esp + 0x4c], eax
// 008e6204  ffd6                 call esi
// 008e6206  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 008e620a  8d430b               lea eax, [ebx + 0xb]
// 008e620d  89842494000000       mov dword ptr [esp + 0x94], eax
// 008e6214  6a00                 push 0
// 008e6216  52                   push edx
// 008e6217  50                   push eax
// 008e6218  8b4704               mov eax, dword ptr [edi + 4]
// 008e621b  50                   push eax
// 008e621c  ffd6                 call esi
// 008e621e  6a00                 push 0
// 008e6220  8d45f9               lea eax, [ebp - 7]
// 008e6223  8d4b0c               lea ecx, [ebx + 0xc]
// 008e6226  50                   push eax
// 008e6227  51                   push ecx
// 008e6228  898c24ac000000       mov dword ptr [esp + 0xac], ecx
// 008e622f  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6232  51                   push ecx
// 008e6233  89442468             mov dword ptr [esp + 0x68], eax
// 008e6237  ffd6                 call esi
// 008e6239  8b542458             mov edx, dword ptr [esp + 0x58]
// 008e623d  6a00                 push 0
// 008e623f  8d430d               lea eax, [ebx + 0xd]
// 008e6242  52                   push edx
// 008e6243  50                   push eax
// 008e6244  89842498000000       mov dword ptr [esp + 0x98], eax
// 008e624b  8b4704               mov eax, dword ptr [edi + 4]
// 008e624e  50                   push eax
// 008e624f  ffd6                 call esi
// 008e6251  6a00                 push 0
// 008e6253  8d45f8               lea eax, [ebp - 8]
// 008e6256  8d4b0e               lea ecx, [ebx + 0xe]
// 008e6259  50                   push eax
// 008e625a  51                   push ecx
// 008e625b  898c24b4000000       mov dword ptr [esp + 0xb4], ecx
// 008e6262  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6265  51                   push ecx
// 008e6266  ffd6                 call esi
// 008e6268  8b5704               mov edx, dword ptr [edi + 4]
// 008e626b  6a00                 push 0
// 008e626d  8d45f8               lea eax, [ebp - 8]
// 008e6270  8d4b0f               lea ecx, [ebx + 0xf]
// 008e6273  50                   push eax
// 008e6274  51                   push ecx
// 008e6275  52                   push edx
// 008e6276  898c2494000000       mov dword ptr [esp + 0x94], ecx
// 008e627d  ffd6                 call esi
// 008e627f  6a00                 push 0
// 008e6281  8d45f8               lea eax, [ebp - 8]
// 008e6284  50                   push eax
// 008e6285  8b4704               mov eax, dword ptr [edi + 4]
// 008e6288  8d4b10               lea ecx, [ebx + 0x10]
// 008e628b  51                   push ecx
// 008e628c  50                   push eax
// 008e628d  898c24c4000000       mov dword ptr [esp + 0xc4], ecx
// 008e6294  ffd6                 call esi
// 008e6296  6a00                 push 0
// 008e6298  8d45f8               lea eax, [ebp - 8]
// 008e629b  8d4b11               lea ecx, [ebx + 0x11]
// 008e629e  50                   push eax
// 008e629f  51                   push ecx
// 008e62a0  898c2488000000       mov dword ptr [esp + 0x88], ecx
// 008e62a7  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e62aa  51                   push ecx
// 008e62ab  ffd6                 call esi
// 008e62ad  8b5704               mov edx, dword ptr [edi + 4]
// 008e62b0  6a00                 push 0
// 008e62b2  8d45f8               lea eax, [ebp - 8]
// 008e62b5  8d4b12               lea ecx, [ebx + 0x12]
// 008e62b8  50                   push eax
// 008e62b9  51                   push ecx
// 008e62ba  52                   push edx
// 008e62bb  898c24bc000000       mov dword ptr [esp + 0xbc], ecx
// 008e62c2  ffd6                 call esi
// 008e62c4  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 008e62c8  8b5704               mov edx, dword ptr [edi + 4]
// 008e62cb  6a00                 push 0
// 008e62cd  8d4313               lea eax, [ebx + 0x13]
// 008e62d0  51                   push ecx
// 008e62d1  50                   push eax
// 008e62d2  52                   push edx
// 008e62d3  89842484000000       mov dword ptr [esp + 0x84], eax
// 008e62da  ffd6                 call esi
// 008e62dc  8d4314               lea eax, [ebx + 0x14]
// 008e62df  8944245c             mov dword ptr [esp + 0x5c], eax
// 008e62e3  6a00                 push 0
// 008e62e5  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 008e62e9  8b5704               mov edx, dword ptr [edi + 4]
// 008e62ec  51                   push ecx
// 008e62ed  50                   push eax
// 008e62ee  52                   push edx
// 008e62ef  ffd6                 call esi
// 008e62f1  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 008e62f5  8b5704               mov edx, dword ptr [edi + 4]
// 008e62f8  6a00                 push 0
// 008e62fa  8d4315               lea eax, [ebx + 0x15]
// 008e62fd  51                   push ecx
// 008e62fe  50                   push eax
// 008e62ff  52                   push edx
// 008e6300  8944247c             mov dword ptr [esp + 0x7c], eax
// 008e6304  ffd6                 call esi
// 008e6306  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 008e630a  8b5704               mov edx, dword ptr [edi + 4]
// 008e630d  6a00                 push 0
// 008e630f  8d4316               lea eax, [ebx + 0x16]
// 008e6312  51                   push ecx
// 008e6313  50                   push eax
// 008e6314  52                   push edx
// 008e6315  898424b4000000       mov dword ptr [esp + 0xb4], eax
// 008e631c  ffd6                 call esi
// 008e631e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008e6322  8b5704               mov edx, dword ptr [edi + 4]
// 008e6325  6a00                 push 0
// 008e6327  8d4317               lea eax, [ebx + 0x17]
// 008e632a  51                   push ecx
// 008e632b  50                   push eax
// 008e632c  52                   push edx
// 008e632d  89442474             mov dword ptr [esp + 0x74], eax
// 008e6331  ffd6                 call esi
// 008e6333  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008e6337  8b5704               mov edx, dword ptr [edi + 4]
// 008e633a  6a00                 push 0
// 008e633c  8d4318               lea eax, [ebx + 0x18]
// 008e633f  51                   push ecx
// 008e6340  50                   push eax
// 008e6341  52                   push edx
// 008e6342  89442464             mov dword ptr [esp + 0x64], eax
// 008e6346  ffd6                 call esi
// 008e6348  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008e634c  8b5704               mov edx, dword ptr [edi + 4]
// 008e634f  6a00                 push 0
// 008e6351  8d4319               lea eax, [ebx + 0x19]
// 008e6354  51                   push ecx
// 008e6355  50                   push eax
// 008e6356  52                   push edx
// 008e6357  898424a8000000       mov dword ptr [esp + 0xa8], eax
// 008e635e  ffd6                 call esi
// 008e6360  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008e6364  8b5704               mov edx, dword ptr [edi + 4]
// 008e6367  6a00                 push 0
// 008e6369  8d431a               lea eax, [ebx + 0x1a]
// 008e636c  51                   push ecx
// 008e636d  50                   push eax
// 008e636e  52                   push edx
// 008e636f  89842498000000       mov dword ptr [esp + 0x98], eax
// 008e6376  ffd6                 call esi
// 008e6378  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 008e637c  8b5704               mov edx, dword ptr [edi + 4]
// 008e637f  6a00                 push 0
// 008e6381  8d431b               lea eax, [ebx + 0x1b]
// 008e6384  51                   push ecx
// 008e6385  50                   push eax
// 008e6386  52                   push edx
// 008e6387  898424ac000000       mov dword ptr [esp + 0xac], eax
// 008e638e  ffd6                 call esi
// 008e6390  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 008e6394  8b5704               mov edx, dword ptr [edi + 4]
// 008e6397  6a00                 push 0
// 008e6399  8d431c               lea eax, [ebx + 0x1c]
// 008e639c  51                   push ecx
// 008e639d  50                   push eax
// 008e639e  52                   push edx
// 008e639f  898424a0000000       mov dword ptr [esp + 0xa0], eax
// 008e63a6  ffd6                 call esi
// 008e63a8  8d431d               lea eax, [ebx + 0x1d]
// 008e63ab  898424b8000000       mov dword ptr [esp + 0xb8], eax
// 008e63b2  6a00                 push 0
// 008e63b4  8b8c24b4000000       mov ecx, dword ptr [esp + 0xb4]
// 008e63bb  8b5704               mov edx, dword ptr [edi + 4]
// 008e63be  51                   push ecx
// 008e63bf  50                   push eax
// 008e63c0  52                   push edx
// 008e63c1  ffd6                 call esi
// 008e63c3  8b8c24b0000000       mov ecx, dword ptr [esp + 0xb0]
// 008e63ca  8b5704               mov edx, dword ptr [edi + 4]
// 008e63cd  6a00                 push 0
// 008e63cf  8d431e               lea eax, [ebx + 0x1e]
// 008e63d2  51                   push ecx
// 008e63d3  50                   push eax
// 008e63d4  52                   push edx
// 008e63d5  898424cc000000       mov dword ptr [esp + 0xcc], eax
// 008e63dc  ffd6                 call esi
// 008e63de  6a00                 push 0
// 008e63e0  8d45ff               lea eax, [ebp - 1]
// 008e63e3  50                   push eax
// 008e63e4  8d4b1f               lea ecx, [ebx + 0x1f]
// 008e63e7  8944244c             mov dword ptr [esp + 0x4c], eax
// 008e63eb  8b4704               mov eax, dword ptr [edi + 4]
// 008e63ee  51                   push ecx
// 008e63ef  50                   push eax
// 008e63f0  898c24d0000000       mov dword ptr [esp + 0xd0], ecx
// 008e63f7  ffd6                 call esi
// 008e63f9  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008e6401  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008e6405  8b5704               mov edx, dword ptr [edi + 4]
// 008e6408  6a00                 push 0
// 008e640a  03cd                 add ecx, ebp
// 008e640c  51                   push ecx
// 008e640d  8d4320               lea eax, [ebx + 0x20]
// 008e6410  50                   push eax
// 008e6411  52                   push edx
// 008e6412  ffd6                 call esi
// 008e6414  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e6418  40                   inc eax
// 008e6419  83f811               cmp eax, 0x11
// 008e641c  89442410             mov dword ptr [esp + 0x10], eax
// 008e6420  7cdf                 jl 0x8e6401
// 008e6422  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6425  6a00                 push 0
// 008e6427  8d4511               lea eax, [ebp + 0x11]
// 008e642a  50                   push eax
// 008e642b  8944243c             mov dword ptr [esp + 0x3c], eax
// 008e642f  8b8424c8000000       mov eax, dword ptr [esp + 0xc8]
// 008e6436  50                   push eax
// 008e6437  51                   push ecx
// 008e6438  ffd6                 call esi
// 008e643a  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 008e6441  6a00                 push 0
// 008e6443  8d4512               lea eax, [ebp + 0x12]
// 008e6446  50                   push eax
// 008e6447  8944241c             mov dword ptr [esp + 0x1c], eax
// 008e644b  8b4704               mov eax, dword ptr [edi + 4]
// 008e644e  52                   push edx
// 008e644f  50                   push eax
// 008e6450  ffd6                 call esi
// 008e6452  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008e6456  8b9424b8000000       mov edx, dword ptr [esp + 0xb8]
// 008e645d  8b4704               mov eax, dword ptr [edi + 4]
// 008e6460  6a00                 push 0
// 008e6462  51                   push ecx
// 008e6463  52                   push edx
// 008e6464  50                   push eax
// 008e6465  ffd6                 call esi
// 008e6467  8b8c2490000000       mov ecx, dword ptr [esp + 0x90]
// 008e646e  8b5704               mov edx, dword ptr [edi + 4]
// 008e6471  6a00                 push 0
// 008e6473  8d4513               lea eax, [ebp + 0x13]
// 008e6476  50                   push eax
// 008e6477  51                   push ecx
// 008e6478  52                   push edx
// 008e6479  8944242c             mov dword ptr [esp + 0x2c], eax
// 008e647d  ffd6                 call esi
// 008e647f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008e6483  8b8c249c000000       mov ecx, dword ptr [esp + 0x9c]
// 008e648a  8b5704               mov edx, dword ptr [edi + 4]
// 008e648d  6a00                 push 0
// 008e648f  50                   push eax
// 008e6490  51                   push ecx
// 008e6491  52                   push edx
// 008e6492  ffd6                 call esi
// 008e6494  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6497  6a00                 push 0
// 008e6499  8d4514               lea eax, [ebp + 0x14]
// 008e649c  50                   push eax
// 008e649d  89442420             mov dword ptr [esp + 0x20], eax
// 008e64a1  8b842490000000       mov eax, dword ptr [esp + 0x90]
// 008e64a8  50                   push eax
// 008e64a9  51                   push ecx
// 008e64aa  ffd6                 call esi
// 008e64ac  8b542418             mov edx, dword ptr [esp + 0x18]
// 008e64b0  8b842498000000       mov eax, dword ptr [esp + 0x98]
// 008e64b7  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e64ba  6a00                 push 0
// 008e64bc  52                   push edx
// 008e64bd  50                   push eax
// 008e64be  51                   push ecx
// 008e64bf  ffd6                 call esi
// 008e64c1  8b542454             mov edx, dword ptr [esp + 0x54]
// 008e64c5  6a00                 push 0
// 008e64c7  8d4515               lea eax, [ebp + 0x15]
// 008e64ca  50                   push eax
// 008e64cb  89442438             mov dword ptr [esp + 0x38], eax
// 008e64cf  8b4704               mov eax, dword ptr [edi + 4]
// 008e64d2  52                   push edx
// 008e64d3  50                   push eax
// 008e64d4  ffd6                 call esi
// 008e64d6  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 008e64da  8b542464             mov edx, dword ptr [esp + 0x64]
// 008e64de  8b4704               mov eax, dword ptr [edi + 4]
// 008e64e1  6a00                 push 0
// 008e64e3  51                   push ecx
// 008e64e4  52                   push edx
// 008e64e5  50                   push eax
// 008e64e6  ffd6                 call esi
// 008e64e8  8d4516               lea eax, [ebp + 0x16]
// 008e64eb  6a00                 push 0
// 008e64ed  89442450             mov dword ptr [esp + 0x50], eax
// 008e64f1  50                   push eax
// 008e64f2  8b8c24ac000000       mov ecx, dword ptr [esp + 0xac]
// 008e64f9  8b5704               mov edx, dword ptr [edi + 4]
// 008e64fc  51                   push ecx
// 008e64fd  52                   push edx
// 008e64fe  ffd6                 call esi
// 008e6500  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 008e6504  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 008e6508  8b5704               mov edx, dword ptr [edi + 4]
// 008e650b  6a00                 push 0
// 008e650d  50                   push eax
// 008e650e  51                   push ecx
// 008e650f  52                   push edx
// 008e6510  ffd6                 call esi
// 008e6512  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6515  6a00                 push 0
// 008e6517  8d4517               lea eax, [ebp + 0x17]
// 008e651a  50                   push eax
// 008e651b  89442434             mov dword ptr [esp + 0x34], eax
// 008e651f  8b442464             mov eax, dword ptr [esp + 0x64]
// 008e6523  50                   push eax
// 008e6524  51                   push ecx
// 008e6525  ffd6                 call esi
// 008e6527  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 008e652b  8b442474             mov eax, dword ptr [esp + 0x74]
// 008e652f  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6532  6a00                 push 0
// 008e6534  52                   push edx
// 008e6535  50                   push eax
// 008e6536  51                   push ecx
// 008e6537  ffd6                 call esi
// 008e6539  8b9424ac000000       mov edx, dword ptr [esp + 0xac]
// 008e6540  6a00                 push 0
// 008e6542  8d4518               lea eax, [ebp + 0x18]
// 008e6545  50                   push eax
// 008e6546  8b4704               mov eax, dword ptr [edi + 4]
// 008e6549  52                   push edx
// 008e654a  50                   push eax
// 008e654b  ffd6                 call esi
// 008e654d  8b4c247c             mov ecx, dword ptr [esp + 0x7c]
// 008e6551  8b5704               mov edx, dword ptr [edi + 4]
// 008e6554  6a00                 push 0
// 008e6556  8d4518               lea eax, [ebp + 0x18]
// 008e6559  50                   push eax
// 008e655a  51                   push ecx
// 008e655b  52                   push edx
// 008e655c  ffd6                 call esi
// 008e655e  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6561  6a00                 push 0
// 008e6563  8d4518               lea eax, [ebp + 0x18]
// 008e6566  50                   push eax
// 008e6567  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 008e656e  50                   push eax
// 008e656f  51                   push ecx
// 008e6570  ffd6                 call esi
// 008e6572  8b942484000000       mov edx, dword ptr [esp + 0x84]
// 008e6579  6a00                 push 0
// 008e657b  8d4518               lea eax, [ebp + 0x18]
// 008e657e  50                   push eax
// 008e657f  8b4704               mov eax, dword ptr [edi + 4]
// 008e6582  52                   push edx
// 008e6583  50                   push eax
// 008e6584  ffd6                 call esi
// 008e6586  8b8c24a8000000       mov ecx, dword ptr [esp + 0xa8]
// 008e658d  8b5704               mov edx, dword ptr [edi + 4]
// 008e6590  6a00                 push 0
// 008e6592  8d4518               lea eax, [ebp + 0x18]
// 008e6595  50                   push eax
// 008e6596  51                   push ecx
// 008e6597  52                   push edx
// 008e6598  ffd6                 call esi
// 008e659a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 008e659e  8b8c248c000000       mov ecx, dword ptr [esp + 0x8c]
// 008e65a5  8b5704               mov edx, dword ptr [edi + 4]
// 008e65a8  6a00                 push 0
// 008e65aa  50                   push eax
// 008e65ab  51                   push ecx
// 008e65ac  52                   push edx
// 008e65ad  ffd6                 call esi
// 008e65af  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 008e65b3  6a00                 push 0
// 008e65b5  50                   push eax
// 008e65b6  8b8c24a8000000       mov ecx, dword ptr [esp + 0xa8]
// 008e65bd  8b5704               mov edx, dword ptr [edi + 4]
// 008e65c0  51                   push ecx
// 008e65c1  52                   push edx
// 008e65c2  ffd6                 call esi
// 008e65c4  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 008e65c8  8b8c2494000000       mov ecx, dword ptr [esp + 0x94]
// 008e65cf  8b5704               mov edx, dword ptr [edi + 4]
// 008e65d2  6a00                 push 0
// 008e65d4  50                   push eax
// 008e65d5  51                   push ecx
// 008e65d6  52                   push edx
// 008e65d7  ffd6                 call esi
// 008e65d9  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 008e65dd  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 008e65e1  8b5704               mov edx, dword ptr [edi + 4]
// 008e65e4  6a00                 push 0
// 008e65e6  50                   push eax
// 008e65e7  51                   push ecx
// 008e65e8  52                   push edx
// 008e65e9  ffd6                 call esi
// 008e65eb  8b442430             mov eax, dword ptr [esp + 0x30]
// 008e65ef  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 008e65f3  8b5704               mov edx, dword ptr [edi + 4]
// 008e65f6  6a00                 push 0
// 008e65f8  50                   push eax
// 008e65f9  51                   push ecx
// 008e65fa  52                   push edx
// 008e65fb  ffd6                 call esi
// 008e65fd  8b442430             mov eax, dword ptr [esp + 0x30]
// 008e6601  8b4c2470             mov ecx, dword ptr [esp + 0x70]
// 008e6605  8b5704               mov edx, dword ptr [edi + 4]
// 008e6608  6a00                 push 0
// 008e660a  50                   push eax
// 008e660b  51                   push ecx
// 008e660c  52                   push edx
// 008e660d  ffd6                 call esi
// 008e660f  8b442418             mov eax, dword ptr [esp + 0x18]
// 008e6613  8b4c2478             mov ecx, dword ptr [esp + 0x78]
// 008e6617  8b5704               mov edx, dword ptr [edi + 4]
// 008e661a  6a00                 push 0
// 008e661c  50                   push eax
// 008e661d  51                   push ecx
// 008e661e  52                   push edx
// 008e661f  ffd6                 call esi
// 008e6621  8b442418             mov eax, dword ptr [esp + 0x18]
// 008e6625  8b8c2480000000       mov ecx, dword ptr [esp + 0x80]
// 008e662c  8b5704               mov edx, dword ptr [edi + 4]
// 008e662f  6a00                 push 0
// 008e6631  50                   push eax
// 008e6632  51                   push ecx
// 008e6633  52                   push edx
// 008e6634  ffd6                 call esi
// 008e6636  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008e663a  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 008e663e  8b5704               mov edx, dword ptr [edi + 4]
// 008e6641  6a00                 push 0
// 008e6643  50                   push eax
// 008e6644  51                   push ecx
// 008e6645  52                   push edx
// 008e6646  ffd6                 call esi
// 008e6648  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008e664c  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 008e6650  8b5704               mov edx, dword ptr [edi + 4]
// 008e6653  6a00                 push 0
// 008e6655  50                   push eax
// 008e6656  51                   push ecx
// 008e6657  52                   push edx
// 008e6658  ffd6                 call esi
// 008e665a  8b442414             mov eax, dword ptr [esp + 0x14]
// 008e665e  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 008e6662  8b5704               mov edx, dword ptr [edi + 4]
// 008e6665  6a00                 push 0
// 008e6667  50                   push eax
// 008e6668  51                   push ecx
// 008e6669  52                   push edx
// 008e666a  ffd6                 call esi
// 008e666c  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008e6670  8d4302               lea eax, [ebx + 2]
// 008e6673  898424c8000000       mov dword ptr [esp + 0xc8], eax
// 008e667a  6a00                 push 0
// 008e667c  8b5704               mov edx, dword ptr [edi + 4]
// 008e667f  51                   push ecx
// 008e6680  50                   push eax
// 008e6681  52                   push edx
// 008e6682  ffd6                 call esi
// 008e6684  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 008e6688  8b5704               mov edx, dword ptr [edi + 4]
// 008e668b  6a00                 push 0
// 008e668d  8d4301               lea eax, [ebx + 1]
// 008e6690  51                   push ecx
// 008e6691  50                   push eax
// 008e6692  52                   push edx
// 008e6693  898424d4000000       mov dword ptr [esp + 0xd4], eax
// 008e669a  ffd6                 call esi
// 008e669c  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008e66a4  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e66a8  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e66ab  6a00                 push 0
// 008e66ad  03c5                 add eax, ebp
// 008e66af  50                   push eax
// 008e66b0  53                   push ebx
// 008e66b1  51                   push ecx
// 008e66b2  ffd6                 call esi
// 008e66b4  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e66b8  40                   inc eax
// 008e66b9  83f811               cmp eax, 0x11
// 008e66bc  89442410             mov dword ptr [esp + 0x10], eax
// 008e66c0  7ce2                 jl 0x8e66a4
// 008e66c2  33db                 xor ebx, ebx
// 008e66c4  8b442450             mov eax, dword ptr [esp + 0x50]
// 008e66c8  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e66cb  6a00                 push 0
// 008e66cd  8d542b01             lea edx, [ebx + ebp + 1]
// 008e66d1  52                   push edx
// 008e66d2  50                   push eax
// 008e66d3  51                   push ecx
// 008e66d4  ffd6                 call esi
// 008e66d6  43                   inc ebx
// 008e66d7  83fb0f               cmp ebx, 0xf
// 008e66da  7ce8                 jl 0x8e66c4
// 008e66dc  8b542438             mov edx, dword ptr [esp + 0x38]
// 008e66e0  8b4704               mov eax, dword ptr [edi + 4]
// 008e66e3  6a00                 push 0
// 008e66e5  8d5d10               lea ebx, [ebp + 0x10]
// 008e66e8  53                   push ebx
// 008e66e9  52                   push edx
// 008e66ea  50                   push eax
// 008e66eb  895c2450             mov dword ptr [esp + 0x50], ebx
// 008e66ef  ffd6                 call esi
// 008e66f1  8b8c2480000000       mov ecx, dword ptr [esp + 0x80]
// 008e66f8  8b5704               mov edx, dword ptr [edi + 4]
// 008e66fb  6a00                 push 0
// 008e66fd  53                   push ebx
// 008e66fe  51                   push ecx
// 008e66ff  52                   push edx
// 008e6700  ffd6                 call esi
// 008e6702  8b442434             mov eax, dword ptr [esp + 0x34]
// 008e6706  8b4c2478             mov ecx, dword ptr [esp + 0x78]
// 008e670a  8b5704               mov edx, dword ptr [edi + 4]
// 008e670d  6a00                 push 0
// 008e670f  50                   push eax
// 008e6710  51                   push ecx
// 008e6711  52                   push edx
// 008e6712  ffd6                 call esi
// 008e6714  8b442434             mov eax, dword ptr [esp + 0x34]
// 008e6718  8b4c2470             mov ecx, dword ptr [esp + 0x70]
// 008e671c  8b5704               mov edx, dword ptr [edi + 4]
// 008e671f  6a00                 push 0
// 008e6721  50                   push eax
// 008e6722  51                   push ecx
// 008e6723  52                   push edx
// 008e6724  ffd6                 call esi
// 008e6726  8b442414             mov eax, dword ptr [esp + 0x14]
// 008e672a  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 008e672e  8b5704               mov edx, dword ptr [edi + 4]
// 008e6731  6a00                 push 0
// 008e6733  50                   push eax
// 008e6734  51                   push ecx
// 008e6735  52                   push edx
// 008e6736  ffd6                 call esi
// 008e6738  8b442414             mov eax, dword ptr [esp + 0x14]
// 008e673c  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 008e6740  8b5704               mov edx, dword ptr [edi + 4]
// 008e6743  6a00                 push 0
// 008e6745  50                   push eax
// 008e6746  51                   push ecx
// 008e6747  52                   push edx
// 008e6748  ffd6                 call esi
// 008e674a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008e674e  8b8c2494000000       mov ecx, dword ptr [esp + 0x94]
// 008e6755  8b5704               mov edx, dword ptr [edi + 4]
// 008e6758  6a00                 push 0
// 008e675a  50                   push eax
// 008e675b  51                   push ecx
// 008e675c  52                   push edx
// 008e675d  ffd6                 call esi
// 008e675f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008e6763  8b8c24a0000000       mov ecx, dword ptr [esp + 0xa0]
// 008e676a  8b5704               mov edx, dword ptr [edi + 4]
// 008e676d  6a00                 push 0
// 008e676f  50                   push eax
// 008e6770  51                   push ecx
// 008e6771  52                   push edx
// 008e6772  ffd6                 call esi
// 008e6774  8b442418             mov eax, dword ptr [esp + 0x18]
// 008e6778  8b8c248c000000       mov ecx, dword ptr [esp + 0x8c]
// 008e677f  8b5704               mov edx, dword ptr [edi + 4]
// 008e6782  6a00                 push 0
// 008e6784  50                   push eax
// 008e6785  51                   push ecx
// 008e6786  52                   push edx
// 008e6787  ffd6                 call esi
// 008e6789  8b442418             mov eax, dword ptr [esp + 0x18]
// 008e678d  8b8c24a8000000       mov ecx, dword ptr [esp + 0xa8]
// 008e6794  8b5704               mov edx, dword ptr [edi + 4]
// 008e6797  6a00                 push 0
// 008e6799  50                   push eax
// 008e679a  51                   push ecx
// 008e679b  52                   push edx
// 008e679c  ffd6                 call esi
// 008e679e  6a00                 push 0
// 008e67a0  8b442434             mov eax, dword ptr [esp + 0x34]
// 008e67a4  8b8c2488000000       mov ecx, dword ptr [esp + 0x88]
// 008e67ab  8b5704               mov edx, dword ptr [edi + 4]
// 008e67ae  50                   push eax
// 008e67af  51                   push ecx
// 008e67b0  52                   push edx
// 008e67b1  ffd6                 call esi
// 008e67b3  8b442430             mov eax, dword ptr [esp + 0x30]
// 008e67b7  8b8c24b4000000       mov ecx, dword ptr [esp + 0xb4]
// 008e67be  8b5704               mov edx, dword ptr [edi + 4]
// 008e67c1  6a00                 push 0
// 008e67c3  50                   push eax
// 008e67c4  51                   push ecx
// 008e67c5  52                   push edx
// 008e67c6  ffd6                 call esi
// 008e67c8  8b442430             mov eax, dword ptr [esp + 0x30]
// 008e67cc  8b4c247c             mov ecx, dword ptr [esp + 0x7c]
// 008e67d0  8b5704               mov edx, dword ptr [edi + 4]
// 008e67d3  6a00                 push 0
// 008e67d5  50                   push eax
// 008e67d6  51                   push ecx
// 008e67d7  52                   push edx
// 008e67d8  ffd6                 call esi
// 008e67da  8b442418             mov eax, dword ptr [esp + 0x18]
// 008e67de  8b8c24ac000000       mov ecx, dword ptr [esp + 0xac]
// 008e67e5  8b5704               mov edx, dword ptr [edi + 4]
// 008e67e8  6a00                 push 0
// 008e67ea  50                   push eax
// 008e67eb  51                   push ecx
// 008e67ec  52                   push edx
// 008e67ed  ffd6                 call esi
// 008e67ef  8b442418             mov eax, dword ptr [esp + 0x18]
// 008e67f3  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 008e67f7  8b5704               mov edx, dword ptr [edi + 4]
// 008e67fa  6a00                 push 0
// 008e67fc  50                   push eax
// 008e67fd  51                   push ecx
// 008e67fe  52                   push edx
// 008e67ff  ffd6                 call esi
// 008e6801  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008e6805  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 008e6809  8b5704               mov edx, dword ptr [edi + 4]
// 008e680c  6a00                 push 0
// 008e680e  50                   push eax
// 008e680f  51                   push ecx
// 008e6810  52                   push edx
// 008e6811  ffd6                 call esi
// 008e6813  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008e6817  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 008e681b  8b5704               mov edx, dword ptr [edi + 4]
// 008e681e  6a00                 push 0
// 008e6820  50                   push eax
// 008e6821  51                   push ecx
// 008e6822  52                   push edx
// 008e6823  ffd6                 call esi
// 008e6825  8b442414             mov eax, dword ptr [esp + 0x14]
// 008e6829  8b8c24a4000000       mov ecx, dword ptr [esp + 0xa4]
// 008e6830  8b5704               mov edx, dword ptr [edi + 4]
// 008e6833  6a00                 push 0
// 008e6835  50                   push eax
// 008e6836  51                   push ecx
// 008e6837  52                   push edx
// 008e6838  ffd6                 call esi
// 008e683a  8b442414             mov eax, dword ptr [esp + 0x14]
// 008e683e  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 008e6842  8b5704               mov edx, dword ptr [edi + 4]
// 008e6845  6a00                 push 0
// 008e6847  50                   push eax
// 008e6848  51                   push ecx
// 008e6849  52                   push edx
// 008e684a  ffd6                 call esi
// 008e684c  8b442434             mov eax, dword ptr [esp + 0x34]
// 008e6850  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 008e6854  8b5704               mov edx, dword ptr [edi + 4]
// 008e6857  6a00                 push 0
// 008e6859  50                   push eax
// 008e685a  51                   push ecx
// 008e685b  52                   push edx
// 008e685c  ffd6                 call esi
// 008e685e  8b442434             mov eax, dword ptr [esp + 0x34]
// 008e6862  6a00                 push 0
// 008e6864  8b8c249c000000       mov ecx, dword ptr [esp + 0x9c]
// 008e686b  8b5704               mov edx, dword ptr [edi + 4]
// 008e686e  50                   push eax
// 008e686f  51                   push ecx
// 008e6870  52                   push edx
// 008e6871  ffd6                 call esi
// 008e6873  8b842488000000       mov eax, dword ptr [esp + 0x88]
// 008e687a  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e687d  6a00                 push 0
// 008e687f  53                   push ebx
// 008e6880  50                   push eax
// 008e6881  51                   push ecx
// 008e6882  ffd6                 call esi
// 008e6884  8b94249c000000       mov edx, dword ptr [esp + 0x9c]
// 008e688b  8b4704               mov eax, dword ptr [edi + 4]
// 008e688e  6a00                 push 0
// 008e6890  53                   push ebx
// 008e6891  52                   push edx
// 008e6892  50                   push eax
// 008e6893  ffd6                 call esi
// 008e6895  33db                 xor ebx, ebx
// 008e6897  eb07                 jmp 0x8e68a0
// 008e6899  8da42400000000       lea esp, [esp]
// 008e68a0  8b942490000000       mov edx, dword ptr [esp + 0x90]
// 008e68a7  8b4704               mov eax, dword ptr [edi + 4]
// 008e68aa  6a00                 push 0
// 008e68ac  8d4c2b01             lea ecx, [ebx + ebp + 1]
// 008e68b0  51                   push ecx
// 008e68b1  52                   push edx
// 008e68b2  50                   push eax
// 008e68b3  ffd6                 call esi
// 008e68b5  43                   inc ebx
// 008e68b6  83fb0f               cmp ebx, 0xf
// 008e68b9  7ce5                 jl 0x8e68a0
// 008e68bb  8b8c249c000000       mov ecx, dword ptr [esp + 0x9c]
// 008e68c2  8b5704               mov edx, dword ptr [edi + 4]
// 008e68c5  6a00                 push 0
// 008e68c7  55                   push ebp
// 008e68c8  51                   push ecx
// 008e68c9  52                   push edx
// 008e68ca  ffd6                 call esi
// 008e68cc  8b842488000000       mov eax, dword ptr [esp + 0x88]
// 008e68d3  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e68d6  6a00                 push 0
// 008e68d8  55                   push ebp
// 008e68d9  50                   push eax
// 008e68da  51                   push ecx
// 008e68db  ffd6                 call esi
// 008e68dd  8b5c2444             mov ebx, dword ptr [esp + 0x44]
// 008e68e1  8b942498000000       mov edx, dword ptr [esp + 0x98]
// 008e68e8  8b4704               mov eax, dword ptr [edi + 4]
// 008e68eb  6a00                 push 0
// 008e68ed  53                   push ebx
// 008e68ee  52                   push edx
// 008e68ef  50                   push eax
// 008e68f0  ffd6                 call esi
// 008e68f2  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 008e68f6  8b5704               mov edx, dword ptr [edi + 4]
// 008e68f9  6a00                 push 0
// 008e68fb  53                   push ebx
// 008e68fc  51                   push ecx
// 008e68fd  52                   push edx
// 008e68fe  ffd6                 call esi
// 008e6900  8b9c24b0000000       mov ebx, dword ptr [esp + 0xb0]
// 008e6907  8b442464             mov eax, dword ptr [esp + 0x64]
// 008e690b  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e690e  6a00                 push 0
// 008e6910  53                   push ebx
// 008e6911  50                   push eax
// 008e6912  51                   push ecx
// 008e6913  ffd6                 call esi
// 008e6915  8b9424a4000000       mov edx, dword ptr [esp + 0xa4]
// 008e691c  8b4704               mov eax, dword ptr [edi + 4]
// 008e691f  6a00                 push 0
// 008e6921  53                   push ebx
// 008e6922  52                   push edx
// 008e6923  50                   push eax
// 008e6924  ffd6                 call esi
// 008e6926  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 008e692a  8b54246c             mov edx, dword ptr [esp + 0x6c]
// 008e692e  8b4704               mov eax, dword ptr [edi + 4]
// 008e6931  6a00                 push 0
// 008e6933  51                   push ecx
// 008e6934  52                   push edx
// 008e6935  50                   push eax
// 008e6936  ffd6                 call esi
// 008e6938  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 008e693c  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 008e6940  8b4704               mov eax, dword ptr [edi + 4]
// 008e6943  6a00                 push 0
// 008e6945  51                   push ecx
// 008e6946  52                   push edx
// 008e6947  50                   push eax
// 008e6948  ffd6                 call esi
// 008e694a  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008e694e  8b542474             mov edx, dword ptr [esp + 0x74]
// 008e6952  8b4704               mov eax, dword ptr [edi + 4]
// 008e6955  6a00                 push 0
// 008e6957  51                   push ecx
// 008e6958  52                   push edx
// 008e6959  50                   push eax
// 008e695a  ffd6                 call esi
// 008e695c  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008e6960  8b9424ac000000       mov edx, dword ptr [esp + 0xac]
// 008e6967  8b4704               mov eax, dword ptr [edi + 4]
// 008e696a  6a00                 push 0
// 008e696c  51                   push ecx
// 008e696d  52                   push edx
// 008e696e  50                   push eax
// 008e696f  ffd6                 call esi
// 008e6971  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008e6975  8b54247c             mov edx, dword ptr [esp + 0x7c]
// 008e6979  6a00                 push 0
// 008e697b  51                   push ecx
// 008e697c  52                   push edx
// 008e697d  8b4704               mov eax, dword ptr [edi + 4]
// 008e6980  50                   push eax
// 008e6981  ffd6                 call esi
// 008e6983  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008e6987  8b9424b4000000       mov edx, dword ptr [esp + 0xb4]
// 008e698e  8b4704               mov eax, dword ptr [edi + 4]
// 008e6991  6a00                 push 0
// 008e6993  51                   push ecx
// 008e6994  52                   push edx
// 008e6995  50                   push eax
// 008e6996  ffd6                 call esi
// 008e6998  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008e699c  8b942484000000       mov edx, dword ptr [esp + 0x84]
// 008e69a3  8b4704               mov eax, dword ptr [edi + 4]
// 008e69a6  6a00                 push 0
// 008e69a8  51                   push ecx
// 008e69a9  52                   push edx
// 008e69aa  50                   push eax
// 008e69ab  ffd6                 call esi
// 008e69ad  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008e69b1  8b9424a8000000       mov edx, dword ptr [esp + 0xa8]
// 008e69b8  8b4704               mov eax, dword ptr [edi + 4]
// 008e69bb  6a00                 push 0
// 008e69bd  51                   push ecx
// 008e69be  52                   push edx
// 008e69bf  50                   push eax
// 008e69c0  ffd6                 call esi
// 008e69c2  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008e69c6  8b94248c000000       mov edx, dword ptr [esp + 0x8c]
// 008e69cd  8b4704               mov eax, dword ptr [edi + 4]
// 008e69d0  6a00                 push 0
// 008e69d2  51                   push ecx
// 008e69d3  52                   push edx
// 008e69d4  50                   push eax
// 008e69d5  ffd6                 call esi
// 008e69d7  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 008e69db  8b9424a0000000       mov edx, dword ptr [esp + 0xa0]
// 008e69e2  8b4704               mov eax, dword ptr [edi + 4]
// 008e69e5  6a00                 push 0
// 008e69e7  51                   push ecx
// 008e69e8  52                   push edx
// 008e69e9  50                   push eax
// 008e69ea  ffd6                 call esi
// 008e69ec  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 008e69f0  8b942494000000       mov edx, dword ptr [esp + 0x94]
// 008e69f7  8b4704               mov eax, dword ptr [edi + 4]
// 008e69fa  6a00                 push 0
// 008e69fc  51                   push ecx
// 008e69fd  52                   push edx
// 008e69fe  50                   push eax
// 008e69ff  ffd6                 call esi
// 008e6a01  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 008e6a05  8b5704               mov edx, dword ptr [edi + 4]
// 008e6a08  6a00                 push 0
// 008e6a0a  53                   push ebx
// 008e6a0b  51                   push ecx
// 008e6a0c  52                   push edx
// 008e6a0d  ffd6                 call esi
// 008e6a0f  8b442468             mov eax, dword ptr [esp + 0x68]
// 008e6a13  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6a16  6a00                 push 0
// 008e6a18  53                   push ebx
// 008e6a19  50                   push eax
// 008e6a1a  51                   push ecx
// 008e6a1b  ffd6                 call esi
// 008e6a1d  8b542444             mov edx, dword ptr [esp + 0x44]
// 008e6a21  8b442470             mov eax, dword ptr [esp + 0x70]
// 008e6a25  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6a28  6a00                 push 0
// 008e6a2a  52                   push edx
// 008e6a2b  50                   push eax
// 008e6a2c  51                   push ecx
// 008e6a2d  ffd6                 call esi
// 008e6a2f  8b542444             mov edx, dword ptr [esp + 0x44]
// 008e6a33  8b442478             mov eax, dword ptr [esp + 0x78]
// 008e6a37  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6a3a  6a00                 push 0
// 008e6a3c  52                   push edx
// 008e6a3d  50                   push eax
// 008e6a3e  51                   push ecx
// 008e6a3f  ffd6                 call esi
// 008e6a41  8b942480000000       mov edx, dword ptr [esp + 0x80]
// 008e6a48  8b4704               mov eax, dword ptr [edi + 4]
// 008e6a4b  6a00                 push 0
// 008e6a4d  55                   push ebp
// 008e6a4e  52                   push edx
// 008e6a4f  50                   push eax
// 008e6a50  ffd6                 call esi
// 008e6a52  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 008e6a56  8b5704               mov edx, dword ptr [edi + 4]
// 008e6a59  6a00                 push 0
// 008e6a5b  55                   push ebp
// 008e6a5c  51                   push ecx
// 008e6a5d  52                   push edx
// 008e6a5e  ffd6                 call esi
// 008e6a60  896c2410             mov dword ptr [esp + 0x10], ebp
// 008e6a64  c744243811000000     mov dword ptr [esp + 0x38], 0x11
// 008e6a6c  8d642400             lea esp, [esp]
// 008e6a70  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e6a74  8b8c24c4000000       mov ecx, dword ptr [esp + 0xc4]
// 008e6a7b  8b5704               mov edx, dword ptr [edi + 4]
// 008e6a7e  68ffffff00           push 0xffffff
// 008e6a83  50                   push eax
// 008e6a84  51                   push ecx
// 008e6a85  52                   push edx
// 008e6a86  ffd6                 call esi
// 008e6a88  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e6a8c  8b8c24c8000000       mov ecx, dword ptr [esp + 0xc8]
// 008e6a93  8b5704               mov edx, dword ptr [edi + 4]
// 008e6a96  68ffffff00           push 0xffffff
// 008e6a9b  50                   push eax
// 008e6a9c  51                   push ecx
// 008e6a9d  52                   push edx
// 008e6a9e  ffd6                 call esi
// 008e6aa0  8b442410             mov eax, dword ptr [esp + 0x10]
// 008e6aa4  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 008e6aa8  8b5704               mov edx, dword ptr [edi + 4]
// 008e6aab  68ffffff00           push 0xffffff
// 008e6ab0  50                   push eax
// 008e6ab1  51                   push ecx
// 008e6ab2  52                   push edx
// 008e6ab3  ffd6                 call esi
// 008e6ab5  b801000000           mov eax, 1
// 008e6aba  01442410             add dword ptr [esp + 0x10], eax
// 008e6abe  29442438             sub dword ptr [esp + 0x38], eax
// 008e6ac2  75ac                 jne 0x8e6a70
// 008e6ac4  8b442450             mov eax, dword ptr [esp + 0x50]
// 008e6ac8  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6acb  68ffffff00           push 0xffffff
// 008e6ad0  55                   push ebp
// 008e6ad1  50                   push eax
// 008e6ad2  51                   push ecx
// 008e6ad3  ffd6                 call esi
// 008e6ad5  8b542440             mov edx, dword ptr [esp + 0x40]
// 008e6ad9  8b442450             mov eax, dword ptr [esp + 0x50]
// 008e6add  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6ae0  68ffffff00           push 0xffffff
// 008e6ae5  52                   push edx
// 008e6ae6  50                   push eax
// 008e6ae7  51                   push ecx
// 008e6ae8  ffd6                 call esi
// 008e6aea  896c2410             mov dword ptr [esp + 0x10], ebp
// 008e6aee  c744244811000000     mov dword ptr [esp + 0x48], 0x11
// 008e6af6  eb08                 jmp 0x8e6b00
// 008e6af8  8da42400000000       lea esp, [esp]
// 008e6aff  90                   nop 
// 008e6b00  8b542410             mov edx, dword ptr [esp + 0x10]
// 008e6b04  8b8424b8000000       mov eax, dword ptr [esp + 0xb8]
// 008e6b0b  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6b0e  68ffffff00           push 0xffffff
// 008e6b13  52                   push edx
// 008e6b14  50                   push eax
// 008e6b15  51                   push ecx
// 008e6b16  ffd6                 call esi
// 008e6b18  8b542410             mov edx, dword ptr [esp + 0x10]
// 008e6b1c  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 008e6b23  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6b26  68ffffff00           push 0xffffff
// 008e6b2b  52                   push edx
// 008e6b2c  50                   push eax
// 008e6b2d  51                   push ecx
// 008e6b2e  ffd6                 call esi
// 008e6b30  8b542410             mov edx, dword ptr [esp + 0x10]
// 008e6b34  8b8424c0000000       mov eax, dword ptr [esp + 0xc0]
// 008e6b3b  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6b3e  68ffffff00           push 0xffffff
// 008e6b43  52                   push edx
// 008e6b44  50                   push eax
// 008e6b45  51                   push ecx
// 008e6b46  ffd6                 call esi
// 008e6b48  b801000000           mov eax, 1
// 008e6b4d  01442410             add dword ptr [esp + 0x10], eax
// 008e6b51  29442448             sub dword ptr [esp + 0x48], eax
// 008e6b55  75a9                 jne 0x8e6b00
// 008e6b57  8b5704               mov edx, dword ptr [edi + 4]
// 008e6b5a  68ffffff00           push 0xffffff
// 008e6b5f  55                   push ebp
// 008e6b60  8bac2498000000       mov ebp, dword ptr [esp + 0x98]
// 008e6b67  55                   push ebp
// 008e6b68  52                   push edx
// 008e6b69  ffd6                 call esi
// 008e6b6b  8b442440             mov eax, dword ptr [esp + 0x40]
// 008e6b6f  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6b72  68ffffff00           push 0xffffff
// 008e6b77  50                   push eax
// 008e6b78  55                   push ebp
// 008e6b79  51                   push ecx
// 008e6b7a  ffd6                 call esi
// 008e6b7c  8b6c2454             mov ebp, dword ptr [esp + 0x54]
// 008e6b80  c744244005000000     mov dword ptr [esp + 0x40], 5
// 008e6b88  eb06                 jmp 0x8e6b90
// 008e6b8a  8d9b00000000         lea ebx, [ebx]
// 008e6b90  8b542444             mov edx, dword ptr [esp + 0x44]
// 008e6b94  68ffffff00           push 0xffffff
// 008e6b99  52                   push edx
// 008e6b9a  8d45ea               lea eax, [ebp - 0x16]
// 008e6b9d  50                   push eax
// 008e6b9e  8b4704               mov eax, dword ptr [edi + 4]
// 008e6ba1  50                   push eax
// 008e6ba2  ffd6                 call esi
// 008e6ba4  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6ba7  68ffffff00           push 0xffffff
// 008e6bac  53                   push ebx
// 008e6bad  8d45ec               lea eax, [ebp - 0x14]
// 008e6bb0  50                   push eax
// 008e6bb1  51                   push ecx
// 008e6bb2  ffd6                 call esi
// 008e6bb4  8b542424             mov edx, dword ptr [esp + 0x24]
// 008e6bb8  68ffffff00           push 0xffffff
// 008e6bbd  52                   push edx
// 008e6bbe  8d45ee               lea eax, [ebp - 0x12]
// 008e6bc1  50                   push eax
// 008e6bc2  8b4704               mov eax, dword ptr [edi + 4]
// 008e6bc5  50                   push eax
// 008e6bc6  ffd6                 call esi
// 008e6bc8  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008e6bcc  8b5704               mov edx, dword ptr [edi + 4]
// 008e6bcf  68ffffff00           push 0xffffff
// 008e6bd4  51                   push ecx
// 008e6bd5  8d45f0               lea eax, [ebp - 0x10]
// 008e6bd8  50                   push eax
// 008e6bd9  52                   push edx
// 008e6bda  ffd6                 call esi
// 008e6bdc  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008e6be0  8b5704               mov edx, dword ptr [edi + 4]
// 008e6be3  68ffffff00           push 0xffffff
// 008e6be8  51                   push ecx
// 008e6be9  8d45f2               lea eax, [ebp - 0xe]
// 008e6bec  50                   push eax
// 008e6bed  52                   push edx
// 008e6bee  ffd6                 call esi
// 008e6bf0  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 008e6bf4  8b5704               mov edx, dword ptr [edi + 4]
// 008e6bf7  68ffffff00           push 0xffffff
// 008e6bfc  51                   push ecx
// 008e6bfd  8d45f4               lea eax, [ebp - 0xc]
// 008e6c00  50                   push eax
// 008e6c01  52                   push edx
// 008e6c02  ffd6                 call esi
// 008e6c04  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 008e6c08  8b5704               mov edx, dword ptr [edi + 4]
// 008e6c0b  68ffffff00           push 0xffffff
// 008e6c10  51                   push ecx
// 008e6c11  8d45f8               lea eax, [ebp - 8]
// 008e6c14  50                   push eax
// 008e6c15  52                   push edx
// 008e6c16  ffd6                 call esi
// 008e6c18  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 008e6c1c  8b5704               mov edx, dword ptr [edi + 4]
// 008e6c1f  68ffffff00           push 0xffffff
// 008e6c24  51                   push ecx
// 008e6c25  8d45f6               lea eax, [ebp - 0xa]
// 008e6c28  50                   push eax
// 008e6c29  52                   push edx
// 008e6c2a  ffd6                 call esi
// 008e6c2c  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008e6c30  8b5704               mov edx, dword ptr [edi + 4]
// 008e6c33  68ffffff00           push 0xffffff
// 008e6c38  51                   push ecx
// 008e6c39  8d45fa               lea eax, [ebp - 6]
// 008e6c3c  50                   push eax
// 008e6c3d  52                   push edx
// 008e6c3e  ffd6                 call esi
// 008e6c40  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008e6c44  8b5704               mov edx, dword ptr [edi + 4]
// 008e6c47  68ffffff00           push 0xffffff
// 008e6c4c  51                   push ecx
// 008e6c4d  8d45fc               lea eax, [ebp - 4]
// 008e6c50  50                   push eax
// 008e6c51  52                   push edx
// 008e6c52  ffd6                 call esi
// 008e6c54  8d45fe               lea eax, [ebp - 2]
// 008e6c57  68ffffff00           push 0xffffff
// 008e6c5c  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008e6c60  8b5704               mov edx, dword ptr [edi + 4]
// 008e6c63  51                   push ecx
// 008e6c64  50                   push eax
// 008e6c65  52                   push edx
// 008e6c66  ffd6                 call esi
// 008e6c68  8b4704               mov eax, dword ptr [edi + 4]
// 008e6c6b  68ffffff00           push 0xffffff
// 008e6c70  53                   push ebx
// 008e6c71  55                   push ebp
// 008e6c72  50                   push eax
// 008e6c73  ffd6                 call esi
// 008e6c75  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 008e6c79  8b5704               mov edx, dword ptr [edi + 4]
// 008e6c7c  68ffffff00           push 0xffffff
// 008e6c81  51                   push ecx
// 008e6c82  8d4502               lea eax, [ebp + 2]
// 008e6c85  50                   push eax
// 008e6c86  52                   push edx
// 008e6c87  ffd6                 call esi
// 008e6c89  8b442434             mov eax, dword ptr [esp + 0x34]
// 008e6c8d  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6c90  68ffffff00           push 0xffffff
// 008e6c95  50                   push eax
// 008e6c96  8d4502               lea eax, [ebp + 2]
// 008e6c99  50                   push eax
// 008e6c9a  51                   push ecx
// 008e6c9b  ffd6                 call esi
// 008e6c9d  8b542414             mov edx, dword ptr [esp + 0x14]
// 008e6ca1  8b4704               mov eax, dword ptr [edi + 4]
// 008e6ca4  68ffffff00           push 0xffffff
// 008e6ca9  52                   push edx
// 008e6caa  55                   push ebp
// 008e6cab  50                   push eax
// 008e6cac  ffd6                 call esi
// 008e6cae  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 008e6cb2  8b5704               mov edx, dword ptr [edi + 4]
// 008e6cb5  68ffffff00           push 0xffffff
// 008e6cba  51                   push ecx
// 008e6cbb  8d45fe               lea eax, [ebp - 2]
// 008e6cbe  50                   push eax
// 008e6cbf  52                   push edx
// 008e6cc0  ffd6                 call esi
// 008e6cc2  8b442418             mov eax, dword ptr [esp + 0x18]
// 008e6cc6  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6cc9  68ffffff00           push 0xffffff
// 008e6cce  50                   push eax
// 008e6ccf  8d45fc               lea eax, [ebp - 4]
// 008e6cd2  50                   push eax
// 008e6cd3  51                   push ecx
// 008e6cd4  ffd6                 call esi
// 008e6cd6  8b542430             mov edx, dword ptr [esp + 0x30]
// 008e6cda  68ffffff00           push 0xffffff
// 008e6cdf  52                   push edx
// 008e6ce0  8d45fa               lea eax, [ebp - 6]
// 008e6ce3  50                   push eax
// 008e6ce4  8b4704               mov eax, dword ptr [edi + 4]
// 008e6ce7  50                   push eax
// 008e6ce8  ffd6                 call esi
// 008e6cea  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 008e6cee  8b5704               mov edx, dword ptr [edi + 4]
// 008e6cf1  68ffffff00           push 0xffffff
// 008e6cf6  51                   push ecx
// 008e6cf7  8d45f6               lea eax, [ebp - 0xa]
// 008e6cfa  50                   push eax
// 008e6cfb  52                   push edx
// 008e6cfc  ffd6                 call esi
// 008e6cfe  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 008e6d02  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6d05  68ffffff00           push 0xffffff
// 008e6d0a  50                   push eax
// 008e6d0b  8d45f8               lea eax, [ebp - 8]
// 008e6d0e  50                   push eax
// 008e6d0f  51                   push ecx
// 008e6d10  ffd6                 call esi
// 008e6d12  8b54244c             mov edx, dword ptr [esp + 0x4c]
// 008e6d16  68ffffff00           push 0xffffff
// 008e6d1b  8d45f4               lea eax, [ebp - 0xc]
// 008e6d1e  52                   push edx
// 008e6d1f  50                   push eax
// 008e6d20  8b4704               mov eax, dword ptr [edi + 4]
// 008e6d23  50                   push eax
// 008e6d24  ffd6                 call esi
// 008e6d26  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 008e6d2a  8b5704               mov edx, dword ptr [edi + 4]
// 008e6d2d  68ffffff00           push 0xffffff
// 008e6d32  51                   push ecx
// 008e6d33  8d45f2               lea eax, [ebp - 0xe]
// 008e6d36  50                   push eax
// 008e6d37  52                   push edx
// 008e6d38  ffd6                 call esi
// 008e6d3a  8b442418             mov eax, dword ptr [esp + 0x18]
// 008e6d3e  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6d41  68ffffff00           push 0xffffff
// 008e6d46  50                   push eax
// 008e6d47  8d45f0               lea eax, [ebp - 0x10]
// 008e6d4a  50                   push eax
// 008e6d4b  51                   push ecx
// 008e6d4c  ffd6                 call esi
// 008e6d4e  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 008e6d52  68ffffff00           push 0xffffff
// 008e6d57  52                   push edx
// 008e6d58  8d45ee               lea eax, [ebp - 0x12]
// 008e6d5b  50                   push eax
// 008e6d5c  8b4704               mov eax, dword ptr [edi + 4]
// 008e6d5f  50                   push eax
// 008e6d60  ffd6                 call esi
// 008e6d62  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008e6d66  8b5704               mov edx, dword ptr [edi + 4]
// 008e6d69  68ffffff00           push 0xffffff
// 008e6d6e  51                   push ecx
// 008e6d6f  8d45ec               lea eax, [ebp - 0x14]
// 008e6d72  50                   push eax
// 008e6d73  52                   push edx
// 008e6d74  ffd6                 call esi
// 008e6d76  8b442434             mov eax, dword ptr [esp + 0x34]
// 008e6d7a  8b4f04               mov ecx, dword ptr [edi + 4]
// 008e6d7d  68ffffff00           push 0xffffff
// 008e6d82  50                   push eax
// 008e6d83  8d45ea               lea eax, [ebp - 0x16]
// 008e6d86  50                   push eax
// 008e6d87  51                   push ecx
// 008e6d88  ffd6                 call esi
// 008e6d8a  45                   inc ebp
// 008e6d8b  836c244001           sub dword ptr [esp + 0x40], 1
// 008e6d90  0f85fafdffff         jne 0x8e6b90
// 008e6d96  5f                   pop edi
// 008e6d97  5e                   pop esi
// 008e6d98  5d                   pop ebp
// 008e6d99  5b                   pop ebx
// 008e6d9a  81c4bc000000         add esp, 0xbc
// 008e6da0  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?DrawLargeSelectCell@CXTColorHex@@IAEXPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp
