// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <new>
extern void (*rakFree)(void*);
namespace DataStructures {
template<class list_type> class List {
public:
    list_type* listArray;
    unsigned int list_size;
    unsigned int allocation_size;
    ~List() { Clear(); if (allocation_size > 0) delete[] listArray; }
    list_type& operator[](const unsigned int position) const { return listArray[position]; }
    unsigned int Size() const { return list_size; }
    void Clear(bool doNotDeallocate = false) {
        if (allocation_size == 0) return;
        if (allocation_size > 512 || doNotDeallocate == false) {
            delete[] listArray;
            allocation_size = 0;
            listArray = 0;
        }
        list_size = 0;
    }
};
}
struct Elem { char* data; bool own; };
struct Owner {
    DataStructures::List<Elem> list;
    ~Owner();
};
Owner::~Owner() {
    for (unsigned i = 0; i < list.Size(); i++)
        if (list[i].own) rakFree(list[i].data);
}
