// from server: 100% by auto
// roc 2012-06 00404f50  unit: RBX::Soundscape::VSoundChannel::?$FactoryProduct::Creator  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00404f50
//
// 00404f50  56                   push esi
// 00404f51  8bf1                 mov esi, ecx
// 00404f53  8b06                 mov eax, dword ptr [esi]
// 00404f55  85c0                 test eax, eax
// 00404f57  740d                 je 0x404f66
// 00404f59  50                   push eax
// 00404f5a  ff150420b200         call dword ptr [0xb22004]
// 00404f60  c70600000000         mov dword ptr [esi], 0
// 00404f66  c7460400000000       mov dword ptr [esi + 4], 0
// 00404f6d  5e                   pop esi
// 00404f6e  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ??1CRegKey@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
