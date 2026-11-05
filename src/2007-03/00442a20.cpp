// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/DebugSettings.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/DebugSettings.h"

#include "reflection/property.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8world/World.h"

namespace RBX {

const char sDebugSettings[] = "DebugSettings";

using namespace Reflection;

static PropDescriptor<DebugSettings, bool> prop_ValidatingDebug(
	"ValidatingDebug",
	"Errors",
	&RBX::DebugSettings::getValidatingDebug,
	&RBX::DebugSettings::setValidatingDebug
);

static EnumPropDescriptor<DebugSettings, Debugable::AssertAction> prop_assertAction(
	"AssertAction",
	"Errors",
	&RBX::DebugSettings::getAssertAction,
	&RBX::DebugSettings::setAssertAction
);

static EnumPropDescriptor<DebugSettings, DebugSettings::ErrorReporting> prop_errorReporting(
	"errorReporting",
	"Errors",
	&RBX::DebugSettings::getErrorReporting,
	&RBX::DebugSettings::setErrorReporting
);

static PropDescriptor<DebugSettings, bool> prop_AnchoredParts(
	"ShowAnchors",
	"Display",
	&RBX::DebugSettings::getShowAnchoredParts,
	&RBX::DebugSettings::setShowAnchoredParts
);

static PropDescriptor<DebugSettings, bool> prop_PartCoordinateFrames(
	"ShowPartCoords",
	"Display",
	&RBX::DebugSettings::getShowPartCoordinateFrames,
	&RBX::DebugSettings::setShowPartCoordinateFrames
);

static PropDescriptor<DebugSettings, bool> prop_ModelCoordinateFrames(
	"ShowModelCoords",
	"Display",
	&RBX::DebugSettings::getShowModelCoordinateFrames,
	&RBX::DebugSettings::setShowModelCoordinateFrames
);

static PropDescriptor<DebugSettings, bool> prop_WorldCoordinateFrames(
	"ShowWorldCoords",
	"Display",
	&RBX::DebugSettings::getShowWorldCoordinateFrames,
	&RBX::DebugSettings::setShowWorldCoordinateFrames
);

static PropDescriptor<DebugSettings, bool> prop_DisableEnvironmentalThrottle(
	"DisableEnvironmentalThrottle",
	"Display",
	&RBX::DebugSettings::getDisableEnvironmentalThrottle,
	&RBX::DebugSettings::setDisableEnvironmentalThrottle
);

// FUNCTION: WEBSERVICE 0x100b2d30
bool DebugSettings::getValidatingDebug() const
{
	return Debugable::validatingDebug;
}

// FUNCTION: WEBSERVICE 0x100b2d40
Debugable::AssertAction DebugSettings::getAssertAction() const
{
	return Debugable::assertAction;
}

// FUNCTION: WEBSERVICE 0x100b2d50
DebugSettings::ErrorReporting DebugSettings::getErrorReporting() const
{
	return errorReporting;
}

// FUNCTION: WEBSERVICE 0x100b2d60
bool DebugSettings::getShowAnchoredParts() const
{
	return PartInstance::showAnchoredParts;
}

// FUNCTION: WEBSERVICE 0x100b2d70
bool DebugSettings::getShowUnalignedParts() const
{
	return PartInstance::showUnalignedParts;
}

// FUNCTION: WEBSERVICE 0x100b2d80
bool DebugSettings::getShowPartCoordinateFrames() const
{
	return PartInstance::showPartCoord;
}

// FUNCTION: WEBSERVICE 0x100b2d90
bool DebugSettings::getShowModelCoordinateFrames() const
{
	return ModelInstance::showModelCoord;
}

// FUNCTION: WEBSERVICE 0x100b2da0
bool DebugSettings::getShowWorldCoordinateFrames() const
{
	return Workspace::showWorldCoord;
}

// FUNCTION: WEBSERVICE 0x100b2db0
bool DebugSettings::getDisableEnvironmentalThrottle() const
{
	return World::disableEnvironmentalThrottle;
}

namespace Reflection {

// FUNCTION: WEBSERVICE 0x100b3f40
template <>
EnumDesc<DebugSettings::ErrorReporting>::EnumDesc()
	: EnumDescriptor("ErrorReporting", typeid(DebugSettings::ErrorReporting))
{
	addPair(DebugSettings::DontReport, "DontReport");
	addPair(DebugSettings::Prompt, "Prompt");
	addPair(DebugSettings::Report, "Report");
}

// FUNCTION: WEBSERVICE 0x100b40c0
template <>
EnumDesc<Debugable::AssertAction>::EnumDesc() : EnumDescriptor("AssertAction", typeid(Debugable::AssertAction))
{
	addPair(Debugable::CrashOnAssert, "CrashOnAssert");
	addPair(Debugable::IgnoreAssert, "IgnoreAssert");
}

} // namespace Reflection

// FUNCTION: WEBSERVICE 0x100b51f0
void DebugSettings::setShowAnchoredParts(bool value)
{
	if (value != PartInstance::showAnchoredParts) {
		PartInstance::showAnchoredParts = value;
		raisePropertyChanged(prop_AnchoredParts);
	}
}

// FUNCTION: WEBSERVICE 0x100b5220
void DebugSettings::setShowUnalignedParts(bool value)
{
	if (value != PartInstance::showUnalignedParts) {
		PartInstance::showUnalignedParts = value;
		raisePropertyChanged(prop_PartCoordinateFrames);
	}
}

// FUNCTION: WEBSERVICE 0x100b5250
void DebugSettings::setShowPartCoordinateFrames(bool value)
{
	if (value != PartInstance::showPartCoord) {
		PartInstance::showPartCoord = value;
		raisePropertyChanged(prop_PartCoordinateFrames);
	}
}

// FUNCTION: WEBSERVICE 0x100b5280
void DebugSettings::setShowModelCoordinateFrames(bool value)
{
	if (value != ModelInstance::showModelCoord) {
		ModelInstance::showModelCoord = value;
		raisePropertyChanged(prop_ModelCoordinateFrames);
	}
}

// FUNCTION: WEBSERVICE 0x100b52b0
void DebugSettings::setShowWorldCoordinateFrames(bool value)
{
	if (value != Workspace::showWorldCoord) {
		Workspace::showWorldCoord = value;
		raisePropertyChanged(prop_WorldCoordinateFrames);
	}
}

// FUNCTION: WEBSERVICE 0x100b52e0
void DebugSettings::setDisableEnvironmentalThrottle(bool value)
{
	if (value != World::disableEnvironmentalThrottle) {
		World::disableEnvironmentalThrottle = value;
		raisePropertyChanged(prop_DisableEnvironmentalThrottle);
	}
}

// FUNCTION: WEBSERVICE 0x100b5310
void DebugSettings::setValidatingDebug(bool value)
{
	if (value != Debugable::validatingDebug) {
		Debugable::validatingDebug = value;
		raisePropertyChanged(prop_ValidatingDebug);
	}
}

// FUNCTION: WEBSERVICE 0x100b5340
void DebugSettings::setAssertAction(Debugable::AssertAction value)
{
	if (value != Debugable::assertAction) {
		Debugable::assertAction = value;
		raisePropertyChanged(prop_assertAction);
	}
}

// FUNCTION: WEBSERVICE 0x100b5370
void DebugSettings::setErrorReporting(ErrorReporting value)
{
	if (value != errorReporting) {
		errorReporting = value;
		raisePropertyChanged(prop_errorReporting);
	}
}
} // namespace RBX
