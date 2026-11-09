// from server: 100% by auto
// roc 2010-06 0081dc20  unit: CXTPPropertyGridView  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081dc20
//
// 0081dc20  56                   push esi
// 0081dc21  57                   push edi
// 0081dc22  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0081dc26  8d44240c             lea eax, [esp + 0xc]
// 0081dc2a  50                   push eax
// 0081dc2b  8bf1                 mov esi, ecx
// 0081dc2d  c70700000000         mov dword ptr [edi], 0
// 0081dc33  e8b81efdff           call 0x7efaf0
// 0081dc38  85c0                 test eax, eax
// 0081dc3a  7f0a                 jg 0x81dc46
// 0081dc3c  5f                   pop edi
// 0081dc3d  b857000780           mov eax, 0x80070057
// 0081dc42  5e                   pop esi
// 0081dc43  c21400               ret 0x14
// 0081dc46  48                   dec eax
// 0081dc47  50                   push eax
// 0081dc48  8d4eac               lea ecx, [esi - 0x54]
// 0081dc4b  e8c0edffff           call 0x81ca10
// 0081dc50  85c0                 test eax, eax
// 0081dc52  74e8                 je 0x81dc3c
// 0081dc54  6a01                 push 1
// 0081dc56  8bc8                 mov ecx, eax
// 0081dc58  e815f11500           call 0x97cd72
// 0081dc5d  8907                 mov dword ptr [edi], eax
// 0081dc5f  5f                   pop edi
// 0081dc60  33c0                 xor eax, eax
// 0081dc62  5e                   pop esi
// 0081dc63  c21400               ret 0x14
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?GetAccessibleChild@CXTPPropertyGridView@@MAEJUtagVARIANT@@PAPAUIDispatch@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
