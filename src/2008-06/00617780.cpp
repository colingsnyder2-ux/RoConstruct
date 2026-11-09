// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_claudeM_8be16f10aab64e51.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("util/Object.h", "roc_espeon_arrowfactoryheader347662b16dc22b66.cpp")
#pragma include_alias(<boost/shared_ptr.hpp>, <roc_espeon_arrowsharedinlineheader0ad389253c5b3b54.cpp>)
#pragma include_alias("boost/shared_ptr.hpp", "roc_espeon_arrowsharedinlineheader0ad389253c5b3b54.cpp")
#undef _RELEASEASSERT
#pragma include_alias("tool/ToolsArrow.h", "roc_espeon_arrowheader66b4d011f2b53c41.cpp")
#pragma include_alias("tool/DragTool.h", "roc_espeon_arrowheader9c817239d1fa3743.cpp")
#pragma include_alias("util/IRenderable.h", "roc_espeon_renderableaccessheaderd4d76fdf723bc309.cpp")
#pragma include_alias("reflection/function.h", "roc_espeon_machineheader2f6c7dcf10adead1.cpp")
#pragma include_alias("reflection/signal.h", "roc_espeon_machineheader16e657153fe9fb6e.cpp")
#pragma include_alias("reflection/type.h", "roc_espeon_machineheader4aaa2bdeb1c2b6c3.cpp")
#pragma include_alias("reflection/reflection.h", "roc_espeon_machineheadera6fefc64bf3a6f9e.cpp")
#pragma include_alias("reflection/Reflection.h", "roc_espeon_machineheadera6fefc64bf3a6f9e.cpp")
#pragma include_alias("reflection/enumconverter.h", "roc_espeon_machineheader297ae1c3351d4ab6.cpp")
#pragma include_alias("reflection/object.h", "roc_espeon_machineheadercadaaebe20af2047.cpp")
#pragma include_alias("reflection/member.h", "roc_espeon_machineheader459d66d9acfae4ab.cpp")
#pragma include_alias("reflection/descriptor.h", "roc_espeon_machineheader0acd23dba6f04ff5.cpp")
#pragma include_alias("reflection/property.h", "roc_espeon_machineheadercfb6c68c9dd60df6.cpp")
#pragma include_alias(<v8tree/Verb.h>, <roc_espeon_insertnativeheader1a746c4cc8c6ae06.cpp>)
#pragma include_alias("v8tree/Verb.h", "roc_espeon_insertnativeheader1a746c4cc8c6ae06.cpp")
#pragma include_alias(<util/Name.h>, <roc_espeon_insertnativeheader115b7bccd0a9061e.cpp>)
#pragma include_alias("util/Name.h", "roc_espeon_insertnativeheader115b7bccd0a9061e.cpp")
#pragma include_alias(<util/Debug.h>, <roc_espeon_insertnativeheader5fe96130a83d2e88.cpp>)
#pragma include_alias("util/Debug.h", "roc_espeon_insertnativeheader5fe96130a83d2e88.cpp")
#pragma include_alias("v8tree/Instance.h", "roc_espeon_nativeinstanceguidportablea1682bda32c99cd2.cpp")
#pragma include_alias("v8datamodel/MouseCommand.h", "roc_espeon_insertnativeheader115b7bccd0a9061e.cpp")
#pragma include_alias(<v8datamodel/MouseCommand.h>, <roc_espeon_insertnativeheader115b7bccd0a9061e.cpp>)
// 2008 MouseCommand (no undoState; native 006159f0/00617150), inlined from roc_codex_mousecommand_2008
#include "util/Name.h"
#include "util/UIEvent.h"
#include "util/TextureId.h"
#include "util/IRenderable.h"

namespace RBX
{
	class PartInstance;
	class Primitive;
	class ContactManager;
	class ICameraOwner;
	class Surface;
	class HitTestFilter;
	class Workspace;
	class XmlState;

	class MouseCommand : public INamed, public IRenderable
	{
	private:
		bool capturedMouse;
	protected:
		Workspace* workspace;
		// Native00617150 starts selection at0x1c, and006159f0 base has workspace at0x18.
        // No undoState member occurs in this earlier client.
	private:
		static G3D::Vector3 ignoreVector3;

	public:
		G3D::Ray getUnitMouseRay(const UIEvent& uiEvent) const;
		G3D::Ray getSearchRay(const UIEvent& uiEvent) const;
		PartInstance* getPart(const UIEvent& uiEvent, const HitTestFilter* filter, G3D::Vector3& hitWorld = ignoreVector3);
		PartInstance* getUnlockedPart(const UIEvent& uiEvent, G3D::Vector3& hitWorld = ignoreVector3);
		PartInstance* getPartByLocalCharacter(const UIEvent& uiEvent, G3D::Vector3& hitWorld = ignoreVector3);
		PartInstance* getUnlockedPartByLocalCharacter(const UIEvent&, G3D::Vector3&);
		Surface* getSurface(const UIEvent&, PartInstance*&, int&);
		Surface* getSurface(const UIEvent&);

		virtual MouseCommand* onMouseDown(const UIEvent& uiEvent)
		{
			return this;
		}
	protected:
		virtual void onMouseIdle(const UIEvent& uiEvent)
		{
			return;
		}

		virtual void onMouseHover(const UIEvent& uiEvent)
		{
			return;
		}

		virtual MouseCommand* onKeyDown(const UIEvent& uiEvent)
		{
			return this;
		}

		virtual MouseCommand* onPeekKeyDown(const UIEvent& uiEvent)
		{
			return NULL;
		}

		virtual void onMouseMove(const UIEvent& uiEvent)
		{
			return;
		}

		virtual void onMouseDelta(const UIEvent& uiEvent)
		{
			return;
		}

		virtual MouseCommand* onMouseUp(const UIEvent& uiEvent)
		{
			releaseCapture();
			return NULL;
		}

		virtual void capture();

		virtual void releaseCapture()
		{
			capturedMouse = false;
		}

		virtual void cancel()
		{
			if (capturedMouse)
				releaseCapture();
		}

		void snapshotSelectionPosition(XmlState*);
		bool characterCanReach(const G3D::Vector3& hitPoint) const;
		MouseCommand(Workspace* workspace);
	public:
		virtual ~MouseCommand();

		bool captured() const
		{
			return capturedMouse;
		}

		virtual MouseCommand* isSticky() const
		{
			return NULL;
		}

		virtual TextureId getCursorId() const;
	private:
		virtual const std::string getCursorName() const
		{
			return "ArrowCursor";
		}

	private:
		static const float maxSearch();
	public:
		static G3D::Ray getUnitMouseRay(const UIEvent& uiEvent, ICameraOwner* _workspace);
		static inline G3D::Ray getSearchRay(const G3D::Ray& unitRay);
		static G3D::Ray getSearchRay(const UIEvent& uiEvent, ICameraOwner* _workspace);
		static Instance* getTopSelectable3d(PartInstance* part);
		static PartInstance* getMousePart(const G3D::Ray& unitRay, const ContactManager& contactManager, const std::vector<const Primitive*>& ignore, const HitTestFilter* filter, G3D::Vector3& hitPoint, float maxSearchGrid);
		static PartInstance* getMousePart(const G3D::Ray& unitRay, const ContactManager& contactManager, const Primitive* ignore, const HitTestFilter* filter, G3D::Vector3& hitPoint, float maxSearchGrid);
	};
}

#include "tool/ToolsArrow.h"
#include "tool/DragTool.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/Workspace.h"
#include <G3D/Rect2D.h>

namespace RBX
{
 __declspec(noalias) boost::shared_ptr<Decal> shared_from(Decal*);
	MouseCommand* ArrowToolBase::onMouseDown(const UIEvent& uiEvent)
	{
		RBXASSERT(uiEvent.eventType == UIEvent::MOUSE_LEFT_BUTTON_DOWN);

		G3D::Vector3 hitWorld;

		PartInstance* part = getUnlockedPart(uiEvent, hitWorld);
		if (part)
		{
			Instance* top = getTopSelectable3d(part);
			UserInputBase* input = uiEvent.userInput;

			ServiceClient<Selection> selection(workspace);

			if (!input->keyDown(SDLK_RSHIFT) && !input->keyDown(SDLK_LSHIFT) &&
				!input->keyDown(SDLK_RCTRL) && !input->keyDown(SDLK_LCTRL))
			{
                boost::shared_ptr<Decal> decal;
                if(selection->isSelected(top))
                    decal=shared_from(findSelectedDecal(part,uiEvent));
                else
                    selection->setSelection(top);
                ServiceClient<FilteredSelection<Instance> > instanceSelection(workspace);
                return DragTool::onMouseDown(part,hitWorld,instanceSelection->items(),uiEvent,workspace,decal);

			}
			else
			{
				if (selection->isSelected(top))
					selection->removeFromSelection(top);
				else
					selection->addToSelection(top);
			}

			return NULL;
		}
		else
		{
			MouseCommand* newCommand = new BoxSelectCommand(workspace);
			return newCommand->onMouseDown(uiEvent);
		}
	}


}
