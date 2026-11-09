// from server: 100% by tester
struct PrismPoly {
    static void destroy(PrismPoly* p);
};

extern "C" void __cdecl sub_90BFB0(void*, void*);
extern "C" void __cdecl sub_982114(void*);

void PrismPoly::destroy(PrismPoly* p)
{
    if (p) {
        sub_90BFB0(p, *(void**)((char*)p + 0x14));
        sub_982114(p);
    }
}
