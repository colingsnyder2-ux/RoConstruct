// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
extern void (*rakFree)(void*);
namespace RakNet {
class BitStream {
public:
    ~BitStream();
    unsigned int numberOfBitsUsed;
    unsigned int numberOfBitsAllocated;
    unsigned int readOffset;
    unsigned char* data;
    bool copyData;
};
BitStream::~BitStream()
{
    if (copyData && numberOfBitsAllocated > 1024 * 8)
        rakFree(data);
}
}
