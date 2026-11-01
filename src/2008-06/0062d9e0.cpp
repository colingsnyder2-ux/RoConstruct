// from server: 100% by colin
extern int minimumCapacity;
extern int minimumCapacityInitialized;
extern const float smallGrowthFactor;
extern const float mediumGrowthFactor;
extern const float largeGrowthFactor;

struct S
{
    int* data;
    int count;
    int capacity;

    void reallocate(int oldCount);
    void resize(int newCount, bool allowShrink);
};

void S::resize(int newCount, bool allowShrink)
{
    int oldCount = count;
    count = newCount;

    int minimum;
    if (!(static_cast<unsigned char>(minimumCapacityInitialized) & 1))
    {
        minimumCapacityInitialized |= 1;
        minimum = 10;
        minimumCapacity = minimum;
    }
    else
    {
        minimum = minimumCapacity;
    }

    int initialCapacity = capacity;
    int currentCount = count;

    if (currentCount > initialCapacity)
    {
        if (initialCapacity == 0)
        {
            capacity = newCount;
            reallocate(oldCount);
            return;
        }

        if (currentCount < minimum)
        {
            capacity = minimum;
            reallocate(oldCount);
            return;
        }

        double factor = smallGrowthFactor;
        unsigned int bytes = capacity * sizeof(int);
        if (bytes > 400000)
            factor = largeGrowthFactor;
        else if (bytes > 64000)
            factor = mediumGrowthFactor;

        int previousCapacity = capacity;
        capacity = static_cast<int>(factor * previousCapacity)
                 - previousCapacity + currentCount;

        if (capacity < minimumCapacity)
            capacity = minimumCapacity;

        reallocate(oldCount);
        return;
    }

    if (currentCount <= initialCapacity / 3 &&
        allowShrink &&
        currentCount > minimum)
    {
        if (currentCount >= oldCount)
            currentCount = oldCount;

        reallocate(currentCount);
    }
}
