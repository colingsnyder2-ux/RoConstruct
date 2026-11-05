// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_b613a14e44d36dab.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#undef _DEBUG
#define _DLL
#define runDragger exePadPtr; std::auto_ptr<RunDragger> runDragger
#include "tool/PartDragTool.h"
#undef runDragger
#include "util/UIEvent.h"
namespace RBX
{
	void PartDragTool::onMouseMove(const UIEvent& uiEvent)
	{
		if ((G3D::Vector2(uiEvent.mousePosition) - downPoint).length() > 4.0f)
			onMouseDelta(uiEvent);
		else
			onMouseIdle(uiEvent);
	}
}
