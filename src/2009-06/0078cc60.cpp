// from server: 100% by auto
// roc 2009-06 0078cc60  unit: CXTPPropertyGridView  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0078cc60
//
// 0078cc60  83ec10               sub esp, 0x10
// 0078cc63  53                   push ebx
// 0078cc64  56                   push esi
// 0078cc65  57                   push edi
// 0078cc66  8bf1                 mov esi, ecx
// 0078cc68  e889c0f8ff           call 0x718cf6
// 0078cc6d  68007f0000           push 0x7f00
// 0078cc72  6a00                 push 0
// 0078cc74  ff15b0ed8900         call dword ptr [0x89edb0]
// 0078cc7a  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0078cc7e  6a00                 push 0
// 0078cc80  6a00                 push 0
// 0078cc82  53                   push ebx
// 0078cc83  8d4c2418             lea ecx, [esp + 0x18]
// 0078cc87  8bf8                 mov edi, eax
// 0078cc89  e8a237feff           call 0x770430
// 0078cc8e  50                   push eax
// 0078cc8f  6800000080           push 0x80000000
// 0078cc94  6816d28a00           push 0x8ad216
// 0078cc99  6a00                 push 0
// 0078cc9b  6a00                 push 0
// 0078cc9d  57                   push edi
// 0078cc9e  6a00                 push 0
// 0078cca0  e859c7f8ff           call 0x7193fe
// 0078cca5  50                   push eax
// 0078cca6  6a00                 push 0
// 0078cca8  8bce                 mov ecx, esi
// 0078ccaa  e8fbbdf8ff           call 0x718aaa
// 0078ccaf  5f                   pop edi
// 0078ccb0  895e54               mov dword ptr [esi + 0x54], ebx
// 0078ccb3  5e                   pop esi
// 0078ccb4  5b                   pop ebx
// 0078ccb5  83c410               add esp, 0x10
// 0078ccb8  c20400               ret 4
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?Create@CXTPPropertyGridToolTip@@QAEXPAVCXTPPropertyGridView@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
