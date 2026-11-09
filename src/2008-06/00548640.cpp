// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// Analog for 00548640: drops one reference to a slot from 00548000; the last
// release clears it and returns the index to the free list (0054ae30).
template<class T>
class List {
public:
    int valid() const;
    unsigned size() const;
    T& operator[](unsigned n);
    char data[0x10];
};

template<class T>
class Pool {
public:
    void push(const T& value);
    char data[0x0c];
};

extern List<int> slotUsed;
extern Pool<unsigned> freeSlots;
extern int slotCount;

void releaseSlot(int index)
{
    if (!slotUsed.valid())
        return;
    if (!slotUsed.size())
        return;
    do {} while (0);
    --slotCount;
    int refs = slotUsed[index];
    do {} while (0);
    if (refs == 1) {
        slotUsed[index] = 0;
        freeSlots.push(index);
    } else {
        slotUsed[index] = refs - 1;
    }
}
