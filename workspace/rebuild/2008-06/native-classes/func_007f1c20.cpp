// Ownerless candidate: func_007f1c20
// 42 bytes, symbol: func_007f1c20
// Lease: ownerless:007f1c20 (RBX::unknown, colin, expires ~2026-11-19 08:45)
// Status: investigated but not matched - shape similar to already-proved function but no byte-exact proof
//
// Assembly:
//   push 0x82329c
//   push 0x823294
//   push 0x823258
//   push 0x823280
//   mov ecx, 0x970bb4
//   call 0x4a0150  ; fn_004a0150 [unit? RBX::Network::VClient::?$FactoryProduct]
//   push 0x7fbb20  ; fn_007fbb20 [unit? seg_007f0000]
//   call 0x6a17af  ; fn_006a17af [unit? ActiveDocView]
//   pop ecx
//   ret
//
// Mined analog (STATEMENT ORDER ONLY, NEVER COPY ITS STRUCTS):
//   extern int g_007f1c20_0;
//   extern int g_007f1c20_1;
//   extern int g_007f1c20_2;
//   extern int g_007f1c20_3;
//   roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
//   struct O_007f1c20 { int m(void*, void*, void*, void*); };
//   extern O_007f1c20 g_obj_007f1c20;
//   extern int g_tail_007f1c20;
//   void func_007f1c20()
//   {
//       g_obj_007f1c20.m((void*)&g_007f1c20_0, (void*)&g_007f1c20_1, (void*)&g_007f1c20_2, (void*)&g_007f1c20_3);
//       tail_fn_007f1c20(&g_tail_007f1c20);
//   }
//
// Investigation status:
//   - No RTTI descriptors referenced
//   - No recorded failures in the matching system
//   - 79% assembly diff match with 007f8be0 (already proved by colin, 100% match)
//     The proved function 007f8be0 has struct O_007f8be0 { int m(void*, void*, int, int); }
//     with method taking 2 ints instead of 2 void*s - types differ
//   - 3 nearest byte-exact matched functions (sim=0.86, size=37):
//       * 007f7e60: AppUnit628Explosion.cpp - RBX::Explosion unit (inactive)
//       * 007f3440: ChangeHistoryStart.cpp - FactoryProduct/SignalDescImpl (inactive)
//       * 007f2800: App__util__RunStateOwner__O2Ob2OyGFGSE.cpp - donor unit (inactive)
//   - Calls RBX::Network::VClient::?$FactoryProduct and ActiveDocView unit function
//   - Shares assembly shape with already-proved 007f8be0 but with type differences
//
// Conclusion:
//   This function has a similar assembly shape to an already-proved function
//   (007f8be0), but the types in the mined analog differ (void* vs int parameter types)
//   so no byte-exact proof can be claimed. The nearest candidates are all marked
//   inactive. Case parked with evidence. Do not invent class/fields/ABI.
//
// Lease: ownerless:007f1c20 -- RBX::unknown -- expires when lease released.