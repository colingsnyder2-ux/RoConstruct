// from server: 35% by atomic.potato
struct Decal {
    char pad0[0x20];
    void* field20;
    void* ctor();
};

extern "C" void __cdecl sub_6bbc50(Decal* self);
extern "C" void* __cdecl sub_64fa70();

extern int dword_B90104;

void* Decal::ctor() {
    sub_6bbc50(this);
    *(void**)((char*)this + 0x00) = (void*)0x9d67ac;
    *(void**)((char*)this + 0x04) = (void*)0x9d67a0;
    *(void**)((char*)this + 0x18) = (void*)0x9d6794;
    *(void**)((char*)this + 0x1c) = (void*)0x9d678c;
    *(void**)((char*)this + 0x94) = (void*)0x9d6774;
    this->field20 = sub_64fa70();
    dword_B90104++;

    return this;
}
