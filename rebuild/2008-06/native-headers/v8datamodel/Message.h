#pragma once
// 2008-06 native RBX::Message and RBX::Hint (inactive). Shape after the donor tools/rbxgs Message.h; every
// field, virtual and descriptor below is read from the 2008-06 binary:
//   RTTI       Message vtable 0083dad4 .?AVMessage@RBX@@ -> DescribedCreatable<Message, Instance, sMessage>
//              (22 bases, IRenderable at +0x130); Hint vtable 00823b6c .?AVHint@RBX@@ ->
//              DescribedCreatable<Hint, Message, sHint> (26 bases). Both names mangle $1?s..@2@3PADA (char
//              arrays in .data: sMessage 009542a0, sHint 009542a8).
//   size       0x15c for both: Creatable<Instance>::create<Message> 004a3850 and create<Hint> 004a4d40
//              allocate 0x15c. Message constructor 005dd120: Base("Message") (literal 0083db14), IRenderable
//              at +0x130 (index2d/index3d -1, bucket 0), std::string text at +0x140 (default-constructed).
//   vtable     Instance slot 3 askSetParent -> 00565ff0 (return true); askAddChild stays Instance's 0068e880.
//              IRenderable (+0x130) slot 0 shouldRender2d -> 00565950 (return true), slot 2 render2d ->
//              Message 005dcd90 / Hint 005dcde0 (both emitted in the Message unit).
//   descriptor desc_Text 0097a668 (PropDescriptor<Message, std::string> "Text"/"Appearance", dynamic
//              initializer 007f6970: getter 005dcad0, setter 005dd280).
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
