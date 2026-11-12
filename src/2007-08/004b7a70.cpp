// from server: 68% by EspClaude
// from server: 60% by colin
// roc 2007-08 004b7a70  unit: Exposer  size: 183 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004b7a70
//
// 004b7a70  51                   push ecx
// 004b7a71  56                   push esi
// 004b7a72  8bf1                 mov esi, ecx
// 004b7a74  807e1400             cmp byte ptr [esi + 0x14], 0
// 004b7a78  57                   push edi
// 004b7a79  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 004b7a7d  7409                 je 0x4b7a88
// 004b7a7f  8b4610               mov eax, dword ptr [esi + 0x10]
// 004b7a82  3bf8                 cmp edi, eax
// 004b7a84  7c02                 jl 0x4b7a88
// 004b7a86  7422                 je 0x4b7aaa
// 004b7a88  8d44240b             lea eax, [esp + 0xb]
// 004b7a8c  50                   push eax
// 004b7a8d  8d4c2420             lea ecx, [esp + 0x20]
// 004b7a91  51                   push ecx
// 004b7a92  8bce                 mov ecx, esi
// 004b7a94  e8b7fbffff           call 0x4b7650
// 004b7a99  807c240b00           cmp byte ptr [esp + 0xb], 0
// 004b7a9e  744e                 je 0x4b7aee
// 004b7aa0  89460c               mov dword ptr [esi + 0xc], eax
// 004b7aa3  897e10               mov dword ptr [esi + 0x10], edi
// 004b7aa6  c6461401             mov byte ptr [esi + 0x14], 1
// 004b7aaa  55                   push ebp
// 004b7aab  8d542420             lea edx, [esp + 0x20]
// 004b7aaf  52                   push edx
// 004b7ab0  8bce                 mov ecx, esi
// 004b7ab2  e869fdffff           call 0x4b7820
// 004b7ab7  8b28                 mov ebp, dword ptr [eax]
// 004b7ab9  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 004b7abd  8b742414             mov esi, dword ptr [esp + 0x14]
// 004b7ac1  6a01                 push 1
// 004b7ac3  6a20                 push 0x20
// 004b7ac5  8d442428             lea eax, [esp + 0x28]
// 004b7ac9  50                   push eax
// 004b7aca  8bcf                 mov ecx, edi
// 004b7acc  c60600               mov byte ptr [esi], 0
// 004b7acf  e87c7ffeff           call 0x49fa50
// 004b7ad4  84c0                 test al, al
// 004b7ad6  740d                 je 0x4b7ae5
// 004b7ad8  8b0f                 mov ecx, dword ptr [edi]
// 004b7ada  2b4f08               sub ecx, dword ptr [edi + 8]
// 004b7add  8b442420             mov eax, dword ptr [esp + 0x20]
// 004b7ae1  3bc8                 cmp ecx, eax
// 004b7ae3  7311                 jae 0x4b7af6
// 004b7ae5  5d                   pop ebp
// 004b7ae6  5f                   pop edi
// 004b7ae7  32c0                 xor al, al
// 004b7ae9  5e                   pop esi
// 004b7aea  59                   pop ecx
// 004b7aeb  c21000               ret 0x10
// 004b7aee  5f                   pop edi
// 004b7aef  32c0                 xor al, al
// 004b7af1  5e                   pop esi
// 004b7af2  59                   pop ecx
// 004b7af3  c21000               ret 0x10
// 004b7af6  53                   push ebx
// 004b7af7  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 004b7afb  56                   push esi
// 004b7afc  53                   push ebx
// 004b7afd  50                   push eax
// 004b7afe  57                   push edi
// 004b7aff  8bcd                 mov ecx, ebp
// 004b7b01  e8aac20000           call 0x4c3db0
// 004b7b06  3bc3                 cmp eax, ebx
// 004b7b08  7d0e                 jge 0x4b7b18
// 004b7b0a  5b                   pop ebx
// 004b7b0b  5d                   pop ebp
// 004b7b0c  c6043000             mov byte ptr [eax + esi], 0
// 004b7b10  5f                   pop edi
// 004b7b11  b001                 mov al, 1
// 004b7b13  5e                   pop esi
// 004b7b14  59                   pop ecx
// 004b7b15  c21000               ret 0x10
// 004b7b18  c6441eff00           mov byte ptr [esi + ebx - 1], 0
// 004b7b1d  5b                   pop ebx
// 004b7b1e  5d                   pop ebp
// 004b7b1f  5f                   pop edi
// 004b7b20  b001                 mov al, 1
// 004b7b22  5e                   pop esi
// 004b7b23  59                   pop ecx
// 004b7b24  c21000               ret 0x10

// RakNet 3.0 StringCompressor::DecodeString (Map::Has inlined; Map::Get,
// OrderedList::GetIndexFromKey, BitStream::ReadCompressed(uchar*,int,bool) and
// HuffmanEncodingTree::DecodeArray called).
// Layouts from the target: Map lastSearchIndex +0xc, lastSearchKey +0x10,
// lastSearchIndexValid +0x14; BitStream numberOfBitsUsed +0, readOffset +8.

namespace DataStructures
{
    template <class key_type>
    int defaultMapKeyComparison(const key_type &a, const key_type &b)
    {
        if (a < b) return -1;
        if (a == b) return 0;
        return 1;
    }

    struct OrderedListIntNode
    {
        void *listArray;
        unsigned int list_size;
        unsigned int allocation_size;
        unsigned GetIndexFromKey(const int &key, bool *objectExists) const;   // 0x4b7650
    };

    template <class key_type, class data_type>
    class Map
    {
    public:
        data_type &Get(const key_type &key);                                  // 0x4b7820
        bool Has(const key_type &key)
        {
            if (HasSavedSearchResult(key))
                return true;

            bool objectExists;
            unsigned index;
            index = mapNodeList.GetIndexFromKey(key, &objectExists);
            if (objectExists)
                SaveLastSearch(key, index);
            return objectExists;
        }

    protected:
        OrderedListIntNode mapNodeList;

        void SaveLastSearch(const key_type &key, const unsigned index)
        {
            lastSearchIndex = index;
            lastSearchKey = key;
            lastSearchIndexValid = true;
        }
        bool HasSavedSearchResult(const key_type &key) const
        {
            return lastSearchIndexValid && defaultMapKeyComparison<key_type>(key, lastSearchKey) == 0;
        }

        unsigned lastSearchIndex;
        key_type lastSearchKey;
        bool lastSearchIndexValid;
    };
}

namespace RakNet
{
    class BitStream
    {
    public:
        template <class templateType>
        bool ReadCompressed(templateType &var)
        {
            return ReadCompressed((unsigned char *)&var, sizeof(templateType) * 8, true);
        }
        bool ReadCompressed(unsigned char *output, const int size, const bool unsignedData);   // 0x49fa50
        inline int GetNumberOfUnreadBits(void) const { return numberOfBitsUsed - readOffset; }

    private:
        int numberOfBitsUsed;
        int numberOfBitsAllocated;
        int readOffset;
    };
}

class HuffmanEncodingTree
{
public:
    unsigned DecodeArray(RakNet::BitStream *input, unsigned sizeInBits, unsigned maxCharsToWrite, unsigned char *output);  // 0x4c3db0
};

class StringCompressor
{
public:
    bool DecodeString(char *output, int maxCharsToWrite, RakNet::BitStream *input, int languageID);

private:
    DataStructures::Map<int, HuffmanEncodingTree *> huffmanEncodingTrees;
};

bool StringCompressor::DecodeString(char *output, int maxCharsToWrite, RakNet::BitStream *input, int languageID)
{
    HuffmanEncodingTree *huffmanEncodingTree;
    if (huffmanEncodingTrees.Has(languageID) == false)
        return false;
    huffmanEncodingTree = huffmanEncodingTrees.Get(languageID);

    unsigned int stringBitLength;
    int bytesInStream;

    output[0] = 0;

    if (input->ReadCompressed(stringBitLength) == false)
        return false;

    if ((unsigned)input->GetNumberOfUnreadBits() < stringBitLength)
        return false;

    bytesInStream = huffmanEncodingTree->DecodeArray(input, stringBitLength, maxCharsToWrite, (unsigned char *)output);

    if (bytesInStream < maxCharsToWrite)
        output[bytesInStream] = 0;
    else
        output[maxCharsToWrite - 1] = 0;

    return true;
}
