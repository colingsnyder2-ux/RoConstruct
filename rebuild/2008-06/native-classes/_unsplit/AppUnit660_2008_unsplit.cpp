// UNSPLIT CANDIDATE (2026-11-08): AppUnit660 tool family
// Originals preserved.

// ---- BEGIN AppUnit660_2008ERA.cpp ----
// Inactive native recovery of the RBX exponential running average unit 00666240..006662e5 (2008-06), between the
// PartDragTool unit and the HUMAN::Running state unit. The classes are declared by util/ExponentialRunningAverage.h
// (donor header, read-only): floatERA {weight +0, avg +4} and Vector3ERA {weight +0, x/y/z +4/+8/+0xc}, the offsets
// every body below reads (reset 00666240 / 00666280 store +4 / +4..+0xc, pushAndGetAverage multiplies by [ecx]).
// See tests/record_native_app_unit660_2008.py.
#include "util/ExponentialRunningAverage.h"

namespace RBX
{
	void floatERA::reset()                                   // 00666240
	{
		avg = 0.0f;
	}

	float floatERA::pushAndGetAverage(float value)           // 00666250
	{
		avg = (value - avg) * weight + avg;
		return avg;
	}

	float floatERA::getAverage()                             // 00666270
	{
		return avg;
	}

	void Vector3ERA::reset()                                 // 00666280: stores +0xc, +8, +4 in that order
	{
		z = 0.0f;
		y = 0.0f;
		x = 0.0f;
	}

	G3D::Vector3 Vector3ERA::pushAndGetAverage(G3D::Vector3 value)   // 00666290
	{
		x = (value.x - x) * weight + x;
		y = (value.y - y) * weight + y;
		z = (value.z - z) * weight + z;
		return G3D::Vector3(x, y, z);
	}

	G3D::Vector3 Vector3ERA::getAverage()                    // 006662d0
	{
		return G3D::Vector3(x, y, z);
	}
}
// ---- END AppUnit660_2008ERA.cpp ----

// ---- BEGIN AppUnit660_2008GroupDragTool.cpp ----
// Inactive native recovery of the RBX::GroupDragTool unit 0066a570..0066aa76 (2008-06) against the committed native
// tool/GroupDragTool.h (read-only). Layout evidence: DragTool::onMouseDown 0066061b news 0x38 for the constructor
// 0066a630; MouseCommand base 0x1c bytes (MouseCommand(Workspace*) 006159f0), megaDragger +0x1c (new 0x2c,
// MegaDragger ctor 0060e630), downPoint +0x20/+0x24, dragging +0x28, lastHit +0x2c..+0x34 (ctor stores); RTTI
// .?AVGroupDragTool@RBX@@ vtable 0084d02c with the IRenderable base vtable 0084d014 at +4.
// Named<MouseCommand, sGroupDragTool>::getName 0066aa60 call_once's a thunk 0066a620 of the function-local Name
// declare 0066a5b0 (sGroupDragTool 00962c54, "GroupDragTool"); the helper names come from StandardVerbs.h
// (codegen analogs). See tests/record_native_app_unit660_2008.py.
#include "tool/GroupDragTool.h"
#include "v8datamodel/Workspace.h"
#include "util/Math.h"
#include "tool/Dragger.h"
#include "StandardVerbs.h"

namespace RBX
{
	// 0058c5c0: commits a ChangeHistoryService waypoint (not declared in a shared header; same local declaration as
	// AxisMoveToolMethods.cpp / CSelectionTreeCtrl.cpp).
	void recordCameraHistory(const char*, const Instance*);

	char sGroupDragTool[] = "GroupDragTool";

	template<> struct NativeToolText<GroupDragTool>
	{
		static const char* get() { return sGroupDragTool; }
	};

	GroupDragTool::GroupDragTool(PartInstance* mousePart, const G3D::Vector3&, const std::vector<boost::weak_ptr<PartInstance> >& partArray, Workspace* workspace)
		: Named<MouseCommand, sGroupDragTool>(workspace),
		  dragging(false)
	{
		megaDragger.reset(new MegaDragger(mousePart, partArray, static_cast<RootInstance*>(workspace)));
	}

	GroupDragTool::~GroupDragTool()
	{
	}

	const std::string GroupDragTool::getCursorName() const
	{
		return dragging ? "GrabRotateCursor" : "DragCursor";
	}

	MouseCommand* GroupDragTool::onKeyDown(const UIEvent& uiEvent)
	{
		if (dragging)
		{
			switch (uiEvent.key)
			{
			case SDLK_r:
				megaDragger->safeRotate(Math::matrixRotateY());
				break;
			case SDLK_t:
				megaDragger->safeRotate(Math::matrixTiltZ());
				break;
			}
			return this;
		}
		return NULL;
	}

	MouseCommand* GroupDragTool::onMouseDown(const UIEvent& uiEvent)
	{
		downPoint = uiEvent.mousePosition;
		capture();
		return this;
	}

	void GroupDragTool::onMouseIdle(const UIEvent& uiEvent)
	{
		G3D::Vector3 hit;

		if (captured() && dragging && megaDragger->mousePartAlive() &&
			Math::intersectRayPlane(getSearchRay(uiEvent), G3D::Plane(G3D::Vector3::unitY(), G3D::Vector3::zero()), hit))
		{
			hit = megaDragger->hitObjectOrPlane(uiEvent);
			megaDragger->continueDragging();

			G3D::Vector3 hitSnapped = Dragger::toGrid(hit);
			G3D::Vector3 delta = Dragger::toGrid(hitSnapped - lastHit);
			lastHit = hitSnapped;

			megaDragger->safeMoveYDrop(delta);
		}
	}

	void GroupDragTool::onMouseMove(const UIEvent& uiEvent)
	{
		if (!dragging && (G3D::Vector2(uiEvent.mousePosition) - downPoint).length() > 4.0f)
		{
			dragging = true;

			megaDragger->startDragging();
			megaDragger->alignAndCleanParts();
			lastHit = megaDragger->hitObjectOrPlane(uiEvent);
		}

		onMouseIdle(uiEvent);
	}

	MouseCommand* GroupDragTool::onMouseUp(const UIEvent&)
	{
		if (dragging)
		{
			megaDragger->finishDragging();
			dragging = false;
			recordCameraHistory(getName().c_str(), workspace);
		}
		releaseCapture();
		return NULL;
	}

	template<> const Name& Named<MouseCommand, sGroupDragTool>::getName() const
	{
		return NativeToolName<GroupDragTool>::get();
	}
}
// ---- END AppUnit660_2008GroupDragTool.cpp ----

// ---- BEGIN AppUnit660_2008PartDragTool.cpp ----
// Inactive native recovery of the RBX::PartDragTool unit 006659a0..00666238 (2008-06) against the committed native
// tool/PartDragTool.h (read-only). Layout evidence: DragTool::onMouseDown 006605c0 news 0x44 for the constructor
// 00665f20; MouseCommand base 0x1c bytes (MouseCommand(Workspace*) 006159f0); runDragger +0x1c and megaDragger +0x20
// (auto_ptrs destroyed in that reverse order by ~PartDragTool 00665bd0: ~MegaDragger 0060e700, ~RunDragger 0066c400),
// dragDecal shared_ptr +0x24/+0x28 (released first), downPoint +0x2c, dragging +0x34, hitWorld +0x38; RTTI
// .?AVPartDragTool@RBX@@ vtable 0084cbb4 with the IRenderable base vtable 0084cb9c at +4.
// Named<MouseCommand, sPartDragTool>::getName 00665f00 call_once's the thunk 00665af0 of the function-local Name
// declare 00665a30 (sPartDragTool 0096265c, "PartDragTool"); the helper names come from StandardVerbs.h (codegen
// analogs). See tests/record_native_app_unit660_2008.py.
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
// ---- END AppUnit660_2008PartDragTool.cpp ----

// ---- BEGIN AppUnit660_2008Units.cpp ----
// Inactive native recovery of the RBX::Units unit 00660180..006601ba (2008-06): the two out-of-line conversions of
// util/Units.h (donor header, read-only), between the Cofm getters 00660160 / 00660170 and the hit-test filter unit
// 006601c0. Both multiply by the 20.0f constant at 008222f0 and return in the cdecl way the callers expect (Vector3 by
// hidden return pointer at 00660180; float in st0 at 006601b0). Callers: 0063e5bb, 00658f82, 0066ec49 (Vector3) and
// 00646c91 (float). See tests/record_native_app_unit660_2008.py.
#include "util/Units.h"

namespace RBX
{
	G3D::Vector3 Units::kmsAccelerationToRbx(const G3D::Vector3& kmsAccel)   // 00660180
	{
		return kmsAccel * 20.0f;
	}

	float Units::kmsForceToRbx(float kmsForce)                                // 006601b0
	{
		return kmsForce * 20.0f;
	}
}
// ---- END AppUnit660_2008Units.cpp ----

