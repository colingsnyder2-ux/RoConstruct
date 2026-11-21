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
	// ContentId +0x20 and currentCursor +0x24 are written); MSVC omits that store only for novtable classes.
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
