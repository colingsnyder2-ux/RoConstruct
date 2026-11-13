// >>> native-status (generated) -- do not edit >>>
// WorkspaceStatus | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 6990c216 | roc native-status --write
#include "util/standardout.h"

void __cdecl reportWorkspaceStatus(unsigned short status, const char* message)
{
    switch (status) {
    case 0:
        RBX::StandardOut::singleton()->print(RBX::MESSAGE_INFO, "%s", message);
        break;
    case 1:
        RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR, "%s", message);
        break;
    case 4:
        RBX::StandardOut::singleton()->print(RBX::MESSAGE_INFO, "%s", message);
        break;
    case 8:
        RBX::StandardOut::singleton()->print(RBX::MESSAGE_INFO, "%s", message);
        break;
    case 16:
        RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR, "%s", message);
        break;
    }
}
