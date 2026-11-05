// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// Analog for 00547f60: resets the slot arrays used by 00548000 to one reserved
// slot (resize 00503100/0054bda0/004806b0), marks slot 0 used and clears the
// free list (0054ad30).
template<class T>
class Array {
public:
    void resize(int n);
    T& operator[](int n);
    T* data;
    int num;
    int numAllocated;
};

template<class T>
class Pool {
public:
    void clear();
    char data[0x0c];
};

class Vec3 { public: float x, y, z; };
class Vec2 { public: float x, y; };

extern Pool<int> freeSlots;
extern Array<Vec3> slotFirst;
extern Array<Vec3> slotSecond;
extern Array<Vec3> slotFourth;
extern Array<Vec2> slotThird;
extern Array<int> slotUsed;

void resetSlots()
{
    slotFirst.resize(1);
    slotSecond.resize(1);
    slotThird.resize(1);
    slotFourth.resize(1);
    slotUsed.resize(1);
    slotUsed[0] = 1;
    freeSlots.clear();
}
