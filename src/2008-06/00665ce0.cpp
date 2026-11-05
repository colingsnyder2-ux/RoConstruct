// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs-dll roc_unit_c7735b8cebac2b93.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#include <memory>
#include "tool/PartDragTool.h"
#include "tool/RunDragger.h"
#include "tool/MegaDragger.h"
#include "v8datamodel/ICameraOwner.h"
namespace RBX {
MouseCommand* PartDragTool::onKeyDown(const UIEvent& uiEvent)
	{
		if ((*reinterpret_cast<std::auto_ptr<MegaDragger>*>(reinterpret_cast<char*>(this) + 0x20))->mousePartAlive())
		{
			if ((*reinterpret_cast<bool*>(reinterpret_cast<char*>(this) + 0x34)))
			{
				switch (uiEvent.key)
				{
				case SDLK_r:
					runDragger->rotatePart((*reinterpret_cast<std::auto_ptr<MegaDragger>*>(reinterpret_cast<char*>(this) + 0x20))->getMousePart().lock().get());
					break;
				case SDLK_t:
					runDragger->tiltPart((*reinterpret_cast<std::auto_ptr<MegaDragger>*>(reinterpret_cast<char*>(this) + 0x20))->getMousePart().lock().get(), reinterpret_cast<ICameraOwner*>(reinterpret_cast<char*>(workspace) + 0x288)->getCamera()->getCameraCoordinateFrame());
					break;
				}
			}

			return this;
		}
		else
		{
			return NULL;
		}
	}

	
}
