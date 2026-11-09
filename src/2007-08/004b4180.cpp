// from server: 44% by colin
struct Descriptor {
    char pad[0x14];
    int type;
};

struct SignalSource {
    char pad[0xec];
    void* field_ec;

    int func(void* a, void* b, int c);
};

extern "C" {
    int __stdcall sub_49F9A0(void*, int, int);
    int __stdcall sub_4A01F0(void*, void*);
    int __stdcall sub_4A0250(void*, void*);
    int __stdcall sub_4A0640(void*, void*);
    int __stdcall sub_4A0D50(void*, void*);
    int __stdcall sub_4A1880(void*, void*);
    int __stdcall sub_4A21A0(void*);
    int __stdcall sub_4A32F0(void*, void*, void*);
    int __stdcall sub_4A8040(void*, void*);
    int __stdcall sub_4A80A0(void*, void*);
    int __stdcall sub_4A8CD0(void*, void*);
    int __stdcall sub_4A8D00(void*, void*);
    int __stdcall sub_4A8D30(void*, void*);
    int __stdcall sub_4A8D70(void*, void*);
    int __stdcall sub_4B3DB0(void*, void*, void*);
    int __stdcall sub_56D7D0();
    int __stdcall sub_56D840();
    int __stdcall sub_56D8B0();
    int __stdcall sub_56D990();
    int __stdcall sub_56DA00();
    int __stdcall sub_56DA70();
    int __stdcall sub_56DB50();
    int __stdcall sub_56DCC0();
    int __stdcall sub_5742B0();
    int __stdcall sub_630D36(void*, int, void*, void*, int);
}

int SignalSource::func(void* a, void* b, int c)
{
    if (c != 0) {
        int local = 0;
        sub_49F9A0(a, 4, (int)&local);
    }

    void* ev = b;
    Descriptor* desc = *(Descriptor**)ev;

    if (desc->type == sub_56DA00()) {
        void* r = (void*)sub_4B3DB0(this, ev, a);
        sub_4A21A0((char*)r + 0xe10);
        return 0;
    }

    desc = *(Descriptor**)ev;
    if (desc->type == sub_56D840()) {
        int local;
        sub_4A0250(&local, a);
        sub_4A8040(ev, &local);
        return 0;
    }

    desc = *(Descriptor**)ev;
    if (desc->type == sub_56D7D0()) {
        int local;
        sub_4A0640(&local, a);
        sub_4A80A0(ev, &local);
        return 0;
    }

    desc = *(Descriptor**)ev;
    if (desc->type == sub_56D8B0()) {
        sub_4A8CD0(ev, a);
        return 0;
    }

    desc = *(Descriptor**)ev;
    if (desc->type == sub_56DCC0()) {
        sub_4A1880(ev, a);
        return 0;
    }

    desc = *(Descriptor**)ev;
    if (desc->type == sub_56DB50()) {
        sub_4A8D00(ev, a);
        return 0;
    }

    desc = *(Descriptor**)ev;
    if (desc->type == sub_56DA70()) {
        sub_4A8D30(ev, a);
        return 0;
    }

    desc = *(Descriptor**)ev;
    if (desc->type == sub_5742B0()) {
        sub_4A8D70(ev, a);
        return 0;
    }

    if (sub_630D36(*(void**)ev, 0, (void*)0x887174, (void*)0x887cdc, 0) != 0) {
        sub_4A01F0(ev, a);
        return 0;
    }

    if (sub_630D36(*(void**)ev, 0, (void*)0x887174, (void*)0x887ca8, 0) != 0) {
        sub_4A32F0(&this->field_ec, ev, a);
        return 0;
    }

    desc = *(Descriptor**)ev;
    if (desc->type == sub_56D990()) {
        sub_4A0D50(ev, a);
    }

    return 0;
}
