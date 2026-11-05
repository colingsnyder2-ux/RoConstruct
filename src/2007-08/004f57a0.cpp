// from server: 49% by colin
// roc 2007-08 004f57a0  unit: boost::bad_lexical_cast  size: 759 bytes

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

struct S {
    void f();
};

extern int g_8bfb00;
extern int g_8bfb04;
extern int g_8bfb08;
extern int g_8bfb0c;
extern int g_8bfb10;
extern int g_8bfb14;
extern int g_8bfb18;
extern int g_8bfb1c;
extern int g_8bfb2c;
extern int g_8bfb50;
extern int g_8bfb54;
extern int g_8bfb58;
extern int g_8bfb5c;
extern int g_8bfb60;
extern int g_8bfb64;
extern int g_8bfb68;
extern int g_8bfb6c;
extern int g_8bfb70;
extern int g_8bfb74;
extern int g_8bfb78;
extern int g_8bfb7c;
extern int g_8bfb80;
extern int g_8bfb84;
extern int g_8bfb88;
extern int g_8bfb8c;
extern char g_8bfac1;
extern int g_8bfac8;
extern int g_8bfad4;
extern void* g_77d2ec;

extern "C" void __cdecl sub_474f70(int);
extern "C" void* __cdecl sub_4f45d0(void*);
extern "C" void* __cdecl sub_4f4680(void*);
extern "C" void __cdecl sub_457dd0();

void S::f()
{
    int* p = (int*)this;
    *p = 0;

    int arg = *(int*)((char*)&arg + 0x18);
    int local1c = (int)&local1c;
    sub_474f70(arg);

    void* r1 = sub_4f45d0(&g_8bfb2c);
    int* esi = (int*)r1;
    int edi = esi[0];
    int eax = g_8bfb00;

    if (edi != eax) {
        if (eax != 0) {
            InterlockedIncrement((long*)(eax + 4));
        }
        g_8bfb00 = 0;
        if (edi != 0) {
            g_8bfb00 = edi;
            ((void (__stdcall*)(void*))g_77d2ec)((void*)(edi + 4));
        }
    }

    g_8bfb04 = esi[1];
    g_8bfb08 = esi[2];
    g_8bfb0c = esi[3];
    g_8bfb10 = esi[4];
    g_8bfb14 = esi[5];
    g_8bfb18 = esi[6];
    g_8bfb1c = esi[7];

    int eax2 = local1c;
    if (eax2 != 0) {
        InterlockedIncrement((long*)(eax2 + 4));
    }

    int local2 = 0;
    int local3 = (int)&local2;
    sub_474f70(arg);

    void* r2 = sub_4f4680(&g_8bfac8);
    esi = (int*)r2;
    edi = esi[0];
    eax = g_8bfb50;

    if (edi != eax) {
        if (eax != 0) {
            InterlockedIncrement((long*)(eax + 4));
        }
        g_8bfb50 = 0;
        if (edi != 0) {
            g_8bfb50 = edi;
            ((void (__stdcall*)(void*))g_77d2ec)((void*)(edi + 4));
        }
    }

    g_8bfb54 = esi[1];
    g_8bfb58 = esi[2];
    g_8bfb5c = esi[3];
    g_8bfb60 = esi[4];
    g_8bfb64 = esi[5];
    g_8bfb68 = esi[6];
    g_8bfb6c = esi[7];

    eax2 = local2;
    if (eax2 != 0) {
        InterlockedIncrement((long*)(eax2 + 4));
    }

    int local4 = 0;
    int local5 = (int)&local4;
    sub_474f70(arg);

    void* r3 = sub_4f45d0(&g_8bfad4);
    esi = (int*)r3;
    edi = esi[0];
    eax = g_8bfb70;

    if (edi != eax) {
        if (eax != 0) {
            InterlockedIncrement((long*)(eax + 4));
        }
        g_8bfb70 = 0;
        if (edi != 0) {
            g_8bfb70 = edi;
            ((void (__stdcall*)(void*))g_77d2ec)((void*)(edi + 4));
        }
    }

    g_8bfb74 = esi[1];
    g_8bfb78 = esi[2];
    g_8bfb7c = esi[3];
    g_8bfb80 = esi[4];
    g_8bfb84 = esi[5];
    g_8bfb88 = esi[6];
    g_8bfb8c = esi[7];

    eax2 = local4;
    if (eax2 != 0) {
        InterlockedIncrement((long*)(eax2 + 4));
    }

    g_8bfac1 = 0;

    eax2 = local5;
    if (eax2 != 0) {
        InterlockedIncrement((long*)(eax2 + 4));
    }
}
