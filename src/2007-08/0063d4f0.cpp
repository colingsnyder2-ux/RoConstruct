// from server: 100% by colin
struct CXTPPaintManager
{
    char pad[0xd8];
    int field_d8;
    int field_e0;
    int field_e8;
    int field_f0;
    int field_fc;

    int* get(int, int);
};

int* CXTPPaintManager::get(int a, int b)
{
    int v = *(int*)((char*)a + 0xfc);
    if (v == 2 || v == 3)
    {
        if (b != 0)
            return (int*)((char*)this + 0xf0);
        return (int*)((char*)this + 0xe8);
    }
    if (b != 0)
        return (int*)((char*)this + 0xe0);
    return (int*)((char*)this + 0xd8);
}
