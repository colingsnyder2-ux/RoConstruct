// from server: 79% by Intel
typedef unsigned long DWORD;
typedef void* LPVOID;

extern "C" void __stdcall EnterCriticalSection(LPVOID);
extern "C" void __stdcall LeaveCriticalSection(LPVOID);

extern "C" int __cdecl sub_972290(int, int);
extern "C" int __cdecl sub_472a10();

struct GeoPairConnector {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;

    int __thiscall sub_8959E0(int arg);
};

int __thiscall GeoPairConnector::sub_8959E0(int arg) {
    if (*(char*)0xE580B3) {
        if (this->field_4 != -1) {
            int (__cdecl* callback)(int, int, int) = (int (__cdecl*)(int, int, int))*(DWORD*)0xE5809C;
            if (callback) {
                if (callback(0xBB32B0, 0xBB32C8, 0x16)) {
                    return (int)this;
                }
            }
            sub_972290(*(unsigned char*)0xE580B3, 0xBB3238);
        }
    }
    if (arg & 1) {
        int esi = sub_472a10();
        EnterCriticalSection((LPVOID)0xB221B8);
        this->field_0 = *(int*)(esi + 0x18);
        *(int*)(esi + 0x18) = (int)this;
        LeaveCriticalSection((LPVOID)0xB221B4);
    }
    return (int)this;
}
