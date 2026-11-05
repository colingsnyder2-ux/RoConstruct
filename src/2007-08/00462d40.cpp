// from server: 42% by colin
struct CInstanceExplorer {
    char pad[0x310];
    CInstanceExplorer();
};

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl sub_0041e690();

CInstanceExplorer::CInstanceExplorer()
{
    void* p = operator_new(0x310);
    if (p != 0) {
        sub_0041e690();
        *(void**)p = (void*)0x79559c;
        *(void**)((char*)p + 0x2cc) = (void*)0x795588;
        *(void**)((char*)p + 0x2e8) = (void*)0x795574;
    }
}
