// from server: 28% by colin
struct S {
    char pad[0x4c];
    void* field_4c;
    void f();
};

extern "C" int __stdcall pubsync(void*);

void S::f() {
    this->field_4c = 0;
    ((void (__thiscall*)(S*))0x551a20)(this);
    if (this->field_4c != 0) {
        pubsync(this->field_4c);
    }
}
