// from server: 37% by colin
struct RBX_Reflection_SignalSource;

struct RBX_Reflection_PropertyDescriptor {
    char pad[0x14];
    int type;
};

struct RBX_Reflection_SignalSource {
    void fireEvent(const RBX_Reflection_PropertyDescriptor* desc, bool hasArg, const void* arg);
};

extern "C" int __cdecl sub_56DA00();
extern "C" int __cdecl sub_56D840();
extern "C" int __cdecl sub_56D7D0();
extern "C" int __cdecl sub_56D8B0();
extern "C" int __cdecl sub_56DCC0();
extern "C" int __cdecl sub_56DB50();
extern "C" int __cdecl sub_56DA70();
extern "C" int __cdecl sub_5742B0();
extern "C" int __cdecl sub_56D990();
extern "C" int __cdecl sub_630D36(const void*, const void*, const void*, int, const void*);

extern "C" void __cdecl sub_49FD90(void* self, const void* data, int size, int flag);
extern "C" void __cdecl sub_4A4EA0(void* self, const void* data, int size);
extern "C" void __cdecl sub_4A0230(void* self, const void* data);
extern "C" void __cdecl sub_4A0590(void* self, const void* data);
extern "C" void __cdecl sub_4A0610(void* self, const void* data);
extern "C" void __cdecl sub_4A01B0(void* self, const void* data);
extern "C" void __cdecl sub_4A0E90(void* self, const void* data);
extern "C" void __cdecl sub_4A0CA0(void* self, const void* data);
extern "C" void __cdecl sub_4A1840(void* self, const void* data);
extern "C" void __cdecl sub_4A8C70(void* self, const void* data);
extern "C" void __cdecl sub_4A8C90(void* self, const void* data);
extern "C" void __cdecl sub_4A8CB0(void* self, const void* data);
extern "C" void __cdecl sub_4A2690(void* self, const void* data);
extern "C" void* __cdecl sub_4A7E00(void* self);
extern "C" void* __cdecl sub_4A7E60(void* self);
extern "C" float __cdecl sub_4A7EC0(void* self);
extern "C" void* __cdecl sub_4B3DB0(void* self, const void* a, const void* b, const void* c);

void RBX_Reflection_SignalSource::fireEvent(const RBX_Reflection_PropertyDescriptor* desc, bool hasArg, const void* arg)
{
    int t = sub_56DA00();
    if (desc->type == t) {
        if (hasArg) {
            sub_49FD90((void*)arg, &hasArg, 4, 1);
        }
        void* p = sub_4B3DB0(this, (void*)desc, (void*)arg, 0);
        sub_4A2690(p, 0);
        return;
    }
    t = sub_56D840();
    if (desc->type == t) {
        if (hasArg) {
            sub_49FD90((void*)arg, &hasArg, 4, 1);
        }
        void* p = sub_4A7E00((void*)desc);
        sub_4A0230((void*)arg, p);
        return;
    }
    t = sub_56D7D0();
    if (desc->type == t) {
        if (hasArg) {
            sub_49FD90((void*)arg, &hasArg, 4, 1);
        }
        void* p = sub_4A7E60((void*)desc);
        sub_4A0590((void*)arg, p);
        return;
    }
    t = sub_56D8B0();
    if (desc->type == t) {
        sub_4A4EA0((void*)arg, (void*)desc, 4);
        float f = sub_4A7EC0((void*)desc);
        sub_4A0610((void*)arg, &f);
        return;
    }
    t = sub_56DCC0();
    if (desc->type == t) {
        sub_4A4EA0((void*)arg, (void*)desc, 5);
        sub_4A1840((void*)desc, (void*)arg);
        return;
    }
    t = sub_56DB50();
    if (desc->type == t) {
        sub_4A4EA0((void*)arg, (void*)desc, 6);
        sub_4A8C70((void*)desc, (void*)arg);
        return;
    }
    t = sub_56DA70();
    if (desc->type == t) {
        sub_4A4EA0((void*)arg, (void*)desc, 7);
        sub_4A8C90((void*)desc, (void*)arg);
        return;
    }
    t = sub_5742B0();
    if (desc->type == t) {
        sub_4A4EA0((void*)arg, (void*)desc, 8);
        sub_4A8CB0((void*)desc, (void*)arg);
        return;
    }
    if (sub_630D36((void*)desc, (void*)0x887174, (void*)0x887CDC, 0, 0)) {
        sub_4A4EA0((void*)arg, (void*)desc, 9);
        sub_4A01B0((void*)desc, (void*)arg);
        return;
    }
    if (sub_630D36((void*)desc, (void*)0x887174, (void*)0x887CA8, 0, 0)) {
        sub_4A4EA0((void*)arg, (void*)desc, 10);
        sub_4A0E90((void*)((char*)this + 0xEC), (void*)arg);
        return;
    }
    t = sub_56D990();
    if (desc->type == t) {
        sub_4A4EA0((void*)arg, (void*)desc, 11);
        sub_4A0CA0((void*)desc, (void*)arg);
        return;
    }
}
