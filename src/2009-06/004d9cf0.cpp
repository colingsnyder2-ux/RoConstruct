// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" __declspec(dllimport) unsigned long __stdcall htonl(unsigned long);
namespace RakNet {
class BitStream {
public:
    static bool DoEndianSwap(void);
    static bool IsNetworkOrder(void) { static bool isNetworkOrder = (htonl(12345) == 12345); return isNetworkOrder; }
};
bool BitStream::DoEndianSwap(void) { return !IsNetworkOrder(); }
}
