// from server: 46% by colin
// roc 2007-08 00446630  unit: VCRenderSettings::?$FactoryProduct  size: 352 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00446630

struct ListBase {
    void* head;
    int   count;
};

struct MapBase {
    void* head;
    int   count;
};

struct CRenderSettings {
    void* vtable;
    char  pad0[0x24];
    ListBase list28;
    ListBase list34;
    char  pad1[0x0c];
    int   field44;
    int   field48;
    int   field4c;
    MapBase map50;
    MapBase map5c;
    char  pad2[0x0c];
    int   field6c;
    int   field70;
    int   field74;
    char  pad3[0x04];
    int   field7c;
    int   field80;
    int   field84;
    char  pad4[0x04];
    int   field8c;
    int   field90;
    int   field94;

    CRenderSettings();
    void sub_4463F0(int a, const char* b);
};

extern "C" void __cdecl sub_587360(const char* a, const char* b);
extern "C" void* __fastcall sub_5835B0(void* self);
extern "C" void* __fastcall sub_579890(void* self);

CRenderSettings::CRenderSettings()
{
    sub_587360((const char*)0x78fd68, (const char*)0x888b6c);
    this->vtable = (void*)0x78fd54;

    this->list28.head = 0;
    this->list28.count = 0;
    {
        void* n = sub_5835B0(&this->list28);
        this->list28.head = n;
        *(char*)((char*)n + 0x15) = 1;
        void* h = this->list28.head;
        *(void**)((char*)h + 4) = h;
        h = this->list28.head;
        *(void**)h = h;
        h = this->list28.head;
        *(void**)((char*)h + 8) = h;
        this->list28.count = 0;
    }

    this->list34.head = 0;
    this->list34.count = 0;
    {
        void* n = sub_5835B0(&this->list34);
        this->list34.head = n;
        *(char*)((char*)n + 0x15) = 1;
        void* h = this->list34.head;
        *(void**)((char*)h + 4) = h;
        h = this->list34.head;
        *(void**)h = h;
        h = this->list34.head;
        *(void**)((char*)h + 8) = h;
        this->list34.count = 0;
    }

    this->field44 = 0;
    this->field48 = 0;
    this->field4c = 0;

    this->map50.head = 0;
    this->map50.count = 0;
    {
        void* n = sub_579890(&this->map50);
        this->map50.head = n;
        *(char*)((char*)n + 0x2d) = 1;
        void* h = this->map50.head;
        *(void**)((char*)h + 4) = h;
        h = this->map50.head;
        *(void**)h = h;
        h = this->map50.head;
        *(void**)((char*)h + 8) = h;
        this->map50.count = 0;
    }

    this->map5c.head = 0;
    this->map5c.count = 0;
    {
        void* n = sub_579890(&this->map5c);
        this->map5c.head = n;
        *(char*)((char*)n + 0x2d) = 1;
        void* h = this->map5c.head;
        *(void**)((char*)h + 4) = h;
        h = this->map5c.head;
        *(void**)h = h;
        h = this->map5c.head;
        *(void**)((char*)h + 8) = h;
        this->map5c.count = 0;
    }

    this->field6c = 0;
    this->field70 = 0;
    this->field74 = 0;
    this->field7c = 0;
    this->field80 = 0;
    this->field84 = 0;
    this->field8c = 0;
    this->field90 = 0;
    this->field94 = 0;

    this->sub_4463F0(1, (const char*)0x78fd60);
    this->sub_4463F0(4, (const char*)0x78fd5c);
    this->sub_4463F0(8, (const char*)0x78fd58);
}
