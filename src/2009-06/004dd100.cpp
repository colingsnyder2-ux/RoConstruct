// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <stdexcept>
namespace RakNet {
class BitStream {
public:
    template<class T> bool Read(T& var);
};
}
RakNet::BitStream& operator>>(RakNet::BitStream& stream, long& value)
{
    if (!stream.Read(value))
        throw std::runtime_error("BitStream >> long failed");
    return stream;
}
