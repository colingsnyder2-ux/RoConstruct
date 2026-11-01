// from server: 100% by auto
// roc 2007-03 00723650  unit: seg_00720000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00723650
//
// 00723650  56                   push esi
// 00723651  8bf1                 mov esi, ecx
// 00723653  8b4604               mov eax, dword ptr [esi + 4]
// 00723656  85c0                 test eax, eax
// 00723658  7414                 je 0x72366e
// 0072365a  50                   push eax
// 0072365b  ff15f8ed7700         call dword ptr [0x77edf8]
// 00723661  8b442408             mov eax, dword ptr [esp + 8]
// 00723665  894604               mov dword ptr [esi + 4], eax
// 00723668  8bc6                 mov eax, esi
// 0072366a  5e                   pop esi
// 0072366b  c20400               ret 4
// 0072366e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00723672  894e04               mov dword ptr [esi + 4], ecx
// 00723675  8bc6                 mov eax, esi
// 00723677  5e                   pop esi
// 00723678  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Util\XTPUtil.cpp (function ??4CXTPIconHandle@@QAEAAV0@PAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Util/XTPUtil.cpp
