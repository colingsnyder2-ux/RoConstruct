// from server: 28% by atomic.potato
extern "C" void* __cdecl sub_982114(void*);
extern "C" void* __cdecl sub_98211a(unsigned int);
extern "C" void* __cdecl sub_531430(int, int);
extern "C" void __cdecl sub_972290(unsigned char, const char*);
extern "C" void __cdecl sub_40ccf0(void*, void*);
extern "C" void* __cdecl sub_7e8a30(void*, int, int, int, int, int);

struct VGuiTextButton {
    void* FactoryProduct(int, int, int, int, int, int, int, int, int, int);
};

void* VGuiTextButton::FactoryProduct(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
    void* p = sub_7e8a30(&a1, a2, a3, a4, a5, a6);
    void* q = *(void**)p;
    *(void**)p = 0;
    void* r = sub_531430(a7, a8);
    sub_40ccf0(this, r);
    sub_982114((void*)a10);
    *(void**)this = (void*)0xbc2cf8;
    if (*(unsigned char*)0xe580b3 != 0) {
        if (*(unsigned char*)0xe580b3 != 0) {
            if (*(unsigned char*)0xe580b3 != 0) {
                if (*(unsigned char*)0xe580b3 != 0) {
                }
            }
        }
    }
    return this;
}
