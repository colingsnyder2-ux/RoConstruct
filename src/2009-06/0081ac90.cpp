// from server: 100% by auto
// roc 2009-06 0081ac90  unit: CXTButtonThemeOffice2003  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0081ac90
//
// 0081ac90  56                   push esi
// 0081ac91  8bf1                 mov esi, ecx
// 0081ac93  8b4604               mov eax, dword ptr [esi + 4]
// 0081ac96  85c0                 test eax, eax
// 0081ac98  7414                 je 0x81acae
// 0081ac9a  50                   push eax
// 0081ac9b  ff1564ed8900         call dword ptr [0x89ed64]
// 0081aca1  8b442408             mov eax, dword ptr [esp + 8]
// 0081aca5  894604               mov dword ptr [esi + 4], eax
// 0081aca8  8bc6                 mov eax, esi
// 0081acaa  5e                   pop esi
// 0081acab  c20400               ret 4
// 0081acae  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0081acb2  894e04               mov dword ptr [esi + 4], ecx
// 0081acb5  8bc6                 mov eax, esi
// 0081acb7  5e                   pop esi
// 0081acb8  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Util\XTPUtil.cpp (function ??4CXTPIconHandle@@QAEAAV0@PAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Util/XTPUtil.cpp
