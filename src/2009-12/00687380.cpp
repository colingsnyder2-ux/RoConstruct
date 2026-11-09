// from server: 38% by atomic.potato
struct Sub {
    void destroy();
    void release();
};

struct Obj {
    void* vtbl0;
    void* vtbl4;
    char pad8[0x10];
    void* vtbl18;
    void* vtbl1c;
    char pad20[0x7c];
    Sub* sub9c;
    char padA0[0x30];
    Sub subD0;
    Sub subD8;
    Sub subE0;

    void destroy();
};

extern "C" void __stdcall sub_7f385a(void* p);
extern "C" void __stdcall sub_686ff0(Sub* p);
extern "C" void __stdcall sub_664370(Sub* p);
extern "C" void __stdcall sub_41af50(Sub* p);
extern "C" void __stdcall sub_722c00(Sub* p);
extern "C" void __stdcall sub_637b00(Obj* p);

void Obj::destroy() {
    this->vtbl0 = (void*)0x9d083c;
    this->vtbl4 = (void*)0x9d0834;
    this->vtbl18 = (void*)0x9d0828;
    this->vtbl1c = (void*)0x9d0820;
    Sub* p = this->sub9c;
    if (p) {
        sub_686ff0(p);
        sub_7f385a(p);
    }
    sub_664370(&this->subE0);
    sub_41af50(&this->subE0);
    sub_664370(&this->subD8);
    sub_41af50(&this->subD8);
    sub_664370(&this->subD0);
    sub_41af50(&this->subD0);
    sub_722c00((Sub*)((char*)this + 0xa0));
    sub_7f385a(*(void**)((char*)this + 0xa0));
    this->vtbl0 = (void*)0x9d072c;
    this->vtbl4 = (void*)0x9d0720;
    this->vtbl18 = (void*)0x9d0714;
    this->vtbl1c = (void*)0x9d070c;
    sub_637b00(this);
}
