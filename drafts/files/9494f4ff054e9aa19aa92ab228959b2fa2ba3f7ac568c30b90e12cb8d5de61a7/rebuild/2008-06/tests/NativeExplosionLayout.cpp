#include "v8datamodel/Explosion.h"
#include <stddef.h>
typedef char size_check[sizeof(RBX::Explosion)==0x15c?1:-1];
typedef char check_age[offsetof(RBX::Explosion,age)==0x144?1:-1];
typedef char check_position[offsetof(RBX::Explosion,position)==0x148?1:-1];
typedef char check_blastRadius[offsetof(RBX::Explosion,blastRadius)==0x154?1:-1];
typedef char check_blastPressure[offsetof(RBX::Explosion,blastPressure)==0x158?1:-1];
