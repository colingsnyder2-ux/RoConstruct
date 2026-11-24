// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" int __fastcall fn_00540fb0(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_00540ce0(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_00540b10(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_00541030(void* self, int unusedEdx);
extern "C" int __fastcall fn_0053f340(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_0053f470(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_00402410(void* self, int unusedEdx);
extern "C" int __fastcall fn_005400f0(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_005410d0(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_0071f210(void* self, int unusedEdx, void* out);
extern "C" int __fastcall fn_004e6c00(void* self, int unusedEdx);
extern "C" int __fastcall fn_00502a70(void* self, int unusedEdx);

// INFERRED: 8-byte string-like temp built from the arg, destroyed by fn_00541030
struct KeyTmp {
    int d[2];
    KeyTmp(int a) { fn_00540fb0(this, 0, a); }
    ~KeyTmp() { fn_00541030(this, 0); }
};

// INFERRED: result object, destroyed by fn_00502a70
struct ResObj {
    int d[1];
    ~ResObj() { fn_00502a70(this, 0); }
};

// INFERRED: by-value 4-byte argument copied through fn_005410d0
struct ByVal {
    int d;
    ByVal(ResObj& o) { fn_005410d0(this, 0, (int)&o); }
};

struct Holder { char pad0[0x28]; char m28[0x20]; char m48[4]; };

extern "C" int __fastcall fn_0053fa50(Holder* self, int unusedEdx, int a, unsigned char flag)
{
    if (flag) {
        bool r;
        {
            KeyTmp t(a);
            r = fn_00540ce0(self->m48, 0, (int)&t) == 1;
        }
        if (r) {
            char out[16];
            KeyTmp t2(a);
            fn_00540b10(self->m28, 0, (int)out, (int)&t2);
        }
        fn_0053f340(self, 0, a);
    } else {
        bool r;
        {
            KeyTmp t(a);
            r = fn_00540ce0(self->m28, 0, (int)&t) == 1;
        }
        if (r) {
            char out[16];
            KeyTmp t2(a);
            fn_00540b10(self->m48, 0, (int)out, (int)&t2);
        }
        ResObj obj;
        int w = fn_0071f210((void*)a, 0, &obj);
        fn_004e6c00((char*)w + 0x20, 0);
        if ((unsigned char)fn_00402410(&obj, 0)) {
            ByVal v(obj);
            fn_005400f0(self, 0, v.d);
        }
        fn_0053f470(self, 0, a);
    }
    return 0;
}
