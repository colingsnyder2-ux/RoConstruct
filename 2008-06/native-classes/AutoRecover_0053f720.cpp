// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: all type names are guesses; the annotated callee names in the
// disassembly comments did not match what the code actually does.

struct Obj8 { int lo; int hi; };

// INFERRED: temporary smart-pointer-like object; the dtor is the 0x502a70 callee
extern "C" void __fastcall fn_00502a70(void* self, int unusedEdx);

struct TmpRef {
    int p;
    TmpRef() : p(0) {}
    ~TmpRef() { fn_00502a70(this, 0); }
};

// INFERRED: getter-type callee, thiscall with 0 stack args, returns a pointer to an object
extern "C" char* __fastcall fn_0071f210(void* self, int unusedEdx);
extern "C" void* __fastcall fn_004e6c00(void* self, int unusedEdx, void* out);
extern "C" int __fastcall fn_00402410(void* self, int unusedEdx);
extern "C" int __fastcall fn_004dc3d0(void* self, int unusedEdx);
// INFERRED: takes 0 stack args per the disassembly
extern "C" void* __fastcall fn_00548f80(void* self, int unusedEdx, void* ret, float f);
extern "C" int fn_0053f920(int a1);
extern "C" Obj8* __fastcall fn_00540660(void* self, int unusedEdx, void* a1);
extern "C" Obj8* __fastcall fn_00540630(void* self, int unusedEdx, void* a1);
// INFERRED: cdecl, caller pops 0x18, hidden return slot + two 8-byte values + arg
extern "C" void* fn_00545d40(void* out, int v2lo, int v2hi, int v1lo, int v1hi, void* arg);
extern "C" int __fastcall fn_00540f20(void* self, int unusedEdx, void* a1);
extern "C" int __fastcall fn_00540690(void* self, int unusedEdx, void* a1);

struct Owner {
    char pad[0xc];
    char container[1]; // INFERRED: sub-object at +0xc
};

typedef void* (__fastcall *VFn18_3)(void* self, int edx, void* a, void* b, float f);
typedef void* (__fastcall *VFn1c_0)(void* self, int edx);

extern "C" void __fastcall fn_0053f720(Owner* self, int unusedEdx, void* arg)
{
    bool r1;
    {
        TmpRef t;
        char* o = fn_0071f210(arg, 0);
        void* p = fn_004e6c00(o + 0x20, 0, &t);
        r1 = fn_00402410(p, 0) != 0;
    }
    if (r1) return;

    bool r2;
    {
        TmpRef t;
        char* o = fn_0071f210(arg, 0);
        void* p = (*(void* (__fastcall **)(void*, int, void*))(*(char**)o + 0x18))(o, 0, &t);
        r2 = fn_004dc3d0(p, 0) != 0;
    }
    if (r2) return;

    bool r3;
    {
        TmpRef t24;
        TmpRef t28;
        char* o = fn_0071f210(arg, 0);
        void* p = ((VFn18_3)(*(void***)o)[6])(o, 0, &t24, &t28, 1.0f);
        char* q = fn_0071f210(p, 0);
        char* z = fn_00548f80(q, 0);
        char* w = fn_0071f210(z, 0);
        r3 = (*(int*)(w + 0x18) != 5);
    }
    if (r3) return;

    {
        char* o = fn_0071f210(arg, 0);
        void* v = ((VFn1c_0)(*(void***)o)[7])(o, 0);
        if (!(fn_0053f920((int)v) & 0xff)) return;
    }

    void* m = self->container;
    char t48[8], t30[8], t38[8], t40[8];
    Obj8* a = fn_00540660(m, 0, t48);
    Obj8* v1 = fn_00540660(m, 0, t30);
    Obj8* v2 = fn_00540630(m, 0, t38);
    void* res = fn_00545d40(t40, v2->lo, v2->hi, v1->lo, v1->hi, arg);
    if (fn_00540f20(res, 0, a) & 0xff) return;
    fn_00540690(m, 0, arg);
}
