// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_af0fac983d599754.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
#include <string>
namespace RakNet {
class BitStream {
public:
    void WriteBits(const unsigned char* input, int numberOfBitsToWrite, const bool rightAlignedBits = true);
    template <class templateType> void Write(templateType var)
    {
        WriteBits((unsigned char*)&var, sizeof(templateType) * 8, true);
    }
};
}
namespace RBX { namespace Network {
inline RakNet::BitStream& operator<<(RakNet::BitStream& stream, unsigned char value) { stream.Write(value); return stream; }
RakNet::BitStream& operator<<(RakNet::BitStream& stream, const std::string& value);
class StringSender {
    std::map<std::string, unsigned char> dictionary;
    std::string strings[128];
    int lastIndex;
public:
    void send(RakNet::BitStream& stream, const std::string& value);
};
void StringSender::send(RakNet::BitStream& stream, const std::string& value)
{
    if (value == "")
    {
        stream << (unsigned char)0;
    }
    else
    {
        std::pair<std::map<std::string, unsigned char>::iterator, bool> pair = dictionary.insert(std::pair<const std::string, unsigned char>(value, (unsigned char)lastIndex));
        if (!pair.second)
        {
            stream << pair.first->second;
        }
        else
        {
            dictionary.erase(strings[lastIndex]);
            strings[lastIndex] = value;
            stream << (unsigned char)(lastIndex | 0x80);
            stream << value;
            lastIndex = lastIndex % 127 + 1;
        }
    }
}
}}
