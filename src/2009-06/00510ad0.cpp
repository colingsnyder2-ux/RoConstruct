// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string.h>
typedef unsigned char RPCIndex;
#define UNDEFINED_RPC_INDEX ((RPCIndex)255)
extern void* (*rakMalloc)(size_t size);
struct RPCNode {
    char* uniqueIdentifier;
    void* functionPointer;
    bool isPointerToMember;
};
namespace DataStructures {
template<class list_type> class List {
public:
    list_type* listArray;
    unsigned int list_size;
    unsigned int allocation_size;
    list_type& operator[](const unsigned int position) const { return listArray[position]; }
    void Insert(const list_type input);
    void Replace(const list_type input, const list_type filler, const unsigned int position);
    unsigned int Size() const { return list_size; }
};
}
class RPCMap {
public:
    DataStructures::List<RPCNode*> rpcSet;
    RPCIndex GetIndexFromFunctionName(const char* uniqueIdentifier);
    void AddIdentifierWithFunction(const char* uniqueIdentifier, void* functionPointer, bool isPointerToMember);
};
void RPCMap::AddIdentifierWithFunction(const char *uniqueIdentifier, void *functionPointer, bool isPointerToMember)
{
    unsigned index, existingNodeIndex;
    RPCNode *node;

    existingNodeIndex=GetIndexFromFunctionName(uniqueIdentifier);
    if ((RPCIndex)existingNodeIndex!=UNDEFINED_RPC_INDEX)
    {
        return;
    }

    node = new RPCNode;
    node->uniqueIdentifier = (char*) rakMalloc(strlen(uniqueIdentifier)+1);
    strcpy(node->uniqueIdentifier, uniqueIdentifier);
    node->functionPointer=functionPointer;
    node->isPointerToMember=isPointerToMember;

    for (index=0; index < rpcSet.Size(); index++)
    {
        if (rpcSet[index]==0)
        {
            rpcSet.Replace(node, 0, index);
            return;
        }
    }

    rpcSet.Insert(node);
}
