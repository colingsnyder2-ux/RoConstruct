#include "v8datamodel/DataModel.h"
namespace RBX {
char sDataModel[] = "DataModel";
}

// Name registrations emitted by this unit (bytes and sX relocation identity proven against the 2008-06 client).
template void RBX::Name::callDoDeclare<RBX::sDataModel>();
