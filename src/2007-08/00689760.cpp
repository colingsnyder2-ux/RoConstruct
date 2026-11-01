// from server: 100% by auto
// roc 2007-08 00689760  unit: CXTPTabClientWnd::CWorkspace  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00689760
//
// 00689760  56                   push esi
// 00689761  8bf1                 mov esi, ecx
// 00689763  8b8e8c000000         mov ecx, dword ptr [esi + 0x8c]
// 00689769  8b01                 mov eax, dword ptr [ecx]
// 0068976b  8b9058010000         mov edx, dword ptr [eax + 0x158]
// 00689771  57                   push edi
// 00689772  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00689776  57                   push edi
// 00689777  ffd2                 call edx
// 00689779  83f8ff               cmp eax, -1
// 0068977c  7419                 je 0x689797
// 0068977e  8d88000000ff         lea ecx, [eax - 0x1000000]
// 00689784  83f907               cmp ecx, 7
// 00689787  7716                 ja 0x68979f
// 00689789  50                   push eax
// 0068978a  e8d1610700           call 0x6ff960
// 0068978f  83c404               add esp, 4
// 00689792  5f                   pop edi
// 00689793  5e                   pop esi
// 00689794  c20400               ret 4
// 00689797  57                   push edi
// 00689798  8bce                 mov ecx, esi
// 0068979a  e8c13c0700           call 0x6fd460
// 0068979f  5f                   pop edi
// 006897a0  5e                   pop esi
// 006897a1  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?GetItemColor@CWorkspace@CXTPTabClientWnd@@MBEKPBVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
