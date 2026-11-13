// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../../../../tmp/claude-0/-home-user/28a5ad2c-f9ca-5f88-a52d-b9a089ed390b/scratchpad/wsov
// 2008-06 native RBX::Workspace input / heartbeat / render / service-provider members (inactive), original unit
// v8datamodel/Workspace.cpp (005a01e0..005a66af). Built against the committed native v8datamodel/Workspace.h
// (read-only); sibling members of the same unit live in AppUnit5A0_2008Workspace.cpp / AppUnit5A4WorkspaceReflection.cpp.
//
// Header inline bodies (not repeated here, emitted where Workspace's vtables are emitted):
//   render3dSelect 00458e90 (`ret 8`, ICF-shared empty body), computeCameraOwnerExtents 005a2c30,
//   cameraMoved 005a2d90, onExtentsChanged 005a2db0 -- all defined inline in v8datamodel/Workspace.h.
#include "v8datamodel/Workspace.h"
#include "v8datamodel/MouseCommand.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/Hopper.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/UserController.h"
#include "v8datamodel/Stats.h"
#include "Network/Players.h"
#include "script/ScriptContext.h"
#include "RbxGraphics/Adorn.h"
#include "util/ILocation.h"
#include <G3D/AABox.h>

namespace RBX
{
	// @005a20e0 ?process@Workspace@RBX@@UAE?AVGuiResponse@2@ABVGuiEvent@2@@Z
	// Entered with the GuiTarget subobject (Workspace+0x2e8): currentCommand +0xc8, idleMouseEvent +0xd0,
	// inMouselookMode +0x110, Notifier<Workspace, DrawChanged> +0x5c. Jump table 005a2250 (event types 1..13).
	// MouseCommand slots: onMouseDown +4, onMouseIdle +8, onMouseHover +0xc, onKeyDown +0x10, onPeekKeyDown +0x14,
	// onMouseMove +0x18, onMouseDelta +0x1c, onMouseUp +0x20. UserInputBase slot +8 is setWrapMode.
	GuiResponse Workspace::process(const GuiEvent& event)
	{
		// Range test (cmp 1 / cmp 7), not the donor's seven-way UIEvent::isMouseEvent() chain.
		if (event.eventType >= UIEvent::MOUSE_RIGHT_BUTTON_DOWN && event.eventType <= UIEvent::MOUSE_IDLE)
		{
			idleMouseEvent = event;
			idleMouseEvent.eventType = UIEvent::MOUSE_IDLE;
		}

		switch (event.eventType)
		{
		// Event types 12 and 13 are past the donor UIEvent enum (KEY_UP = 11); the 2008 enumerator names are not
		// recovered (header proposal for util/UIEvent.h). Both raise DrawChanged and leave mouselook.
		case 12:
		case 13:
			raiseDrawChanged();
		case UIEvent::MOUSE_RIGHT_BUTTON_UP:
			inMouselookMode = false;
			event.userInput->setWrapMode(UserInputBase::WRAP_AUTO);
			break;
		case UIEvent::KEY_DOWN:
			currentCommand->onPeekKeyDown(event);
			if (!currentCommand->captured())
				return GuiResponse::notUsed();
			setMouseCommand(currentCommand->onKeyDown(event));
			break;
		case UIEvent::MOUSE_RIGHT_BUTTON_DOWN:
			inMouselookMode = true;
			event.userInput->setWrapMode(UserInputBase::WRAP_CENTER);
			break;
		case UIEvent::MOUSE_LEFT_BUTTON_DOWN:
			if (!currentCommand->captured())
				setMouseCommand(currentCommand->onMouseDown(event));
			break;
		case UIEvent::MOUSE_MOVE:
			if (currentCommand->captured())
				currentCommand->onMouseMove(event);
			else
				currentCommand->onMouseHover(event);
			break;
		case UIEvent::MOUSE_DELTA:
			if (currentCommand->captured())
				currentCommand->onMouseDelta(event);
			break;
		case UIEvent::MOUSE_LEFT_BUTTON_UP:
			setMouseCommand(currentCommand->onMouseUp(event));
			break;
		default:
			return GuiResponse::notUsed();
		}

		if (currentCommand->captured())
			return GuiResponse::used(this);
		else
			return GuiResponse::used();
	}

	// @005a3470 ?onEvent@Workspace@RBX@@EAEXPBVRunService@2@VHeartbeat@2@@Z
	// Entered with the Listener<RunService, Heartbeat> subobject (Workspace+0x384).
	void Workspace::onEvent(const RunService*, Heartbeat)
	{
		onMovingHeartbeat();

		if (idleMouseEvent.eventType == UIEvent::MOUSE_IDLE)
			currentCommand->onMouseIdle(idleMouseEvent);

		if (!Network::Players::findLocalCharacter(this))
		{
			if (ControllerService* controllerService = ServiceProvider::find<ControllerService>(this))
			{
				if (UserInputBase* userInput = controllerService->getHardwareDevice())
				{
					MovementKeys keys;
					userInput->getMovementKeys(keys);
					if (keys.any())
						getCamera()->moveWithKeys(keys, unknown0x3cc++);
					else
						unknown0x3cc = 0;
				}
			}
		}
	}

	// @005a5890 ?setImageServerView@Workspace@RBX@@QAEXABVRect2D@G3D@@@Z
	void Workspace::setImageServerView(const G3D::Rect2D& viewPortRect)
	{
		verifyCamera();

		HopperBin* superHack = NULL;

		for (size_t i = 0; i < numChildren(); i++)
		{
			HopperBin* hopperBin = dynamic_cast<HopperBin*>(getChild(i));
			ILocation* location = dynamic_cast<ILocation*>(getChild(i));
			IRenderable* renderable = dynamic_cast<IRenderable*>(getChild(i));

			if (location && renderable)
			{
				G3D::CoordinateFrame modelCoord = location->getLocation();
				getCamera()->setImageServerViewNoLerp(modelCoord, viewPortRect);
			}

			if (hopperBin)
				superHack = hopperBin;
		}

		if (superHack)
			superHack->setParent(ServiceProvider::create<StarterPackService>(this));

		imageServerViewHack = (imageServerViewHack <= 0);
	}

	// @005a0690 (unit-local helper of render3dAdorn, bound through boost::bind; for_each instance 005a1890)
	static void DrawAdorn(boost::shared_ptr<Instance> wsi, Adorn* adorn, SelectState selectState, Workspace* workspace)
	{
		if (IRenderable* ir = dynamic_cast<IRenderable*>(wsi.get()))
		{
			if (workspace->contains(wsi.get()))
				ir->render3dSelect(adorn, selectState);
		}
	}

	// @005a59e0 ?render3dAdorn@Workspace@RBX@@UAEXPAVAdorn@2@@Z
	void Workspace::render3dAdorn(Adorn* adorn)
	{
		verifyCamera();

		viewPort = adorn->getViewport();

		ServiceClient<Selection> sel(this);
		if (sel)
			std::for_each(sel->selection->begin(), sel->selection->end(), boost::bind(&DrawAdorn, _1, adorn, SELECT_NORMAL, this));

		render3dAdornItems(adorn);

		if (showWorldCoord)
		{
			adorn->setObjectToWorldMatrix(G3D::CoordinateFrame());
			adorn->axes(G3D::Color3::red(), G3D::Color3::green(), G3D::Color3::blue(), 50.0f);
		}

		if (showHashGrid)
		{
			adorn->setObjectToWorldMatrix(G3D::CoordinateFrame());
			adorn->box(G3D::AABox(G3D::Vector3(28, 4, 12), G3D::Vector3(32, 8, 16)), G3D::Color4(1.0f, 0.2f, 0.2f, 0.5f), G3D::Color4::zero());
		}
	}

	// @005a66b0 ?onServiceProvider@Workspace@RBX@@EAEXPBVServiceProvider@2@0@Z
	void Workspace::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		if (oldProvider)
		{
			Notifier<RunService, Heartbeat>::disconnect(oldProvider->find<RunService>(), this);

			if (statsItem)
			{
				statsItem->setParent(NULL);
				statsItem.reset();
			}
		}

		if (newProvider)
		{
			scriptContext = newProvider->create<ScriptContext>();

			RunService* runService = newProvider->find<RunService>();
			Notifier<RunService, Heartbeat>::connect(runService, this);

			if (Stats::StatsService* stats = newProvider->create<Stats::StatsService>())
			{
				statsItem = Creatable<Instance>::create<WorkspaceStatsItem>(this, world.get(), runService);
				statsItem->setParent(stats);
			}
		}
	}
}
