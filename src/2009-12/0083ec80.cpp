// from server: 63% by atomic.potato
extern "C" void* __stdcall GlobalAlloc(unsigned int, unsigned int);
extern "C" int __stdcall CloseClipboard();
extern "C" int __stdcall EmptyClipboard();
extern "C" void* __stdcall SetClipboardData(unsigned int, void*);

extern void* g_98cc1c;
extern void* g_98cc18;
extern void* g_98cc0c;
extern void* g_98b1c8;
extern unsigned short g_b9adb4;

struct CActiveDocView
{
    char pad[0x90];
    void* GetSomething();
};

struct CXTPCommandBar
{
    char pad[0x4];
    int IsSomething();
};

struct CCustomizeEdit
{
    char pad[0xb8];
    void* GetDoc();
};

void* __fastcall sub_92656e(void*);
void __fastcall sub_40f230(void*);
void* __fastcall sub_814700(void*);
void* __fastcall sub_80d470(void*);
void* __fastcall sub_810230(void*);
void* __fastcall sub_8104b0(void);

void __fastcall sub_83ec80(CCustomizeEdit* self)
{
    if (g_98cc1c != 0)
    {
        char buf[0x3c];
        sub_92656e(buf);
        void* p = g_98cc18;
        typedef void* (__thiscall *Fn)(int, void*);
        ((Fn)p)(2, buf);

        if (((CXTPCommandBar*)self)->IsSomething() != 0)
        {
            sub_8104b0();
            typedef void* (__stdcall *Fn2)(int, int);
            void* h = ((Fn2)g_98b1c8)(2, 1);
            ((Fn)p)(g_b9adb4, h);
        }

        void* doc = ((CActiveDocView*)self)->GetSomething();
        void* r = sub_814700(*(void**)((char*)self + 0xb8));
        (void)r;
        void* q = sub_80d470(doc);
        if (q != 0)
        {
            void* doc2 = ((CActiveDocView*)self)->GetSomething();
            void* r2 = sub_814700(*(void**)((char*)self + 0xb8));
            (void)r2;
            sub_810230(doc2);
        }
    }

    typedef void* (__stdcall *Fn3)();
    ((Fn3)g_98cc0c)();
    sub_40f230(0);
}
