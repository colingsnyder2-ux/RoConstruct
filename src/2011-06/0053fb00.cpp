// from server: 100% by auto
// roc 2011-06 0053fb00  unit: G3D::MemoryManager  size: 761 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0053fb00
//
// 0053fb00  b801000000           mov eax, 1
// 0053fb05  8405a8a2cb00         test byte ptr [0xcba2a8], al
// 0053fb0b  0f85d1020000         jne 0x53fde2
// 0053fb11  0905a8a2cb00         or dword ptr [0xcba2a8], eax
// 0053fb17  0f57c0               xorps xmm0, xmm0
// 0053fb1a  f30f100d143ba600     movss xmm1, dword ptr [0xa63b14]
// 0053fb22  8405c0a1cb00         test byte ptr [0xcba1c0], al
// 0053fb28  751e                 jne 0x53fb48
// 0053fb2a  0905c0a1cb00         or dword ptr [0xcba1c0], eax
// 0053fb30  f30f1105b4a1cb00     movss dword ptr [0xcba1b4], xmm0
// 0053fb38  f30f1105b8a1cb00     movss dword ptr [0xcba1b8], xmm0
// 0053fb40  f30f110dbca1cb00     movss dword ptr [0xcba1bc], xmm1
// 0053fb48  f30f1015b4a1cb00     movss xmm2, dword ptr [0xcba1b4]
// 0053fb50  f30f111548a2cb00     movss dword ptr [0xcba248], xmm2
// 0053fb58  f30f1015b8a1cb00     movss xmm2, dword ptr [0xcba1b8]
// 0053fb60  f30f11154ca2cb00     movss dword ptr [0xcba24c], xmm2
// 0053fb68  f30f1015bca1cb00     movss xmm2, dword ptr [0xcba1bc]
// 0053fb70  f30f111550a2cb00     movss dword ptr [0xcba250], xmm2
// 0053fb78  8405a0a1cb00         test byte ptr [0xcba1a0], al
// 0053fb7e  751e                 jne 0x53fb9e
// 0053fb80  0905a0a1cb00         or dword ptr [0xcba1a0], eax
// 0053fb86  f30f110d94a1cb00     movss dword ptr [0xcba194], xmm1
// 0053fb8e  f30f110598a1cb00     movss dword ptr [0xcba198], xmm0
// 0053fb96  f30f11059ca1cb00     movss dword ptr [0xcba19c], xmm0
// 0053fb9e  f30f101594a1cb00     movss xmm2, dword ptr [0xcba194]
// 0053fba6  f30f111554a2cb00     movss dword ptr [0xcba254], xmm2
// 0053fbae  f30f101598a1cb00     movss xmm2, dword ptr [0xcba198]
// 0053fbb6  f30f111558a2cb00     movss dword ptr [0xcba258], xmm2
// 0053fbbe  f30f10159ca1cb00     movss xmm2, dword ptr [0xcba19c]
// 0053fbc6  f30f11155ca2cb00     movss dword ptr [0xcba25c], xmm2
// 0053fbce  8405b0a1cb00         test byte ptr [0xcba1b0], al
// 0053fbd4  751e                 jne 0x53fbf4
// 0053fbd6  0905b0a1cb00         or dword ptr [0xcba1b0], eax
// 0053fbdc  f30f1105a4a1cb00     movss dword ptr [0xcba1a4], xmm0
// 0053fbe4  f30f110da8a1cb00     movss dword ptr [0xcba1a8], xmm1
// 0053fbec  f30f1105aca1cb00     movss dword ptr [0xcba1ac], xmm0
// 0053fbf4  f30f1015a4a1cb00     movss xmm2, dword ptr [0xcba1a4]
// 0053fbfc  f30f101d685ba700     movss xmm3, dword ptr [0xa75b68]
// 0053fc04  f30f111560a2cb00     movss dword ptr [0xcba260], xmm2
// 0053fc0c  f30f1015a8a1cb00     movss xmm2, dword ptr [0xcba1a8]
// 0053fc14  f30f111564a2cb00     movss dword ptr [0xcba264], xmm2
// 0053fc1c  f30f1015aca1cb00     movss xmm2, dword ptr [0xcba1ac]
// 0053fc24  f30f111568a2cb00     movss dword ptr [0xcba268], xmm2
// 0053fc2c  840510a2cb00         test byte ptr [0xcba210], al
// 0053fc32  751e                 jne 0x53fc52
// 0053fc34  090510a2cb00         or dword ptr [0xcba210], eax
// 0053fc3a  f30f110d04a2cb00     movss dword ptr [0xcba204], xmm1
// 0053fc42  f30f111d08a2cb00     movss dword ptr [0xcba208], xmm3
// 0053fc4a  f30f11050ca2cb00     movss dword ptr [0xcba20c], xmm0
// 0053fc52  f30f101504a2cb00     movss xmm2, dword ptr [0xcba204]
// 0053fc5a  f30f11156ca2cb00     movss dword ptr [0xcba26c], xmm2
// 0053fc62  f30f101508a2cb00     movss xmm2, dword ptr [0xcba208]
// 0053fc6a  f30f111570a2cb00     movss dword ptr [0xcba270], xmm2
// 0053fc72  f30f10150ca2cb00     movss xmm2, dword ptr [0xcba20c]
// 0053fc7a  f30f111574a2cb00     movss dword ptr [0xcba274], xmm2
// 0053fc82  8405f0a1cb00         test byte ptr [0xcba1f0], al
// 0053fc88  751e                 jne 0x53fca8
// 0053fc8a  0905f0a1cb00         or dword ptr [0xcba1f0], eax
// 0053fc90  f30f110de4a1cb00     movss dword ptr [0xcba1e4], xmm1
// 0053fc98  f30f110de8a1cb00     movss dword ptr [0xcba1e8], xmm1
// 0053fca0  f30f1105eca1cb00     movss dword ptr [0xcba1ec], xmm0
// 0053fca8  f30f1015e4a1cb00     movss xmm2, dword ptr [0xcba1e4]
// 0053fcb0  f30f111578a2cb00     movss dword ptr [0xcba278], xmm2
// 0053fcb8  f30f1015e8a1cb00     movss xmm2, dword ptr [0xcba1e8]
// 0053fcc0  f30f11157ca2cb00     movss dword ptr [0xcba27c], xmm2
// 0053fcc8  f30f1015eca1cb00     movss xmm2, dword ptr [0xcba1ec]
// 0053fcd0  f30f111580a2cb00     movss dword ptr [0xcba280], xmm2
// 0053fcd8  f30f10152cfba700     movss xmm2, dword ptr [0xa7fb2c]
// 0053fce0  8405e0a1cb00         test byte ptr [0xcba1e0], al
// 0053fce6  751e                 jne 0x53fd06
// 0053fce8  0905e0a1cb00         or dword ptr [0xcba1e0], eax
// 0053fcee  f30f1105d4a1cb00     movss dword ptr [0xcba1d4], xmm0
// 0053fcf6  f30f1115d8a1cb00     movss dword ptr [0xcba1d8], xmm2
// 0053fcfe  f30f110ddca1cb00     movss dword ptr [0xcba1dc], xmm1
// 0053fd06  f30f1025d4a1cb00     movss xmm4, dword ptr [0xcba1d4]
// 0053fd0e  f30f112584a2cb00     movss dword ptr [0xcba284], xmm4
// 0053fd16  f30f1025d8a1cb00     movss xmm4, dword ptr [0xcba1d8]
// 0053fd1e  f30f112588a2cb00     movss dword ptr [0xcba288], xmm4
// 0053fd26  f30f1025dca1cb00     movss xmm4, dword ptr [0xcba1dc]
// 0053fd2e  f30f11258ca2cb00     movss dword ptr [0xcba28c], xmm4
// 0053fd36  8405d0a1cb00         test byte ptr [0xcba1d0], al
// 0053fd3c  751e                 jne 0x53fd5c
// 0053fd3e  0905d0a1cb00         or dword ptr [0xcba1d0], eax
// 0053fd44  f30f1115c4a1cb00     movss dword ptr [0xcba1c4], xmm2
// 0053fd4c  f30f1105c8a1cb00     movss dword ptr [0xcba1c8], xmm0
// 0053fd54  f30f110dcca1cb00     movss dword ptr [0xcba1cc], xmm1
// 0053fd5c  f30f100dc4a1cb00     movss xmm1, dword ptr [0xcba1c4]
// 0053fd64  f30f110d90a2cb00     movss dword ptr [0xcba290], xmm1
// 0053fd6c  f30f100dc8a1cb00     movss xmm1, dword ptr [0xcba1c8]
// 0053fd74  f30f110d94a2cb00     movss dword ptr [0xcba294], xmm1
// 0053fd7c  f30f100dcca1cb00     movss xmm1, dword ptr [0xcba1cc]
// 0053fd84  f30f110d98a2cb00     movss dword ptr [0xcba298], xmm1
// 0053fd8c  840500a2cb00         test byte ptr [0xcba200], al
// 0053fd92  751e                 jne 0x53fdb2
// 0053fd94  090500a2cb00         or dword ptr [0xcba200], eax
// 0053fd9a  f30f111df4a1cb00     movss dword ptr [0xcba1f4], xmm3
// 0053fda2  f30f111df8a1cb00     movss dword ptr [0xcba1f8], xmm3
// 0053fdaa  f30f1105fca1cb00     movss dword ptr [0xcba1fc], xmm0
// 0053fdb2  f30f1005f4a1cb00     movss xmm0, dword ptr [0xcba1f4]
// 0053fdba  f30f11059ca2cb00     movss dword ptr [0xcba29c], xmm0
// 0053fdc2  f30f1005f8a1cb00     movss xmm0, dword ptr [0xcba1f8]
// 0053fdca  f30f1105a0a2cb00     movss dword ptr [0xcba2a0], xmm0
// 0053fdd2  f30f1005fca1cb00     movss xmm0, dword ptr [0xcba1fc]
// 0053fdda  f30f1105a4a2cb00     movss dword ptr [0xcba2a4], xmm0
// 0053fde2  6a07                 push 7
// 0053fde4  6a00                 push 0
// 0053fde6  e865300000           call 0x542e50
// 0053fdeb  8d0440               lea eax, [eax + eax*2]
// 0053fdee  83c408               add esp, 8
// 0053fdf1  8d048548a2cb00       lea eax, [eax*4 + 0xcba248]
// 0053fdf8  c3                   ret 
// library rbx2016-g3d/Color3.cpp (function ?wheelRandom@Color3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color3.cpp
