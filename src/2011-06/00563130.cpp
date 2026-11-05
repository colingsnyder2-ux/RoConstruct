// from server: 100% by tester
struct S {
    char pad[0x1c];
    int field_1c;
    char pad2[4];
    int field_24;
    int field_28;
};

int __stdcall sub_72e9b0(S* obj) {
    if (obj != 0 && obj->field_1c != 0 && obj->field_24 != 0) {
        int v = *(int*)(obj->field_1c + 0x34);
        if (v != 0) {
            ((void (__cdecl*)(int, int))obj->field_24)(obj->field_28, v);
        }
        ((void (__cdecl*)(int, int))obj->field_24)(obj->field_28, obj->field_1c);
        obj->field_1c = 0;
        return 0;
    }
    return -2;
}
