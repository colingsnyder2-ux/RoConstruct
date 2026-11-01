// from server: 99% by EspClaude
#include <string.h>
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
typedef unsigned int BitSize_t;
typedef unsigned int RakNetTime;
typedef unsigned __int64 RakNetTimeNS;
typedef unsigned char MessageID;
typedef unsigned short SystemIndex;
struct SystemAddress { unsigned int binaryAddress; unsigned short port; };
enum PacketPriority { SYSTEM_PRIORITY };
enum PacketReliability { UNRELIABLE, UNRELIABLE_SEQUENCED, RELIABLE };
namespace RakNet {
class BitStream {
public:
    BitStream(const unsigned int initialBytesToAllocate);
    unsigned char* GetData(void) const { return data; }
    BitSize_t GetNumberOfBitsUsed(void) const { return numberOfBitsUsed; }
    BitStream();
    void WriteCompressed(unsigned int var);
    BitStream(unsigned char* _data, const unsigned int lengthInBytes, bool _copyData);
    ~BitStream();
    bool ReadBits(unsigned char* inOutByteArray, BitSize_t numberOfBitsToRead, bool alignBitsToRight = true);
    void WriteBits(const unsigned char* inByteArray, BitSize_t numberOfBitsToWrite, const bool rightAlignedBits = true);
    void SetWriteOffset(const BitSize_t offset);
    static bool DoEndianSwap(void);
    static void ReverseBytes(unsigned char* input, unsigned char* output, const unsigned int length);
    template <class templateType> bool Read(templateType& var)
    {
        if (DoEndianSwap()) {
            unsigned char output[sizeof(templateType)];
            if (ReadBits((unsigned char*)output, sizeof(templateType) * 8, true)) {
                ReverseBytes(output, (unsigned char*)&var, sizeof(templateType));
                return true;
            }
            return false;
        }
        else
            return ReadBits((unsigned char*)&var, sizeof(templateType) * 8, true);
    }
    template <class templateType> void Write(templateType var)
    {
        if (sizeof(var) == 1)
            WriteBits((unsigned char*)&var, sizeof(templateType) * 8, true);
        else if (DoEndianSwap()) {
            unsigned char output[sizeof(templateType)];
            ReverseBytes((unsigned char*)&var, output, sizeof(templateType));
            WriteBits((unsigned char*)output, sizeof(templateType) * 8, true);
        }
        else
            WriteBits((unsigned char*)&var, sizeof(templateType) * 8, true);
    }
private:
    BitSize_t numberOfBitsUsed;
    BitSize_t numberOfBitsAllocated;
    BitSize_t readOffset;
    unsigned char* data;
    bool copyData;
    unsigned char stackData[1024];
};
}
class HuffmanEncodingTree {
public:
    void EncodeArray(unsigned char* input, size_t sizeInBytes, RakNet::BitStream* output);
};
namespace DataStructures {
template <class key_type, class data_type> struct MapNode { key_type mapNodeKey; data_type mapNodeData; };
template <class key_type, class data_type> int NodeComparisonFunc(const key_type& a, const MapNode<key_type, data_type>& b);
template <class key_type, class data_type> class Map {
public:
    typedef MapNode<key_type, data_type> Node;
    unsigned GetIndexFromKey(const key_type& key, bool* objectExists, int (*cf)(const key_type&, const Node&)) const;
    void SaveLastSearch(const key_type& key, const unsigned index) const { (void)key; (void)index; }
    bool HasSavedSearchResult(const key_type& key) const { (void)key; return false; }
    Node& at(const unsigned int position) const { return listArray[position]; }
    bool Has(const key_type& key) const
    {
        if (HasSavedSearchResult(key))
            return true;
        bool objectExists;
        unsigned index;
        index = GetIndexFromKey(key, &objectExists, NodeComparisonFunc<key_type, data_type>);
        if (objectExists)
            SaveLastSearch(key, index);
        return objectExists;
    }
    data_type& Get(const key_type& key) const
    {
        if (HasSavedSearchResult(key))
            return at(0).mapNodeData;
        bool objectExists;
        unsigned index;
        index = GetIndexFromKey(key, &objectExists, NodeComparisonFunc<key_type, data_type>);
        SaveLastSearch(key, index);
        return at(index).mapNodeData;
    }
    Node* listArray; unsigned int list_size; unsigned int allocation_size;
};
}
class StringCompressor {
public:
    void EncodeString(const char* input, int maxCharsToWrite, RakNet::BitStream* output, int languageID);
    DataStructures::Map<int, HuffmanEncodingTree*> huffmanEncodingTrees;
};
void StringCompressor::EncodeString(const char* input, int maxCharsToWrite, RakNet::BitStream* output, int languageID)
{
    HuffmanEncodingTree* huffmanEncodingTree;
    if (huffmanEncodingTrees.Has(languageID) == false)
        return;
    huffmanEncodingTree = huffmanEncodingTrees.Get(languageID);
    if (input == 0)
    {
        output->WriteCompressed((unsigned int)0);
        return;
    }
    RakNet::BitStream encodedBitStream;
    unsigned int stringBitLength;
    int charsToWrite;
    if (maxCharsToWrite <= 0 || (int)strlen(input) < maxCharsToWrite)
        charsToWrite = (int)strlen(input);
    else
        charsToWrite = maxCharsToWrite - 1;
    huffmanEncodingTree->EncodeArray((unsigned char*)input, charsToWrite, &encodedBitStream);
    stringBitLength = (unsigned int)encodedBitStream.GetNumberOfBitsUsed();
    output->WriteCompressed(stringBitLength);
    output->WriteBits(encodedBitStream.GetData(), stringBitLength);
}
