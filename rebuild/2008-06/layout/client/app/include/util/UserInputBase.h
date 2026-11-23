// =============================================================================
// UserInputBase.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/util/UserInputBase.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "RbxGraphics/TextureProxyBase.h"
#include "util/TextureId.h"
#include <G3D/Vector2.h>
#include <SDL.h>
#include "util/MovementKeys.h"

namespace RBX
{
	class Adorn;
	// INFERRED: __declspec(novtable) - the ctor 005ceaa0 never stores a vftable pointer (only the string member at +4,
	class __declspec(novtable) UserInputBase
	{
	public:
		enum WrapMode
		{
			WRAP_AUTO,
			WRAP_CENTER
		};

	private:
		ContentId currentCursorId;
		G3D::ReferenceCountedPointer<TextureProxyBase> currentCursor;

	protected:
		virtual G3D::Vector2 getCursorPosition() = 0;
		virtual G3D::ReferenceCountedPointer<TextureProxyBase> getGameCursor(Adorn*);
	public:
		UserInputBase();
	public:
		void init(Adorn*);
	public:
		~UserInputBase();
	public:
		virtual void setWrapMode(WrapMode) = 0;
		virtual WrapMode getWrapMode() const = 0;
		virtual void centerCursor() = 0;
		virtual bool keyDown(SDLKey) const = 0;
		void getMovementKeys(MovementKeys&) const;
		bool altKeyDown() const;
		bool shiftKeyDown() const;
		bool ctrlKeyDown() const;
		virtual void setKeyState(SDLKey, bool) = 0;
		virtual void setCursorId(Adorn*, const TextureId&);
		void renderGameCursor(Adorn*);
	public:
		bool sub_004674a0();   // INFERRED: 004674a0, placeholder name (identity tier), body byte-proved (Inferred_004674a0.cpp)
	};
}
