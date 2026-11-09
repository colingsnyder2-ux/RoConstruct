// from server: 100% by auto
// roc 2010-06 007e5ba0  unit: CRobloxTreeCtrl  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e5ba0
//
// 007e5ba0  53                   push ebx
// 007e5ba1  8b1d54ba9e00         mov ebx, dword ptr [0x9eba54]
// 007e5ba7  56                   push esi
// 007e5ba8  57                   push edi
// 007e5ba9  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007e5bad  57                   push edi
// 007e5bae  8bf1                 mov esi, ecx
// 007e5bb0  8b4634               mov eax, dword ptr [esi + 0x34]
// 007e5bb3  8b4020               mov eax, dword ptr [eax + 0x20]
// 007e5bb6  6a02                 push 2
// 007e5bb8  680a110000           push 0x110a
// 007e5bbd  50                   push eax
// 007e5bbe  ffd3                 call ebx
// 007e5bc0  85c0                 test eax, eax
// 007e5bc2  7517                 jne 0x7e5bdb
// 007e5bc4  8b7634               mov esi, dword ptr [esi + 0x34]
// 007e5bc7  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 007e5bca  57                   push edi
// 007e5bcb  6a03                 push 3
// 007e5bcd  680a110000           push 0x110a
// 007e5bd2  51                   push ecx
// 007e5bd3  ffd3                 call ebx
// 007e5bd5  5f                   pop edi
// 007e5bd6  5e                   pop esi
// 007e5bd7  5b                   pop ebx
// 007e5bd8  c20400               ret 4
// 007e5bdb  8b16                 mov edx, dword ptr [esi]
// 007e5bdd  50                   push eax
// 007e5bde  8b4210               mov eax, dword ptr [edx + 0x10]
// 007e5be1  8bce                 mov ecx, esi
// 007e5be3  ffd0                 call eax
// 007e5be5  5f                   pop edi
// 007e5be6  5e                   pop esi
// 007e5be7  5b                   pop ebx
// 007e5be8  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?GetPrevItem@CXTTreeBase@@UBEPAU_TREEITEM@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
