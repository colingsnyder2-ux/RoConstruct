// from server: 100% by auto
// roc 2009-06 00803e60  unit: CXTColorPageCustom  size: 501 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00803e60
//
// 00803e60  53                   push ebx
// 00803e61  56                   push esi
// 00803e62  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00803e66  57                   push edi
// 00803e67  8bf9                 mov edi, ecx
// 00803e69  8d8788000000         lea eax, [edi + 0x88]
// 00803e6f  50                   push eax
// 00803e70  6a65                 push 0x65
// 00803e72  56                   push esi
// 00803e73  e80e55f1ff           call 0x719386
// 00803e78  8d8f08010000         lea ecx, [edi + 0x108]
// 00803e7e  51                   push ecx
// 00803e7f  6a66                 push 0x66
// 00803e81  56                   push esi
// 00803e82  e8ff54f1ff           call 0x719386
// 00803e87  8d9780010000         lea edx, [edi + 0x180]
// 00803e8d  52                   push edx
// 00803e8e  6a69                 push 0x69
// 00803e90  56                   push esi
// 00803e91  e8f054f1ff           call 0x719386
// 00803e96  8d87d4010000         lea eax, [edi + 0x1d4]
// 00803e9c  50                   push eax
// 00803e9d  6a6b                 push 0x6b
// 00803e9f  56                   push esi
// 00803ea0  e8e154f1ff           call 0x719386
// 00803ea5  8d8f28020000         lea ecx, [edi + 0x228]
// 00803eab  51                   push ecx
// 00803eac  6a6a                 push 0x6a
// 00803eae  56                   push esi
// 00803eaf  e8d254f1ff           call 0x719386
// 00803eb4  8d977c020000         lea edx, [edi + 0x27c]
// 00803eba  52                   push edx
// 00803ebb  6a68                 push 0x68
// 00803ebd  56                   push esi
// 00803ebe  e8c354f1ff           call 0x719386
// 00803ec3  8d87d0020000         lea eax, [edi + 0x2d0]
// 00803ec9  50                   push eax
// 00803eca  6a6c                 push 0x6c
// 00803ecc  56                   push esi
// 00803ecd  e8b454f1ff           call 0x719386
// 00803ed2  8d8f24030000         lea ecx, [edi + 0x324]
// 00803ed8  51                   push ecx
// 00803ed9  6a6d                 push 0x6d
// 00803edb  56                   push esi
// 00803edc  e8a554f1ff           call 0x719386
// 00803ee1  8d9778030000         lea edx, [edi + 0x378]
// 00803ee7  52                   push edx
// 00803ee8  6a74                 push 0x74
// 00803eea  56                   push esi
// 00803eeb  e89654f1ff           call 0x719386
// 00803ef0  8d87cc030000         lea eax, [edi + 0x3cc]
// 00803ef6  50                   push eax
// 00803ef7  6a77                 push 0x77
// 00803ef9  56                   push esi
// 00803efa  e88754f1ff           call 0x719386
// 00803eff  8d8f20040000         lea ecx, [edi + 0x420]
// 00803f05  51                   push ecx
// 00803f06  6a75                 push 0x75
// 00803f08  56                   push esi
// 00803f09  e87854f1ff           call 0x719386
// 00803f0e  8d9774040000         lea edx, [edi + 0x474]
// 00803f14  52                   push edx
// 00803f15  6a70                 push 0x70
// 00803f17  56                   push esi
// 00803f18  e86954f1ff           call 0x719386
// 00803f1d  8d87c8040000         lea eax, [edi + 0x4c8]
// 00803f23  50                   push eax
// 00803f24  6a78                 push 0x78
// 00803f26  56                   push esi
// 00803f27  e85a54f1ff           call 0x719386
// 00803f2c  8d8f1c050000         lea ecx, [edi + 0x51c]
// 00803f32  51                   push ecx
// 00803f33  6a79                 push 0x79
// 00803f35  56                   push esi
// 00803f36  e84b54f1ff           call 0x719386
// 00803f3b  8d9770050000         lea edx, [edi + 0x570]
// 00803f41  52                   push edx
// 00803f42  6a73                 push 0x73
// 00803f44  56                   push esi
// 00803f45  e83c54f1ff           call 0x719386
// 00803f4a  8d87c4050000         lea eax, [edi + 0x5c4]
// 00803f50  50                   push eax
// 00803f51  6a6f                 push 0x6f
// 00803f53  56                   push esi
// 00803f54  e82d54f1ff           call 0x719386
// 00803f59  8d8f18060000         lea ecx, [edi + 0x618]
// 00803f5f  51                   push ecx
// 00803f60  6a76                 push 0x76
// 00803f62  56                   push esi
// 00803f63  e81e54f1ff           call 0x719386
// 00803f68  8d976c060000         lea edx, [edi + 0x66c]
// 00803f6e  52                   push edx
// 00803f6f  6a71                 push 0x71
// 00803f71  56                   push esi
// 00803f72  e80f54f1ff           call 0x719386
// 00803f77  8d87c0060000         lea eax, [edi + 0x6c0]
// 00803f7d  50                   push eax
// 00803f7e  6a6e                 push 0x6e
// 00803f80  56                   push esi
// 00803f81  e80054f1ff           call 0x719386
// 00803f86  8d8f14070000         lea ecx, [edi + 0x714]
// 00803f8c  51                   push ecx
// 00803f8d  6a72                 push 0x72
// 00803f8f  56                   push esi
// 00803f90  e8f153f1ff           call 0x719386
// 00803f95  8d9f68070000         lea ebx, [edi + 0x768]
// 00803f9b  53                   push ebx
// 00803f9c  6a6e                 push 0x6e
// 00803f9e  56                   push esi
// 00803f9f  e8b0880400           call 0x84c854
// 00803fa4  8b13                 mov edx, dword ptr [ebx]
// 00803fa6  68ff000000           push 0xff
// 00803fab  6a00                 push 0
// 00803fad  52                   push edx
// 00803fae  56                   push esi
// 00803faf  e89a880400           call 0x84c84e
// 00803fb4  8d9f6c070000         lea ebx, [edi + 0x76c]
// 00803fba  53                   push ebx
// 00803fbb  6a76                 push 0x76
// 00803fbd  56                   push esi
// 00803fbe  e891880400           call 0x84c854
// 00803fc3  8b03                 mov eax, dword ptr [ebx]
// 00803fc5  68ff000000           push 0xff
// 00803fca  6a00                 push 0
// 00803fcc  50                   push eax
// 00803fcd  56                   push esi
// 00803fce  e87b880400           call 0x84c84e
// 00803fd3  8d9f70070000         lea ebx, [edi + 0x770]
// 00803fd9  53                   push ebx
// 00803fda  6a6f                 push 0x6f
// 00803fdc  56                   push esi
// 00803fdd  e872880400           call 0x84c854
// 00803fe2  8b0b                 mov ecx, dword ptr [ebx]
// 00803fe4  68ff000000           push 0xff
// 00803fe9  6a00                 push 0
// 00803feb  51                   push ecx
// 00803fec  56                   push esi
// 00803fed  e85c880400           call 0x84c84e
// 00803ff2  8d9f74070000         lea ebx, [edi + 0x774]
// 00803ff8  53                   push ebx
// 00803ff9  6a73                 push 0x73
// 00803ffb  56                   push esi
// 00803ffc  e853880400           call 0x84c854
// 00804001  8b13                 mov edx, dword ptr [ebx]
// 00804003  68ff000000           push 0xff
// 00804008  6a00                 push 0
// 0080400a  52                   push edx
// 0080400b  56                   push esi
// 0080400c  e83d880400           call 0x84c84e
// 00804011  8d9f78070000         lea ebx, [edi + 0x778]
// 00804017  53                   push ebx
// 00804018  6a71                 push 0x71
// 0080401a  56                   push esi
// 0080401b  e834880400           call 0x84c854
// 00804020  8b03                 mov eax, dword ptr [ebx]
// 00804022  68ff000000           push 0xff
// 00804027  6a00                 push 0
// 00804029  50                   push eax
// 0080402a  56                   push esi
// 0080402b  e81e880400           call 0x84c84e
// 00804030  81c77c070000         add edi, 0x77c
// 00804036  57                   push edi
// 00804037  6a72                 push 0x72
// 00804039  56                   push esi
// 0080403a  e815880400           call 0x84c854
// 0080403f  8b0f                 mov ecx, dword ptr [edi]
// 00804041  68ff000000           push 0xff
// 00804046  6a00                 push 0
// 00804048  51                   push ecx
// 00804049  56                   push esi
// 0080404a  e8ff870400           call 0x84c84e
// 0080404f  5f                   pop edi
// 00804050  5e                   pop esi
// 00804051  5b                   pop ebx
// 00804052  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?DoDataExchange@CXTPColorPageCustom@@MAEXPAVCDataExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
