// from server: 35% by atomic.potato
struct GfxClustererPart
{
    char pad0[4];
    unsigned int count;
    int capacity;
    char padC[4];
    void resize(int);
};

extern "C" void *__cdecl sub_542840();

struct Vec3
{
    float x, y, z;
};

struct Entry
{
    char pad0[0x10];
    void *vtable;
    Vec3 pos;
    float w;
};

void GfxClustererPart::resize(int newCount)
{
    int oldCount = count;
    if (oldCount == newCount)
        return;

    int oldCap = capacity;
    count = newCount;

    if (newCount < oldCount)
    {
        int i = oldCount - newCount;
        Entry *p = (Entry *)((char *)this + 0) + newCount;
        while (i)
        {
            p->vtable = (void *)0xa7fbc4;
            p++;
            i--;
        }
    }

    if (count > capacity)
    {
        if (capacity == 0)
        {
            capacity = newCount;
            resize(oldCount);
        }
        else
        {
            int cap = capacity;
            if (cap < 10)
            {
                capacity = 10;
            }
            else
            {
                float f;
                int scaled = cap * 36;
                if (scaled > 0x61a80)
                    f = *(float *)0xa78a94;
                else if (scaled > 0xfa00)
                    f = *(float *)0xa75cec;
                else
                    f = *(float *)0xa76e74;
                int grown = (int)((float)cap * f) - cap + count;
                capacity = grown;
                if (grown < 10)
                    capacity = 10;
            }
            resize(oldCount);
        }
    }
    else
    {
        int cap = capacity;
        int third = cap / 3;
        if (count > third)
        {
            if (*(char *)0 == 0)
            {
            }
            else if (count > 10)
            {
                if (count >= oldCount)
                    count = oldCount;
                resize(count);
            }
        }
    }

    if (oldCount < count)
    {
        Entry *p = (Entry *)((char *)this + 0) + oldCount;
        while (oldCount < count)
        {
            if (p)
            {
                p->vtable = (void *)0xa7fbc4;
                Vec3 *v = (Vec3 *)sub_542840();
                p->pos = *v;
                p->w = 0.0f;
            }
            oldCount++;
            p++;
        }
    }
}
