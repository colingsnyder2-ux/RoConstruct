// from server: 22% by Intel
struct MegaClusterInstance {
    int field_8;
    int field_C;
    int field_10;
    char pad_14[0x70];
    int field_84;

    int __thiscall GetSetImpl(int a1, int a2);
};

extern "C" void __stdcall string_ctor(void* thisptr, const void* src);

int __thiscall MegaClusterInstance::GetSetImpl(int a1, int a2) {
    int v3 = 0;
    if (a1)
        v3 = a1 - 0x1C;
    int v4 = *(int*)(v3 + 0x84);
    int v5 = field_10;
    int v6 = *(int*)(v4 + v5);
    v6 += field_C;
    int v7 = field_8;
    int v8 = v6 + v3 + 0x84;
    int v9 = ((int(__thiscall*)(int))v7)(v8);
    string_ctor((void*)a2, (void*)v9);
    return a2;
}
