// from server: 100% by auto
// roc 2010-06 008045b0  unit: CXTPPropExchangeArchive  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008045b0
//
// 008045b0  56                   push esi
// 008045b1  8bf1                 mov esi, ecx
// 008045b3  8b06                 mov eax, dword ptr [esi]
// 008045b5  8b9090000000         mov edx, dword ptr [eax + 0x90]
// 008045bb  ffd2                 call edx
// 008045bd  85c0                 test eax, eax
// 008045bf  7506                 jne 0x8045c7
// 008045c1  33c0                 xor eax, eax
// 008045c3  5e                   pop esi
// 008045c4  c20c00               ret 0xc
// 008045c7  837e2800             cmp dword ptr [esi + 0x28], 0
// 008045cb  7518                 jne 0x8045e5
// 008045cd  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008045d1  8b08                 mov ecx, dword ptr [eax]
// 008045d3  51                   push ecx
// 008045d4  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 008045d7  e8b48d1700           call 0x97d390
// 008045dc  b801000000           mov eax, 1
// 008045e1  5e                   pop esi
// 008045e2  c20c00               ret 0xc
// 008045e5  8b442410             mov eax, dword ptr [esp + 0x10]
// 008045e9  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 008045ec  6a00                 push 0
// 008045ee  8d562c               lea edx, [esi + 0x2c]
// 008045f1  52                   push edx
// 008045f2  50                   push eax
// 008045f3  e8928d1700           call 0x97d38a
// 008045f8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008045fc  8901                 mov dword ptr [ecx], eax
// 008045fe  85c0                 test eax, eax
// 00804600  74bf                 je 0x8045c1
// 00804602  b801000000           mov eax, 1
// 00804607  5e                   pop esi
// 00804608  c20c00               ret 0xc
// library xtp-13.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?ExchangeRuntimeClass@CXTPPropExchangeArchive@@UAEHPBDAAPAUCRuntimeClass@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
