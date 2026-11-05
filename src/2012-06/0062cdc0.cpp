// from server: 100% by auto
// roc 2012-06 0062cdc0  unit: G3D::Sphere  size: 393 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062cdc0
//
// 0062cdc0  8b442404             mov eax, dword ptr [esp + 4]
// 0062cdc4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0062cdc8  f30f1000             movss xmm0, dword ptr [eax]
// 0062cdcc  f30f5901             mulss xmm0, dword ptr [ecx]
// 0062cdd0  f30f104804           movss xmm1, dword ptr [eax + 4]
// 0062cdd5  f30f59490c           mulss xmm1, dword ptr [ecx + 0xc]
// 0062cdda  f30f58c1             addss xmm0, xmm1
// 0062cdde  f30f104808           movss xmm1, dword ptr [eax + 8]
// 0062cde3  f30f594918           mulss xmm1, dword ptr [ecx + 0x18]
// 0062cde8  f30f58c1             addss xmm0, xmm1
// 0062cdec  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0062cdf0  f30f1102             movss dword ptr [edx], xmm0
// 0062cdf4  f30f104004           movss xmm0, dword ptr [eax + 4]
// 0062cdf9  f30f594110           mulss xmm0, dword ptr [ecx + 0x10]
// 0062cdfe  f30f104808           movss xmm1, dword ptr [eax + 8]
// 0062ce03  f30f59491c           mulss xmm1, dword ptr [ecx + 0x1c]
// 0062ce08  f30f58c1             addss xmm0, xmm1
// 0062ce0c  f30f104904           movss xmm1, dword ptr [ecx + 4]
// 0062ce11  f30f5908             mulss xmm1, dword ptr [eax]
// 0062ce15  f30f58c1             addss xmm0, xmm1
// 0062ce19  f30f114204           movss dword ptr [edx + 4], xmm0
// 0062ce1e  f30f104004           movss xmm0, dword ptr [eax + 4]
// 0062ce23  f30f594114           mulss xmm0, dword ptr [ecx + 0x14]
// 0062ce28  f30f104808           movss xmm1, dword ptr [eax + 8]
// 0062ce2d  f30f594920           mulss xmm1, dword ptr [ecx + 0x20]
// 0062ce32  f30f58c1             addss xmm0, xmm1
// 0062ce36  f30f104908           movss xmm1, dword ptr [ecx + 8]
// 0062ce3b  f30f5908             mulss xmm1, dword ptr [eax]
// 0062ce3f  f30f58c1             addss xmm0, xmm1
// 0062ce43  f30f114208           movss dword ptr [edx + 8], xmm0
// 0062ce48  f30f104010           movss xmm0, dword ptr [eax + 0x10]
// 0062ce4d  f30f59410c           mulss xmm0, dword ptr [ecx + 0xc]
// 0062ce52  f30f104918           movss xmm1, dword ptr [ecx + 0x18]
// 0062ce57  f30f594814           mulss xmm1, dword ptr [eax + 0x14]
// 0062ce5c  f30f58c1             addss xmm0, xmm1
// 0062ce60  f30f10480c           movss xmm1, dword ptr [eax + 0xc]
// 0062ce65  f30f5909             mulss xmm1, dword ptr [ecx]
// 0062ce69  f30f58c1             addss xmm0, xmm1
// 0062ce6d  f30f11420c           movss dword ptr [edx + 0xc], xmm0
// 0062ce72  f30f104010           movss xmm0, dword ptr [eax + 0x10]
// 0062ce77  f30f594110           mulss xmm0, dword ptr [ecx + 0x10]
// 0062ce7c  f30f104904           movss xmm1, dword ptr [ecx + 4]
// 0062ce81  f30f59480c           mulss xmm1, dword ptr [eax + 0xc]
// 0062ce86  f30f58c1             addss xmm0, xmm1
// 0062ce8a  f30f10491c           movss xmm1, dword ptr [ecx + 0x1c]
// 0062ce8f  f30f594814           mulss xmm1, dword ptr [eax + 0x14]
// 0062ce94  f30f58c1             addss xmm0, xmm1
// 0062ce98  f30f114210           movss dword ptr [edx + 0x10], xmm0
// 0062ce9d  f30f104010           movss xmm0, dword ptr [eax + 0x10]
// 0062cea2  f30f594114           mulss xmm0, dword ptr [ecx + 0x14]
// 0062cea7  f30f104908           movss xmm1, dword ptr [ecx + 8]
// 0062ceac  f30f59480c           mulss xmm1, dword ptr [eax + 0xc]
// 0062ceb1  f30f58c1             addss xmm0, xmm1
// 0062ceb5  f30f104920           movss xmm1, dword ptr [ecx + 0x20]
// 0062ceba  f30f594814           mulss xmm1, dword ptr [eax + 0x14]
// 0062cebf  f30f58c1             addss xmm0, xmm1
// 0062cec3  f30f114214           movss dword ptr [edx + 0x14], xmm0
// 0062cec8  f30f10401c           movss xmm0, dword ptr [eax + 0x1c]
// 0062cecd  f30f59410c           mulss xmm0, dword ptr [ecx + 0xc]
// 0062ced2  f30f104918           movss xmm1, dword ptr [ecx + 0x18]
// 0062ced7  f30f594820           mulss xmm1, dword ptr [eax + 0x20]
// 0062cedc  f30f58c1             addss xmm0, xmm1
// 0062cee0  f30f104818           movss xmm1, dword ptr [eax + 0x18]
// 0062cee5  f30f5909             mulss xmm1, dword ptr [ecx]
// 0062cee9  f30f58c1             addss xmm0, xmm1
// 0062ceed  f30f114218           movss dword ptr [edx + 0x18], xmm0
// 0062cef2  f30f10401c           movss xmm0, dword ptr [eax + 0x1c]
// 0062cef7  f30f594110           mulss xmm0, dword ptr [ecx + 0x10]
// 0062cefc  f30f104904           movss xmm1, dword ptr [ecx + 4]
// 0062cf01  f30f594818           mulss xmm1, dword ptr [eax + 0x18]
// 0062cf06  f30f58c1             addss xmm0, xmm1
// 0062cf0a  f30f10491c           movss xmm1, dword ptr [ecx + 0x1c]
// 0062cf0f  f30f594820           mulss xmm1, dword ptr [eax + 0x20]
// 0062cf14  f30f58c1             addss xmm0, xmm1
// 0062cf18  f30f11421c           movss dword ptr [edx + 0x1c], xmm0
// 0062cf1d  f30f10401c           movss xmm0, dword ptr [eax + 0x1c]
// 0062cf22  f30f104908           movss xmm1, dword ptr [ecx + 8]
// 0062cf27  f30f594818           mulss xmm1, dword ptr [eax + 0x18]
// 0062cf2c  f30f594114           mulss xmm0, dword ptr [ecx + 0x14]
// 0062cf31  f30f58c1             addss xmm0, xmm1
// 0062cf35  f30f104920           movss xmm1, dword ptr [ecx + 0x20]
// 0062cf3a  f30f594820           mulss xmm1, dword ptr [eax + 0x20]
// 0062cf3f  f30f58c1             addss xmm0, xmm1
// 0062cf43  f30f114220           movss dword ptr [edx + 0x20], xmm0
// 0062cf48  c3                   ret 
// library rbx2016-g3d/Matrix3.cpp (function ?_mul@Matrix3@G3D@@CAXABV12@0AAV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix3.cpp
