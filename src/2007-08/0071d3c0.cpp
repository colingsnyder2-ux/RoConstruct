// from server: 100% by colin
struct CXTPTabPaintManager_CColorSetWhidbey
{
    void* vtable;
    char pad[0x58];
    int field_5c;
    int field_60;
    int field_64;
    CXTPTabPaintManager_CColorSetWhidbey* construct();
};

extern "C" void* __cdecl memset(void*, int, unsigned int);

CXTPTabPaintManager_CColorSetWhidbey* CXTPTabPaintManager_CColorSetWhidbey::construct()
{
    this->vtable = (void*)0x7e0d50;
    memset((char*)this + 4, 0, 0x5c);
    this->field_5c = 1;
    this->field_60 = 0;
    this->field_64 = 0;
    return this;
}
