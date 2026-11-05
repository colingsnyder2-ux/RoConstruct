// from server: 42% by atomic.potato
struct Flag {
    char pad[0x168];
    void* field_168;
    char pad2[0x220 - 0x16c];
    void* field_220;
    void* field_c;
    void* construct(int);
};

extern "C" void __stdcall sub_5e61f0(int);
extern "C" void* __stdcall sub_591230();

void* Flag::construct(int arg) {
    if (arg != 0) {
        *(void**)((char*)this + 0x168) = (void*)0x7bb71c;
        *(void**)((char*)this + 0x220) = (void*)0x7a4ccc;
    }
    sub_5e61f0(0);
    void* p = *(void**)((char*)this + 0x168);
    *(void**)this = (void*)0x7bd61c;
    *(void**)((char*)this + 4) = (void*)0x7bd610;
    *(void**)((char*)this + 0x10) = (void*)0x7bd608;
    *(void**)((char*)this + 0x14) = (void*)0x7bd5f8;
    *(void**)((char*)this + 0x2c) = (void*)0x7bd5e8;
    *(void**)((char*)this + 0x44) = (void*)0x7bd5d8;
    *(void**)((char*)this + 0x5c) = (void*)0x7bd5c8;
    *(void**)((char*)this + 0x74) = (void*)0x7bd5b8;
    *(void**)((char*)this + 0x8c) = (void*)0x7bd5a8;
    *(void**)((char*)this + 0xe8) = (void*)0x7bd5a0;
    *(void**)((char*)this + 0x158) = (void*)0x7bd588;
    int ecx = *(int*)((char*)p + 4);
    *(void**)(ecx + (int)this + 0x168) = (void*)0x7bd580;
    void* edx = *(void**)((char*)this + 0x168);
    int eax = *(int*)((char*)edx + 4);
    int ecx2 = eax - 0xb8;
    *(void**)(eax + (int)this + 0x164) = (void*)ecx2;
    this->field_c = sub_591230();

    return this;
}
