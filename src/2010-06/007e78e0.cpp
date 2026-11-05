// from server: 100% by auto
// roc 2010-06 007e78e0  unit: CRobloxTreeCtrl  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e78e0
//
// 007e78e0  8b4134               mov eax, dword ptr [ecx + 0x34]
// 007e78e3  8b4838               mov ecx, dword ptr [eax + 0x38]
// 007e78e6  85c9                 test ecx, ecx
// 007e78e8  7403                 je 0x7e78ed
// 007e78ea  51                   push ecx
// 007e78eb  eb0b                 jmp 0x7e78f8
// 007e78ed  8b4020               mov eax, dword ptr [eax + 0x20]
// 007e78f0  50                   push eax
// 007e78f1  ff154cba9e00         call dword ptr [0x9eba4c]
// 007e78f7  50                   push eax
// 007e78f8  e86d03fcff           call 0x7a7c6a
// 007e78fd  85c0                 test eax, eax
// 007e78ff  741c                 je 0x7e791d
// 007e7901  8b4020               mov eax, dword ptr [eax + 0x20]
// 007e7904  85c0                 test eax, eax
// 007e7906  7415                 je 0x7e791d
// 007e7908  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007e790c  51                   push ecx
// 007e790d  8b4904               mov ecx, dword ptr [ecx + 4]
// 007e7910  51                   push ecx
// 007e7911  6a4e                 push 0x4e
// 007e7913  50                   push eax
// 007e7914  ff1554ba9e00         call dword ptr [0x9eba54]
// 007e791a  c20400               ret 4
// 007e791d  33c0                 xor eax, eax
// 007e791f  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?SendNotify@CXTTreeBase@@MAEJPAUtagNMHDR@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
