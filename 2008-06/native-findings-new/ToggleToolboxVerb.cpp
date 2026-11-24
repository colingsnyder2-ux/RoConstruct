#include "../native-headers/ToggleToolboxVerb.h"
#include "../native-headers/v8datamodel/DataModel.h"
#include <G3D/System.h>

ToggleToolboxVerb::ToggleToolboxVerb(CRobloxView* view, RBX::DataModel* model)
    : RBX::Verb(model, "ToggleToolbox"), view(view), model(model), createdAt(G3D::System::getLocalTime()) {}
