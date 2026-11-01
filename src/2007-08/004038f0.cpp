// from server: 100% by colin
struct VCWorkspaceCComObject {
    void* field0;
    void* field4;
    void* field8;
    void* fieldC;
    void* field10;
    void* field14;
    void* field18;
    void* field1C;
    void* field20;
    void* field24;
    int SetSomething(void* p1, void* p2);
};

int VCWorkspaceCComObject::SetSomething(void* p1, void* p2) {
    VCWorkspaceCComObject* self;
    if (p1 != 0) {
        self = (VCWorkspaceCComObject*)((char*)p1 - 0x20);
    } else {
        self = 0;
    }
    if (self->field24 != p2) {
        if (p2 != 0) {
            void** vtbl = *(void***)p2;
            void (__stdcall *addref)(void*) = (void (__stdcall *)(void*))vtbl[1];
            addref(p2);
        }
        void* old = self->field24;
        if (old != 0) {
            void** vtbl2 = *(void***)old;
            void (__stdcall *release)(void*) = (void (__stdcall *)(void*))vtbl2[2];
            release(old);
        }
        self->field24 = p2;
    }
    return 0;
}
