#include "gui/Widget.h"

namespace RBX
{
	class MenuItem : public VerbWidget
	{
	private:
		std::string accelerator;

	protected:
		virtual bool canLoseFocus();
	public:
		MenuItem(Verb*, const std::string&, std::string);
		MenuItem(Verb*, const std::string&);
		virtual void render2d(Adorn*);
	};
}
