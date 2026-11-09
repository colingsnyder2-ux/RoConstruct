// from server: 100% by colin
extern "C" __declspec(dllimport) void *__stdcall LoadLibraryA(const char *);

struct CXTPPropertyGridItemEnum {
    void *construct();
};

extern void *__fastcall sub_671140(void *);
extern void *__fastcall sub_672130(void *);
extern void __cdecl sub_630B8C(void *, int, int);

void *CXTPPropertyGridItemEnum::construct()
{
    void *p = sub_671140(this);
    void *q = sub_672130(p);
    *(void **)((char *)this + 0xd4) = q;
    sub_630B8C(this, 0, 0xd0);
    *(void **)((char *)this + 0xd0) = LoadLibraryA("UxTheme.dll");
    return this;
}
