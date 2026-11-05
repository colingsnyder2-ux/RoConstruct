// from server: 67% by atomic.potato
struct CXTPControls {
    char pad0[0x14];
    int field14;
    char pad18[0x8];
    int field20;
    char pad24[0xa4];
    int fieldc8;
    char padcc[0xc];
    int fieldd8;
    char pade0[0x20];
    int field100;
    char pad104[0x7c];
    int field180;
    int field184;
    char pad188[0x48];
    int field1d0;
    int field1d4;
    int field1d8;
    int field1dc;
    int GetSomething();
    int GetOther();
};

struct Helper {
    char pad0[8];
    int a;
    int b;
};

extern "C" void __stdcall sub_84b270(Helper* h, CXTPControls* c);
extern "C" void __stdcall sub_7f47d8(int* out, Helper* h);

void __stdcall sub_8354c0(CXTPControls* self, int* out)
{
    Helper h;
    out[0] = self->fieldd8;
    out[0x38 / 4] = (int)self;
    out[1] = self->GetSomething();
    out[0x14 / 4] = self->fieldc8;
    sub_84b270(&h, self);
    if (self->field180 != 0) {
        sub_7f47d8((int*)&h, (Helper*)self->field180);
    }
    int* p;
    if (self->field20 != 0) {
        p = (int*)&h;
    } else {
        p = (int*)(self->field184 + 0x28);
    }
    out[0xc / 4] = p[0];
    out[0x10 / 4] = p[1];
    out[8 / 4] = (self->field100 == 4) ? 1 : 0;
    out[0x18 / 4] = *(int*)(self->field184 + 0x14);
    out[0x1c / 4] = *(int*)(self->field184 + 0x18);
    out[0x20 / 4] = *(int*)(self->field184 + 0x1c);
    out[0x24 / 4] = *(int*)(self->field184 + 0x20);
    out[0x28 / 4] = *(int*)(self->field184 + 0x24);
    out[0x30 / 4] = *(int*)(self->field184 + 0x28);
    out[0x34 / 4] = *(int*)(self->field184 + 0x2c);
    int r = self->GetOther();
    out[0x3c / 4] = r;
    out[0x40 / 4] = 0;
    out[0x44 / 4] = 0;
    out[0x48 / 4] = 0;
    out[0x4c / 4] = 0;
    if (r != 0) {
        out[0x40 / 4] = self->field1d0;
        out[0x44 / 4] = self->field1d4;
        out[0x48 / 4] = self->field1d8;
        out[0x4c / 4] = self->field1dc;
    }
}
