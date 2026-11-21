// Inactive 2008-06 recovery: the MarshaledListener<..>::EventData rows CScriptEditor.cpp instantiates
// (application range 00460000..0046c000, between ~CScriptEditor's MarshaledListener members 00464970..00464a40
// and its ctor 00465010).
//
// CScriptEditor (native CScriptEditor.h, read-only) derives MarshaledListener<Instance, PropertyChanged> at +0xf0
// and MarshaledListener<RunService, RunState> at +0x114; their marshal bodies allocate the EventData objects
// (00464ea0 new(0x18) for Instance / PropertyChanged, 00464f80 new(0x14) for RunService / RunState; checked by the
// recorder's layout probe). Vtables 0081b390 / 0081b39c (RTTI), base EventDataBase (vtable 0080f860).
// The template bodies come from the native util/MarshaledListener.h (read-only); this unit only names the two
// specialisations the binary emits here.
// BLOCKED (whole unit, compiler error since the auto-save commit 742ee5c22a): util/MarshaledListener.h has a stray
// `}` (plus a duplicated INFERRED comment) after releaseMarshalWindow that closes namespace RBX before the
// MarshaledListener template (C2143 at its line 26). Proposal to the util/ header owner: delete those added lines.
// Batch 26 trial with that one fix in a scratch copy: EventData ctor 00464af0 IDENTICAL (with the inline copy
// constructors below); onEvent 004649f0 parked (see the instantiation comment).
#include "util/MarshaledListener.h"
#include "v8tree/Instance.h"
#include "v8tree/PropertyChanged.h"
#include "util/RunStateOwner.h"

namespace RBX
{
	// INFERRED: the original copies PropertyChanged inline in EventData's ctor 00464af0 (two dword moves from the
	// argument into +0x10/+0x14) and in execute 00464c60; v8tree/PropertyChanged.h only declares the copy constructor,
	// so it is defined unit-locally as in NotifierRaiseTemplatesB2008.cpp (implicit member-wise copy of `property`).
	// INFERRED: same evidence; reflection/property.h only declares Property's copy constructor (ConstProperty's is inline).
	inline Reflection::Property::Property(const Property& other) : ConstProperty(other) {}
	inline PropertyChanged::PropertyChanged(const PropertyChanged& other) : property(other.property) {}
}

// RunService / RunState: ctor 00464b60, dtor 00464ce0, ??_G 00464e00, execute 00464d70 (+ catch 00464dbe).
template class RBX::MarshaledListener<RBX::RunService, RBX::RunState>::EventData;

// Instance / PropertyChanged: ctor 00464af0, dtor 00464bd0, ??_G 00464de0, execute 00464c60 (+ catch 00464cbd).
// The ctor and execute copy PropertyChanged inline in the original (unit-local inline copy constructor above).
// onEvent 004649f0 (67 B) is the util/MarshaledListener.h inline body, emitted by the explicit instantiation below.
// 004649f0 PARKED (3 rejected): the original reserves a slot (`push ecx`), loads both event dwords before `sub esp, 8`
// and stores the argument temporary's address (`mov [esp+0x10], esp`); rejected: inline Property/PropertyChanged copies
// (61 B, no slot), header onEvent without throw() (same 61 B), Property copy through getDescriptor()/getInstance() (85 B).
template class RBX::MarshaledListener<RBX::Instance, RBX::PropertyChanged>::EventData;

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class RBX::MarshaledListener<RBX::Instance,RBX::PropertyChanged,RBX::Instance,RBX::PropertyChanged>;
template class RBX::MarshaledListener<RBX::RunService,enum RBX::RunState,RBX::RunService,enum RBX::RunState>;
template class boost::shared_ptr<RBX::Instance const >;
template class boost::shared_ptr<RBX::RunService const >;
template class std::_Vector_const_iterator<RBX::MarshaledListener<RBX::Instance,RBX::PropertyChanged,RBX::Instance,RBX::PropertyChanged>::EventData *,std::allocator<RBX::MarshaledListener<RBX::Instance,RBX::PropertyChanged,RBX::Instance,RBX::PropertyChanged>::EventData *> >;
template class std::_Vector_const_iterator<RBX::MarshaledListener<RBX::RunService,enum RBX::RunState,RBX::RunService,enum RBX::RunState>::EventData *,std::allocator<RBX::MarshaledListener<RBX::RunService,enum RBX::RunState,RBX::RunService,enum RBX::RunState>::EventData *> >;
template class std::_Vector_iterator<RBX::MarshaledListener<RBX::Instance,RBX::PropertyChanged,RBX::Instance,RBX::PropertyChanged>::EventData *,std::allocator<RBX::MarshaledListener<RBX::Instance,RBX::PropertyChanged,RBX::Instance,RBX::PropertyChanged>::EventData *> >;
template class std::_Vector_iterator<RBX::MarshaledListener<RBX::RunService,enum RBX::RunState,RBX::RunService,enum RBX::RunState>::EventData *,std::allocator<RBX::MarshaledListener<RBX::RunService,enum RBX::RunState,RBX::RunService,enum RBX::RunState>::EventData *> >;
template class std::vector<RBX::MarshaledListener<RBX::Instance,RBX::PropertyChanged,RBX::Instance,RBX::PropertyChanged>::EventData *,std::allocator<RBX::MarshaledListener<RBX::Instance,RBX::PropertyChanged,RBX::Instance,RBX::PropertyChanged>::EventData *> >;
template class std::vector<RBX::MarshaledListener<RBX::RunService,enum RBX::RunState,RBX::RunService,enum RBX::RunState>::EventData *,std::allocator<RBX::MarshaledListener<RBX::RunService,enum RBX::RunState,RBX::RunService,enum RBX::RunState>::EventData *> >;
