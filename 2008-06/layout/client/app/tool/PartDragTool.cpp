#include "tool/PartDragTool.h"
#include "tool/RunDragger.h"
#include "tool/MegaDragger.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Selection.h"
#include "StandardVerbs.h"

namespace RBX
{
	void recordCameraHistory(const char*, const Instance*);

	char sPartDragTool[] = "PartDragTool";

	template<> struct NativeToolText<PartDragTool>
	{
		static const char* get() { return sPartDragTool; }
	};

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

template class std::_Container_base_aux_alloc_real<std::allocator<RBX::PVInstance *> >;
template class std::_Vector_const_iterator<RBX::PVInstance *,std::allocator<RBX::PVInstance *> >;
template class std::_Vector_iterator<RBX::PVInstance *,std::allocator<RBX::PVInstance *> >;
template class std::auto_ptr<RBX::RunDragger>;
template class std::vector<RBX::PVInstance *,std::allocator<RBX::PVInstance *> >;
