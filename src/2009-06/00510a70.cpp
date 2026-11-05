// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern void (*rakFree)(void*);
struct RPCNode { char* uniqueIdentifier; };
template<class T> struct List {
    T* listArray; unsigned list_size; unsigned allocation_size;
    unsigned Size() const { return list_size; }
    T& operator[](unsigned i) const { return listArray[i]; }
    void Clear() {
        if (allocation_size == 0) return;
        delete[] listArray;
        allocation_size = 0; listArray = 0; list_size = 0;
    }
};
class RPCMap { public: List<RPCNode*> rpcSet; void Clear(); };
void RPCMap::Clear(void)
{
	unsigned i;
	RPCNode *node;
	for (i=0; i < rpcSet.Size(); i++)
	{
		node=rpcSet[i];
		if (node)
		{
			rakFree(node->uniqueIdentifier);
			delete node;
		}
	}
	rpcSet.Clear();
}
