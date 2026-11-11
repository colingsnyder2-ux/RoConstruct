// native-flags: /O2 /GS- /EHsc /MD /GS- /IC:\Users\colin\RoConstruct\tools\rbxgs\Client\Network\raknet30\Source
// >>> native-status (generated) -- do not edit >>>
// StringCompressor | 2008-06 | 1 byte-exact, inactive (not link-selected)
// 1/1 mapped addresses byte-exact | 0 unproved | no mapped strings | by -
// <<< native-status | src 63b2c950 | roc native-status --write
#include "../../../tools/rbxgs/Client/Network/raknet30/Source/StringCompressor.h"
#include "DS_HuffmanEncodingTree.h"
#include "BitStream.h"

StringCompressor* StringCompressor::Instance(void)
{
	return instance;
}
