# ClickDetector first draft (untested)
Lease retained. No compilation, recorder, or tests run. Inbox events.jsonl absent. Donor include search found no declaration.

RTTI type descriptor 0095b50c -> COL 008b4d44 (offset zero) -> vtable 00845afc. Creator TD 0094e640 -> COL 0089fc18 -> vtable 0083882c -> 005c0be0 -> allocation helper 005c0b60. At 005c0b7f push 0x14c precedes malloc; 005c0ba4 calls ctor 006297e0.

Base chain: ClickDetector -> DescribedCreatable -> Reflection::Described -> FactoryProduct -> Instance; secondary IRenderable at 0x130 (ctor initializes indices at 134/138 to -1, bucket 13c to zero; destructor calls 0047d410 on +130).
Vtables by offset: 0:845afc,10:845af0,14:845ae8,20:845ae0,24:845ad0,44:845ac0,64:845ab0,84:845aa0,a4:845a90,c4:845a80,130:845a68.

006297e0 -> ??0ClickDetector@RBX@@QAE@XZ
006299a0 -> ??1ClickDetector@RBX@@UAE@XZ
00629a50 scalar deleting destructor; secondary thunks 629920/629990 lead here.
Ctor calls 6296e0 base ctor, initializes dword 140=0, float 144=32 (833eac), sets name from 845b3c. Dtor calls FactoryProduct destructor 629340.

Open: bool/float descriptor accessors not yet located; field 148 identity and lifetime unresolved. Tail byte array is allocation-only placeholder, not a recovered member. Render virtual slots point to 60a2f0 and 565950 and need recovery. askSetParent 6298d0 performs two RTTI casts (TDs 92dd50,932a40); declaration only. Recorder currently includes ctor/dtor only, no exactness claimed. Replace tail placeholder after accessor/static-registration evidence; recorder expected to expose unresolved virtual links until recovered.
