// from server: 50% by Intel
// roc 2012-06 00465230  unit: VCRenderSettingsItem::?$FactoryProduct  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00465230

extern "C" void* __cdecl sub_98211a(unsigned int);
extern "C" void* __cdecl sub_982114(unsigned int);

extern "C" const int g_b57ca0;

struct FactoryProduct {
    void* method(int a1, int a2, int a3);
};

void* FactoryProduct::method(int a1, int a2, int a3)
{
    void* v1 = sub_98211a(0x10);
    if (v1)
    {
        *(int*)v1 = g_b57ca0;
        *(int*)((char*)v1 + 4) = a1;
        *(int*)((char*)v1 + 8) = a2;
        *(int*)((char*)v1 + 12) = a3;
    }
    else
    {
        v1 = 0;
    }
    int* v2 = (int*)sub_982114(0);
    *v2 = (int)v1;
    return v2;
}
