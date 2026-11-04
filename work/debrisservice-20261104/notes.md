# DebrisService first draft (uncompiled)
RTTI descriptor 00961500 names .?AVDebrisService@RBX@@.
Complete-object locators reference that descriptor: primary 008bd74c -> vtable 00849aec; secondary tables 00849ae0, 00849ad8, 00849ad0, 00849ac0, 00849ab0, 00849aa0, 00849a90, 00849a80, 00849a70. Located by scanning PE mapped words for COL descriptor references, then references to COL addresses. Constructor stores confirm all tables and offsets.
Primary table reference search identifies ctor 0063be90. Relative-call search finds creator 005c2e10: push 0x158 at 005c2e2f, malloc at 005c2e39, ctor call at 005c2e54.
Secondary deleting-dtor thunk 0063bfd0 adjusts this by 0x10 and jumps 0063c050; deleting dtor calls ordinary destructor 0063bfe0.
Ctor initializes queue at 0x130 (proxy allocation 4 bytes, zero stores +0x10/+0x14/+0x18/+0x1c), maxItems=300 at 0x150, timer=null at 0x154. Dtor calls queue cleanup 0063b6d0, deletes proxy, calls FactoryProduct dtor 0063b340.
Base chain: DebrisService -> DescribedCreatable -> Reflection::Described -> FactoryProduct -> Instance; additional empty Service base. Donor declaration copied with native sDebrisService array convention and explicit virtual destructor. Donor pad[8] retained, not independently inferred fields.
Open: compile/layout validation, queue ABI/helper bindings, remaining addItem/setMaxItems/cleanup/onServiceProvider implementations. No small leaf body independently identified. No compile, recorder, or tests run. Inbox events.jsonl absent. Lease retained.
