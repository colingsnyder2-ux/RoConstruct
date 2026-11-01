// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <stdexcept>
#include <string>
class BitStream { public: bool ReadBits(unsigned char* output, unsigned int numberOfBitsToRead, bool alignBitsToRight = true); };
namespace RBX {
class Compressor {
public:
	static int readCompressionType(BitStream& stream);
};
int Compressor::readCompressionType(BitStream& stream)
{
	unsigned int compressionType = 0;
	if (!stream.ReadBits((unsigned char*)&compressionType, 2, true))
		throw std::runtime_error("Compressor::readTranslation failed reading compressionType");
	return (unsigned short)compressionType;
}
}
