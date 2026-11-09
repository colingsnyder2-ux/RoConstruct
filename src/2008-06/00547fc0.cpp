// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// Analog for 00547fc0: adds references to a slot from 00548000 and to the
// global count, returning the slot index.
template<class T>
class List {
public:
    T& operator[](unsigned n);
    char data[0x10];
};

extern List<int> slotUsed;
extern int slotCount;

int addSlotReferences(int index, int amount)
{
    do {} while (0);
    int& refs = slotUsed[index];
    refs += amount;
    slotCount += amount;
    return index;
}
