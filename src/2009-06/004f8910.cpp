// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace DataStructures {
template<class list_type> class List {
public:
    ~List()
    {
        if (allocation_size > 0)
            delete[] listArray;
    }
    void Clear(bool doNotDeallocateSmallBlocks = false)
    {
        if (allocation_size == 0)
            return;
        if (allocation_size > 512 || doNotDeallocateSmallBlocks == false) {
            delete[] listArray;
            allocation_size = 0;
            listArray = 0;
        }
        list_size = 0;
    }
    list_type* listArray;
    unsigned int list_size;
    unsigned int allocation_size;
};
}
struct Elem { ~Elem(); int a, b; };
class Holder {
public:
    ~Holder();
    DataStructures::List<Elem> list;
};
Holder::~Holder()
{
    list.Clear(false);
}
