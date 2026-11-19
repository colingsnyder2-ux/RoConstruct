// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native Creatable<Instance>::create<ControllerService>() instance (inactive): malloc 0x144, constructor
// ControllerService::ControllerService 005cb9e0. The registry names this address create<ForceField> (0045c580), but
// create<ForceField> is 005c1520 (malloc 0x148, constructor 0062d6b0, v8datamodel/ForceField.h sizeof 0x148), so the
// original ForceField size was right and the address is the ControllerService factory.
#include "v8datamodel/UserController.h"

using namespace RBX;
template boost::shared_ptr<ControllerService> Creatable<Instance>::create<ControllerService>();
