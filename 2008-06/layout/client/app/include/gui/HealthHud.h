#pragma once
#include "gui/Gui.h"

struct NativeWidgetLayout;

namespace RBX
{
	class Visit;

	class HealthHud : public GuiItem
	{
	private:
		boost::shared_ptr<Visit> visit;                              // +0x144

	private:
		virtual void render2d(Adorn*);                               // slot 24, 00656690
	public:
		HealthHud();                                                 // 00656490
		friend struct ::NativeWidgetLayout;
	};
}
