// Inactive native recovery of the RBX::PartDragTool unit 006659a0..00666238 (2008-06) against the committed native
// tool/PartDragTool.h (read-only). Layout evidence: DragTool::onMouseDown 006605c0 news 0x44 for the constructor
// 00665f20; MouseCommand base 0x1c bytes (MouseCommand(Workspace*) 006159f0); runDragger +0x1c and megaDragger +0x20
// (auto_ptrs destroyed in that reverse order by ~PartDragTool 00665bd0: ~MegaDragger 0060e700, ~RunDragger 0066c400),
// dragDecal shared_ptr +0x24/+0x28 (released first), downPoint +0x2c, dragging +0x34, hitWorld +0x38; RTTI
// .?AVPartDragTool@RBX@@ vtable 0084cbb4 with the IRenderable base vtable 0084cb9c at +4.
// Named<MouseCommand, sPartDragTool>::getName 00665f00 call_once's the thunk 00665af0 of the function-local Name
// declare 00665a30 (sPartDragTool 0096265c, "PartDragTool"); the helper names come from StandardVerbs.h (codegen
// analogs). See tests/record_native_app_unit660_2008.py.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// >>> native-status (generated) -- do not edit >>>
// AppUnit660_2008PartDragTool | 2008-06 | draft (no current byte proof)
// 0/6 mapped addresses byte-exact | 6 unproved | no mapped strings | by EspClaude (+4) (mixed 3)
// <<< native-status | src 638440b6 | roc native-status --write
#include "tool/PartDragTool.h"
#include "tool/RunDragger.h"
#include "tool/MegaDragger.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Selection.h"
#include "StandardVerbs.h"

namespace RBX
{
	// 0058c5c0: commits a ChangeHistoryService waypoint (not declared in a shared header; same local declaration as
	// AxisMoveToolMethods.cpp / CSelectionTreeCtrl.cpp).
	void recordCameraHistory(const char*, const Instance*);

	char sPartDragTool[] = "PartDragTool";

	template<> struct NativeToolText<PartDragTool>
	{
		static const char* get() { return sPartDragTool; }
	};

	// 00665f20: new(0x70) RunDragger (0066c900), then new(0x2c) MegaDragger(part, items, workspace) (0060e540, the
	// std::vector<PVInstance*> overload).
	PartDragTool::PartDragTool(PartInstance* part, const G3D::Vector3& point, Workspace* workspace, boost::shared_ptr<Instance> decal)
		: Named<MouseCommand, sPartDragTool>(workspace),
		  dragDecal(decal),
		  dragging(false),
		  hitWorld(point)
	{
		runDragger.reset(new RunDragger);
		std::vector<PVInstance*> items;
		items.push_back(part);
		megaDragger.reset(new MegaDragger(part, items, static_cast<RootInstance*>(workspace)));
	}

	PartDragTool::~PartDragTool()
	{
	}

	MouseCommand* PartDragTool::onMouseDown(const UIEvent& uiEvent)
	{
		downPoint = uiEvent.mousePosition;
		capture();
		return this;
	}

	void PartDragTool::onMouseIdle(const UIEvent& uiEvent)
	{
		if (captured() && dragging && megaDragger->mousePartAlive())
		{
			megaDragger->continueDragging();
			runDragger->snap(getUnitMouseRay(uiEvent));
		}
	}

	void PartDragTool::onMouseMove(const UIEvent& uiEvent)
	{
		if ((G3D::Vector2(uiEvent.mousePosition) - downPoint).length() > 4.0f)
			onMouseDelta(uiEvent);
		else
			onMouseIdle(uiEvent);
	}

#ifdef NATIVE_APPUNIT660_PENDING
	// These three bodies call MegaDragger::getMousePart, which the original emits out of line at 00665aa0 (an inline
	// member returning the weak_ptr copy); the committed native tool/MegaDragger.h does not declare it (proposal).
	void PartDragTool::onMouseDelta(const UIEvent& uiEvent)
	{
		if (!dragging && megaDragger->mousePartAlive())
		{
			dragging = true;

			megaDragger->startDragging();
			runDragger->init(workspace, megaDragger->getMousePart(), hitWorld);
		}

		onMouseIdle(uiEvent);
	}

	MouseCommand* PartDragTool::onKeyDown(const UIEvent& uiEvent)
	{
		if (megaDragger->mousePartAlive())
		{
			if (dragging)
			{
				switch (uiEvent.key)
				{
				case SDLK_r:
					runDragger->rotatePart(megaDragger->getMousePart().lock().get());
					break;
				case SDLK_t:
					runDragger->tiltPart(megaDragger->getMousePart().lock().get(), workspace->getCamera()->getCameraCoordinateFrame());
					break;
				}
			}
			return this;
		}
		return NULL;
	}

	void PartDragTool::render3dAdorn(Adorn* adorn)
	{
		if (megaDragger->mousePartAlive())
			megaDragger->getMousePart().lock()->render3dSelect(adorn, SELECT_NORMAL);
	}
#endif

	MouseCommand* PartDragTool::onMouseUp(const UIEvent& uiEvent)
	{
		if (dragging)
		{
			if (megaDragger->mousePartAlive())
				runDragger->snap(getUnitMouseRay(uiEvent));
			megaDragger->finishDragging();
			dragging = false;
			recordCameraHistory(getName().c_str(), workspace);
		}
		else if (dragDecal)
		{
			ServiceClient<Selection> selection(workspace);
			selection->clearSelection();
			Selection* selected = selection.operator->();
			selected->addToSelection(dragDecal.get());
		}
		releaseCapture();
		return NULL;
	}

	template<> const Name& Named<MouseCommand, sPartDragTool>::getName() const
	{
		return NativeToolName<PartDragTool>::get();
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::PVInstance *> >;
template class std::_Vector_const_iterator<RBX::PVInstance *,std::allocator<RBX::PVInstance *> >;
template class std::_Vector_iterator<RBX::PVInstance *,std::allocator<RBX::PVInstance *> >;
template class std::auto_ptr<RBX::RunDragger>;
template class std::vector<RBX::PVInstance *,std::allocator<RBX::PVInstance *> >;
