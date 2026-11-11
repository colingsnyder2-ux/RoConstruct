#pragma once
// >>> native-status (generated) -- do not edit >>>
// MouseCommand | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 30392501 | roc native-status --write
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
	class Decal;
	class HitTestFilter;
	class Workspace;
	class XmlState;

	class MouseCommand : public INamed, public IRenderable
	{
	private:
		bool capturedMouse;
	protected:
		Workspace* workspace;

	private:
		static G3D::Vector3 ignoreVector3;

	public:
		G3D::Ray getUnitMouseRay(const UIEvent& uiEvent) const;
		G3D::Ray getSearchRay(const UIEvent& uiEvent) const;
		PartInstance* getPart(const UIEvent& uiEvent, const HitTestFilter* filter, G3D::Vector3& hitWorld = ignoreVector3);
		PartInstance* getUnlockedPart(const UIEvent& uiEvent, G3D::Vector3& hitWorld = ignoreVector3);
		PartInstance* getPartByLocalCharacter(const UIEvent& uiEvent, G3D::Vector3& hitWorld = ignoreVector3);
		PartInstance* getUnlockedPartByLocalCharacter(const UIEvent&, G3D::Vector3& = ignoreVector3);
		Surface* getSurface(const UIEvent&, PartInstance*&, int&);
		Surface* getSurface(const UIEvent&);
		Decal* getDecal(PartInstance*, const UIEvent&);

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
		// Recovered distance helper; original method name unproven.
		float distanceFromCharacter(const G3D::Vector3&) const;
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
