// from server: 100% by auto
// roc 2011-06 00811000  unit: CXTPPaintManager  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00811000
//
// 00811000  8b542418             mov edx, dword ptr [esp + 0x18]
// 00811004  8b01                 mov eax, dword ptr [ecx]
// 00811006  8b8080000000         mov eax, dword ptr [eax + 0x80]
// 0081100c  53                   push ebx
// 0081100d  56                   push esi
// 0081100e  57                   push edi
// 0081100f  6a00                 push 0
// 00811011  6a01                 push 1
// 00811013  52                   push edx
// 00811014  8b542434             mov edx, dword ptr [esp + 0x34]
// 00811018  6a00                 push 0
// 0081101a  52                   push edx
// 0081101b  8b542434             mov edx, dword ptr [esp + 0x34]
// 0081101f  6a00                 push 0
// 00811021  52                   push edx
// 00811022  ffd0                 call eax
// 00811024  837c242c00           cmp dword ptr [esp + 0x2c], 0
// 00811029  50                   push eax
// 0081102a  742a                 je 0x811056
// 0081102c  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00811030  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00811034  51                   push ecx
// 00811035  56                   push esi
// 00811036  8d7902               lea edi, [ecx + 2]
// 00811039  57                   push edi
// 0081103a  8d5602               lea edx, [esi + 2]
// 0081103d  52                   push edx
// 0081103e  8d59fe               lea ebx, [ecx - 2]
// 00811041  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00811045  53                   push ebx
// 00811046  52                   push edx
// 00811047  51                   push ecx
// 00811048  e863f5ffff           call 0x8105b0
// 0081104d  83c420               add esp, 0x20
// 00811050  5f                   pop edi
// 00811051  5e                   pop esi
// 00811052  5b                   pop ebx
// 00811053  c22000               ret 0x20
// 00811056  8b542420             mov edx, dword ptr [esp + 0x20]
// 0081105a  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0081105e  8d7201               lea esi, [edx + 1]
// 00811061  56                   push esi
// 00811062  51                   push ecx
// 00811063  4a                   dec edx
// 00811064  52                   push edx
// 00811065  8d7902               lea edi, [ecx + 2]
// 00811068  57                   push edi
// 00811069  52                   push edx
// 0081106a  8b542428             mov edx, dword ptr [esp + 0x28]
// 0081106e  8d59fe               lea ebx, [ecx - 2]
// 00811071  53                   push ebx
// 00811072  52                   push edx
// 00811073  e838f5ffff           call 0x8105b0
// 00811078  83c420               add esp, 0x20
// 0081107b  5f                   pop edi
// 0081107c  5e                   pop esi
// 0081107d  5b                   pop ebx
// 0081107e  c22000               ret 0x20
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPPaintManager.cpp (function ?DrawDropDownGlyph@CXTPPaintManager@@UAEXPAVCDC@@PAVCXTPControl@@VCPoint@@HHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPPaintManager.cpp
