// from server: 100% by auto
// roc 2009-12 008b56c0  unit: CXTPDockingPaneSplitterContainer  size: 493 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008b56c0
//
// 008b56c0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008b56c4  83ec08               sub esp, 8
// 008b56c7  48                   dec eax
// 008b56c8  837c241800           cmp dword ptr [esp + 0x18], 0
// 008b56cd  56                   push esi
// 008b56ce  8b742410             mov esi, dword ptr [esp + 0x10]
// 008b56d2  89442418             mov dword ptr [esp + 0x18], eax
// 008b56d6  0f84e5000000         je 0x8b57c1
// 008b56dc  50                   push eax
// 008b56dd  8b442418             mov eax, dword ptr [esp + 0x18]
// 008b56e1  83c0fc               add eax, -4
// 008b56e4  50                   push eax
// 008b56e5  8d4c240c             lea ecx, [esp + 0xc]
// 008b56e9  51                   push ecx
// 008b56ea  8bce                 mov ecx, esi
// 008b56ec  e851f0f3ff           call 0x7f4742
// 008b56f1  8b542418             mov edx, dword ptr [esp + 0x18]
// 008b56f5  8b442414             mov eax, dword ptr [esp + 0x14]
// 008b56f9  52                   push edx
// 008b56fa  48                   dec eax
// 008b56fb  50                   push eax
// 008b56fc  8bce                 mov ecx, esi
// 008b56fe  e839f0f3ff           call 0x7f473c
// 008b5703  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008b5707  8b542414             mov edx, dword ptr [esp + 0x14]
// 008b570b  83c1fd               add ecx, -3
// 008b570e  51                   push ecx
// 008b570f  4a                   dec edx
// 008b5710  52                   push edx
// 008b5711  8d44240c             lea eax, [esp + 0xc]
// 008b5715  50                   push eax
// 008b5716  8bce                 mov ecx, esi
// 008b5718  e825f0f3ff           call 0x7f4742
// 008b571d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008b5721  8b542414             mov edx, dword ptr [esp + 0x14]
// 008b5725  83c104               add ecx, 4
// 008b5728  51                   push ecx
// 008b5729  4a                   dec edx
// 008b572a  52                   push edx
// 008b572b  8bce                 mov ecx, esi
// 008b572d  e80af0f3ff           call 0x7f473c
// 008b5732  8b442418             mov eax, dword ptr [esp + 0x18]
// 008b5736  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008b573a  83c002               add eax, 2
// 008b573d  50                   push eax
// 008b573e  49                   dec ecx
// 008b573f  51                   push ecx
// 008b5740  8d54240c             lea edx, [esp + 0xc]
// 008b5744  52                   push edx
// 008b5745  8bce                 mov ecx, esi
// 008b5747  e8f6eff3ff           call 0x7f4742
// 008b574c  8b442418             mov eax, dword ptr [esp + 0x18]
// 008b5750  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008b5754  83c002               add eax, 2
// 008b5757  83c103               add ecx, 3
// 008b575a  50                   push eax
// 008b575b  51                   push ecx
// 008b575c  8bce                 mov ecx, esi
// 008b575e  e8d9eff3ff           call 0x7f473c
// 008b5763  8b542418             mov edx, dword ptr [esp + 0x18]
// 008b5767  8b442414             mov eax, dword ptr [esp + 0x14]
// 008b576b  83c2fe               add edx, -2
// 008b576e  52                   push edx
// 008b576f  83c003               add eax, 3
// 008b5772  50                   push eax
// 008b5773  8bce                 mov ecx, esi
// 008b5775  e8c2eff3ff           call 0x7f473c
// 008b577a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008b577e  8b542414             mov edx, dword ptr [esp + 0x14]
// 008b5782  83c1fe               add ecx, -2
// 008b5785  51                   push ecx
// 008b5786  4a                   dec edx
// 008b5787  52                   push edx
// 008b5788  8bce                 mov ecx, esi
// 008b578a  e8adeff3ff           call 0x7f473c
// 008b578f  8b442418             mov eax, dword ptr [esp + 0x18]
// 008b5793  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008b5797  40                   inc eax
// 008b5798  50                   push eax
// 008b5799  49                   dec ecx
// 008b579a  51                   push ecx
// 008b579b  8d54240c             lea edx, [esp + 0xc]
// 008b579f  52                   push edx
// 008b57a0  8bce                 mov ecx, esi
// 008b57a2  e89beff3ff           call 0x7f4742
// 008b57a7  8b442418             mov eax, dword ptr [esp + 0x18]
// 008b57ab  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008b57af  40                   inc eax
// 008b57b0  50                   push eax
// 008b57b1  83c103               add ecx, 3
// 008b57b4  51                   push ecx
// 008b57b5  8bce                 mov ecx, esi
// 008b57b7  e880eff3ff           call 0x7f473c
// 008b57bc  5e                   pop esi
// 008b57bd  83c408               add esp, 8
// 008b57c0  c3                   ret 
// 008b57c1  8b542414             mov edx, dword ptr [esp + 0x14]
// 008b57c5  83c002               add eax, 2
// 008b57c8  89442418             mov dword ptr [esp + 0x18], eax
// 008b57cc  48                   dec eax
// 008b57cd  50                   push eax
// 008b57ce  83c2fd               add edx, -3
// 008b57d1  52                   push edx
// 008b57d2  8d44240c             lea eax, [esp + 0xc]
// 008b57d6  50                   push eax
// 008b57d7  8bce                 mov ecx, esi
// 008b57d9  e864eff3ff           call 0x7f4742
// 008b57de  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008b57e2  8b542414             mov edx, dword ptr [esp + 0x14]
// 008b57e6  49                   dec ecx
// 008b57e7  51                   push ecx
// 008b57e8  83c204               add edx, 4
// 008b57eb  52                   push edx
// 008b57ec  8bce                 mov ecx, esi
// 008b57ee  e849eff3ff           call 0x7f473c
// 008b57f3  8b442418             mov eax, dword ptr [esp + 0x18]
// 008b57f7  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008b57fb  48                   dec eax
// 008b57fc  50                   push eax
// 008b57fd  51                   push ecx
// 008b57fe  8d54240c             lea edx, [esp + 0xc]
// 008b5802  52                   push edx
// 008b5803  8bce                 mov ecx, esi
// 008b5805  e838eff3ff           call 0x7f4742
// 008b580a  8b442418             mov eax, dword ptr [esp + 0x18]
// 008b580e  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008b5812  83c003               add eax, 3
// 008b5815  50                   push eax
// 008b5816  51                   push ecx
// 008b5817  8bce                 mov ecx, esi
// 008b5819  e81eeff3ff           call 0x7f473c
// 008b581e  8b542418             mov edx, dword ptr [esp + 0x18]
// 008b5822  8b442414             mov eax, dword ptr [esp + 0x14]
// 008b5826  4a                   dec edx
// 008b5827  52                   push edx
// 008b5828  83c0fe               add eax, -2
// 008b582b  50                   push eax
// 008b582c  8d4c240c             lea ecx, [esp + 0xc]
// 008b5830  51                   push ecx
// 008b5831  8bce                 mov ecx, esi
// 008b5833  e80aeff3ff           call 0x7f4742
// 008b5838  8b542418             mov edx, dword ptr [esp + 0x18]
// 008b583c  8b442414             mov eax, dword ptr [esp + 0x14]
// 008b5840  83c2fa               add edx, -6
// 008b5843  52                   push edx
// 008b5844  83c0fe               add eax, -2
// 008b5847  50                   push eax
// 008b5848  8bce                 mov ecx, esi
// 008b584a  e8edeef3ff           call 0x7f473c
// 008b584f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008b5853  8b542414             mov edx, dword ptr [esp + 0x14]
// 008b5857  83c1fa               add ecx, -6
// 008b585a  51                   push ecx
// 008b585b  83c202               add edx, 2
// 008b585e  52                   push edx
// 008b585f  8bce                 mov ecx, esi
// 008b5861  e8d6eef3ff           call 0x7f473c
// 008b5866  8b442418             mov eax, dword ptr [esp + 0x18]
// 008b586a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008b586e  48                   dec eax
// 008b586f  83c102               add ecx, 2
// 008b5872  50                   push eax
// 008b5873  51                   push ecx
// 008b5874  8bce                 mov ecx, esi
// 008b5876  e8c1eef3ff           call 0x7f473c
// 008b587b  8b542418             mov edx, dword ptr [esp + 0x18]
// 008b587f  8b442414             mov eax, dword ptr [esp + 0x14]
// 008b5883  4a                   dec edx
// 008b5884  52                   push edx
// 008b5885  40                   inc eax
// 008b5886  50                   push eax
// 008b5887  8d4c240c             lea ecx, [esp + 0xc]
// 008b588b  51                   push ecx
// 008b588c  8bce                 mov ecx, esi
// 008b588e  e8afeef3ff           call 0x7f4742
// 008b5893  8b542418             mov edx, dword ptr [esp + 0x18]
// 008b5897  83c2fa               add edx, -6
// 008b589a  8b442414             mov eax, dword ptr [esp + 0x14]
// 008b589e  52                   push edx
// 008b589f  40                   inc eax
// 008b58a0  50                   push eax
// 008b58a1  8bce                 mov ecx, esi
// 008b58a3  e894eef3ff           call 0x7f473c
// 008b58a8  5e                   pop esi
// 008b58a9  83c408               add esp, 8
// 008b58ac  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?DrawPinnButton@CXTPDockingPaneCaptionButton@@SAXPAVCDC@@VCPoint@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
