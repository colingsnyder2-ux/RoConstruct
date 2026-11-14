#include "OgreConfigDialog.h"
#include "OgreException.h"

namespace Ogre {
ConfigDialog::ConfigDialog() : mSelectedRenderSystem(0) {}
bool ConfigDialog::display()
{
    OGRE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED,
        "Browser demo selects its renderer directly; desktop dialogs are unavailable",
        "ConfigDialog::display");
}
}
