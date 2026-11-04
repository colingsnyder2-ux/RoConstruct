# FlagStandService ctor 0062ccd0: shared-header proposal (orchestrator, 2026-11-04)

Target ctor body (donor tools/rbxgs/Client/App/v8datamodel/FlagStand.cpp:85): `setName("FlagStandService"); propArchivable.setValue(this, false);`
Our draft matches all 231 bytes except one virtual call slot: target `mov ecx,[0x973e8c]; mov edx,[ecx]; call [edx+0xc]`, ours `[edx+8]`.

1. reflection (owner): original `TypedPropertyDescriptor<T>::GetSet` has 4 virtual slots, donor property.h declares 3
   (isReadOnly, getValue, setValue). Evidence: GetSetImpl vtable 0x84593c (RTTI BoundPropGetSet<ClickDetector> of BoundProp<float,1>)
   = [0x60a2f0 "return false", 0x60a2f0 "return false", 0x62a130 getValue (ret 4), 0x5bd680 setValue (ret 8)].
   Proposal: a native reflection/property.h override adding one more `virtual bool ... const` before getValue (name unproven;
   two leading bool predicates both returning false). Rerun every proof that uses BoundProp/PropDescriptor GetSetImpl vtables.
2. v8tree/Instance.h (owner): declare `static Reflection::BoundProp<bool, 1> propArchivable;` (donor Instance.h:157);
   its GetSet pointer is loaded from 0x973e8c.
After both land, restore the donor ctor body and the ctor row in record_native_flag_stand_service.py.
