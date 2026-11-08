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
#include "util/MarshaledListener.h"
#include "v8tree/Instance.h"
#include "v8tree/PropertyChanged.h"
#include "util/RunStateOwner.h"

// RunService / RunState: ctor 00464b60, dtor 00464ce0, ??_G 00464e00, execute 00464d70 (+ catch 00464dbe).
template class RBX::MarshaledListener<RBX::RunService, RBX::RunState>::EventData;

// Instance / PropertyChanged: ctor 00464af0, dtor 00464bd0, ??_G 00464de0, execute 00464c60 (+ catch 00464cbd).
// The ctor and execute copy PropertyChanged inline in the original; with the current shared headers the copy is
// the declared out-of-line PropertyChanged(const PropertyChanged&) (see the receipt proposals).
template class RBX::MarshaledListener<RBX::Instance, RBX::PropertyChanged>::EventData;
