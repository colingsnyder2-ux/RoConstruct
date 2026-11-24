// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: opaque types; singleton cache with mutex at +0x10 and map at +0x3c
struct Vec3 { float x, y, z; };
struct Vec2 { float x, y; };
struct Key { Vec3 v; int normalId; Vec2 uv; };

extern "C" void fn_004d9750();
extern "C" void fn_00557330(void (*f)(), long* flag);
extern "C" int __fastcall fn_004e8720(void* self, int unusedEdx, int a1, int a2);
extern "C" void* __fastcall fn_004ea000(void* self, int unusedEdx, int a1);
extern "C" void* __fastcall fn_006a0920(void* self, int unusedEdx, int a1);
extern "C" void* __fastcall fn_004f4b20(void* self, int unusedEdx, Vec3* v, int n, Vec2* uv);
extern "C" void __fastcall fn_00563090(void* self);
extern "C" void __fastcall fn_005630e0(void* self);
extern "C" void __fastcall fn_00598fa0(void* self, int unusedEdx, void* p);
extern "C" void* fn_00972724_ptr;
extern long g_once_flag_00972738;

struct Cache { char pad[0x10]; char mutex[0x2c]; char map[1]; };
extern Cache* g_cache_00972724;

extern "C" void* fn_004edeb0(Vec3* v, int normalId, Vec2* uv)
{
    fn_00557330(fn_004d9750, &g_once_flag_00972738);
    Cache* c = g_cache_00972724;
    void* mtx = (char*)c + 0x10;
    fn_00563090(mtx);

    Key key;
    key.v = *v;
    key.normalId = normalId;
    key.uv.x = uv->x;
    key.uv.y = uv->y;

    char* map = (char*)c + 0x3c;
    int it[2];
    fn_004e8720(map, 0, (int)it, (int)&key);

    void* result;
    if (it[1] == *(int*)(map + 0x18)) {
        void* mem = fn_006a0920(0, 0, 0x8c);
        result = mem ? fn_004f4b20(mem, 0, v, normalId, uv) : 0;
        void* slot = fn_004ea000(map, 0, (int)&key);
        fn_00598fa0(slot, 0, result);
    } else {
        result = *(void**)(it[1] + 0x24);
    }
    fn_005630e0(mtx);
    return result;
}
