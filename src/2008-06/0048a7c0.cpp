// from server: 100% by king_originala
extern unsigned int initialization_flags;
extern int minimum_capacity;
extern float growth_small;
extern float growth_medium;
extern float growth_large;

struct Element
{
    float x, y, z, w;
};

struct S
{
    Element* data;
    int size;
    int capacity;

    void reallocate(int count);
    void resize(int count, bool allowShrink);
};

void S::resize(int count, bool allowShrink)
{
    int oldSize = size;
    size = count;

    int minimum;
    if (!(initialization_flags & 1))
    {
        initialization_flags |= 1;
        minimum = 10;
        minimum_capacity = minimum;
    }
    else
    {
        minimum = minimum_capacity;
    }

    int newSize = size;
    if (newSize > capacity)
    {
        if (!capacity)
        {
            capacity = count;
            reallocate(oldSize);
        }
        else if (newSize < minimum)
        {
            capacity = minimum;
            reallocate(oldSize);
        }
        else
        {
            double growth = growth_small;
            unsigned int bytes = (unsigned int)capacity * sizeof(Element);
            if (bytes > 400000)
                growth = growth_large;
            else if (bytes > 64000)
                growth = growth_medium;

            int oldCapacity = capacity;
            capacity = (int)(growth * oldCapacity) - oldCapacity + newSize;
            if (capacity < minimum_capacity)
                capacity = minimum_capacity;
            reallocate(oldSize);
        }
    }
    else if (newSize <= capacity / 3 && allowShrink && newSize > minimum)
    {
        reallocate(newSize < oldSize ? newSize : oldSize);
    }

    for (int i = oldSize; i < size; ++i)
    {
        Element* p = data + i;
        if (p)
        {
            p->x = 0.0f;
            p->y = 0.0f;
            p->z = 0.0f;
            p->w = 0.0f;
        }
    }
}
