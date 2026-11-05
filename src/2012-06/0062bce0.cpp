// from server: 100% by auto
// roc 2012-06 0062bce0  unit: G3D::Sphere  size: 761 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062bce0
//
// 0062bce0  b801000000           mov eax, 1
// 0062bce5  84055886e200         test byte ptr [0xe28658], al
// 0062bceb  0f85d1020000         jne 0x62bfc2
// 0062bcf1  09055886e200         or dword ptr [0xe28658], eax
// 0062bcf7  0f57c0               xorps xmm0, xmm0
// 0062bcfa  f30f100d40c4b400     movss xmm1, dword ptr [0xb4c440]
// 0062bd02  84057085e200         test byte ptr [0xe28570], al
// 0062bd08  751e                 jne 0x62bd28
// 0062bd0a  09057085e200         or dword ptr [0xe28570], eax
// 0062bd10  f30f11056485e200     movss dword ptr [0xe28564], xmm0
// 0062bd18  f30f11056885e200     movss dword ptr [0xe28568], xmm0
// 0062bd20  f30f110d6c85e200     movss dword ptr [0xe2856c], xmm1
// 0062bd28  f30f10156485e200     movss xmm2, dword ptr [0xe28564]
// 0062bd30  f30f1115f885e200     movss dword ptr [0xe285f8], xmm2
// 0062bd38  f30f10156885e200     movss xmm2, dword ptr [0xe28568]
// 0062bd40  f30f1115fc85e200     movss dword ptr [0xe285fc], xmm2
// 0062bd48  f30f10156c85e200     movss xmm2, dword ptr [0xe2856c]
// 0062bd50  f30f11150086e200     movss dword ptr [0xe28600], xmm2
// 0062bd58  84055085e200         test byte ptr [0xe28550], al
// 0062bd5e  751e                 jne 0x62bd7e
// 0062bd60  09055085e200         or dword ptr [0xe28550], eax
// 0062bd66  f30f110d4485e200     movss dword ptr [0xe28544], xmm1
// 0062bd6e  f30f11054885e200     movss dword ptr [0xe28548], xmm0
// 0062bd76  f30f11054c85e200     movss dword ptr [0xe2854c], xmm0
// 0062bd7e  f30f10154485e200     movss xmm2, dword ptr [0xe28544]
// 0062bd86  f30f11150486e200     movss dword ptr [0xe28604], xmm2
// 0062bd8e  f30f10154885e200     movss xmm2, dword ptr [0xe28548]
// 0062bd96  f30f11150886e200     movss dword ptr [0xe28608], xmm2
// 0062bd9e  f30f10154c85e200     movss xmm2, dword ptr [0xe2854c]
// 0062bda6  f30f11150c86e200     movss dword ptr [0xe2860c], xmm2
// 0062bdae  84056085e200         test byte ptr [0xe28560], al
// 0062bdb4  751e                 jne 0x62bdd4
// 0062bdb6  09056085e200         or dword ptr [0xe28560], eax
// 0062bdbc  f30f11055485e200     movss dword ptr [0xe28554], xmm0
// 0062bdc4  f30f110d5885e200     movss dword ptr [0xe28558], xmm1
// 0062bdcc  f30f11055c85e200     movss dword ptr [0xe2855c], xmm0
// 0062bdd4  f30f10155485e200     movss xmm2, dword ptr [0xe28554]
// 0062bddc  f30f101d7027b600     movss xmm3, dword ptr [0xb62770]
// 0062bde4  f30f11151086e200     movss dword ptr [0xe28610], xmm2
// 0062bdec  f30f10155885e200     movss xmm2, dword ptr [0xe28558]
// 0062bdf4  f30f11151486e200     movss dword ptr [0xe28614], xmm2
// 0062bdfc  f30f10155c85e200     movss xmm2, dword ptr [0xe2855c]
// 0062be04  f30f11151886e200     movss dword ptr [0xe28618], xmm2
// 0062be0c  8405c085e200         test byte ptr [0xe285c0], al
// 0062be12  751e                 jne 0x62be32
// 0062be14  0905c085e200         or dword ptr [0xe285c0], eax
// 0062be1a  f30f110db485e200     movss dword ptr [0xe285b4], xmm1
// 0062be22  f30f111db885e200     movss dword ptr [0xe285b8], xmm3
// 0062be2a  f30f1105bc85e200     movss dword ptr [0xe285bc], xmm0
// 0062be32  f30f1015b485e200     movss xmm2, dword ptr [0xe285b4]
// 0062be3a  f30f11151c86e200     movss dword ptr [0xe2861c], xmm2
// 0062be42  f30f1015b885e200     movss xmm2, dword ptr [0xe285b8]
// 0062be4a  f30f11152086e200     movss dword ptr [0xe28620], xmm2
// 0062be52  f30f1015bc85e200     movss xmm2, dword ptr [0xe285bc]
// 0062be5a  f30f11152486e200     movss dword ptr [0xe28624], xmm2
// 0062be62  8405a085e200         test byte ptr [0xe285a0], al
// 0062be68  751e                 jne 0x62be88
// 0062be6a  0905a085e200         or dword ptr [0xe285a0], eax
// 0062be70  f30f110d9485e200     movss dword ptr [0xe28594], xmm1
// 0062be78  f30f110d9885e200     movss dword ptr [0xe28598], xmm1
// 0062be80  f30f11059c85e200     movss dword ptr [0xe2859c], xmm0
// 0062be88  f30f10159485e200     movss xmm2, dword ptr [0xe28594]
// 0062be90  f30f11152886e200     movss dword ptr [0xe28628], xmm2
// 0062be98  f30f10159885e200     movss xmm2, dword ptr [0xe28598]
// 0062bea0  f30f11152c86e200     movss dword ptr [0xe2862c], xmm2
// 0062bea8  f30f10159c85e200     movss xmm2, dword ptr [0xe2859c]
// 0062beb0  f30f11153086e200     movss dword ptr [0xe28630], xmm2
// 0062beb8  f30f10154c85b600     movss xmm2, dword ptr [0xb6854c]
// 0062bec0  84059085e200         test byte ptr [0xe28590], al
// 0062bec6  751e                 jne 0x62bee6
// 0062bec8  09059085e200         or dword ptr [0xe28590], eax
// 0062bece  f30f11058485e200     movss dword ptr [0xe28584], xmm0
// 0062bed6  f30f11158885e200     movss dword ptr [0xe28588], xmm2
// 0062bede  f30f110d8c85e200     movss dword ptr [0xe2858c], xmm1
// 0062bee6  f30f10258485e200     movss xmm4, dword ptr [0xe28584]
// 0062beee  f30f11253486e200     movss dword ptr [0xe28634], xmm4
// 0062bef6  f30f10258885e200     movss xmm4, dword ptr [0xe28588]
// 0062befe  f30f11253886e200     movss dword ptr [0xe28638], xmm4
// 0062bf06  f30f10258c85e200     movss xmm4, dword ptr [0xe2858c]
// 0062bf0e  f30f11253c86e200     movss dword ptr [0xe2863c], xmm4
// 0062bf16  84058085e200         test byte ptr [0xe28580], al
// 0062bf1c  751e                 jne 0x62bf3c
// 0062bf1e  09058085e200         or dword ptr [0xe28580], eax
// 0062bf24  f30f11157485e200     movss dword ptr [0xe28574], xmm2
// 0062bf2c  f30f11057885e200     movss dword ptr [0xe28578], xmm0
// 0062bf34  f30f110d7c85e200     movss dword ptr [0xe2857c], xmm1
// 0062bf3c  f30f100d7485e200     movss xmm1, dword ptr [0xe28574]
// 0062bf44  f30f110d4086e200     movss dword ptr [0xe28640], xmm1
// 0062bf4c  f30f100d7885e200     movss xmm1, dword ptr [0xe28578]
// 0062bf54  f30f110d4486e200     movss dword ptr [0xe28644], xmm1
// 0062bf5c  f30f100d7c85e200     movss xmm1, dword ptr [0xe2857c]
// 0062bf64  f30f110d4886e200     movss dword ptr [0xe28648], xmm1
// 0062bf6c  8405b085e200         test byte ptr [0xe285b0], al
// 0062bf72  751e                 jne 0x62bf92
// 0062bf74  0905b085e200         or dword ptr [0xe285b0], eax
// 0062bf7a  f30f111da485e200     movss dword ptr [0xe285a4], xmm3
// 0062bf82  f30f111da885e200     movss dword ptr [0xe285a8], xmm3
// 0062bf8a  f30f1105ac85e200     movss dword ptr [0xe285ac], xmm0
// 0062bf92  f30f1005a485e200     movss xmm0, dword ptr [0xe285a4]
// 0062bf9a  f30f11054c86e200     movss dword ptr [0xe2864c], xmm0
// 0062bfa2  f30f1005a885e200     movss xmm0, dword ptr [0xe285a8]
// 0062bfaa  f30f11055086e200     movss dword ptr [0xe28650], xmm0
// 0062bfb2  f30f1005ac85e200     movss xmm0, dword ptr [0xe285ac]
// 0062bfba  f30f11055486e200     movss dword ptr [0xe28654], xmm0
// 0062bfc2  6a07                 push 7
// 0062bfc4  6a00                 push 0
// 0062bfc6  e8f5000000           call 0x62c0c0
// 0062bfcb  8d0440               lea eax, [eax + eax*2]
// 0062bfce  83c408               add esp, 8
// 0062bfd1  8d0485f885e200       lea eax, [eax*4 + 0xe285f8]
// 0062bfd8  c3                   ret 
// library rbx2016-g3d/Color3.cpp (function ?wheelRandom@Color3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color3.cpp
