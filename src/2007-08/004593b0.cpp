// from server: 51% by colin
struct CRobloxWnd {
    char pad[0x58];
    int field_58;
    char pad2[0x94 - 0x5c];
    void* field_94;
    char pad3[0x9c - 0x98];
    void* field_9c;
    void func_458b80();
    void func_458ec0(int, int);
    void func_4593b0(int, int);
};

extern "C" {
    int __stdcall func_46d600();
    int __stdcall func_5085b0(void*, void*);
}

struct FakeString {
    char data[0x1c];
    FakeString();
    FakeString(const char*);
    FakeString(const FakeString&);
    ~FakeString();
};

extern FakeString* __stdcall string_ctor_copy(FakeString*, const FakeString*);
extern FakeString* __stdcall string_ctor_char(FakeString*, const char*);
extern void __stdcall string_dtor(FakeString*);

extern void* g_8bd0d8;

void CRobloxWnd::func_4593b0(int a, int b)
{
    if (this->field_94 == 0)
        return;
    if (this->field_9c == 0)
        return;

    int v = func_46d600();
    FakeString s1;
    string_ctor_copy(&s1, (const FakeString*)v);

    FakeString s2;
    string_ctor_char(&s2, "MOBILITY RADEON 7500");

    char result = (char)func_5085b0(&s1, &s2);
    string_dtor(&s2);

    if (result) {
        this->field_58 = 2;
        this->func_458b80();
        if (this->field_58 == 2) {
            this->func_458ec0(a, b);
        }
    }

    void* p = this->field_94;
    if (g_8bd0d8 != p) {
        void** vt = *(void***)p;
        void (*fn)(void*) = *(void (**)(void*))((char*)vt + 0x98);
        fn(p);
        g_8bd0d8 = p;
    }

    string_dtor(&s1);
}
