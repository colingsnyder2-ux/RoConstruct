// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" __declspec(dllimport) unsigned long __stdcall htonl(unsigned long hostlong);
namespace RakNet {
typedef unsigned int BitSize_t;
class BitStream {
public:
	bool ReadBits(unsigned char* output, BitSize_t numberOfBitsToRead, const bool alignBitsToRight = true);
	inline static bool IsNetworkOrder(void) { static bool isNetworkOrder = (htonl(12345) == 12345); return isNetworkOrder; }
	inline static bool DoEndianSwap(void) { return IsNetworkOrder() == false; }
	inline static void ReverseBytes(unsigned char* input, unsigned char* output, const unsigned int length)
	{
		for (BitSize_t i = 0; i < length; i++)
			output[i] = input[length - i - 1];
	}
	template<class templateType> bool Read(templateType& var)
	{
		if (sizeof(var) == 1)
			return ReadBits((unsigned char*)&var, sizeof(templateType) * 8, true);
		else
		{
			if (DoEndianSwap())
			{
				unsigned char output[sizeof(templateType)];
				if (ReadBits((unsigned char*)output, sizeof(templateType) * 8, true))
				{
					ReverseBytes(output, (unsigned char*)&var, sizeof(templateType));
					return true;
				}
				return false;
			}
			else
				return ReadBits((unsigned char*)&var, sizeof(templateType) * 8, true);
		}
	}
};
template bool BitStream::Read<unsigned int>(unsigned int&);
}
