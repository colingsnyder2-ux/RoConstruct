// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: iterator/pointer types are opaque; shapes come from the disassembly only.
struct It { int a, b; };

extern "C" int __fastcall fn_00540e80(void* self, int unusedEdx);
extern "C" int __fastcall fn_00540630(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_00540660(void* self, int unusedEdx, int a1);
extern "C" bool __fastcall fn_00540f20(It* self, int unusedEdx, It* other);
extern "C" void* __fastcall fn_00541180(It* self, int unusedEdx);
extern "C" void __fastcall fn_00540f50(It* self, int unusedEdx);
extern "C" int __fastcall fn_0071f210(void* self, int unusedEdx);
extern "C" int __fastcall fn_00540530(void* self, int unusedEdx, int a1);
extern "C" void __fastcall fn_00502a70(void* self, int unusedEdx);
extern "C" void* __fastcall fn_004e6030(void* self, int unusedEdx, void* p);
extern "C" int __fastcall fn_00545e30(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_00540780(void* self, int unusedEdx);
extern "C" void __fastcall fn_004d7db0(void* self, int unusedEdx, void* model);
extern "C" void __fastcall fn_004d8320(void* self, int unusedEdx, void* ptr);
extern int g_00972890;

struct Ref {
    void* p;
    ~Ref() { fn_00502a70(this, 0); }
};

struct Scene {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(void* model, int flag);
};

extern "C" void __fastcall fn_005400f0(Scene* self, int unusedEdx, Ref arg)
{
    It it, end;
    int base = fn_00540e80(&arg, 0) + 0xf0;
    fn_00540630((void*)base, 0, (int)&it);
    for (;;) {
        fn_00540660((void*)(fn_00540e80(&arg, 0) + 0xf0), 0, (int)&end);
        if (!fn_00540f20(&it, 0, &end))
            break;
        void* elem = fn_00541180(&it, 0);
        {
            Ref tmp;
            fn_004e6030(&tmp, 0, 0);
            fn_00540530((void*)(fn_0071f210(elem, 0) + 0x20), 0, (int)&tmp);
        }
        g_00972890 -= 1;
        fn_004d7db0(self, 0, elem);
        self->v4(elem, 1);
        fn_00540f50(&it, 0);
    }
    {
        Ref tmp2;
        fn_00545e30(&tmp2, 0, (int)&arg);
        fn_004d8320(self, 0, &tmp2);
    }
    fn_00540780((void*)(fn_00540e80(&arg, 0) + 0xf0), 0);
}
