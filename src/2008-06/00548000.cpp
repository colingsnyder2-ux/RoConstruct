// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// Analog for 00548000: allocates a slot in parallel global arrays, reusing a
// freed index (pop 0054ae50) when the free list (size 0054ad50) is non-empty.
template<class T>
class Array {
public:
    int size() const;
    void append(const T& value);
    T& operator[](int n);
    T pop(bool shrinkUnderlyingArrayIfNecessary);
    T* data;
    int num;
    int numAllocated;
};

template<class T>
class List {
public:
    void push_back(const T& value);
    T& operator[](unsigned n);
    char data[0x10];
};

template<class T>
class Pool {
public:
    unsigned size() const;
    T pop(bool shrink);
    char data[0x0c];
};

class Vec3 {
public:
    Vec3& operator=(const Vec3& other);
    float x, y, z;
};

class Vec2 {
public:
    Vec2& operator=(const Vec2& other);
    float x, y;
};

const Vec3& defaultVec3();

extern bool slotsInitialized;
extern bool slotsDirty;
extern Pool<int> freeSlots;
extern Array<Vec3> slotFirst;
extern Array<Vec3> slotSecond;
extern Array<Vec3> slotFourth;
extern Array<Vec2> slotThird;
extern List<int> slotUsed;
extern int slotCount;

int allocateSlot(const Vec3& first, const Vec3& second, const Vec2& third)
{
    if (!slotsInitialized)
        slotsInitialized = true;
    slotsDirty = true;
    int index;
    if (freeSlots.size() == 0) {
        index = slotFirst.size();
        do {} while (0);
        slotFirst.append(first);
        do {} while (0);
        slotSecond.append(second);
        do {} while (0);
        slotThird.append(third);
        do {} while (0);
        slotFourth.append(defaultVec3());
        do {} while (0);
        slotUsed.push_back(1);
    } else {
        index = freeSlots.pop(false);
        slotFirst[index] = first;
        slotSecond[index] = second;
        slotThird[index] = third;
        slotFourth[index] = defaultVec3();
        do {} while (0);
        slotUsed[index] = 1;
    }
    ++slotCount;
    return index;
}
