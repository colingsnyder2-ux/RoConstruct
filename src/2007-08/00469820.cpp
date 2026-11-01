// from server: 100% by colin
extern "C" int* __stdcall sub_4697c0(int index);

struct LDraw2RobloxColorMap
{
    int lookup(int index);
};

int LDraw2RobloxColorMap::lookup(int index)
{
    int* p = sub_4697c0(index);
    if (p)
        return p[2];
    return 1;
}
