// from server: 100% by auto
// roc 2010-06 00809660  unit: PAUHWND__::?$CArray  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00809660
//
// 00809660  56                   push esi
// 00809661  57                   push edi
// 00809662  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00809666  8bf1                 mov esi, ecx
// 00809668  85ff                 test edi, edi
// 0080966a  7d05                 jge 0x809671
// 0080966c  e8dbe5f9ff           call 0x7a7c4c
// 00809671  3b7e08               cmp edi, dword ptr [esi + 8]
// 00809674  7c0b                 jl 0x809681
// 00809676  6aff                 push -1
// 00809678  8d4701               lea eax, [edi + 1]
// 0080967b  50                   push eax
// 0080967c  e87f7cfdff           call 0x7e1300
// 00809681  8b542410             mov edx, dword ptr [esp + 0x10]
// 00809685  8b4e04               mov ecx, dword ptr [esi + 4]
// 00809688  8b02                 mov eax, dword ptr [edx]
// 0080968a  8904b9               mov dword ptr [ecx + edi*4], eax
// 0080968d  5f                   pop edi
// 0080968e  5e                   pop esi
// 0080968f  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTResize.cpp (function ?SetAtGrow@?$CArray@PAVCXTResizeItem@@AAPAV1@@@QAEXHAAPAVCXTResizeItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTResize.cpp
