// from server: 40% by colin
struct CRobloxDoc {
    void construct();
};

extern "C" void* __stdcall sub_62FF5C();
extern "C" void* __stdcall sub_5835B0();

void CRobloxDoc::construct() {
    sub_62FF5C();
    *(void**)((char*)this + 0x54) = 0;
    *(void**)((char*)this + 0x58) = 0;
    *(void**)((char*)this + 0x5C) = 0;
    *(void**)((char*)this + 0x60) = 0;
    *(void**)this = (void*)0x79172C;
    void* p = sub_5835B0();
    *(void**)((char*)this + 0x58) = p;
    *(unsigned char*)((char*)p + 0x15) = 1;
    void* q = *(void**)((char*)this + 0x58);
    *(void**)((char*)q + 4) = q;
    void* r = *(void**)((char*)this + 0x58);
    *(void**)r = r;
    void* s = *(void**)((char*)this + 0x58);
    *(void**)((char*)s + 8) = s;
    *(void**)((char*)this + 0x5C) = 0;
}
