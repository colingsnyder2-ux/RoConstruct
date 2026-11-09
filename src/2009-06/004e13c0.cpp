// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
class HuffmanEncodingTree {
public:
    void GenerateFromFrequencyTable(unsigned int frequencyTable[256]);
};
namespace RakNet { template<class T> T* OP_NEW(); }
namespace DataStructures {
template<class list_type> class List {
public:
    List() { allocation_size = 0; listArray = 0; list_size = 0; }
    ~List();
    list_type* listArray;
    unsigned int list_size;
    unsigned int allocation_size;
};
template<class key_type, class data_type> class Map {
public:
    struct MapNode { key_type mapNodeKey; data_type mapNodeData; };
    static void IMPLEMENT_DEFAULT_COMPARISON() {}
    Map() { lastSearchIndexValid = false; }
    ~Map();
    void Set(const key_type& key, const data_type& data);
    List<MapNode> mapNodeList;
    key_type lastSearchKey;
    unsigned lastSearchIndex;
    bool lastSearchIndexValid;
};
}
extern unsigned int englishCharacterFrequencies[256];
class StringCompressor {
public:
    StringCompressor();
    DataStructures::Map<int, HuffmanEncodingTree*> huffmanEncodingTrees;
};
StringCompressor::StringCompressor()
{
    DataStructures::Map<int, HuffmanEncodingTree*>::IMPLEMENT_DEFAULT_COMPARISON();
    HuffmanEncodingTree* huffmanEncodingTree = RakNet::OP_NEW<HuffmanEncodingTree>();
    huffmanEncodingTree->GenerateFromFrequencyTable(englishCharacterFrequencies);
    huffmanEncodingTrees.Set(0, huffmanEncodingTree);
}
