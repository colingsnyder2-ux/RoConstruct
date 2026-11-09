// from server: 33% by colin
struct RBX_Instance {
    char pad[0x298];
    void* field_298;
    void* field_294;
};

struct RBX_VSpawnerService {
    char pad0[0xc];
    void* field_c;
    char pad10[0xec - 0x10];
    void* field_ec;
    char padF0[0x294 - 0xf0];
    void* field_294;
    void* field_298;
    char pad29C[0x2a0 - 0x29c];

    void sub_59feb0(void* arg);
    void* sub_5a08c0();
    void construct(void* arg);
};

void RBX_VSpawnerService::construct(void* arg) {
    void* p = this->field_298;
    this->field_294 = (void*)0x7a4cac;
    void* q = *(void**)((char*)p + 4);
    *(void**)((char*)q + (int)this + 0x298) = (void*)0x7a4ca4;
    this->sub_59feb0(arg);
    void* e = this->field_ec;
    *(void**)this = (void*)0x7b3a7c;
    *(void**)((char*)this + 4) = (void*)0x7b3a74;
    *(void**)((char*)this + 0x10) = (void*)0x7b3a6c;
    *(void**)((char*)this + 0x14) = (void*)0x7b3a5c;
    *(void**)((char*)this + 0x2c) = (void*)0x7b3a4c;
    *(void**)((char*)this + 0x44) = (void*)0x7b3a3c;
    *(void**)((char*)this + 0x5c) = (void*)0x7b3a2c;
    *(void**)((char*)this + 0x74) = (void*)0x7b3a1c;
    *(void**)((char*)this + 0x8c) = (void*)0x7b3a0c;
    *(void**)((char*)this + 0xe8) = (void*)0x7b3a00;
    *(void**)((char*)this + 0x158) = (void*)0x7b39f0;
    *(void**)((char*)this + 0x170) = (void*)0x7b39e4;
    *(void**)((char*)this + 0x17c) = (void*)0x7b39cc;
    void* r = *(void**)((char*)e + 4);
    *(void**)((char*)r + (int)this + 0xec) = (void*)0x7b39c0;
    void* e2 = this->field_ec;
    void* s = *(void**)((char*)e2 + 8);
    *(void**)((char*)s + (int)this + 0xec) = (void*)0x7b39b8;
    void* e3 = this->field_ec;
    void* t = *(void**)((char*)e3 + 0xc);
    *(void**)((char*)t + (int)this + 0xec) = (void*)0x7b399c;
    void* e4 = this->field_ec;
    void* u = *(void**)((char*)e4 + 4);
    void* v = (void*)((char*)u - 0x198);
    *(void**)((char*)u + (int)this + 0xe8) = v;
    void* e5 = this->field_ec;
    void* w = *(void**)((char*)e5 + 8);
    void* x = (void*)((char*)w - 0x1a0);
    *(void**)((char*)w + (int)this + 0xe8) = x;
    void* e6 = this->field_ec;
    void* y = *(void**)((char*)e6 + 0xc);
    void* z = (void*)((char*)y - 0x1a8);
    *(void**)((char*)y + (int)this + 0xe8) = z;
    void* result = this->sub_5a08c0();
    this->field_c = result;
}
