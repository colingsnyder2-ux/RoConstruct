// =============================================================================
// Message.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/Message.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "v8tree/Instance.h"
#include "util/IRenderable.h"

namespace RBX
{
	extern const char sMessage[];

	class Message : public DescribedCreatable<Message, Instance, sMessage>, public IRenderable
	{
	protected:
		std::string text;                          // +0x140

	protected:
		void renderFullScreen(Adorn* adorn);       // 005dcb50
		void renderPersonalMsg(Adorn* adorn);      // 005dcc60
	public:
		Message();                                 // 005dd120 (destructor 004a3a90, deleting 005dd260)

		virtual bool shouldRender2d() const
		{
			return true;                           // 00565950 (ICF-shared)
		}

		virtual void render2d(Adorn* adorn);       // 005dcd90

		virtual bool askSetParent(const Instance* instance) const
		{
			return true;                           // 00565ff0 (ICF-shared)
		}

		const std::string& getText() const         // 005dcad0
		{
			return text;
		}

		void setText(const std::string& value);    // 005dd280
	};

	extern const char sHint[];

	class Hint : public DescribedCreatable<Hint, Message, sHint>
	{
	private:
		virtual void render2d(Adorn* adorn);       // 005dcde0
	};
}
