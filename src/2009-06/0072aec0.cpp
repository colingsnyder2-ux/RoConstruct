// from server: 100% by auto
// roc 2009-06 0072aec0  unit: CXTPCommandBar  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0072aec0
//
// 0072aec0  56                   push esi
// 0072aec1  8bf1                 mov esi, ecx
// 0072aec3  85f6                 test esi, esi
// 0072aec5  7518                 jne 0x72aedf
// 0072aec7  68f0b87100           push 0x71b8f0
// 0072aecc  b99426a500           mov ecx, 0xa52694
// 0072aed1  e82a101200           call 0x84bf00
// 0072aed6  85c0                 test eax, eax
// 0072aed8  752d                 jne 0x72af07
// 0072aeda  e805defeff           call 0x718ce4
// 0072aedf  8b86a8000000         mov eax, dword ptr [esi + 0xa8]
// 0072aee5  85c0                 test eax, eax
// 0072aee7  751e                 jne 0x72af07
// 0072aee9  68f0b87100           push 0x71b8f0
// 0072aeee  b99426a500           mov ecx, 0xa52694
// 0072aef3  e808101200           call 0x84bf00
// 0072aef8  85c0                 test eax, eax
// 0072aefa  7505                 jne 0x72af01
// 0072aefc  e8e3ddfeff           call 0x718ce4
// 0072af01  8986a8000000         mov dword ptr [esi + 0xa8], eax
// 0072af07  5e                   pop esi
// 0072af08  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?GetMouseManager@CXTPCommandBars@@QBEPAVCXTPMouseManager@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
