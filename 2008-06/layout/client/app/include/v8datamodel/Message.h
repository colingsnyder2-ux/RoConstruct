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
