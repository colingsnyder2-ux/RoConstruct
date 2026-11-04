#include "v8datamodel/ClickDetector.h"
#include <stddef.h>
typedef char size_check[sizeof(RBX::ClickDetector)==0x14c?1:-1];
typedef char first_check[offsetof(RBX::ClickDetector,field_140)==0x140?1:-1];
typedef char float_check[offsetof(RBX::ClickDetector,maxActivationDistance)==0x144?1:-1];
