// >>> native-status (generated) -- do not edit >>>
// DocumentException | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 68baf0f4 | roc native-status --write
#include "util/StandardOut.h"
#include <exception>

void reportDocumentException(const std::exception& error)
{
    RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR, error.what());
}
