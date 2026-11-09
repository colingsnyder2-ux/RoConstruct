// from server: 100% by auto
// roc 2010-06 008697b0  unit: CXTPDockingPaneSplitterContainer  size: 493 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008697b0
//
// 008697b0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008697b4  83ec08               sub esp, 8
// 008697b7  48                   dec eax
// 008697b8  837c241800           cmp dword ptr [esp + 0x18], 0
// 008697bd  56                   push esi
// 008697be  8b742410             mov esi, dword ptr [esp + 0x10]
// 008697c2  89442418             mov dword ptr [esp + 0x18], eax
// 008697c6  0f84e5000000         je 0x8698b1
// 008697cc  50                   push eax
// 008697cd  8b442418             mov eax, dword ptr [esp + 0x18]
// 008697d1  83c0fc               add eax, -4
// 008697d4  50                   push eax
// 008697d5  8d4c240c             lea ecx, [esp + 0xc]
// 008697d9  51                   push ecx
// 008697da  8bce                 mov ecx, esi
// 008697dc  e89bf0f3ff           call 0x7a887c
// 008697e1  8b542418             mov edx, dword ptr [esp + 0x18]
// 008697e5  8b442414             mov eax, dword ptr [esp + 0x14]
// 008697e9  52                   push edx
// 008697ea  48                   dec eax
// 008697eb  50                   push eax
// 008697ec  8bce                 mov ecx, esi
// 008697ee  e883f0f3ff           call 0x7a8876
// 008697f3  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008697f7  8b542414             mov edx, dword ptr [esp + 0x14]
// 008697fb  83c1fd               add ecx, -3
// 008697fe  51                   push ecx
// 008697ff  4a                   dec edx
// 00869800  52                   push edx
// 00869801  8d44240c             lea eax, [esp + 0xc]
// 00869805  50                   push eax
// 00869806  8bce                 mov ecx, esi
// 00869808  e86ff0f3ff           call 0x7a887c
// 0086980d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00869811  8b542414             mov edx, dword ptr [esp + 0x14]
// 00869815  83c104               add ecx, 4
// 00869818  51                   push ecx
// 00869819  4a                   dec edx
// 0086981a  52                   push edx
// 0086981b  8bce                 mov ecx, esi
// 0086981d  e854f0f3ff           call 0x7a8876
// 00869822  8b442418             mov eax, dword ptr [esp + 0x18]
// 00869826  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0086982a  83c002               add eax, 2
// 0086982d  50                   push eax
// 0086982e  49                   dec ecx
// 0086982f  51                   push ecx
// 00869830  8d54240c             lea edx, [esp + 0xc]
// 00869834  52                   push edx
// 00869835  8bce                 mov ecx, esi
// 00869837  e840f0f3ff           call 0x7a887c
// 0086983c  8b442418             mov eax, dword ptr [esp + 0x18]
// 00869840  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00869844  83c002               add eax, 2
// 00869847  83c103               add ecx, 3
// 0086984a  50                   push eax
// 0086984b  51                   push ecx
// 0086984c  8bce                 mov ecx, esi
// 0086984e  e823f0f3ff           call 0x7a8876
// 00869853  8b542418             mov edx, dword ptr [esp + 0x18]
// 00869857  8b442414             mov eax, dword ptr [esp + 0x14]
// 0086985b  83c2fe               add edx, -2
// 0086985e  52                   push edx
// 0086985f  83c003               add eax, 3
// 00869862  50                   push eax
// 00869863  8bce                 mov ecx, esi
// 00869865  e80cf0f3ff           call 0x7a8876
// 0086986a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0086986e  8b542414             mov edx, dword ptr [esp + 0x14]
// 00869872  83c1fe               add ecx, -2
// 00869875  51                   push ecx
// 00869876  4a                   dec edx
// 00869877  52                   push edx
// 00869878  8bce                 mov ecx, esi
// 0086987a  e8f7eff3ff           call 0x7a8876
// 0086987f  8b442418             mov eax, dword ptr [esp + 0x18]
// 00869883  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00869887  40                   inc eax
// 00869888  50                   push eax
// 00869889  49                   dec ecx
// 0086988a  51                   push ecx
// 0086988b  8d54240c             lea edx, [esp + 0xc]
// 0086988f  52                   push edx
// 00869890  8bce                 mov ecx, esi
// 00869892  e8e5eff3ff           call 0x7a887c
// 00869897  8b442418             mov eax, dword ptr [esp + 0x18]
// 0086989b  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0086989f  40                   inc eax
// 008698a0  50                   push eax
// 008698a1  83c103               add ecx, 3
// 008698a4  51                   push ecx
// 008698a5  8bce                 mov ecx, esi
// 008698a7  e8caeff3ff           call 0x7a8876
// 008698ac  5e                   pop esi
// 008698ad  83c408               add esp, 8
// 008698b0  c3                   ret 
// 008698b1  8b542414             mov edx, dword ptr [esp + 0x14]
// 008698b5  83c002               add eax, 2
// 008698b8  89442418             mov dword ptr [esp + 0x18], eax
// 008698bc  48                   dec eax
// 008698bd  50                   push eax
// 008698be  83c2fd               add edx, -3
// 008698c1  52                   push edx
// 008698c2  8d44240c             lea eax, [esp + 0xc]
// 008698c6  50                   push eax
// 008698c7  8bce                 mov ecx, esi
// 008698c9  e8aeeff3ff           call 0x7a887c
// 008698ce  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008698d2  8b542414             mov edx, dword ptr [esp + 0x14]
// 008698d6  49                   dec ecx
// 008698d7  51                   push ecx
// 008698d8  83c204               add edx, 4
// 008698db  52                   push edx
// 008698dc  8bce                 mov ecx, esi
// 008698de  e893eff3ff           call 0x7a8876
// 008698e3  8b442418             mov eax, dword ptr [esp + 0x18]
// 008698e7  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008698eb  48                   dec eax
// 008698ec  50                   push eax
// 008698ed  51                   push ecx
// 008698ee  8d54240c             lea edx, [esp + 0xc]
// 008698f2  52                   push edx
// 008698f3  8bce                 mov ecx, esi
// 008698f5  e882eff3ff           call 0x7a887c
// 008698fa  8b442418             mov eax, dword ptr [esp + 0x18]
// 008698fe  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00869902  83c003               add eax, 3
// 00869905  50                   push eax
// 00869906  51                   push ecx
// 00869907  8bce                 mov ecx, esi
// 00869909  e868eff3ff           call 0x7a8876
// 0086990e  8b542418             mov edx, dword ptr [esp + 0x18]
// 00869912  8b442414             mov eax, dword ptr [esp + 0x14]
// 00869916  4a                   dec edx
// 00869917  52                   push edx
// 00869918  83c0fe               add eax, -2
// 0086991b  50                   push eax
// 0086991c  8d4c240c             lea ecx, [esp + 0xc]
// 00869920  51                   push ecx
// 00869921  8bce                 mov ecx, esi
// 00869923  e854eff3ff           call 0x7a887c
// 00869928  8b542418             mov edx, dword ptr [esp + 0x18]
// 0086992c  8b442414             mov eax, dword ptr [esp + 0x14]
// 00869930  83c2fa               add edx, -6
// 00869933  52                   push edx
// 00869934  83c0fe               add eax, -2
// 00869937  50                   push eax
// 00869938  8bce                 mov ecx, esi
// 0086993a  e837eff3ff           call 0x7a8876
// 0086993f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00869943  8b542414             mov edx, dword ptr [esp + 0x14]
// 00869947  83c1fa               add ecx, -6
// 0086994a  51                   push ecx
// 0086994b  83c202               add edx, 2
// 0086994e  52                   push edx
// 0086994f  8bce                 mov ecx, esi
// 00869951  e820eff3ff           call 0x7a8876
// 00869956  8b442418             mov eax, dword ptr [esp + 0x18]
// 0086995a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0086995e  48                   dec eax
// 0086995f  83c102               add ecx, 2
// 00869962  50                   push eax
// 00869963  51                   push ecx
// 00869964  8bce                 mov ecx, esi
// 00869966  e80beff3ff           call 0x7a8876
// 0086996b  8b542418             mov edx, dword ptr [esp + 0x18]
// 0086996f  8b442414             mov eax, dword ptr [esp + 0x14]
// 00869973  4a                   dec edx
// 00869974  52                   push edx
// 00869975  40                   inc eax
// 00869976  50                   push eax
// 00869977  8d4c240c             lea ecx, [esp + 0xc]
// 0086997b  51                   push ecx
// 0086997c  8bce                 mov ecx, esi
// 0086997e  e8f9eef3ff           call 0x7a887c
// 00869983  8b542418             mov edx, dword ptr [esp + 0x18]
// 00869987  83c2fa               add edx, -6
// 0086998a  8b442414             mov eax, dword ptr [esp + 0x14]
// 0086998e  52                   push edx
// 0086998f  40                   inc eax
// 00869990  50                   push eax
// 00869991  8bce                 mov ecx, esi
// 00869993  e8deeef3ff           call 0x7a8876
// 00869998  5e                   pop esi
// 00869999  83c408               add esp, 8
// 0086999c  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?DrawPinnButton@CXTPDockingPaneCaptionButton@@SAXPAVCDC@@VCPoint@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
