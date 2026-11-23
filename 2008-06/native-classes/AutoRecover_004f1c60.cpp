// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: cache lookup of a material by tint, with a weak-pointer map under GuidRegistryMutex.
// Signature guessed from the disassembly (ret 16: out pointer plus Color3 passed by value in 3 dwords).
// Every callee is declared as an opaque fn_ extern. The body is only a best-effort sketch. It has not been compiled or diffed.

struct Color3Args { float r, g, b; };

extern "C" void fn_00557330(void (*fn)(), long* flag);                                    // boost::call_once
extern "C" void fn_00563090(void* mutex);                                                 // GuidRegistryMutex::lock
extern "C" void fn_005630e0(void* mutex);                                                 // GuidRegistryMutex::unlock
extern "C" void* __fastcall fn_004f1710(void* map, int unusedEdx, void* key, void* outPtr); // map::operator[]
extern "C" void __fastcall fn_004f0c40(void* weakPtr, int unusedEdx, void* strongPtr);    // weak = strong
extern "C" void* __fastcall fn_004f0a20(void* self, int unusedEdx, void* out, Color3Args tint); // getSurfacesTexture
extern "C" void* fn_00551730();                                                           // Part::getMaterial
extern "C" void __fastcall fn_00598fa0(void* ptr, int unusedEdx, void* p);                // setPointer

extern void* g_materialCache; // INFERRED: 0x972880 map object, mutex at +0x40

extern "C" void** __fastcall fn_004f1c60(void* self, int unusedEdx, void** out, float r, float g, float b)
{
    void* cache = g_materialCache;
    void* mutex = (char*)cache + 0x40;
    fn_00563090(mutex);
    *out = 0;
    // INFERRED: find(key); on miss build a new material for the tint and cache it via map[key] = ptr.
    Color3Args tint = { r, g, b };
    void* mat = fn_004f0a20(self, 0, 0, tint);
    fn_00598fa0(out, 0, mat);
    fn_004f0c40(fn_004f1710(cache, 0, &tint, out), 0, out);
    fn_005630e0(mutex);
    return out;
}
