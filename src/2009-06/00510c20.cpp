// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <new>
namespace DataStructures {
template<class T> class List {
public:
    ~List() { if (allocation_size > 0) delete[] listArray; }
    T* listArray; unsigned list_size, allocation_size;
};
}
struct RPCNode;
class RPCMap {
public:
    ~RPCMap();
    void Clear();
    DataStructures::List<RPCNode*> rpcSet;
};
RPCMap::~RPCMap() { Clear(); }
