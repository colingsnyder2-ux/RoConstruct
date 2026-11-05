// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/Tool.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Tool.h"

#include "reflection/property.h"
#include "util/Name.h"
#include "v8datamodel/Mouse.h"
#include "v8datamodel/ToolMouseCommand.h"

namespace RBX {

const char sTool[] = "Tool";

static Reflection::PropDescriptor<Tool, int> prop_BackendToolState(
	"BackendToolState",
	"Appearance",
	&RBX::Tool::getBackendToolState,
	&RBX::Tool::setBackendToolState,
	Reflection::PropertyDescriptor::STREAMING
);

// STUB: WEBSERVICE 0x100cc300
void Tool::setBackendToolStateNoReplicate(int value)
{
	STUB(0x100cc300);
}

// STUB: WEBSERVICE 0x100cc480
void Tool::setBackendToolState(int value)
{
	if (value != backendToolState) {
		setBackendToolStateNoReplicate(value);
		raisePropertyChanged(prop_BackendToolState);
	}
}

} // namespace RBX

template const RBX::Name& RBX::Name::doDeclare<RBX::sToolMouseCommand>();
template const RBX::Name& RBX::Name::doDeclare<RBX::sMouse>();
template void RBX::Name::callDoDeclare<RBX::sToolMouseCommand>();
template void RBX::Name::callDoDeclare<RBX::sMouse>();
