// from server: 47% by Intel
struct DebugSettings {
    int vtable;
    int field_4;
};

extern "C" int (__thiscall *sub_972290)(const char*, int);
extern "C" int __stdcall sub_B22644(int);

int __stdcall sub_678100(DebugSettings* a1) {
    int v1 = 0;
    if (*(char*)0xE580B3) {
        if (!*(int*)0xE296BC) {
            int v2 = *(int*)0xE5809C;
            if (v2) {
                if (!((int(__cdecl*)(int, int, int))v2)(0xB8DBF8, 0xB8DBDC, 0x55)) {
                    sub_972290((const char*)0xB8DB58, *(unsigned char*)0xE580B3);
                }
            } else {
                sub_972290((const char*)0xB8DB58, *(unsigned char*)0xE580B3);
            }
        }
    }
    sub_B22644((int)a1);
    return (int)a1;
}
