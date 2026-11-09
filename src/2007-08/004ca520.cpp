// from server: 65% by Intel
struct VTable {
    void* v0;
    void* v1;
    void* v2;
    void* v3;
    void* v4;
    void* v5;
    int (__thiscall* v6)(void*);
};

struct Object {
    VTable* vptr;
};

extern "C" Object* __stdcall sub_4CA490(Object* a1, int a2, int a3);

int __stdcall sub_4CA520(int a1, int a2, int a3)
{
    Object* obj;
    int result;

    obj = sub_4CA490((Object*)a1, a2, a3);
    if (!obj)
        return 0;

    result = obj->vptr->v6(obj);
    if (result)
    {
        result = obj->vptr->v6(obj);
        return result;
    }

    return (int)obj;
}
