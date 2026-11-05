// Layout probes for the inactive native 2008-06 leaves (tests/record_native_leaves2008.py): each function compiles to
// `mov eax, imm32; ret`. The two emitters at the end make the compiler emit inline-only COMDAT bodies whose original
// copies live in other units (NullController::getStaticNullController 00599e50 with its atexit 007fdbc0 and the
// NullController vtable 00832a04 slots; GuiTarget::process 005732d0 with the GuiTarget vtable 0082f848).
#include <new>
#include <stddef.h>
#include "leaves2008/Log2008.h"
#include "leaves2008/IndexBox2008.h"
#include "leaves2008/NullController2008.h"
#include "leaves2008/GuiTarget2008.h"
#include "leaves2008/Point2008.h"
#include "leaves2008/RevoluteLink2008.h"
#include "leaves2008/BlockBlockContact2008.h"

struct NativeLeaves2008Layout
{
	static size_t logName() { return offsetof(RBX::Log, name); }
	static size_t logStream() { return offsetof(RBX::Log, stream); }
	static size_t indexBoxCorner() { return offsetof(RBX::IndexBox, corner); }
	static size_t bbcConnectors() { return offsetof(RBX::BlockBlockContact, connectors); }
	static size_t bbcMatched() { return offsetof(RBX::BlockBlockContact, matched); }
	static size_t bbcAxisId() { return offsetof(RBX::BlockBlockContact, separatingAxisId); }
	static size_t bbcSeparation() { return offsetof(RBX::BlockBlockContact, separation); }
	static size_t bbcPlaneContact() { return offsetof(RBX::BlockBlockContact, planeContact); }
	static size_t bbcFeature() { return offsetof(RBX::BlockBlockContact, feature); }
	static size_t bbcOtherPlane() { return offsetof(RBX::BlockBlockContact, otherPlaneID); }
};

size_t nativeLogNameOffset() { return NativeLeaves2008Layout::logName(); }
size_t nativeLogWorstSeverityOffset() { return offsetof(RBX::Log, worstSeverity); }
size_t nativeLogFileOffset() { return offsetof(RBX::Log, logFile); }
size_t nativeLogStreamOffset() { return NativeLeaves2008Layout::logStream(); }
size_t nativeIndexBoxCornerOffset() { return NativeLeaves2008Layout::indexBoxCorner(); }
size_t nativeIndexBoxSize() { return sizeof(RBX::IndexBox); }
size_t nativeNullControllerSize() { return sizeof(RBX::NullController); }
size_t nativeGuiResponseSize() { return sizeof(RBX::GuiResponse); }
size_t nativePointSize() { return sizeof(RBX::Point); }
size_t nativeRevoluteLinkSize() { return sizeof(RBX::RevoluteLink); }
size_t nativeBlockBlockContactSize() { return sizeof(RBX::BlockBlockContact); }
size_t nativeBlockBlockContactConnectorsOffset() { return NativeLeaves2008Layout::bbcConnectors(); }
size_t nativeBlockBlockContactMatchedOffset() { return NativeLeaves2008Layout::bbcMatched(); }
size_t nativeBlockBlockContactAxisIdOffset() { return NativeLeaves2008Layout::bbcAxisId(); }
size_t nativeBlockBlockContactSeparationOffset() { return NativeLeaves2008Layout::bbcSeparation(); }
size_t nativeBlockBlockContactPlaneContactOffset() { return NativeLeaves2008Layout::bbcPlaneContact(); }
size_t nativeBlockBlockContactFeatureOffset() { return NativeLeaves2008Layout::bbcFeature(); }
size_t nativeBlockBlockContactOtherPlaneOffset() { return NativeLeaves2008Layout::bbcOtherPlane(); }

RBX::NullController* (*nativeEmitStaticNullController())() { return &RBX::NullController::getStaticNullController; }
RBX::GuiTarget* nativeEmitGuiTarget(void* place) { return new (place) RBX::GuiTarget; }
