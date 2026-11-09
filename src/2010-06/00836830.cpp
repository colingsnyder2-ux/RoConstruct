// from server: 100% by auto
// roc 2010-06 00836830  unit: CXTPOffice2007Theme  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00836830
//
// 00836830  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00836834  56                   push esi
// 00836835  8b742408             mov esi, dword ptr [esp + 8]
// 00836839  8d4801               lea ecx, [eax + 1]
// 0083683c  51                   push ecx
// 0083683d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00836841  8d5101               lea edx, [ecx + 1]
// 00836844  52                   push edx
// 00836845  50                   push eax
// 00836846  51                   push ecx
// 00836847  8bce                 mov ecx, esi
// 00836849  e8466a1400           call 0x97d294
// 0083684e  8b442410             mov eax, dword ptr [esp + 0x10]
// 00836852  8d4801               lea ecx, [eax + 1]
// 00836855  51                   push ecx
// 00836856  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0083685a  51                   push ecx
// 0083685b  49                   dec ecx
// 0083685c  50                   push eax
// 0083685d  51                   push ecx
// 0083685e  8bce                 mov ecx, esi
// 00836860  e82f6a1400           call 0x97d294
// 00836865  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00836869  8b442418             mov eax, dword ptr [esp + 0x18]
// 0083686d  50                   push eax
// 0083686e  8d5101               lea edx, [ecx + 1]
// 00836871  52                   push edx
// 00836872  48                   dec eax
// 00836873  50                   push eax
// 00836874  51                   push ecx
// 00836875  8bce                 mov ecx, esi
// 00836877  e8186a1400           call 0x97d294
// 0083687c  8b442418             mov eax, dword ptr [esp + 0x18]
// 00836880  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00836884  50                   push eax
// 00836885  51                   push ecx
// 00836886  48                   dec eax
// 00836887  49                   dec ecx
// 00836888  50                   push eax
// 00836889  51                   push ecx
// 0083688a  8bce                 mov ecx, esi
// 0083688c  e8036a1400           call 0x97d294
// 00836891  5e                   pop esi
// 00836892  c21400               ret 0x14
// library xtp-13.2.1/Source\CommandBars\XTPOffice2003Theme.cpp (function ?ExcludeCorners@CXTPOffice2003Theme@@QAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPOffice2003Theme.cpp
