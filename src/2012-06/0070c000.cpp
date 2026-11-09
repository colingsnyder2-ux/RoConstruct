// from server: 42% by Intel
extern "C" float g_float_00b62774;

struct Vector3 {
    float x, y, z;
};

extern "C" Vector3* __stdcall sub_006cbf60(Vector3* out, Vector3* a2, Vector3* a3);

struct VHopperBin_FactoryProduct {
    void method(Vector3* out);
};

void VHopperBin_FactoryProduct::method(Vector3* out) {
    Vector3 v1;
    Vector3 v2;
    v1.x = g_float_00b62774;
    v1.y = g_float_00b62774;
    v1.z = g_float_00b62774;
    v2.x = g_float_00b62774;
    v2.y = g_float_00b62774;
    v2.z = g_float_00b62774;
    Vector3* result = sub_006cbf60(&v1, &v2, &v1);
    out->x = result->x;
    out->y = result->x;
    out->z = result->x;
}
