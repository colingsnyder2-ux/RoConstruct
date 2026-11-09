// from server: 100% by colin
struct SurfaceGetSet {
    int get;
    int set;
    void setValue(int instance) const;
};

extern "C" int __fastcall sub_00573890(int);

void SurfaceGetSet::setValue(int instance) const
{
    int obj;
    if (instance != 0) {
        obj = sub_00573890(instance - 4);
    } else {
        obj = sub_00573890(0);
    }
    int fn = *(int*)((char*)this + 4);
    ((void (__thiscall*)(int))fn)(obj + 0x10);
}
