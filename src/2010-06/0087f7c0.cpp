// from server: 22% by atomic.potato
struct CXTPPropertyGridOffice2007Theme {
    char pad0[0x34];
    int field34;
    char pad1[0x08];
    int field40;
    char pad2[0x08];
    int field4c;
    char pad3[0x08];
    int field58;
    char pad4[0x18];
    int field74;
    void Init();
};

extern "C" void* __stdcall sub_9ecee8(const char*);

void* __fastcall sub_895a70();
void __fastcall sub_895370(void* self, void* arg);

void CXTPPropertyGridOffice2007Theme::Init()
{
    void* p;
    void* q;
    void* r;
    void* s;
    void* t;
    void* u;
    void* v;

    sub_9ecee8((const char*)0xa6e568);
    p = sub_895a70();
    sub_895370(p, 0);
    *(void**)((char*)this->field74 + 0x4c + 4) = p;
    sub_9ecee8((const char*)0xa6e534);
    q = sub_895a70();
    sub_895370(q, 0);
    *(void**)((char*)this->field74 + 0x64 + 4) = q;
    sub_9ecee8((const char*)0xa6e524);
    r = sub_895a70();
    sub_895370(r, 0);
    this->field58 = (int)r;
    sub_9ecee8((const char*)0xa6e518);
    s = sub_895a70();
    sub_895370(s, 0);
    this->field4c = (int)s;
    sub_9ecee8((const char*)0xa6e568);
    t = sub_895a70();
    sub_895370(t, 0);
    this->field34 = 0xffd1ad;
    this->field40 = 0xcf9365;
    *(int*)((char*)this->field74 + 0x38) = 0xffe8d6;
    *(int*)((char*)this->field74 + 0x44) = 0;
    *(int*)((char*)this->field74 + 0x50) = 0xffe8d6;
    *(int*)((char*)this->field74 + 0x68) = 0x8b4215;
    this->field58 = 0;
    this->field4c = 0xe8c8b3;
}
