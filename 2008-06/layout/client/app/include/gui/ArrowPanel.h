// =============================================================================
// ArrowPanel.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/gui/ArrowPanel.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "gui/WidgetButtons.h"
#include "v8world/Controller.h"

struct NativeWidgetLayout;

namespace RBX
{
	class DataModel;

	class ArrowPanel : public TopMenuBar
	{
	protected:
		DataModel* dataModel;                                        // +0x15c
		Controller::ControllerType controller;                       // +0x160

	public:
		ArrowPanel(Adorn*, DataModel*, Controller::ControllerType);  // 00657780 (not attempted)
		virtual bool isVisible() const;                              // slot 21, 00656db0 (not attempted)
		virtual G3D::Vector2 getSize() const;                        // slot 23, 00656bf0
		friend struct ::NativeWidgetLayout;
		public:
		void init(RBX::Adorn *,std::basic_string<char,std::char_traits<char>,std::allocator<char> > const &,std::basic_string<char,std::char_traits<char>,std::allocator<char> > const &,std::basic_string<char,std::char_traits<char>,std::allocator<char> > const &,std::basic_string<char,std::char_traits<char>,std::allocator<char> > const &,std::basic_string<char,std::char_traits<char>,std::allocator<char> > const &,SDLKey,SDLKey,SDLKey,SDLKey);   // INFERRED: ?init@ArrowPanel@RBX@@QAEXPAVAdorn@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@1111W4SDLKey@@222@Z (header gap, header_gap_fill.py)
};

	class ArrowButton : public ImageKeyButton
	{
	private:
		DataModel* dataModel;                                        // +0x188
		Controller::ControllerType controller;                       // +0x18c

	public:
		ArrowButton(Adorn*, const std::string&, SDLKey, Controller::ControllerType, DataModel*);  // 006570a0
		virtual bool isEnabled();                                    // slot 30, 00657be0 (not attempted)
		friend struct ::NativeWidgetLayout;
	};
}
