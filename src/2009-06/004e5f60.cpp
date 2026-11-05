// from server: 43% by atomic.potato
struct S {
    char pad0[0x2be8];
    char field_2be8[0x2d0];
    char field_2eb8[0x100];

    void f(void* arg);
};

extern "C" void __stdcall sub_4DC760(void* a, void* b);
extern "C" void __stdcall sub_4DD200(void* a, void* b);
extern "C" void __stdcall sub_4E4880(void* a, int b);
extern "C" int __stdcall sub_507340();
extern "C" void __stdcall sub_50C150(void* a, void* b);
extern "C" void* __stdcall sub_718A38(int size);

void S::f(void* arg)
{
    char local;
    sub_4DC760(arg, &local);
    sub_4DD200(arg, &local);
    if (local != 0) {
        int t = sub_507340();
        sub_4E4880(field_2eb8, t - *(int*)&local);
    } else {
        void* p = sub_718A38(0x18);
        if (p != 0) {
            *(int*)((char*)p + 8) = 0;
            *(int*)((char*)p + 0xc) = 0;
            *(int*)((char*)p + 0x14) = *(int*)&local;
            *(int*)((char*)p + 0x10) = (int)this;
            *(int*)((char*)p + 0) = 0x8c6e7c;
            sub_50C150(field_2be8, p);
        } else {
            sub_50C150(field_2be8, 0);
        }
    }
}
