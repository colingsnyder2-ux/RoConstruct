# FlagStandService first draft (uncompiled)
Lease held for four hours, gpt-6.1-sol. Inbox events.jsonl absent.
RTTI descriptor 0095c088 -> COL 008b5b00 -> primary vtable 008461ec; secondary tables 008461dc, 008461d4, 008461cc, 008461bc, 008461ac, 0084619c, 0084618c, 0084617c, 0084616c.
Base chain: DescribedCreatable -> Reflection::Described -> FactoryProduct -> Instance; Service empty secondary base, matching donor.
Creator 005c12b0 pushes 0x14c to malloc and calls ctor 0062ccd0. ctor constructs list at +0x130 through 0061a200; observed list head +0x144 and size +0x148 prove 0x1c list storage.
0062ccd0 -> ??0FlagStandService@RBX@@QAE@XZ
0062c1c0 -> ??1FlagStandService@RBX@@UAE@XZ (writes all ten class vptrs: explicit empty virtual destructor)
0062c2c0 -> scalar deleting destructor; adjustor at 0062c2a0 subtracts 0x10.
0062bfc0 -> ?FindStandWithFlag@FlagStandService@RBX@@QAEPAVFlagStand@2@PAVFlag@2@@Z
0062c820 -> DescribedCreatable default ctor; 0062bad0 FactoryProduct default ctor; 0062ba70 FactoryProduct destructor.
005c0390 -> classDescriptor specialization; descriptor 00977db0 guard 00977e70 atexit 007fe730.
Found ctor by functions.jsonl string references, followed creator callers and base call_targets; all listed bodies inspected with native-asm. Unit labels frequently misidentify FlagStandService as FlagStand.
RegisterFlagStand and UnregisterFlagStand donor bodies supplied; target registration is inlined in 0062cf40; list remove helper 0062c0c0. FindClosestEmptyStandForFlag declaration retained from donor, body unresolved.
Recorder is a draft: remaining TU helper prefix rows, static descriptor bindings, FactoryProduct ctor and list helper bindings must be added by orchestrator after compilation reveals mangling. Archivable getset alias avoids changing shared Instance header; canonical propArchivable declaration should be proposed when its owner is available. Local minimal FlagStand declaration should be replaced by canonical header when available.
Check: python rebuild/2008-06/tests/record_native_flag_stand_service.py
No compilation, recorder, tests, or commits performed.
