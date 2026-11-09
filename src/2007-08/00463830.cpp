// from server: 43% by colin
struct Listener {
    void* vtable;
    char pad[0x20];
    void* field24;
    char pad2[0x8];
    void destroy();
};

extern "C" {
    long __stdcall InterlockedDecrement(long volatile*);
    void __stdcall sub_457DD0(void*);
    void __stdcall sub_77E6AC(void*);
}

void Listener::destroy()
{
    this->vtable = (void*)0x795b74;
    if (this->field24) {
        if (InterlockedDecrement((long*)((char*)this->field24 + 4)) == 0) {
            sub_457DD0(this->field24);
            if (this->field24) {
                void** vt = *(void***)this->field24;
                ((void (__stdcall*)(void*, int))vt[0])(this->field24, 1);
            }
        }
        this->field24 = 0;
    }
    sub_77E6AC((char*)this + 4);
}
