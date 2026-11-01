// from server: 37% by Intel
extern "C" void __cdecl Function518d80(void *, int, void *);

struct G3D_VVector2int16_TypedPropertyDescriptor
{
    char pad_0[0xE0];
    int *begin;
    int *end;
    int *capacity_end;
    int *first;
    int *last;

    bool __stdcall f(int value);
};

bool __stdcall G3D_VVector2int16_TypedPropertyDescriptor::f(int value)
{
    int *first = this->first;
    int *last = this->last;
    if (first != last)
    {
        do
        {
            if (*first == value)
                return false;
            ++first;
        } while (first != last);
    }

    int *begin = this->begin;
    int *end = this->end;
    int size = 0;
    if (end != 0)
        size = (end - begin) >> 2;

    int *capacity_end = this->capacity_end;
    int capacity = (capacity_end - begin) >> 2;

    if (size < capacity)
    {
        *end = value;
        this->end = end + 1;
        return true;
    }

    Function518d80(this, 1, &value);
    return true;
}
