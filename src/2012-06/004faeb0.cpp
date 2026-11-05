// from server: 32% by atomic.potato
struct Sub {
    char pad[0x30];
    void init();
};

struct Obj {
    void* vtbl;
    Sub sub8;
    char pad_38[0x30];
    float f38;
    float f3c;
    char b40;
    char b41;
    char b42;
    char b43;
    char pad_44[4];
    void* p48;
    void* p4c;
    void* p50;
    Sub sub54;
    char pad_84[0x30];
    char b84;
    char b85;
    Obj();
};

Obj::Obj()
{
    this->vtbl = (void*)0xb6a694;
    this->sub8.init();
    this->f38 = 0.0f;
    this->f3c = 0.0f;
    this->b40 = 0;
    this->b41 = 0;
    this->b42 = 0;
    this->b43 = 0;
    this->vtbl = (void*)0xb6ae84;
    this->p48 = 0;
    this->p4c = 0;
    this->p50 = 0;
    this->sub54.init();
    this->b84 = 0;
    this->b85 = 0;
}
