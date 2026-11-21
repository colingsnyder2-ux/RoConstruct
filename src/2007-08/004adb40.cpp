// from server: 100% by Intel_Inside


#include <vector>

namespace RBX {

class SlotBase {
public:
    virtual ~SlotBase();
};

template<class T>
class Slot : public SlotBase {
public:
    T value;
};

extern unsigned int nextSlotIndex;

template<class T>
struct SlotIndex {
    static unsigned int get() {
        static unsigned int index = nextSlotIndex++;
        return index;
    }
};

class SlotTable {
    std::vector<SlotBase*> slots;
public:
    unsigned int size() const;

    template<class T>
    T& get() {
        while (size() <= SlotIndex<T>::get())
            slots.push_back(NULL);
        SlotBase*& slot = slots[SlotIndex<T>::get()];
        if (!slot)
            slot = new Slot<T>;
        return static_cast<Slot<T>*>(slot)->value;
    }
};

unsigned int SlotTable::size() const
{
    return slots.size();
}

struct AutoJointState {
    int field_0;
};

template AutoJointState& SlotTable::get<AutoJointState>();

}
