// from server: 20% by atomic.potato
struct Inner {
    char pad0[0xc];
    int field_c;
    char pad10[0x10];
    int field_20;
    float field_24;
};

struct Vec {
    char pad0[0xc];
    int begin;
    int end;
};

struct Obj {
    char pad0[4];
    Inner* field_4;
    char pad8[4];
    int field_c;
    char pad10[0x10];
    Inner* field_20;
    float field_24;
};

extern "C" void __stdcall sub_677e50();
extern "C" void __stdcall sub_67ad50();
extern "C" void __stdcall sub_7821f0();
extern "C" void __stdcall sub_7819b0();
extern "C" void __stdcall sub_781de0();
extern "C" void __stdcall sub_781ab0();
extern "C" void __stdcall sub_66f770();
extern "C" void __stdcall sub_6bad70();
extern "C" void __stdcall sub_6877a0();
extern "C" void __stdcall sub_782190();

void __stdcall MoveUpSelectionVerb_impl(Obj* self, int arg);

void __stdcall MoveUpSelectionVerb_impl(Obj* self, int arg)
{
    Inner* esi = self->field_20;
    sub_677e50();
    Inner* ecx = self->field_20;
    int eax;
    if (ecx) {
        sub_67ad50();
        eax = (int)ecx;
    } else {
        eax = 0;
    }
    Vec* v = (Vec*)(eax + 0xa4);
    int count = (v->end - v->begin) >> 2;
    if (count > 0) {
        int a = self->field_c;
        sub_7821f0();
        sub_7819b0();
        float f = self->field_24;
        sub_781de0();
        sub_781ab0();
        Inner* ecx2 = self->field_20;
        int eax2;
        if (ecx2) {
            sub_66f770();
            eax2 = (int)ecx2;
        } else {
            eax2 = 0;
        }
        sub_6bad70();
        int a2 = self->field_c;
        Inner* edi = self->field_4;
        char* p;
        if (*(int*)((char*)edi + 0x18) < 0x10) {
            p = (char*)edi + 4;
        } else {
            p = *(char**)((char*)edi + 4);
        }
        sub_6877a0();
        sub_782190();
    }
}
