// from server: 100% by colin
struct RBX_Instance {
    char pad[0xbc];
    RBX_Instance* next;
};

extern "C" int __cdecl sub_630D36(int, int, int, int, int);
extern "C" int __fastcall sub_5E6F10(int);

int __cdecl sub_5E70E0(RBX_Instance* p)
{
    while (p != 0) {
        int r = sub_630D36((int)p, 0, 0x881f4c, 0x884e04, 0);
        if (r != 0) {
            return sub_5E6F10(r);
        }
        p = p->next;
    }
    return 0;
}
