// from server: 32% by colin
// roc 2007-08 005581b0  unit: RBX::DataModel  size: 836 bytes

extern "C" int __stdcall std_string_ctor(void* self, const char* s);
extern "C" int __stdcall std_string_eq_cstr(const void* self, const char* s);

extern "C" int __stdcall sub_5017C0(void* self, const char* fmt, ...);
extern "C" int __stdcall sub_557260();
extern "C" int __stdcall sub_557290(void* self);
extern "C" int __stdcall sub_5574D0(void* self);
extern "C" int __stdcall sub_5804B0(void* self, const void* val);
extern "C" int __stdcall sub_580600(void* self, const void* val);
extern "C" int __stdcall sub_5A8FF0(void* self);
extern "C" int __stdcall sub_5A9000(void* self);
extern "C" int __stdcall sub_5A9010(void* self);
extern "C" int __stdcall sub_5A9020(void* self);
extern "C" int __stdcall sub_5A9030(void* self);
extern "C" int __stdcall sub_5A9040(void* self);
extern "C" int __stdcall sub_5A9380(void* self);
extern "C" int __stdcall sub_5A9390(void* self);
extern "C" int __stdcall sub_5A93A0(void* self);
extern "C" int __stdcall sub_5CF520(void* self);
extern "C" int __stdcall sub_5CF560(void* self);

struct DataModel {
    char pad[0x10];
    void* field10;
    char pad2[0x54];
    void* field68;
    char pad3[0x10];
    int method(const void* name, void* out);
};

int DataModel::method(const void* name, void* out)
{
    void* ebx = *(void**)((char*)field10 + 0x27c);
    int local = 0;
    void* pname = (void*)name;

    if (std_string_eq_cstr(pname, "$Ph|")) {
        float f = *(float*)((char*)field68 + 0xb0);
        sub_580600(out, &f);
        return (int)out;
    }
    if (std_string_eq_cstr(pname, "contactPairHitRatio")) {
        double d = *(double*)((char*)field68 + 0x98);
        sub_5017C0(out, "%.3g", d);
        return (int)out;
    }
    if (std_string_eq_cstr(pname, "9w ~")) {
        sub_5574D0(field68);
        return (int)out;
    }
    if (std_string_eq_cstr(pname, "9w8~")) {
        local = *(int*)((char*)ebx + 0x5c);
        sub_5804B0(out, &local);
        return (int)out;
    }
    if (std_string_eq_cstr(pname, "^][Y")) {
        local = *(int*)((char*)ebx + 0x70);
        sub_5804B0(out, &local);
        return (int)out;
    }
    if (std_string_eq_cstr(pname, "_^][Y")) {
        local = *(int*)((char*)ebx + 0x74);
        sub_5804B0(out, &local);
        return (int)out;
    }
    if (std_string_eq_cstr(pname, "energyBody")) {
        sub_5A9000(ebx);
        local = *(int*)((char*)ebx + 0x70);
        sub_5804B0(out, &local);
        return (int)out;
    }
    if (std_string_eq_cstr(pname, "energyConnector")) {
        local = sub_5A9010(ebx);
        sub_5804B0(out, &local);
        return (int)out;
    }
    if (std_string_eq_cstr(pname, "energyTotal")) {
        local = sub_5A9020(ebx);
        sub_5804B0(out, &local);
        return (int)out;
    }
    if (std_string_eq_cstr(pname, "h31u")) {
        float f = sub_557260();
        sub_580600(out, &f);
        return (int)out;
    }
    if (std_string_eq_cstr(pname, "Replication: %s << %s-%d")) {
        local = *(int*)((char*)ebx + 0x78);
        sub_5804B0(out, &local);
        return (int)out;
    }
    if (std_string_eq_cstr(pname, "energyBody2")) {
        local = sub_5A9030(ebx);
        sub_5804B0(out, &local);
        return (int)out;
    }
    if (std_string_eq_cstr(pname, "energyConnector2")) {
        local = sub_5A9040(ebx);
        sub_5804B0(out, &local);
        return (int)out;
    }
    if (std_string_eq_cstr(pname, "energyTotal2")) {
        local = sub_5A9380(ebx);
        sub_5804B0(out, &local);
        return (int)out;
    }
    if (std_string_eq_cstr(pname, "energyBody3")) {
        local = sub_5A93A0(ebx);
        sub_5804B0(out, &local);
        return (int)out;
    }
    if (std_string_eq_cstr(pname, "energyConnector3")) {
        local = sub_5A9390(ebx);
        sub_5804B0(out, &local);
        return (int)out;
    }
    if (std_string_eq_cstr(pname, "energyTotal3")) {
        void* p = (void*)sub_5A8FF0(ebx);
        float f = (float)sub_5CF560(p);
        sub_580600(out, &f);
        return (int)out;
    }
    if (std_string_eq_cstr(pname, "energyBody4")) {
        void* p = (void*)sub_5A8FF0(ebx);
        float f = (float)sub_5CF520(p);
        sub_580600(out, &f);
        return (int)out;
    }
    if (std_string_eq_cstr(pname, "energyConnector4")) {
        void* p = (void*)sub_5A8FF0(ebx);
        float f = (float)sub_557290(p);
        sub_580600(out, &f);
        return (int)out;
    }

    std_string_ctor(out, "unknown");
    return (int)out;
}
