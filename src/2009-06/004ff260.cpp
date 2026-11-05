// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct SystemAddress
{
	unsigned int binaryAddress;
	unsigned short port;
};
namespace RakNet {
class BitStream {
public:
	bool ReadBits(unsigned char* inOutByteArray, int numberOfBitsToRead, const bool alignBitsToRight = true);
	bool Read(unsigned short& var);
	bool Read(SystemAddress& var);
};
bool BitStream::Read(SystemAddress& var)
{
	ReadBits((unsigned char*)&var.binaryAddress, sizeof(var.binaryAddress) * 8, true);
	var.binaryAddress = ~var.binaryAddress;
	return Read(var.port);
}
}
