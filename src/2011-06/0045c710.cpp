// from server: 100% by auto
// roc 2011-06 0045c710  unit: CRobloxModule  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0045c710
//
// 0045c710  53                   push ebx
// 0045c711  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0045c715  85db                 test ebx, ebx
// 0045c717  7509                 jne 0x45c722
// 0045c719  b803400080           mov eax, 0x80004003
// 0045c71e  5b                   pop ebx
// 0045c71f  c20400               ret 4
// 0045c722  56                   push esi
// 0045c723  57                   push edi
// 0045c724  33ff                 xor edi, edi
// 0045c726  397928               cmp dword ptr [ecx + 0x28], edi
// 0045c729  8d7128               lea esi, [ecx + 0x28]
// 0045c72c  751a                 jne 0x45c748
// 0045c72e  56                   push esi
// 0045c72f  6838e7a600           push 0xa6e738
// 0045c734  6a01                 push 1
// 0045c736  57                   push edi
// 0045c737  689816ac00           push 0xac1698
// 0045c73c  ff158030a400         call dword ptr [0xa43080]
// 0045c742  8bf8                 mov edi, eax
// 0045c744  85ff                 test edi, edi
// 0045c746  7c0e                 jl 0x45c756
// 0045c748  8b06                 mov eax, dword ptr [esi]
// 0045c74a  8903                 mov dword ptr [ebx], eax
// 0045c74c  8b36                 mov esi, dword ptr [esi]
// 0045c74e  8b0e                 mov ecx, dword ptr [esi]
// 0045c750  8b5104               mov edx, dword ptr [ecx + 4]
// 0045c753  56                   push esi
// 0045c754  ffd2                 call edx
// 0045c756  8bc7                 mov eax, edi
// 0045c758  5f                   pop edi
// 0045c759  5e                   pop esi
// 0045c75a  5b                   pop ebx
// 0045c75b  c20400               ret 4
// library atl-8.0/atl.cpp (function ?GetGITPtr@CAtlModule@ATL@@UAEJPAPAUIGlobalInterfaceTable@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
