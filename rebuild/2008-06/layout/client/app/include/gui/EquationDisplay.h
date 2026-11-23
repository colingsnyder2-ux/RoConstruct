// =============================================================================
// EquationDisplay.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/gui/EquationDisplay.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "gui/Gui.h"

struct NativeWidgetLayout;

namespace RBX
{
	class EquationDisplay : public TextDisplay
	{
	private:
		std::string equation;                                        // +0x188

	protected:
		virtual std::string getLabel() const;                        // slot 25, 00656940 (not attempted)
	public:
		EquationDisplay(const std::string&, const std::string&);     // 00656a50
		friend struct ::NativeWidgetLayout;
	};
}
