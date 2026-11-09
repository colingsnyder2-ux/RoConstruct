// from server: 100% by auto
// roc 2011-06 00540b20  unit: G3D::MemoryManager  size: 393 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00540b20
//
// 00540b20  8b442404             mov eax, dword ptr [esp + 4]
// 00540b24  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00540b28  f30f1000             movss xmm0, dword ptr [eax]
// 00540b2c  f30f5901             mulss xmm0, dword ptr [ecx]
// 00540b30  f30f104804           movss xmm1, dword ptr [eax + 4]
// 00540b35  f30f59490c           mulss xmm1, dword ptr [ecx + 0xc]
// 00540b3a  f30f58c1             addss xmm0, xmm1
// 00540b3e  f30f104808           movss xmm1, dword ptr [eax + 8]
// 00540b43  f30f594918           mulss xmm1, dword ptr [ecx + 0x18]
// 00540b48  f30f58c1             addss xmm0, xmm1
// 00540b4c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00540b50  f30f1102             movss dword ptr [edx], xmm0
// 00540b54  f30f104004           movss xmm0, dword ptr [eax + 4]
// 00540b59  f30f594110           mulss xmm0, dword ptr [ecx + 0x10]
// 00540b5e  f30f104808           movss xmm1, dword ptr [eax + 8]
// 00540b63  f30f59491c           mulss xmm1, dword ptr [ecx + 0x1c]
// 00540b68  f30f58c1             addss xmm0, xmm1
// 00540b6c  f30f104904           movss xmm1, dword ptr [ecx + 4]
// 00540b71  f30f5908             mulss xmm1, dword ptr [eax]
// 00540b75  f30f58c1             addss xmm0, xmm1
// 00540b79  f30f114204           movss dword ptr [edx + 4], xmm0
// 00540b7e  f30f104004           movss xmm0, dword ptr [eax + 4]
// 00540b83  f30f594114           mulss xmm0, dword ptr [ecx + 0x14]
// 00540b88  f30f104808           movss xmm1, dword ptr [eax + 8]
// 00540b8d  f30f594920           mulss xmm1, dword ptr [ecx + 0x20]
// 00540b92  f30f58c1             addss xmm0, xmm1
// 00540b96  f30f104908           movss xmm1, dword ptr [ecx + 8]
// 00540b9b  f30f5908             mulss xmm1, dword ptr [eax]
// 00540b9f  f30f58c1             addss xmm0, xmm1
// 00540ba3  f30f114208           movss dword ptr [edx + 8], xmm0
// 00540ba8  f30f104010           movss xmm0, dword ptr [eax + 0x10]
// 00540bad  f30f59410c           mulss xmm0, dword ptr [ecx + 0xc]
// 00540bb2  f30f104918           movss xmm1, dword ptr [ecx + 0x18]
// 00540bb7  f30f594814           mulss xmm1, dword ptr [eax + 0x14]
// 00540bbc  f30f58c1             addss xmm0, xmm1
// 00540bc0  f30f10480c           movss xmm1, dword ptr [eax + 0xc]
// 00540bc5  f30f5909             mulss xmm1, dword ptr [ecx]
// 00540bc9  f30f58c1             addss xmm0, xmm1
// 00540bcd  f30f11420c           movss dword ptr [edx + 0xc], xmm0
// 00540bd2  f30f104010           movss xmm0, dword ptr [eax + 0x10]
// 00540bd7  f30f594110           mulss xmm0, dword ptr [ecx + 0x10]
// 00540bdc  f30f104904           movss xmm1, dword ptr [ecx + 4]
// 00540be1  f30f59480c           mulss xmm1, dword ptr [eax + 0xc]
// 00540be6  f30f58c1             addss xmm0, xmm1
// 00540bea  f30f10491c           movss xmm1, dword ptr [ecx + 0x1c]
// 00540bef  f30f594814           mulss xmm1, dword ptr [eax + 0x14]
// 00540bf4  f30f58c1             addss xmm0, xmm1
// 00540bf8  f30f114210           movss dword ptr [edx + 0x10], xmm0
// 00540bfd  f30f104010           movss xmm0, dword ptr [eax + 0x10]
// 00540c02  f30f594114           mulss xmm0, dword ptr [ecx + 0x14]
// 00540c07  f30f104908           movss xmm1, dword ptr [ecx + 8]
// 00540c0c  f30f59480c           mulss xmm1, dword ptr [eax + 0xc]
// 00540c11  f30f58c1             addss xmm0, xmm1
// 00540c15  f30f104920           movss xmm1, dword ptr [ecx + 0x20]
// 00540c1a  f30f594814           mulss xmm1, dword ptr [eax + 0x14]
// 00540c1f  f30f58c1             addss xmm0, xmm1
// 00540c23  f30f114214           movss dword ptr [edx + 0x14], xmm0
// 00540c28  f30f10401c           movss xmm0, dword ptr [eax + 0x1c]
// 00540c2d  f30f59410c           mulss xmm0, dword ptr [ecx + 0xc]
// 00540c32  f30f104918           movss xmm1, dword ptr [ecx + 0x18]
// 00540c37  f30f594820           mulss xmm1, dword ptr [eax + 0x20]
// 00540c3c  f30f58c1             addss xmm0, xmm1
// 00540c40  f30f104818           movss xmm1, dword ptr [eax + 0x18]
// 00540c45  f30f5909             mulss xmm1, dword ptr [ecx]
// 00540c49  f30f58c1             addss xmm0, xmm1
// 00540c4d  f30f114218           movss dword ptr [edx + 0x18], xmm0
// 00540c52  f30f10401c           movss xmm0, dword ptr [eax + 0x1c]
// 00540c57  f30f594110           mulss xmm0, dword ptr [ecx + 0x10]
// 00540c5c  f30f104904           movss xmm1, dword ptr [ecx + 4]
// 00540c61  f30f594818           mulss xmm1, dword ptr [eax + 0x18]
// 00540c66  f30f58c1             addss xmm0, xmm1
// 00540c6a  f30f10491c           movss xmm1, dword ptr [ecx + 0x1c]
// 00540c6f  f30f594820           mulss xmm1, dword ptr [eax + 0x20]
// 00540c74  f30f58c1             addss xmm0, xmm1
// 00540c78  f30f11421c           movss dword ptr [edx + 0x1c], xmm0
// 00540c7d  f30f10401c           movss xmm0, dword ptr [eax + 0x1c]
// 00540c82  f30f104908           movss xmm1, dword ptr [ecx + 8]
// 00540c87  f30f594818           mulss xmm1, dword ptr [eax + 0x18]
// 00540c8c  f30f594114           mulss xmm0, dword ptr [ecx + 0x14]
// 00540c91  f30f58c1             addss xmm0, xmm1
// 00540c95  f30f104920           movss xmm1, dword ptr [ecx + 0x20]
// 00540c9a  f30f594820           mulss xmm1, dword ptr [eax + 0x20]
// 00540c9f  f30f58c1             addss xmm0, xmm1
// 00540ca3  f30f114220           movss dword ptr [edx + 0x20], xmm0
// 00540ca8  c3                   ret 
// library rbx2016-g3d/Matrix3.cpp (function ?_mul@Matrix3@G3D@@CAXABV12@0AAV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix3.cpp
