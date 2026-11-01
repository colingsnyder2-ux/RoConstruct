// from server: 44% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl sub_840ba0(int);

struct LuaArguments {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int f(int* a2);
};

int LuaArguments::f(int* a2) {
    char buffer[24];
    buffer[0] = *reinterpret_cast<char*>(a2);
    *reinterpret_cast<int*>(buffer + 4) = a2[1];
    *reinterpret_cast<int*>(buffer + 8) = a2[2];
    *reinterpret_cast<int*>(buffer + 12) = a2[3];
    *reinterpret_cast<int*>(buffer + 16) = a2[4];
    int ref = a2[5];
    *reinterpret_cast<int*>(buffer + 20) = ref;
    *reinterpret_cast<int*>(buffer + 24) = reinterpret_cast<int>(buffer);
    if (ref) {
        _InterlockedExchangeAdd(reinterpret_cast<volatile long*>(ref + 4), 1);
    }
    sub_840ba0(field_0);
    return 1;
}
