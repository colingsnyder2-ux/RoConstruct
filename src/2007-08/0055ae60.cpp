// from server: 42% by tester
// roc 2007-08 0055ae60  size: 309 bytes
// Reconstructed from target assembly.

extern "C" {
    void __stdcall msvcp80_string_ctor(void* self);
    void __stdcall msvcp80_string_dtor(void* self);
    void __stdcall msvcp80_stringstream_ctor(void* self, int mode);
    void __stdcall msvcp80_stringstream_dtor(void* self);
    void __stdcall msvcp80_ostream_flush(void* self);

    void* __stdcall sub_569800();
    void  __stdcall sub_53e720(void* self, void* arg);
    void  __stdcall sub_467cd0(void* self, void* arg);
    void  __stdcall sub_566670(void* self, void* arg);
    void  __stdcall sub_4675d0(void* self);
    void  __stdcall sub_40f800(void* self);
    void  __stdcall sub_62fc62(void* p);
    void  __stdcall sub_553ea0(void* a, void* b, int c, void* d);
}

struct Creator {
    void ctor(int, int, int, int, int, int, int, int);
};

void Creator::ctor(int, int, int, int, int, int, int, int)
{
    char local_50[0x28];
    char local_28[0x1c];
    char local_0c[0x1c];

    msvcp80_stringstream_ctor(local_50, 3);

    void* obj = sub_569800();

    sub_53e720(this, obj);

    sub_467cd0(local_28, local_50);

    sub_566670(local_28, obj);

    msvcp80_ostream_flush(local_50);

    sub_4675d0(local_28);

    if (obj) {
        sub_40f800(obj);
        sub_62fc62(obj);
    }

    msvcp80_string_ctor(local_0c);

    char temp[0x20];
    sub_553ea0(temp, local_50, 1, local_0c);

    msvcp80_string_dtor(local_0c);

    msvcp80_string_dtor(local_28);

    msvcp80_stringstream_dtor(local_50);
}
