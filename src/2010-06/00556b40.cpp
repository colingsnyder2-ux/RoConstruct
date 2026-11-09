// from server: 100% by auto
// roc 2010-06 00556b40  unit: seg_00550000  size: 393 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00556b40
//
// 00556b40  8b442404             mov eax, dword ptr [esp + 4]
// 00556b44  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00556b48  f30f1000             movss xmm0, dword ptr [eax]
// 00556b4c  f30f5901             mulss xmm0, dword ptr [ecx]
// 00556b50  f30f104804           movss xmm1, dword ptr [eax + 4]
// 00556b55  f30f59490c           mulss xmm1, dword ptr [ecx + 0xc]
// 00556b5a  f30f58c1             addss xmm0, xmm1
// 00556b5e  f30f104808           movss xmm1, dword ptr [eax + 8]
// 00556b63  f30f594918           mulss xmm1, dword ptr [ecx + 0x18]
// 00556b68  f30f58c1             addss xmm0, xmm1
// 00556b6c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00556b70  f30f1102             movss dword ptr [edx], xmm0
// 00556b74  f30f104004           movss xmm0, dword ptr [eax + 4]
// 00556b79  f30f594110           mulss xmm0, dword ptr [ecx + 0x10]
// 00556b7e  f30f104808           movss xmm1, dword ptr [eax + 8]
// 00556b83  f30f59491c           mulss xmm1, dword ptr [ecx + 0x1c]
// 00556b88  f30f58c1             addss xmm0, xmm1
// 00556b8c  f30f104904           movss xmm1, dword ptr [ecx + 4]
// 00556b91  f30f5908             mulss xmm1, dword ptr [eax]
// 00556b95  f30f58c1             addss xmm0, xmm1
// 00556b99  f30f114204           movss dword ptr [edx + 4], xmm0
// 00556b9e  f30f104004           movss xmm0, dword ptr [eax + 4]
// 00556ba3  f30f594114           mulss xmm0, dword ptr [ecx + 0x14]
// 00556ba8  f30f104808           movss xmm1, dword ptr [eax + 8]
// 00556bad  f30f594920           mulss xmm1, dword ptr [ecx + 0x20]
// 00556bb2  f30f58c1             addss xmm0, xmm1
// 00556bb6  f30f104908           movss xmm1, dword ptr [ecx + 8]
// 00556bbb  f30f5908             mulss xmm1, dword ptr [eax]
// 00556bbf  f30f58c1             addss xmm0, xmm1
// 00556bc3  f30f114208           movss dword ptr [edx + 8], xmm0
// 00556bc8  f30f104010           movss xmm0, dword ptr [eax + 0x10]
// 00556bcd  f30f59410c           mulss xmm0, dword ptr [ecx + 0xc]
// 00556bd2  f30f104918           movss xmm1, dword ptr [ecx + 0x18]
// 00556bd7  f30f594814           mulss xmm1, dword ptr [eax + 0x14]
// 00556bdc  f30f58c1             addss xmm0, xmm1
// 00556be0  f30f10480c           movss xmm1, dword ptr [eax + 0xc]
// 00556be5  f30f5909             mulss xmm1, dword ptr [ecx]
// 00556be9  f30f58c1             addss xmm0, xmm1
// 00556bed  f30f11420c           movss dword ptr [edx + 0xc], xmm0
// 00556bf2  f30f104010           movss xmm0, dword ptr [eax + 0x10]
// 00556bf7  f30f594110           mulss xmm0, dword ptr [ecx + 0x10]
// 00556bfc  f30f104904           movss xmm1, dword ptr [ecx + 4]
// 00556c01  f30f59480c           mulss xmm1, dword ptr [eax + 0xc]
// 00556c06  f30f58c1             addss xmm0, xmm1
// 00556c0a  f30f10491c           movss xmm1, dword ptr [ecx + 0x1c]
// 00556c0f  f30f594814           mulss xmm1, dword ptr [eax + 0x14]
// 00556c14  f30f58c1             addss xmm0, xmm1
// 00556c18  f30f114210           movss dword ptr [edx + 0x10], xmm0
// 00556c1d  f30f104010           movss xmm0, dword ptr [eax + 0x10]
// 00556c22  f30f594114           mulss xmm0, dword ptr [ecx + 0x14]
// 00556c27  f30f104908           movss xmm1, dword ptr [ecx + 8]
// 00556c2c  f30f59480c           mulss xmm1, dword ptr [eax + 0xc]
// 00556c31  f30f58c1             addss xmm0, xmm1
// 00556c35  f30f104920           movss xmm1, dword ptr [ecx + 0x20]
// 00556c3a  f30f594814           mulss xmm1, dword ptr [eax + 0x14]
// 00556c3f  f30f58c1             addss xmm0, xmm1
// 00556c43  f30f114214           movss dword ptr [edx + 0x14], xmm0
// 00556c48  f30f10401c           movss xmm0, dword ptr [eax + 0x1c]
// 00556c4d  f30f59410c           mulss xmm0, dword ptr [ecx + 0xc]
// 00556c52  f30f104918           movss xmm1, dword ptr [ecx + 0x18]
// 00556c57  f30f594820           mulss xmm1, dword ptr [eax + 0x20]
// 00556c5c  f30f58c1             addss xmm0, xmm1
// 00556c60  f30f104818           movss xmm1, dword ptr [eax + 0x18]
// 00556c65  f30f5909             mulss xmm1, dword ptr [ecx]
// 00556c69  f30f58c1             addss xmm0, xmm1
// 00556c6d  f30f114218           movss dword ptr [edx + 0x18], xmm0
// 00556c72  f30f10401c           movss xmm0, dword ptr [eax + 0x1c]
// 00556c77  f30f594110           mulss xmm0, dword ptr [ecx + 0x10]
// 00556c7c  f30f104904           movss xmm1, dword ptr [ecx + 4]
// 00556c81  f30f594818           mulss xmm1, dword ptr [eax + 0x18]
// 00556c86  f30f58c1             addss xmm0, xmm1
// 00556c8a  f30f10491c           movss xmm1, dword ptr [ecx + 0x1c]
// 00556c8f  f30f594820           mulss xmm1, dword ptr [eax + 0x20]
// 00556c94  f30f58c1             addss xmm0, xmm1
// 00556c98  f30f11421c           movss dword ptr [edx + 0x1c], xmm0
// 00556c9d  f30f10401c           movss xmm0, dword ptr [eax + 0x1c]
// 00556ca2  f30f104908           movss xmm1, dword ptr [ecx + 8]
// 00556ca7  f30f594818           mulss xmm1, dword ptr [eax + 0x18]
// 00556cac  f30f594114           mulss xmm0, dword ptr [ecx + 0x14]
// 00556cb1  f30f58c1             addss xmm0, xmm1
// 00556cb5  f30f104920           movss xmm1, dword ptr [ecx + 0x20]
// 00556cba  f30f594820           mulss xmm1, dword ptr [eax + 0x20]
// 00556cbf  f30f58c1             addss xmm0, xmm1
// 00556cc3  f30f114220           movss dword ptr [edx + 0x20], xmm0
// 00556cc8  c3                   ret 
// library rbx2016-g3d/Matrix3.cpp (function ?_mul@Matrix3@G3D@@CAXABV12@0AAV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix3.cpp
