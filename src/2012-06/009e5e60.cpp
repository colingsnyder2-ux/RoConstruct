// roc 2012-06 009e5e60  unit: CXTSplitterWnd  size: 552 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e5e60
//
// 009e5e60  51                   push ecx
// 009e5e61  56                   push esi
// 009e5e62  57                   push edi
// 009e5e63  8bf1                 mov esi, ecx
// 009e5e65  33ff                 xor edi, edi
// 009e5e67  39befc000000         cmp dword ptr [esi + 0xfc], edi
// 009e5e6d  7530                 jne 0x9e5e9f
// 009e5e6f  8b442410             mov eax, dword ptr [esp + 0x10]
// 009e5e73  50                   push eax
// 009e5e74  e8b13c0b00           call 0xa99b2a
// 009e5e79  39be14010000         cmp dword ptr [esi + 0x114], edi
// 009e5e7f  0f84fd010000         je 0x9e6082
// 009e5e85  57                   push edi
// 009e5e86  6800000006           push 0x6000000
// 009e5e8b  57                   push edi
// 009e5e8c  8bce                 mov ecx, esi
// 009e5e8e  e8c5c9f9ff           call 0x982858
// 009e5e93  89be14010000         mov dword ptr [esi + 0x114], edi
// 009e5e99  5f                   pop edi
// 009e5e9a  5e                   pop esi
// 009e5e9b  59                   pop ecx
// 009e5e9c  c20400               ret 4
// 009e5e9f  39be98000000         cmp dword ptr [esi + 0x98], edi
// 009e5ea5  0f84d7010000         je 0x9e6082
// 009e5eab  53                   push ebx
// 009e5eac  ff15743ab200         call dword ptr [0xb23a74]
// 009e5eb2  8b16                 mov edx, dword ptr [esi]
// 009e5eb4  8b8258010000         mov eax, dword ptr [edx + 0x158]
// 009e5eba  8d9eb8000000         lea ebx, [esi + 0xb8]
// 009e5ec0  53                   push ebx
// 009e5ec1  8bce                 mov ecx, esi
// 009e5ec3  ffd0                 call eax
// 009e5ec5  39be9c000000         cmp dword ptr [esi + 0x9c], edi
// 009e5ecb  7413                 je 0x9e5ee0
// 009e5ecd  8b16                 mov edx, dword ptr [esi]
// 009e5ecf  8b9258010000         mov edx, dword ptr [edx + 0x158]
// 009e5ed5  8d86c8000000         lea eax, [esi + 0xc8]
// 009e5edb  50                   push eax
// 009e5edc  8bce                 mov ecx, esi
// 009e5ede  ffd2                 call edx
// 009e5ee0  8b06                 mov eax, dword ptr [esi]
// 009e5ee2  8b9074010000         mov edx, dword ptr [eax + 0x174]
// 009e5ee8  55                   push ebp
// 009e5ee9  57                   push edi
// 009e5eea  57                   push edi
// 009e5eeb  8bce                 mov ecx, esi
// 009e5eed  89be9c000000         mov dword ptr [esi + 0x9c], edi
// 009e5ef3  89be98000000         mov dword ptr [esi + 0x98], edi
// 009e5ef9  ffd2                 call edx
// 009e5efb  8b2df43ab200         mov ebp, dword ptr [0xb23af4]
// 009e5f01  6aff                 push -1
// 009e5f03  6aff                 push -1
// 009e5f05  53                   push ebx
// 009e5f06  8944241c             mov dword ptr [esp + 0x1c], eax
// 009e5f0a  ffd5                 call ebp
// 009e5f0c  6aff                 push -1
// 009e5f0e  6aff                 push -1
// 009e5f10  8dbec8000000         lea edi, [esi + 0xc8]
// 009e5f16  57                   push edi
// 009e5f17  ffd5                 call ebp
// 009e5f19  837c241800           cmp dword ptr [esp + 0x18], 0
// 009e5f1e  5d                   pop ebp
// 009e5f1f  0f842f010000         je 0x9e6054
// 009e5f25  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 009e5f2b  83f801               cmp eax, 1
// 009e5f2e  7513                 jne 0x9e5f43
// 009e5f30  8b06                 mov eax, dword ptr [esi]
// 009e5f32  8b8ebc000000         mov ecx, dword ptr [esi + 0xbc]
// 009e5f38  8b9064010000         mov edx, dword ptr [eax + 0x164]
// 009e5f3e  e90c010000           jmp 0x9e604f
// 009e5f43  83f865               cmp eax, 0x65
// 009e5f46  7c45                 jl 0x9e5f8d
// 009e5f48  83f873               cmp eax, 0x73
// 009e5f4b  7f40                 jg 0x9e5f8d
// 009e5f4d  83be0401000000       cmp dword ptr [esi + 0x104], 0
// 009e5f54  740f                 je 0x9e5f65
// 009e5f56  8b8ec4000000         mov ecx, dword ptr [esi + 0xc4]
// 009e5f5c  83e904               sub ecx, 4
// 009e5f5f  898ebc000000         mov dword ptr [esi + 0xbc], ecx
// 009e5f65  8b16                 mov edx, dword ptr [esi]
// 009e5f67  8b929c010000         mov edx, dword ptr [edx + 0x19c]
// 009e5f6d  83c09b               add eax, -0x65
// 009e5f70  50                   push eax
// 009e5f71  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 009e5f77  50                   push eax
// 009e5f78  8bce                 mov ecx, esi
// 009e5f7a  ffd2                 call edx
// 009e5f7c  8b06                 mov eax, dword ptr [esi]
// 009e5f7e  8b9050010000         mov edx, dword ptr [eax + 0x150]
// 009e5f84  8bce                 mov ecx, esi
// 009e5f86  ffd2                 call edx
// 009e5f88  e9c7000000           jmp 0x9e6054
// 009e5f8d  83f802               cmp eax, 2
// 009e5f90  7507                 jne 0x9e5f99
// 009e5f92  8b0b                 mov ecx, dword ptr [ebx]
// 009e5f94  e9ae000000           jmp 0x9e6047
// 009e5f99  3dc9000000           cmp eax, 0xc9
// 009e5f9e  7c3e                 jl 0x9e5fde
// 009e5fa0  3dd7000000           cmp eax, 0xd7
// 009e5fa5  7f37                 jg 0x9e5fde
// 009e5fa7  83be0401000000       cmp dword ptr [esi + 0x104], 0
// 009e5fae  740b                 je 0x9e5fbb
// 009e5fb0  8b8ec0000000         mov ecx, dword ptr [esi + 0xc0]
// 009e5fb6  83e904               sub ecx, 4
// 009e5fb9  890b                 mov dword ptr [ebx], ecx
// 009e5fbb  8b16                 mov edx, dword ptr [esi]
// 009e5fbd  8b92a0010000         mov edx, dword ptr [edx + 0x1a0]
// 009e5fc3  0537ffffff           add eax, 0xffffff37
// 009e5fc8  50                   push eax
// 009e5fc9  8b03                 mov eax, dword ptr [ebx]
// 009e5fcb  50                   push eax
// 009e5fcc  8bce                 mov ecx, esi
// 009e5fce  ffd2                 call edx
// 009e5fd0  8b06                 mov eax, dword ptr [esi]
// 009e5fd2  8b9050010000         mov edx, dword ptr [eax + 0x150]
// 009e5fd8  8bce                 mov ecx, esi
// 009e5fda  ffd2                 call edx
// 009e5fdc  eb76                 jmp 0x9e6054
// 009e5fde  3d2d010000           cmp eax, 0x12d
// 009e5fe3  7c48                 jl 0x9e602d
// 009e5fe5  3d0d020000           cmp eax, 0x20d
// 009e5fea  7f41                 jg 0x9e602d
// 009e5fec  05d3feffff           add eax, 0xfffffed3
// 009e5ff1  99                   cdq 
// 009e5ff2  b90f000000           mov ecx, 0xf
// 009e5ff7  f7f9                 idiv ecx
// 009e5ff9  8bce                 mov ecx, esi
// 009e5ffb  8bda                 mov ebx, edx
// 009e5ffd  8b16                 mov edx, dword ptr [esi]
// 009e5fff  8b929c010000         mov edx, dword ptr [edx + 0x19c]
// 009e6005  50                   push eax
// 009e6006  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 009e600c  50                   push eax
// 009e600d  ffd2                 call edx
// 009e600f  8b0f                 mov ecx, dword ptr [edi]
// 009e6011  8b06                 mov eax, dword ptr [esi]
// 009e6013  8b90a0010000         mov edx, dword ptr [eax + 0x1a0]
// 009e6019  53                   push ebx
// 009e601a  51                   push ecx
// 009e601b  8bce                 mov ecx, esi
// 009e601d  ffd2                 call edx
// 009e601f  8b06                 mov eax, dword ptr [esi]
// 009e6021  8b9050010000         mov edx, dword ptr [eax + 0x150]
// 009e6027  8bce                 mov ecx, esi
// 009e6029  ffd2                 call edx
// 009e602b  eb27                 jmp 0x9e6054
// 009e602d  83f803               cmp eax, 3
// 009e6030  7522                 jne 0x9e6054
// 009e6032  8b8ebc000000         mov ecx, dword ptr [esi + 0xbc]
// 009e6038  8b06                 mov eax, dword ptr [esi]
// 009e603a  8b9064010000         mov edx, dword ptr [eax + 0x164]
// 009e6040  51                   push ecx
// 009e6041  8bce                 mov ecx, esi
// 009e6043  ffd2                 call edx
// 009e6045  8b0f                 mov ecx, dword ptr [edi]
// 009e6047  8b06                 mov eax, dword ptr [esi]
// 009e6049  8b9068010000         mov edx, dword ptr [eax + 0x168]
// 009e604f  51                   push ecx
// 009e6050  8bce                 mov ecx, esi
// 009e6052  ffd2                 call edx
// 009e6054  8b06                 mov eax, dword ptr [esi]
// 009e6056  8b9074010000         mov edx, dword ptr [eax + 0x174]
// 009e605c  6a00                 push 0
// 009e605e  6a00                 push 0
// 009e6060  8bce                 mov ecx, esi
// 009e6062  ffd2                 call edx
// 009e6064  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 009e6068  5b                   pop ebx
// 009e6069  3bc8                 cmp ecx, eax
// 009e606b  7515                 jne 0x9e6082
// 009e606d  85c9                 test ecx, ecx
// 009e606f  7411                 je 0x9e6082
// 009e6071  8b06                 mov eax, dword ptr [esi]
// 009e6073  8b9078010000         mov edx, dword ptr [eax + 0x178]
// 009e6079  51                   push ecx
// 009e607a  6aff                 push -1
// 009e607c  6aff                 push -1
// 009e607e  8bce                 mov ecx, esi
// 009e6080  ffd2                 call edx
// 009e6082  5f                   pop edi
// 009e6083  5e                   pop esi
// 009e6084  59                   pop ecx
// 009e6085  c20400               ret 4
// copied from an identical function in another client (function ?StopTracking@CXTSplitterWnd@@MAEXH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /MD /GS /EHsc /Ob1
// roc-lib: xtp-11.2.2-shared-mfc-internals Source/Controls/XTSplitterWnd.cpp
// MFC 9 afximpl.h: AFX_CX_BORDER = AFX_CY_BORDER = 1.
#define CX_BORDER 1
#define CY_BORDER 1