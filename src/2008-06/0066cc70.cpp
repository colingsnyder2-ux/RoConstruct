// from server: 100% by king_originala
struct Array
{
    void** data;
    int count;
};

int __stdcall f(void* item, const Array* array)
{
    if (item)
    {
        void** found;
        int i = 0;

        for (; i < array->count; ++i)
        {
            if (array->data[i] == item)
            {
                found = array->data + i;
                goto searched;
            }
        }

        found = array->data + array->count;

    searched:
        if (found == array->data + array->count)
            return 1;
    }

    return 0;
}
