// from server: 100% by auto
// roc 2010-06 007e6690  unit: CRobloxTreeCtrl  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e6690
//
// 007e6690  83790400             cmp dword ptr [ecx + 4], 0
// 007e6694  7411                 je 0x7e66a7
// 007e6696  8b442404             mov eax, dword ptr [esp + 4]
// 007e669a  6a03                 push 3
// 007e669c  6a03                 push 3
// 007e669e  50                   push eax
// 007e669f  e86cfcffff           call 0x7e6310
// 007e66a4  c20400               ret 4
// 007e66a7  8b542404             mov edx, dword ptr [esp + 4]
// 007e66ab  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 007e66ae  8b4120               mov eax, dword ptr [ecx + 0x20]
// 007e66b1  52                   push edx
// 007e66b2  6a09                 push 9
// 007e66b4  680b110000           push 0x110b
// 007e66b9  50                   push eax
// 007e66ba  ff1554ba9e00         call dword ptr [0x9eba54]
// 007e66c0  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?SelectItem@CXTTreeBase@@QAEHPAU_TREEITEM@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
