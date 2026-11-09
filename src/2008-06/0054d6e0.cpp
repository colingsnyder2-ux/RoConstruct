// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD


#pragma optimize("", off)

extern int __cdecl iMin(int, int);
extern int __cdecl iMax(int, int);

extern const float growthDefault;
extern const float growthLarge;
extern const float growthMedium;

void* __cdecl operator new(unsigned int, void*);
void __cdecl operator delete(void*, void*);

struct Element {
    char storage[24];
    Element();
};

struct Mesh {
    Element* data;
    int size;
    int capacity;

    void resize(int, bool);
    void reallocate(int);
};

void Mesh::resize(int count, bool allowShrink)
{
    int oldSize = size;
    size = count;

    for (int i = size; i < oldSize; ++i) {
    }

    static int minimum = iMax(10, 1);

    if (size > capacity) {
        if (capacity == 0) {
            capacity = count;
            do {
            } while (0);
            reallocate(oldSize);
        } else {
            if (size < minimum) {
                capacity = minimum;
            } else {
                float growth = growthDefault;
                unsigned int bytes = capacity * sizeof(Element);

                if (bytes > 400000)
                    growth = growthLarge;
                else if (bytes > 64000)
                    growth = growthMedium;

                capacity = size - capacity + int(capacity * growth);

                if (capacity < minimum)
                    capacity = minimum;
            }
            reallocate(oldSize);
        }
    } else if (size <= capacity / 3 && allowShrink && size > minimum) {
        reallocate(iMin(size, oldSize));
    }

    for (int i = oldSize; i < size; ++i) {
        new (data + i) Element;
    }
}
