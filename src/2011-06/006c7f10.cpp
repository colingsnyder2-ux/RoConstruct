// from server: 38% by atomic.potato
struct GuiTextMixin {
    void* field0;
    void* field4;
    void* field8;
    void* fieldC;
};

extern "C" void* __cdecl operator_new(unsigned int);

struct GetSetImpl {
    void* vtable;
    void* a;
    void* b;
    void* c;
};

void* GetSetImpl_ctor(void* self, void* a, void* b, void* c);

void* __fastcall GetSetImpl_create(void** out, void* unused, void* a, void* b, void* c) {
    void* mem = operator_new(0x10);
    if (mem) {
        GetSetImpl* p = (GetSetImpl*)mem;
        p->a = a;
        p->vtable = (void*)0xaa4b3c;
        p->b = b;
        p->c = c;
        *out = p;
        return out;
    }
    *out = 0;
    return out;
}
