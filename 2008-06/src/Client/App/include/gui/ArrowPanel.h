#include "gui/Button.h"
#include "v8world/Controller.h"

namespace RBX
{
	class DataModel;

	class ArrowPanel : public TopMenuBar
	{
	protected:
		DataModel* dataModel;
		Controller::ControllerType controller;

	protected:
		void init(Adorn*, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, SDLKey, SDLKey, SDLKey, SDLKey);
	public:
		ArrowPanel(Adorn*, DataModel*, Controller::ControllerType);
		virtual bool isVisible() const;
		virtual G3D::Vector2 getSize() const;
	};

	class ArrowButton : public ImageKeyButton
	{
	private:
		DataModel* dataModel;
		Controller::ControllerType controller;

	public:
		ArrowButton(Adorn*, const std::string&, SDLKey, Controller::ControllerType, DataModel*);
		virtual bool isEnabled();
	};
}
