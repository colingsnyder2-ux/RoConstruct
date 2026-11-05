// from server: 27% by atomic.potato
struct VPlayer;

struct VPlayerVtbl {
    void* pad0;
    int (__thiscall* f4)(VPlayer*);
    int (__thiscall* f8)(VPlayer*, char*);
    int (__thiscall* fc)(VPlayer*, void*);
};

struct VPlayer {
    VPlayerVtbl* vtbl;
};

struct Value {
    void* p;
    void* q;
    Value();
};

extern "C" char* __cdecl sub_6C5290(Value*);
extern "C" void __cdecl sub_41B1D0(Value*);
extern "C" void __cdecl sub_972D70(int, const char*, char*);
extern "C" void __cdecl sub_983144(const char*, char*);

char VPlayer_GetByte(VPlayer* self) {
    char result;
    Value v;
    char buf[4];
    int n;
    char* s;
    int r;

    r = self->vtbl->f4(self);
    if (r < 1) goto L_4670;

    if (self->vtbl->f8(self, &result)) {
        return result;
    }

    sub_41B1D0(&v);
    n = 0;
    if (self->vtbl->fc(self, &v)) {
        char b = *sub_6C5290(&v);
        if (v.p) {
            (*(void (__thiscall**)(void*, char*))((char*)v.p + 4))(v.p, buf);
        }
        return b;
    }
    if (v.p) {
        (*(void (__thiscall**)(void*, char*))((char*)v.p + 4))(v.p, buf);
    }

L_4670:
    s = *(char**)0;
    if (s) {
        return *s;
    }
    sub_972D70(1, (const char*)0xB70754, buf);
    sub_983144((const char*)0xCD806C, buf);
    return 0;
}
