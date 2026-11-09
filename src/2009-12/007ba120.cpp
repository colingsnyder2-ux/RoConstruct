// from server: 28% by atomic.potato
struct Sub1 {
    void ctor();
    void dtor();
};

struct Sub2 {
    void ctor();
    void dtor();
};

struct Sub3 {
    void dtor();
};

struct TreeStage {
    void* vtable;
    char pad1[4];
    void* field8;
    char pad2[4];
    Sub3 sub10;
    char pad3[0x14];
    Sub1 sub28;
    char pad4[0x1c];
    Sub2 sub48;
    void dtor();
};

void Sub1::ctor() {}
void Sub1::dtor() {}
void Sub2::ctor() {}
void Sub2::dtor() {}
void Sub3::dtor() {}

void TreeStage::dtor()
{
    this->vtable = (void*)0x9ee32c;
    *(void**)((char*)this + 0x10) = (void*)0x9ee314;
    this->sub48.ctor();
    this->sub28.ctor();
    this->sub10.dtor();
    if (this->field8) {
        (*(void(__thiscall**)(void*, int))*(void**)this->field8)(this->field8, 1);
    }
}
