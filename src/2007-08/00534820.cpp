// from server: 100% by colin
struct ScriptContext {
    void* method_00534820(int, float, float, float);
};

extern "C" void* __cdecl sub_005BE5B0(int, int);
extern "C" void __cdecl sub_005BDE00(int, int, int);
extern "C" void __cdecl sub_005BE160(int, int);

extern int dword_008ABE78;

void* __cdecl method_00534820(int a, float x, float y, float z) {
    void* p = sub_005BE5B0(a, 12);
    if (p != 0) {
        *(float*)p = x;
        *(float*)((char*)p + 4) = y;
        *(float*)((char*)p + 8) = z;
    }
    sub_005BDE00(a, -10000, dword_008ABE78);
    sub_005BE160(a, -2);
    return p;
}
