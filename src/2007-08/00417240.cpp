// from server: 100% by colin
extern "C" int __cdecl func_0062fef6(int);
extern "C" int __cdecl func_0062fc62(int);

struct type_info {
    bool __thiscall operator==(const type_info&) const;
};

extern type_info type_info_00883790;
extern bool (__thiscall* ptr_0077e708)(const type_info*, const type_info*);

int __cdecl func_00417240(int a, int b)
{
    if (b == 2) {
        int v = a;
        bool r = ptr_0077e708(&type_info_00883790, (const type_info*)v);
        return r ? v : 0;
    }
    if (b == 0) {
        int p = func_0062fef6(1);
        if (p != 0) {
            *(char*)p = *(char*)a;
        }
        return p;
    }
    func_0062fc62(a);
    return 0;
}
