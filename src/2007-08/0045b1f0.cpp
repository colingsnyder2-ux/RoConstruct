// from server: 26% by TrollStein
struct StatsItem {
    char pad0[0x128];
    int field128;
    int field130;
    int field134;
    int field138;
    int field13c;
    int field140;
    int field144;
    int field148;
};

void sub_45AAC0(void*);
void* sub_45AFB0(void*, const char*, void*);
void* sub_45B0D0(void*, const char*, void*);
void* sub_5974E0(void*, const char*);

StatsItem* __stdcall StatsItem_ctor(StatsItem* self, int arg)
{
    sub_45AAC0(self);
    self->field128 = arg;
    *(void**)((char*)self + 0x00) = (void*)0x793c0c;
    *(void**)((char*)self + 0x04) = (void*)0x793c00;
    *(void**)((char*)self + 0x10) = (void*)0x793bf8;
    *(void**)((char*)self + 0x14) = (void*)0x793be8;
    *(void**)((char*)self + 0x2c) = (void*)0x793bd8;
    *(void**)((char*)self + 0x44) = (void*)0x793bc8;
    *(void**)((char*)self + 0x5c) = (void*)0x793bb8;
    *(void**)((char*)self + 0x74) = (void*)0x793ba8;
    *(void**)((char*)self + 0x8c) = (void*)0x793b98;

    sub_45AFB0(self, (const char*)0x793c54, (void*)(arg + 0x108));
    void* r = sub_45AFB0(self, (const char*)0x793b84, (void*)(arg + 0x108));
    r = sub_45AFB0(r, (const char*)0x793b78, (void*)(arg + 0x160));
    r = sub_45AFB0(r, (const char*)0x793b64, (void*)(arg + 0x1b8));
    r = sub_45AFB0(r, (const char*)0x793b5c, (void*)(arg + 0xb0));
    r = sub_45B0D0(r, (const char*)0x793b50, (void*)(arg + 0x220));
    r = sub_45B0D0(r, (const char*)0x793b40, (void*)(arg + 0x228));
    r = sub_45B0D0(r, (const char*)0x793b28, (void*)(arg + 0x234));
    r = sub_45B0D0(r, (const char*)0x793b18, (void*)(arg + 0x22c));
    r = sub_45B0D0(r, (const char*)0x793b08, (void*)(arg + 0x230));
    sub_45AFB0(self, (const char*)0x793afc, (void*)(arg + 0x58));

    void* p = sub_5974E0(self, (const char*)0x793af0);
    self->field130 = (int)p;
    sub_45B0D0(p, (const char*)0x793ae0, (void*)0x8bfbdc);
    sub_45B0D0((void*)self->field130, (const char*)0x793acc, (void*)0x8bfbe0);
    sub_45B0D0((void*)self->field130, (const char*)0x793abc, (void*)0x8bfbe4);

    void* q = sub_5974E0(self, (const char*)0x793ab4);
    void* s = sub_5974E0(q, (const char*)0x793ab0);
    self->field134 = (int)s;
    void* t = sub_5974E0(q, (const char*)0x793aac);
    self->field138 = (int)t;
    void* u = sub_5974E0(q, (const char*)0x793aa4);
    self->field13c = (int)u;

    void* v = sub_5974E0(self, (const char*)0x793a94);
    void* w = sub_5974E0(v, (const char*)0x793a8c);
    self->field140 = (int)w;
    void* x = sub_5974E0(v, (const char*)0x793a84);
    self->field144 = (int)x;

    return self;
}
