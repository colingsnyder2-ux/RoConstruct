// from server: 100% by auto
// roc 2009-06 007ee7c0  unit: VCEdit::?$CXTMaskEditT  size: 160 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007ee7c0
//
// 007ee7c0  8b542404             mov edx, dword ptr [esp + 4]
// 007ee7c4  0fb7c2               movzx eax, dx
// 007ee7c7  05e01effff           add eax, 0xffff1ee0
// 007ee7cc  83f80b               cmp eax, 0xb
// 007ee7cf  7755                 ja 0x7ee826
// 007ee7d1  ff248530e87e00       jmp dword ptr [eax*4 + 0x7ee830]
// 007ee7d8  e803faffff           call 0x7ee1e0
// 007ee7dd  b801000000           mov eax, 1
// 007ee7e2  c20800               ret 8
// 007ee7e5  e866eeffff           call 0x7ed650
// 007ee7ea  b801000000           mov eax, 1
// 007ee7ef  c20800               ret 8
// 007ee7f2  e849faffff           call 0x7ee240
// 007ee7f7  b801000000           mov eax, 1
// 007ee7fc  c20800               ret 8
// 007ee7ff  e85cf4ffff           call 0x7edc60
// 007ee804  b801000000           mov eax, 1
// 007ee809  c20800               ret 8
// 007ee80c  e8dfe6ffff           call 0x7ecef0
// 007ee811  b801000000           mov eax, 1
// 007ee816  c20800               ret 8
// 007ee819  e802f1ffff           call 0x7ed920
// 007ee81e  b801000000           mov eax, 1
// 007ee823  c20800               ret 8
// 007ee826  89542404             mov dword ptr [esp + 4], edx
// 007ee82a  e95fa3f2ff           jmp 0x718b8e
// 007ee82f  90                   nop 
// 007ee830  ffe7                 jmp edi
// 007ee832  7e00                 jle 0x7ee834
// 007ee834  26e87e00e5e7         call 0xe863e8b8
// 007ee83a  7e00                 jle 0x7ee83c
// 007ee83c  d8e7                 fsub st(7)
// 007ee83e  7e00                 jle 0x7ee840
// 007ee840  26e87e00f2e7         call 0xe870e8c4
// 007ee846  7e00                 jle 0x7ee848
// 007ee848  26e87e0026e8         call 0xe8a4e8cc
// 007ee84e  7e00                 jle 0x7ee850
// 007ee850  26e87e0026e8         call 0xe8a4e8d4
// 007ee856  7e00                 jle 0x7ee858
// 007ee858  19e8                 sbb eax, ebp
// 007ee85a  7e00                 jle 0x7ee85c
// 007ee85c  0ce8                 or al, 0xe8
// 007ee85e  7e00                 jle 0x7ee860
// library xtp-15.2.1/Source\Controls\Deprecated\XTFlatComboBox.cpp (function ?OnCommand@?$CXTPMaskEditT@VCEdit@@@@MAEHIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTFlatComboBox.cpp
