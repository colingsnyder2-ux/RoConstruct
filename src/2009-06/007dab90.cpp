// from server: 100% by auto
// roc 2009-06 007dab90  unit: CXTPDockingPaneSplitterContainer  size: 493 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007dab90
//
// 007dab90  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007dab94  83ec08               sub esp, 8
// 007dab97  48                   dec eax
// 007dab98  837c241800           cmp dword ptr [esp + 0x18], 0
// 007dab9d  56                   push esi
// 007dab9e  8b742410             mov esi, dword ptr [esp + 0x10]
// 007daba2  89442418             mov dword ptr [esp + 0x18], eax
// 007daba6  0f84e5000000         je 0x7dac91
// 007dabac  50                   push eax
// 007dabad  8b442418             mov eax, dword ptr [esp + 0x18]
// 007dabb1  83c0fc               add eax, -4
// 007dabb4  50                   push eax
// 007dabb5  8d4c240c             lea ecx, [esp + 0xc]
// 007dabb9  51                   push ecx
// 007dabba  8bce                 mov ecx, esi
// 007dabbc  e84dedf3ff           call 0x71990e
// 007dabc1  8b542418             mov edx, dword ptr [esp + 0x18]
// 007dabc5  8b442414             mov eax, dword ptr [esp + 0x14]
// 007dabc9  52                   push edx
// 007dabca  48                   dec eax
// 007dabcb  50                   push eax
// 007dabcc  8bce                 mov ecx, esi
// 007dabce  e835edf3ff           call 0x719908
// 007dabd3  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007dabd7  8b542414             mov edx, dword ptr [esp + 0x14]
// 007dabdb  83c1fd               add ecx, -3
// 007dabde  51                   push ecx
// 007dabdf  4a                   dec edx
// 007dabe0  52                   push edx
// 007dabe1  8d44240c             lea eax, [esp + 0xc]
// 007dabe5  50                   push eax
// 007dabe6  8bce                 mov ecx, esi
// 007dabe8  e821edf3ff           call 0x71990e
// 007dabed  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007dabf1  8b542414             mov edx, dword ptr [esp + 0x14]
// 007dabf5  83c104               add ecx, 4
// 007dabf8  51                   push ecx
// 007dabf9  4a                   dec edx
// 007dabfa  52                   push edx
// 007dabfb  8bce                 mov ecx, esi
// 007dabfd  e806edf3ff           call 0x719908
// 007dac02  8b442418             mov eax, dword ptr [esp + 0x18]
// 007dac06  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007dac0a  83c002               add eax, 2
// 007dac0d  50                   push eax
// 007dac0e  49                   dec ecx
// 007dac0f  51                   push ecx
// 007dac10  8d54240c             lea edx, [esp + 0xc]
// 007dac14  52                   push edx
// 007dac15  8bce                 mov ecx, esi
// 007dac17  e8f2ecf3ff           call 0x71990e
// 007dac1c  8b442418             mov eax, dword ptr [esp + 0x18]
// 007dac20  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007dac24  83c002               add eax, 2
// 007dac27  83c103               add ecx, 3
// 007dac2a  50                   push eax
// 007dac2b  51                   push ecx
// 007dac2c  8bce                 mov ecx, esi
// 007dac2e  e8d5ecf3ff           call 0x719908
// 007dac33  8b542418             mov edx, dword ptr [esp + 0x18]
// 007dac37  8b442414             mov eax, dword ptr [esp + 0x14]
// 007dac3b  83c2fe               add edx, -2
// 007dac3e  52                   push edx
// 007dac3f  83c003               add eax, 3
// 007dac42  50                   push eax
// 007dac43  8bce                 mov ecx, esi
// 007dac45  e8beecf3ff           call 0x719908
// 007dac4a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007dac4e  8b542414             mov edx, dword ptr [esp + 0x14]
// 007dac52  83c1fe               add ecx, -2
// 007dac55  51                   push ecx
// 007dac56  4a                   dec edx
// 007dac57  52                   push edx
// 007dac58  8bce                 mov ecx, esi
// 007dac5a  e8a9ecf3ff           call 0x719908
// 007dac5f  8b442418             mov eax, dword ptr [esp + 0x18]
// 007dac63  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007dac67  40                   inc eax
// 007dac68  50                   push eax
// 007dac69  49                   dec ecx
// 007dac6a  51                   push ecx
// 007dac6b  8d54240c             lea edx, [esp + 0xc]
// 007dac6f  52                   push edx
// 007dac70  8bce                 mov ecx, esi
// 007dac72  e897ecf3ff           call 0x71990e
// 007dac77  8b442418             mov eax, dword ptr [esp + 0x18]
// 007dac7b  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007dac7f  40                   inc eax
// 007dac80  50                   push eax
// 007dac81  83c103               add ecx, 3
// 007dac84  51                   push ecx
// 007dac85  8bce                 mov ecx, esi
// 007dac87  e87cecf3ff           call 0x719908
// 007dac8c  5e                   pop esi
// 007dac8d  83c408               add esp, 8
// 007dac90  c3                   ret 
// 007dac91  8b542414             mov edx, dword ptr [esp + 0x14]
// 007dac95  83c002               add eax, 2
// 007dac98  89442418             mov dword ptr [esp + 0x18], eax
// 007dac9c  48                   dec eax
// 007dac9d  50                   push eax
// 007dac9e  83c2fd               add edx, -3
// 007daca1  52                   push edx
// 007daca2  8d44240c             lea eax, [esp + 0xc]
// 007daca6  50                   push eax
// 007daca7  8bce                 mov ecx, esi
// 007daca9  e860ecf3ff           call 0x71990e
// 007dacae  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007dacb2  8b542414             mov edx, dword ptr [esp + 0x14]
// 007dacb6  49                   dec ecx
// 007dacb7  51                   push ecx
// 007dacb8  83c204               add edx, 4
// 007dacbb  52                   push edx
// 007dacbc  8bce                 mov ecx, esi
// 007dacbe  e845ecf3ff           call 0x719908
// 007dacc3  8b442418             mov eax, dword ptr [esp + 0x18]
// 007dacc7  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007daccb  48                   dec eax
// 007daccc  50                   push eax
// 007daccd  51                   push ecx
// 007dacce  8d54240c             lea edx, [esp + 0xc]
// 007dacd2  52                   push edx
// 007dacd3  8bce                 mov ecx, esi
// 007dacd5  e834ecf3ff           call 0x71990e
// 007dacda  8b442418             mov eax, dword ptr [esp + 0x18]
// 007dacde  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007dace2  83c003               add eax, 3
// 007dace5  50                   push eax
// 007dace6  51                   push ecx
// 007dace7  8bce                 mov ecx, esi
// 007dace9  e81aecf3ff           call 0x719908
// 007dacee  8b542418             mov edx, dword ptr [esp + 0x18]
// 007dacf2  8b442414             mov eax, dword ptr [esp + 0x14]
// 007dacf6  4a                   dec edx
// 007dacf7  52                   push edx
// 007dacf8  83c0fe               add eax, -2
// 007dacfb  50                   push eax
// 007dacfc  8d4c240c             lea ecx, [esp + 0xc]
// 007dad00  51                   push ecx
// 007dad01  8bce                 mov ecx, esi
// 007dad03  e806ecf3ff           call 0x71990e
// 007dad08  8b542418             mov edx, dword ptr [esp + 0x18]
// 007dad0c  8b442414             mov eax, dword ptr [esp + 0x14]
// 007dad10  83c2fa               add edx, -6
// 007dad13  52                   push edx
// 007dad14  83c0fe               add eax, -2
// 007dad17  50                   push eax
// 007dad18  8bce                 mov ecx, esi
// 007dad1a  e8e9ebf3ff           call 0x719908
// 007dad1f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007dad23  8b542414             mov edx, dword ptr [esp + 0x14]
// 007dad27  83c1fa               add ecx, -6
// 007dad2a  51                   push ecx
// 007dad2b  83c202               add edx, 2
// 007dad2e  52                   push edx
// 007dad2f  8bce                 mov ecx, esi
// 007dad31  e8d2ebf3ff           call 0x719908
// 007dad36  8b442418             mov eax, dword ptr [esp + 0x18]
// 007dad3a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007dad3e  48                   dec eax
// 007dad3f  83c102               add ecx, 2
// 007dad42  50                   push eax
// 007dad43  51                   push ecx
// 007dad44  8bce                 mov ecx, esi
// 007dad46  e8bdebf3ff           call 0x719908
// 007dad4b  8b542418             mov edx, dword ptr [esp + 0x18]
// 007dad4f  8b442414             mov eax, dword ptr [esp + 0x14]
// 007dad53  4a                   dec edx
// 007dad54  52                   push edx
// 007dad55  40                   inc eax
// 007dad56  50                   push eax
// 007dad57  8d4c240c             lea ecx, [esp + 0xc]
// 007dad5b  51                   push ecx
// 007dad5c  8bce                 mov ecx, esi
// 007dad5e  e8abebf3ff           call 0x71990e
// 007dad63  8b542418             mov edx, dword ptr [esp + 0x18]
// 007dad67  83c2fa               add edx, -6
// 007dad6a  8b442414             mov eax, dword ptr [esp + 0x14]
// 007dad6e  52                   push edx
// 007dad6f  40                   inc eax
// 007dad70  50                   push eax
// 007dad71  8bce                 mov ecx, esi
// 007dad73  e890ebf3ff           call 0x719908
// 007dad78  5e                   pop esi
// 007dad79  83c408               add esp, 8
// 007dad7c  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?DrawPinnButton@CXTPDockingPaneCaptionButton@@SAXPAVCDC@@VCPoint@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
