// native-flags: /O2 /GS- /EHsc /MD /GS- /IC:\Users\colin\RoConstruct\tools\rbxgs\Client\Network\raknet30\Source
#include "../../../tools/rbxgs/Client/Network/raknet30/Source/StringCompressor.h"
#include "DS_HuffmanEncodingTree.h"
#include "BitStream.h"

StringCompressor* StringCompressor::Instance(void)
{
	return instance;
}
