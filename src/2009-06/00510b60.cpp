// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string.h>
extern void* (*rakMalloc) (size_t size);
extern void* (*rakRealloc) (void *p, size_t size);
extern void (*rakFree) (void *p);
namespace DataStructures {
template <class list_type> class List {
public:
    list_type& operator[](const unsigned int position) const { return listArray[position]; }
    void Replace(const list_type input, const list_type filler, const unsigned int position);
    unsigned int Size(void) const { return list_size; }
    list_type* listArray;
    unsigned int list_size;
    unsigned int allocation_size;
};
}
typedef unsigned char RPCIndex;
static const RPCIndex UNDEFINED_RPC_INDEX = ((RPCIndex)-1);
struct RPCNode {
    char* uniqueIdentifier;
    void* functionPointer;
    bool isPointerToMember;
};
struct RPCMap {
    RPCIndex GetIndexFromFunctionName(const char* uniqueIdentifier);
    void AddIdentifierAtIndex(const char* uniqueIdentifier, RPCIndex insertionIndex);
    DataStructures::List<RPCNode*> rpcSet;
};
void RPCMap::AddIdentifierAtIndex(const char *uniqueIdentifier, RPCIndex insertionIndex)
{
	unsigned existingNodeIndex;
	RPCNode *node, *oldNode;

	existingNodeIndex=GetIndexFromFunctionName(uniqueIdentifier);

	if (existingNodeIndex==insertionIndex)
		return; // Already there

	if ((RPCIndex)existingNodeIndex!=UNDEFINED_RPC_INDEX)
	{
		oldNode=rpcSet[existingNodeIndex];
		rpcSet[existingNodeIndex]=0;
		rakFree(oldNode->uniqueIdentifier);
		delete oldNode;
	}

	node = new RPCNode;
	node->uniqueIdentifier = (char*) rakMalloc(strlen(uniqueIdentifier)+1);
	strcpy(node->uniqueIdentifier, uniqueIdentifier);
	node->functionPointer=0;

	if (insertionIndex < rpcSet.Size())
	{
		oldNode=rpcSet[insertionIndex];
		if (oldNode)
		{
			delete [] oldNode->uniqueIdentifier;
			delete oldNode;
		}
		rpcSet[insertionIndex]=node;
	}
	else
	{
		rpcSet.Replace(node, 0, insertionIndex);
	}
}
