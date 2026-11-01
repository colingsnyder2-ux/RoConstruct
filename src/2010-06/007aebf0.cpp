// from server: 100% by auto
// roc 2010-06 007aebf0  unit: CXTPPaintManager  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007aebf0
//
// 007aebf0  8b542418             mov edx, dword ptr [esp + 0x18]
// 007aebf4  8b01                 mov eax, dword ptr [ecx]
// 007aebf6  8b8080000000         mov eax, dword ptr [eax + 0x80]
// 007aebfc  53                   push ebx
// 007aebfd  56                   push esi
// 007aebfe  57                   push edi
// 007aebff  6a00                 push 0
// 007aec01  6a01                 push 1
// 007aec03  52                   push edx
// 007aec04  8b542434             mov edx, dword ptr [esp + 0x34]
// 007aec08  6a00                 push 0
// 007aec0a  52                   push edx
// 007aec0b  8b542434             mov edx, dword ptr [esp + 0x34]
// 007aec0f  6a00                 push 0
// 007aec11  52                   push edx
// 007aec12  ffd0                 call eax
// 007aec14  837c242c00           cmp dword ptr [esp + 0x2c], 0
// 007aec19  50                   push eax
// 007aec1a  742a                 je 0x7aec46
// 007aec1c  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007aec20  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 007aec24  51                   push ecx
// 007aec25  56                   push esi
// 007aec26  8d7902               lea edi, [ecx + 2]
// 007aec29  57                   push edi
// 007aec2a  8d5602               lea edx, [esi + 2]
// 007aec2d  52                   push edx
// 007aec2e  8d59fe               lea ebx, [ecx - 2]
// 007aec31  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007aec35  53                   push ebx
// 007aec36  52                   push edx
// 007aec37  51                   push ecx
// 007aec38  e863f5ffff           call 0x7ae1a0
// 007aec3d  83c420               add esp, 0x20
// 007aec40  5f                   pop edi
// 007aec41  5e                   pop esi
// 007aec42  5b                   pop ebx
// 007aec43  c22000               ret 0x20
// 007aec46  8b542420             mov edx, dword ptr [esp + 0x20]
// 007aec4a  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007aec4e  8d7201               lea esi, [edx + 1]
// 007aec51  56                   push esi
// 007aec52  51                   push ecx
// 007aec53  4a                   dec edx
// 007aec54  52                   push edx
// 007aec55  8d7902               lea edi, [ecx + 2]
// 007aec58  57                   push edi
// 007aec59  52                   push edx
// 007aec5a  8b542428             mov edx, dword ptr [esp + 0x28]
// 007aec5e  8d59fe               lea ebx, [ecx - 2]
// 007aec61  53                   push ebx
// 007aec62  52                   push edx
// 007aec63  e838f5ffff           call 0x7ae1a0
// 007aec68  83c420               add esp, 0x20
// 007aec6b  5f                   pop edi
// 007aec6c  5e                   pop esi
// 007aec6d  5b                   pop ebx
// 007aec6e  c22000               ret 0x20
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPPaintManager.cpp (function ?DrawDropDownGlyph@CXTPPaintManager@@UAEXPAVCDC@@PAVCXTPControl@@VCPoint@@HHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPPaintManager.cpp
