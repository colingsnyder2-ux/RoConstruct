// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/creatable-n-params
// 2008-06 native Creatable<Instance>::create<X, ...> instances of the GUI hud builders and ForceField (inactive):
// create<ForceField> 0045c580, create<ImageButton, Adorn*, Verb*, const char*> 00601f00,
// create<PercentPanel, Rect::Location, Rect::Location, Vector2> 006021e0, create<ArrowPanel, Adorn*, DataModel*,
// Controller::ControllerType> 00602650, create<ArrowButton, Adorn*, std::string, SDLKey, ControllerType, DataModel*>
// 00657190. The 3- and 5-parameter create forms come from the
// creatable-n-params overlay of util/Object.h (the core header only has 0..2 parameters).
#include "gui/ArrowPanel.h"
#include "gui/WidgetButtons.h"
#include "gui/Gui.h"
#include "v8datamodel/ForceField.h"
#include "v8datamodel/DataModel.h"

using namespace RBX;
template boost::shared_ptr<ForceField> Creatable<Instance>::create<ForceField>();
template boost::shared_ptr<ImageButton> Creatable<Instance>::create<ImageButton, Adorn*, Verb*, const char*>(Adorn*, Verb*, const char*);
template boost::shared_ptr<PercentPanel> Creatable<Instance>::create<PercentPanel, Rect::Location, Rect::Location, G3D::Vector2>(Rect::Location, Rect::Location, G3D::Vector2);
template boost::shared_ptr<ArrowPanel> Creatable<Instance>::create<ArrowPanel, Adorn*, DataModel*, Controller::ControllerType>(Adorn*, DataModel*, Controller::ControllerType);
template boost::shared_ptr<ArrowButton> Creatable<Instance>::create<ArrowButton, Adorn*, std::string, SDLKey, Controller::ControllerType, DataModel*>(Adorn*, std::string, SDLKey, Controller::ControllerType, DataModel*);
// Deleter::operator() 00405e30 (Instance::predelete(obj) 0055b770, then delete obj) waits on the core v8tree/Instance.h
// declaring `static void predelete(Instance*)` (header proposal; not declared in the native header yet).
