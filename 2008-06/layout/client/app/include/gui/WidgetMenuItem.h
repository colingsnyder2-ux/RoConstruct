#pragma once
#include "gui/Widget.h"

struct NativeWidgetLayout;

namespace RBX
{
	class MenuItem : public VerbWidget
	{
	private:
		std::string accelerator;                                     // +0x14c

	protected:
		virtual bool canLoseFocus();                                 // slot 17, 00565950
	public:
		MenuItem(Verb*, const std::string&);                         // 0064ebf0
		virtual void render2d(Adorn*);                               // slot 24, 0064edb0 (not attempted)
		friend struct ::NativeWidgetLayout;
	};
}
