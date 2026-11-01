// from server: 100% by auto
// roc 2007-03 006de750  unit: seg_006d0000  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006de750
//
// 006de750  56                   push esi
// 006de751  8bf1                 mov esi, ecx
// 006de753  8b4620               mov eax, dword ptr [esi + 0x20]
// 006de756  85c0                 test eax, eax
// 006de758  7450                 je 0x6de7aa
// 006de75a  53                   push ebx
// 006de75b  57                   push edi
// 006de75c  8d7e58               lea edi, [esi + 0x58]
// 006de75f  57                   push edi
// 006de760  8d5e54               lea ebx, [esi + 0x54]
// 006de763  53                   push ebx
// 006de764  68b0000000           push 0xb0
// 006de769  50                   push eax
// 006de76a  ff1550ee7700         call dword ptr [0x77ee50]
// 006de770  8d8680000000         lea eax, [esi + 0x80]
// 006de776  50                   push eax
// 006de777  8bce                 mov ecx, esi
// 006de779  e866fff3ff           call 0x61e6e4
// 006de77e  8bce                 mov ecx, esi
// 006de780  e81beeffff           call 0x6dd5a0
// 006de785  837c241000           cmp dword ptr [esp + 0x10], 0
// 006de78a  741c                 je 0x6de7a8
// 006de78c  6a01                 push 1
// 006de78e  53                   push ebx
// 006de78f  8bce                 mov ecx, esi
// 006de791  e87afeffff           call 0x6de610
// 006de796  6a01                 push 1
// 006de798  57                   push edi
// 006de799  8bce                 mov ecx, esi
// 006de79b  e870feffff           call 0x6de610
// 006de7a0  8b1b                 mov ebx, dword ptr [ebx]
// 006de7a2  391f                 cmp dword ptr [edi], ebx
// 006de7a4  7d02                 jge 0x6de7a8
// 006de7a6  891f                 mov dword ptr [edi], ebx
// 006de7a8  5f                   pop edi
// 006de7a9  5b                   pop ebx
// 006de7aa  5e                   pop esi
// 006de7ab  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Deprecated\XTFlatComboBox.cpp (function ?GetMaskState@?$CXTPMaskEditT@VCEdit@@@@IAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTFlatComboBox.cpp
