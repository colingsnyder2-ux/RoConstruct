// from server: 51% by colin
struct CRobloxControlColorSelector
{
    int sub_44BBD0(int* value);
    int* sub_44BB80(int* out, int index);
    int method(int* a, int* b, int* c, int* d);
};

extern "C" int __stdcall sub_44BA60(int index);
extern "C" void* __stdcall sub_77DD74(void* self, void* value);
extern "C" void* __stdcall sub_77DDB8(void* self, const char* message);

int CRobloxControlColorSelector::method(int* a, int* b, int* c, int* d)
{
    int local = 0;
    if (a == 0)
        goto fail;
    if (b == 0)
        goto fail;
    if (c == 0)
        goto fail;

    {
        int value[2];
        value[0] = a[0];
        value[1] = a[1];

        int index = sub_44BBD0(value);
        if (index == -1)
            goto fail;

        int* entry = (int*)sub_44BA60(index);
        *c = entry[1];

        int temp[4];
        int* result = sub_44BB80(temp, index);
        b[0] = result[0];
        b[1] = result[1];
        b[2] = result[2];
        b[3] = result[3];

        int* entry2 = (int*)sub_44BA60(index);
        sub_77DD74(d, entry2 + 2);
    }

    return (int)d;

fail:
    sub_77DDB8(d, (const char*)0x785954);
    return (int)d;
}
