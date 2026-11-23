// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native PartInstance / Workspace debug-flag statics (inactive). All .bss (read as 0 from the exe image).
#include "v8datamodel/Workspace.h"
#include "v8datamodel/PartInstance.h"

namespace RBX
{
	bool PartInstance::highlightSleepParts = false;  // 00975f8a
	bool PartInstance::highlightAwakeParts = false;  // INFERRED: 00975f8b (next byte), zero
	bool PartInstance::showAnchoredParts = false;    // 00975f8c
	bool PartInstance::showPartCoord = false;        // INFERRED: 00975f8d/8e, zero
	bool PartInstance::showUnalignedParts = false;   // 00975f8e
	bool PartInstance::showSpanningTree = false;     // 00975f8f
	bool Workspace::showWorldCoord = false;          // 00976899
	bool Workspace::showHashGrid = false;            // INFERRED: zero
}
