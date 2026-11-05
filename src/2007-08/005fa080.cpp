// from server: 55% by colin
struct Sub {
    char pad0[4];
    Sub* f4;
    Sub* f8;
    Sub* fc;
};

struct Obj {
    char pad0[0xec];
    Sub* sub_ec;
};

extern "C" void __stdcall func_00578ed0(Obj* self, void* arg);

void func_005fa080(Obj* self, void* arg)
{
    Sub* s = self->sub_ec;
    *(void**)((char*)s->f4 + 0x298) = (void*)0x7a4ca4;
    *(void**)((char*)self + 0x294) = (void*)0x7a4cac;
    func_00578ed0(self, arg);
    *(void**)((char*)self + 0x00) = (void*)0x7c1f34;
    *(void**)((char*)self + 0x04) = (void*)0x7c1f2c;
    *(void**)((char*)self + 0x10) = (void*)0x7c1f24;
    *(void**)((char*)self + 0x14) = (void*)0x7c1f14;
    *(void**)((char*)self + 0x2c) = (void*)0x7c1f04;
    *(void**)((char*)self + 0x44) = (void*)0x7c1ef4;
    *(void**)((char*)self + 0x5c) = (void*)0x7c1ee4;
    *(void**)((char*)self + 0x74) = (void*)0x7c1ed4;
    *(void**)((char*)self + 0x8c) = (void*)0x7c1ec4;
    *(void**)((char*)self + 0xe8) = (void*)0x7c1eb8;
    *(void**)((char*)self + 0x158) = (void*)0x7c1ea8;
    *(void**)((char*)self + 0x170) = (void*)0x7c1e9c;
    *(void**)((char*)self + 0x17c) = (void*)0x7c1e84;
    Sub* s2 = self->sub_ec;
    *(void**)((char*)s2->f4 + 0xec) = (void*)0x7c1e78;
    Sub* s3 = self->sub_ec;
    *(void**)((char*)s3->f8 + 0xec) = (void*)0x7c1e70;
    Sub* s4 = self->sub_ec;
    *(void**)((char*)s4->fc + 0xec) = (void*)0x7c1e54;
    Sub* s5 = self->sub_ec;
    *(void**)((char*)s5->f4 + 0xe8) = (char*)s5->f4 - 0x198;
    Sub* s6 = self->sub_ec;
    *(void**)((char*)s6->f8 + 0xe8) = (char*)s6->f8 - 0x1a0;
    Sub* s7 = self->sub_ec;
    *(void**)((char*)s7->fc + 0xe8) = (char*)s7->fc - 0x1a8;
}
