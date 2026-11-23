// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: structure is a find-or-create in a std::map<Vector3, Texture*> registry guarded by a mutex; exact types unknown.
extern "C" {
void __cdecl fn_00557330(void (*once)(), long* flag);
void __fastcall fn_00563090(void* self, int unusedEdx);
void __fastcall fn_005630e0(void* self, int unusedEdx);
int __fastcall fn_004e8690(void* self, int unusedEdx, int a1, int a2);
void* __fastcall fn_006a0920(void* self, int unusedEdx, int a1);
int __fastcall fn_00500350(void* self, int unusedEdx, int a1, int a2);
int __fastcall fn_004ea140(void* self, int unusedEdx, int a1);
void __fastcall fn_00598fa0(void* self, int unusedEdx, int ptr);
}

struct Vec3Key { float x, y, z; };

extern char* g_registry; // INFERRED: singleton at 0x972734
extern long g_registryOnce;
void registryInit();

extern "C" int fn_004ef650(const float* v, int arg2)
{
    fn_00557330(registryInit, &g_registryOnce);
    char* reg = g_registry;
    void* mutex = reg + 0x10;
    fn_00563090(mutex, 0);

    Vec3Key key;
    key.x = v[0];
    key.y = v[1];
    key.z = v[2];

    char* map = reg + 0x1c;
    int out[2];
    fn_004e8690(map, 0, (int)out, (int)&key);

    int result;
    if (out[1] == *(int*)(map + 0x18)) {
        int obj = 0;
        void* mem = fn_006a0920(0, 0, 0x8c);
        if (mem)
            obj = fn_00500350(mem, 0, (int)v, arg2);
        int ref = fn_004ea140(map, 0, (int)&key);
        fn_00598fa0((void*)ref, 0, obj);
        result = obj;
    } else {
        result = *(int*)(out[1] + 0x1c);
    }
    fn_005630e0(mutex, 0);
    return result;
}
