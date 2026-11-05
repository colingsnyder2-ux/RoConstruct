// from server: 100% by EspClaude
// roc 2009-06 00510980  unit: RakNet RPCMap::RemoveNode
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
__declspec(dllimport) void __cdecl operator delete[](void*);
void __cdecl operator delete(void*);
struct RPCNode {
    char* uniqueIdentifier;
};
struct RPCList {
    RPCNode** listArray;
    RPCNode*& operator[](unsigned i) { return listArray[i]; }
};
class RPCMap {
public:
    unsigned char GetIndexFromFunctionName(const char* uniqueIdentifier);
    void RemoveNode(const char* uniqueIdentifier);
    RPCList rpcSet;
};
void RPCMap::RemoveNode(const char* uniqueIdentifier)
{
    unsigned index;
    index = GetIndexFromFunctionName(uniqueIdentifier);
    RPCNode* node;
    node = rpcSet[index];
    delete[] node->uniqueIdentifier;
    delete node;
    rpcSet[index] = 0;
}
