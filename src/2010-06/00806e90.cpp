// from server: 100% by auto
// roc 2010-06 00806e90  unit: CXTPPropExchangeXMLNode  size: 304 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00806e90
//
// 00806e90  83ec20               sub esp, 0x20
// 00806e93  56                   push esi
// 00806e94  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00806e98  33c0                 xor eax, eax
// 00806e9a  57                   push edi
// 00806e9b  8b3d64a79e00         mov edi, dword ptr [0x9ea764]
// 00806ea1  89442418             mov dword ptr [esp + 0x18], eax
// 00806ea5  8944241c             mov dword ptr [esp + 0x1c], eax
// 00806ea9  89442420             mov dword ptr [esp + 0x20], eax
// 00806ead  89442424             mov dword ptr [esp + 0x24], eax
// 00806eb1  8d442424             lea eax, [esp + 0x24]
// 00806eb5  50                   push eax
// 00806eb6  8d4c2426             lea ecx, [esp + 0x26]
// 00806eba  51                   push ecx
// 00806ebb  8d542428             lea edx, [esp + 0x28]
// 00806ebf  52                   push edx
// 00806ec0  8d442426             lea eax, [esp + 0x26]
// 00806ec4  50                   push eax
// 00806ec5  8d4c242e             lea ecx, [esp + 0x2e]
// 00806ec9  51                   push ecx
// 00806eca  8d54242c             lea edx, [esp + 0x2c]
// 00806ece  52                   push edx
// 00806ecf  686408a600           push 0xa60864
// 00806ed4  56                   push esi
// 00806ed5  ffd7                 call edi
// 00806ed7  83c420               add esp, 0x20
// 00806eda  83f803               cmp eax, 3
// 00806edd  0f848d000000         je 0x806f70
// 00806ee3  83f805               cmp eax, 5
// 00806ee6  0f8484000000         je 0x806f70
// 00806eec  83f806               cmp eax, 6
// 00806eef  747f                 je 0x806f70
// 00806ef1  33c0                 xor eax, eax
// 00806ef3  89442418             mov dword ptr [esp + 0x18], eax
// 00806ef7  8944241c             mov dword ptr [esp + 0x1c], eax
// 00806efb  89442420             mov dword ptr [esp + 0x20], eax
// 00806eff  89442424             mov dword ptr [esp + 0x24], eax
// 00806f03  8d442424             lea eax, [esp + 0x24]
// 00806f07  50                   push eax
// 00806f08  8d4c2426             lea ecx, [esp + 0x26]
// 00806f0c  51                   push ecx
// 00806f0d  8d542428             lea edx, [esp + 0x28]
// 00806f11  52                   push edx
// 00806f12  685808a600           push 0xa60858
// 00806f17  56                   push esi
// 00806f18  ffd7                 call edi
// 00806f1a  83c414               add esp, 0x14
// 00806f1d  83f802               cmp eax, 2
// 00806f20  7405                 je 0x806f27
// 00806f22  83f803               cmp eax, 3
// 00806f25  7572                 jne 0x806f99
// 00806f27  0fb7442420           movzx eax, word ptr [esp + 0x20]
// 00806f2c  0fb7542422           movzx edx, word ptr [esp + 0x22]
// 00806f31  8bc8                 mov ecx, eax
// 00806f33  c1e104               shl ecx, 4
// 00806f36  2bc8                 sub ecx, eax
// 00806f38  8d048a               lea eax, [edx + ecx*4]
// 00806f3b  0fb7542424           movzx edx, word ptr [esp + 0x24]
// 00806f40  8bc8                 mov ecx, eax
// 00806f42  c1e104               shl ecx, 4
// 00806f45  2bc8                 sub ecx, eax
// 00806f47  8d048a               lea eax, [edx + ecx*4]
// 00806f4a  89442408             mov dword ptr [esp + 8], eax
// 00806f4e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00806f52  5f                   pop edi
// 00806f53  db442404             fild dword ptr [esp + 4]
// 00806f57  c7400800000000       mov dword ptr [eax + 8], 0
// 00806f5e  5e                   pop esi
// 00806f5f  dc355008a600         fdiv qword ptr [0xa60850]
// 00806f65  dd18                 fstp qword ptr [eax]
// 00806f67  b801000000           mov eax, 1
// 00806f6c  83c420               add esp, 0x20
// 00806f6f  c3                   ret 
// 00806f70  d9ee                 fldz 
// 00806f72  8d4c240c             lea ecx, [esp + 0xc]
// 00806f76  51                   push ecx
// 00806f77  dd5c2410             fstp qword ptr [esp + 0x10]
// 00806f7b  8d54241c             lea edx, [esp + 0x1c]
// 00806f7f  52                   push edx
// 00806f80  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00806f88  e8d37dc6ff           call 0x46ed60
// 00806f8d  83c408               add esp, 8
// 00806f90  f7d8                 neg eax
// 00806f92  1bc0                 sbb eax, eax
// 00806f94  83c001               add eax, 1
// 00806f97  7408                 je 0x806fa1
// 00806f99  5f                   pop edi
// 00806f9a  33c0                 xor eax, eax
// 00806f9c  5e                   pop esi
// 00806f9d  83c420               add esp, 0x20
// 00806fa0  c3                   ret 
// 00806fa1  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00806fa5  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00806fa9  8911                 mov dword ptr [ecx], edx
// 00806fab  8b542410             mov edx, dword ptr [esp + 0x10]
// 00806faf  895104               mov dword ptr [ecx + 4], edx
// 00806fb2  5f                   pop edi
// 00806fb3  894108               mov dword ptr [ecx + 8], eax
// 00806fb6  b801000000           mov eax, 1
// 00806fbb  5e                   pop esi
// 00806fbc  83c420               add esp, 0x20
// 00806fbf  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?ParseDateTimeISO8601@@YAHAAVCOleDateTime@ATL@@PBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
