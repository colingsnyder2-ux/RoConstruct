// from server: 62% by atomic.potato
extern "C" {
    int __stdcall InterlockedIncrement(int volatile*);
}

struct String {
    void* pad[4];
    String();
    String(const char*);
    ~String();
};

struct Base1 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

struct Base2 {
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
};

struct SoundServiceStatsItem : Base1, Base2 {
    char pad0[0x94 - 0x20];
    int field94;
    int field98;
    int field9c;
    String str_a0;
    char pad1[0xc0 - 0xa0 - sizeof(String)];
    float fieldc0;
    float fieldc4;
    char pad2[0xcc - 0xc4 - 4];
    unsigned char fieldcc;
    unsigned char fieldcd;
    char pad3[0xd0 - 0xcd - 1];
    int fieldd0;
    int fieldd4;
    int fieldd8;
    int fielddc;

    SoundServiceStatsItem();
};

extern "C" void* __stdcall sub_6b68b0();
extern "C" void* __stdcall sub_636ac0(void*);
extern "C" void* __stdcall sub_632470();
extern "C" void* __stdcall sub_98b20c(void*);
extern "C" void* __stdcall sub_98b6e8();
extern "C" void* __stdcall sub_98b6f4(void*);
extern "C" void* __stdcall sub_98b6e4();

extern float g_9af2dc;
extern float g_9aea18;

SoundServiceStatsItem::SoundServiceStatsItem()
{
    sub_6b68b0();
    *(void**)((char*)this + 0) = (void*)0x9d6124;
    *(void**)((char*)this + 4) = (void*)0x9d6118;
    *(void**)((char*)this + 0x18) = (void*)0x9d610c;
    *(void**)((char*)this + 0x1c) = (void*)0x9d6104;

    void* (__stdcall *pfn)(void*) = (void* (__stdcall*)(void*))sub_98b20c;
    pfn((void*)0xb7b44c);

    *(void**)((char*)this + 0) = (void*)0x9d5d64;
    *(void**)((char*)this + 4) = (void*)0x9d5d5c;
    *(void**)((char*)this + 0x18) = (void*)0x9d5d50;
    *(void**)((char*)this + 0x1c) = (void*)0x9d5d48;

    field94 = 0;
    field98 = 0;
    field9c = 0;

    String* pstr = (String*)((char*)this + 0xa0);
    sub_98b6e8();
    pstr->String::String();
    *(void**)((char*)this + 0xa0 + 0x1c) = sub_632470();

    fieldc0 = g_9af2dc;
    fieldcd &= 0xf8;
    fieldc4 = g_9aea18;
    fieldcc = 0;
    fieldd0 = -1;
    fieldd4 = 0;

    pfn((void*)0xb7a220);

    fieldd8 = 0;
    fielddc = 0;

    sub_98b6f4((void*)0x9ad820);
    sub_636ac0((char*)this + 0xa0);
    sub_98b6e4();
}
