// from server: 75% by atomic.potato
extern "C" {
    int __stdcall sub_972290(int, const char*);
}

struct VButton {
    void* vtable;
};

struct Creator {
    void* vtable;
    void* field4;
};

extern char byte_E580B3;
extern int dword_E188A8;
extern int (__stdcall *dword_E5809C)(int, const char*, const char*);

void __stdcall sub_4019D0(void*);
void __stdcall sub_4A11D0(void*);

void* __fastcall sub_439FA0(VButton* self);

void __fastcall Creator_ctor(Creator* self);

void __fastcall Creator_ctor(Creator* self)
{
    self->vtable = (void*)0xB50CBC;
    if (byte_E580B3 != 0 && dword_E188A8 != 0x29A) {
        if (dword_E5809C != 0) {
            if (dword_E5809C(0xE2, (const char*)0xB42FA8, (const char*)0xB42F90)) {
                goto skip;
            }
        }
        sub_972290((int)byte_E580B3, (const char*)0xB43368);
    }
skip:
    void* r = sub_439FA0((VButton*)self);
    sub_4019D0(&r);
    sub_4A11D0(&r);
}
