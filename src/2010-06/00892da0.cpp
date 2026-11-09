// from server: 100% by auto
// roc 2010-06 00892da0  unit: CXTColorPageCustom  size: 453 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00892da0
//
// 00892da0  83ec10               sub esp, 0x10
// 00892da3  56                   push esi
// 00892da4  57                   push edi
// 00892da5  8bf1                 mov esi, ecx
// 00892da7  e81855f1ff           call 0x7a82c4
// 00892dac  8d8614070000         lea eax, [esi + 0x714]
// 00892db2  85c0                 test eax, eax
// 00892db4  7403                 je 0x892db9
// 00892db6  8b4020               mov eax, dword ptr [eax + 0x20]
// 00892db9  8b3d54ba9e00         mov edi, dword ptr [0x9eba54]
// 00892dbf  6a00                 push 0
// 00892dc1  50                   push eax
// 00892dc2  8b8698030000         mov eax, dword ptr [esi + 0x398]
// 00892dc8  6869040000           push 0x469
// 00892dcd  50                   push eax
// 00892dce  ffd7                 call edi
// 00892dd0  50                   push eax
// 00892dd1  e8944ef1ff           call 0x7a7c6a
// 00892dd6  8b8e98030000         mov ecx, dword ptr [esi + 0x398]
// 00892ddc  68ff000000           push 0xff
// 00892de1  6a00                 push 0
// 00892de3  6865040000           push 0x465
// 00892de8  51                   push ecx
// 00892de9  ffd7                 call edi
// 00892deb  8d866c060000         lea eax, [esi + 0x66c]
// 00892df1  85c0                 test eax, eax
// 00892df3  7403                 je 0x892df8
// 00892df5  8b4020               mov eax, dword ptr [eax + 0x20]
// 00892df8  8b9640040000         mov edx, dword ptr [esi + 0x440]
// 00892dfe  6a00                 push 0
// 00892e00  50                   push eax
// 00892e01  6869040000           push 0x469
// 00892e06  52                   push edx
// 00892e07  ffd7                 call edi
// 00892e09  50                   push eax
// 00892e0a  e85b4ef1ff           call 0x7a7c6a
// 00892e0f  8b8640040000         mov eax, dword ptr [esi + 0x440]
// 00892e15  68ff000000           push 0xff
// 00892e1a  6a00                 push 0
// 00892e1c  6865040000           push 0x465
// 00892e21  50                   push eax
// 00892e22  ffd7                 call edi
// 00892e24  8d8670050000         lea eax, [esi + 0x570]
// 00892e2a  85c0                 test eax, eax
// 00892e2c  7403                 je 0x892e31
// 00892e2e  8b4020               mov eax, dword ptr [eax + 0x20]
// 00892e31  8b8e94040000         mov ecx, dword ptr [esi + 0x494]
// 00892e37  6a00                 push 0
// 00892e39  50                   push eax
// 00892e3a  6869040000           push 0x469
// 00892e3f  51                   push ecx
// 00892e40  ffd7                 call edi
// 00892e42  50                   push eax
// 00892e43  e8224ef1ff           call 0x7a7c6a
// 00892e48  8b9694040000         mov edx, dword ptr [esi + 0x494]
// 00892e4e  68ff000000           push 0xff
// 00892e53  6a00                 push 0
// 00892e55  6865040000           push 0x465
// 00892e5a  52                   push edx
// 00892e5b  ffd7                 call edi
// 00892e5d  8d86c0060000         lea eax, [esi + 0x6c0]
// 00892e63  85c0                 test eax, eax
// 00892e65  7403                 je 0x892e6a
// 00892e67  8b4020               mov eax, dword ptr [eax + 0x20]
// 00892e6a  6a00                 push 0
// 00892e6c  50                   push eax
// 00892e6d  8b86ec030000         mov eax, dword ptr [esi + 0x3ec]
// 00892e73  6869040000           push 0x469
// 00892e78  50                   push eax
// 00892e79  ffd7                 call edi
// 00892e7b  50                   push eax
// 00892e7c  e8e94df1ff           call 0x7a7c6a
// 00892e81  8b8eec030000         mov ecx, dword ptr [esi + 0x3ec]
// 00892e87  68ff000000           push 0xff
// 00892e8c  6a00                 push 0
// 00892e8e  6865040000           push 0x465
// 00892e93  51                   push ecx
// 00892e94  ffd7                 call edi
// 00892e96  8d86c4050000         lea eax, [esi + 0x5c4]
// 00892e9c  85c0                 test eax, eax
// 00892e9e  7403                 je 0x892ea3
// 00892ea0  8b4020               mov eax, dword ptr [eax + 0x20]
// 00892ea3  8b96e8040000         mov edx, dword ptr [esi + 0x4e8]
// 00892ea9  6a00                 push 0
// 00892eab  50                   push eax
// 00892eac  6869040000           push 0x469
// 00892eb1  52                   push edx
// 00892eb2  ffd7                 call edi
// 00892eb4  50                   push eax
// 00892eb5  e8b04df1ff           call 0x7a7c6a
// 00892eba  8b86e8040000         mov eax, dword ptr [esi + 0x4e8]
// 00892ec0  68ff000000           push 0xff
// 00892ec5  6a00                 push 0
// 00892ec7  6865040000           push 0x465
// 00892ecc  50                   push eax
// 00892ecd  ffd7                 call edi
// 00892ecf  8d8618060000         lea eax, [esi + 0x618]
// 00892ed5  85c0                 test eax, eax
// 00892ed7  7403                 je 0x892edc
// 00892ed9  8b4020               mov eax, dword ptr [eax + 0x20]
// 00892edc  8b8e3c050000         mov ecx, dword ptr [esi + 0x53c]
// 00892ee2  6a00                 push 0
// 00892ee4  50                   push eax
// 00892ee5  6869040000           push 0x469
// 00892eea  51                   push ecx
// 00892eeb  ffd7                 call edi
// 00892eed  50                   push eax
// 00892eee  e8774df1ff           call 0x7a7c6a
// 00892ef3  8b963c050000         mov edx, dword ptr [esi + 0x53c]
// 00892ef9  68ff000000           push 0xff
// 00892efe  6a00                 push 0
// 00892f00  6865040000           push 0x465
// 00892f05  52                   push edx
// 00892f06  ffd7                 call edi
// 00892f08  8b8e28010000         mov ecx, dword ptr [esi + 0x128]
// 00892f0e  8d442408             lea eax, [esp + 8]
// 00892f12  50                   push eax
// 00892f13  51                   push ecx
// 00892f14  ff153cbc9e00         call dword ptr [0x9ebc3c]
// 00892f1a  8d542408             lea edx, [esp + 8]
// 00892f1e  52                   push edx
// 00892f1f  8bce                 mov ecx, esi
// 00892f21  e8ec59f1ff           call 0x7a8912
// 00892f26  6a04                 push 4
// 00892f28  6a00                 push 0
// 00892f2a  8d442410             lea eax, [esp + 0x10]
// 00892f2e  50                   push eax
// 00892f2f  ff15dcbb9e00         call dword ptr [0x9ebbdc]
// 00892f35  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00892f39  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00892f3d  8b542410             mov edx, dword ptr [esp + 0x10]
// 00892f41  6a01                 push 1
// 00892f43  2bc8                 sub ecx, eax
// 00892f45  51                   push ecx
// 00892f46  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00892f4a  2bd1                 sub edx, ecx
// 00892f4c  52                   push edx
// 00892f4d  50                   push eax
// 00892f4e  51                   push ecx
// 00892f4f  8d8e08010000         lea ecx, [esi + 0x108]
// 00892f55  e8184ef1ff           call 0x7a7d72
// 00892f5a  5f                   pop edi
// 00892f5b  b801000000           mov eax, 1
// 00892f60  5e                   pop esi
// 00892f61  83c410               add esp, 0x10
// 00892f64  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTColorPageCustom.cpp (function ?OnInitDialog@CXTColorPageCustom@@MAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageCustom.cpp
