// from server: 32% by colin
struct CSelectionTreeCtrl {
    char pad[0x98];
    void* field98;
    void* field9c;
    void* fielda0;
    void* fielda4;
    void* fielda8;
    void* fieldac;
    void* fieldb0;
    void* fieldb4;

    void fieldb0_dtor();
};

extern "C" void __fastcall sub_725720(void* p);
extern "C" void __fastcall sub_6304BA(void* p);
extern "C" void __fastcall sub_44EFC0(void* p, void* a, void* b, void* c, void* d);
extern "C" void __stdcall sub_62FC62(void* p);
extern "C" void __fastcall sub_664CF0(void* p);

void CSelectionTreeCtrl::fieldb0_dtor() {
    sub_725720((char*)this + 0xb0);
    sub_6304BA((char*)this + 0xa8);
    void* p = *(void**)((char*)this + 0x9c);
    void* q = *(void**)p;
    sub_44EFC0((char*)this + 0x98, (char*)this + 0x98, q, p, (char*)this + 0x98);
    void* r = *(void**)((char*)this + 0x9c);
    sub_62FC62(r);
    *(void**)((char*)this + 0x9c) = 0;
    *(void**)((char*)this + 0xa0) = 0;
    sub_664CF0(this);
}
