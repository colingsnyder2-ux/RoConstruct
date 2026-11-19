#pragma once
// 2008-06 RBX::GuiEvent / GuiResponse / GuiTarget. From the donor
// tools/openrbx/.../gui/GuiEvent.h; uses the same util/UIEvent.h as the native
// Workspace.h include chain (one definition of RBX::UIEvent).
// Layout evidence: 00575890 reads event.eventType at +0 and event.key at +8, and writes
// a 2-field GuiResponse (+0 enum, +4 target pointer).
#include "util/UIEvent.h"

namespace RBX
{
	class IDataState;

	class GuiEvent : public UIEvent
	{
	public:
		IDataState* iDataState; // 0x14

		GuiEvent(const UIEvent& event, IDataState* iDataState) : UIEvent(event), iDataState(iDataState) {}
	};

	class GuiResponse
	{
	public:
		enum ResponseType
		{
			NOT_USED = 0,
			USED = 1,
			USED_AND_FINISHED = 2
		};

		bool wasUsed() { return response != NOT_USED; }
		bool wasNotUsed() { return response == NOT_USED; }
		bool wasFinished() { return response == USED_AND_FINISHED; }
		GuiTarget* getTarget() { return target; }

		static GuiResponse notUsed() { return GuiResponse(NOT_USED, NULL); }
		static GuiResponse used() { return GuiResponse(USED, NULL); }
		static GuiResponse used(GuiTarget* target) { return GuiResponse(USED, target); }
		static GuiResponse finished() { return GuiResponse(USED_AND_FINISHED, NULL); }

	private:
		GuiResponse(ResponseType response, GuiTarget* target) : response(response), target(target) {}

	private:
		ResponseType response; // 0x00
		GuiTarget* target;     // 0x04
	};

	class GuiTarget
	{
	public:
		virtual GuiResponse process(const GuiEvent& guiEvent) { return GuiResponse::notUsed(); }
	};
}
