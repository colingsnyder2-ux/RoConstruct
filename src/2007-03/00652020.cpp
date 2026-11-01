// from server: 100% by auto
// roc 2007-03 00652020  unit: seg_00650000  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00652020
//
// 00652020  83790400             cmp dword ptr [ecx + 4], 0
// 00652024  7411                 je 0x652037
// 00652026  8b442404             mov eax, dword ptr [esp + 4]
// 0065202a  6a03                 push 3
// 0065202c  6a03                 push 3
// 0065202e  50                   push eax
// 0065202f  e8ccfcffff           call 0x651d00
// 00652034  c20400               ret 4
// 00652037  8b542404             mov edx, dword ptr [esp + 4]
// 0065203b  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 0065203e  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00652041  52                   push edx
// 00652042  6a09                 push 9
// 00652044  680b110000           push 0x110b
// 00652049  50                   push eax
// 0065204a  ff1550ee7700         call dword ptr [0x77ee50]
// 00652050  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?SelectItem@CXTPTreeBase@@QAEHPAU_TREEITEM@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
