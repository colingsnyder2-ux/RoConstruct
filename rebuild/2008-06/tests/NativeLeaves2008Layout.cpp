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

struct NativeLeaves2008Layout
{
	static size_t logName() { return offsetof(RBX::Log, name); }
	static size_t logStream() { return offsetof(RBX::Log, stream); }
	static size_t indexBoxCorner() { return offsetof(RBX::IndexBox, corner); }
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

RBX::NullController* (*nativeEmitStaticNullController())() { return &RBX::NullController::getStaticNullController; }
RBX::GuiTarget* nativeEmitGuiTarget(void* place) { return new (place) RBX::GuiTarget; }
