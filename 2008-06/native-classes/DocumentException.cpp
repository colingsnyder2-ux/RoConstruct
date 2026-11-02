#include "util/StandardOut.h"
#include <exception>

void reportDocumentException(const std::exception& error)
{
    RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR, error.what());
}
