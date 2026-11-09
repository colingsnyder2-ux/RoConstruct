// from server: 80% by colin
struct VCRobloxDoc_VerbBinder {
    char pad[0x54];
    void insert(int, int);
};

extern "C" int __cdecl sub_52CB30();
extern "C" int *__fastcall sub_4339D0(int *, int, int *);

void VCRobloxDoc_VerbBinder::insert(int a, int b) {
    int *p;
    if (b != 0) {
        int v = *(int *)(b + 4);
        int tmp = a;
        p = sub_4339D0((int *)((char *)this + 0x54), 0, &tmp);
        *p = v;
    } else {
        int v = sub_52CB30();
        int tmp = a;
        p = sub_4339D0((int *)((char *)this + 0x54), 0, &tmp);
        *p = v;
    }
}
