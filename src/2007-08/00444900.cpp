// from server: 32% by colin
struct S {
    char pad[0xe8];
    void* field_e8;
    void construct(char* name, int flags, int mode);
};

extern "C" {
    void* __stdcall CreateFileA(const char*, unsigned long, unsigned long, void*, unsigned long, unsigned long, void*);
    int __stdcall FindClose(void*);
    int __stdcall CloseHandle(void*);
}

extern void* G2_00786dcc;
extern void* G3_0078f6fc;

void __stdcall sub_40f800(void*);
void __cdecl sub_62fc62(void*);
void __stdcall sub_40fb40(void*);
void __stdcall sub_566c00(void*, void*);
void __stdcall sub_567100(void*, void*);
void __stdcall sub_542160(void*, void*, void*);
void __stdcall sub_4434c0(void*);
void* __stdcall sub_443140(void*);
void __stdcall sub_418400(void);
void __stdcall sub_418690(void);
void __stdcall sub_443ca0(void);
void __stdcall sub_425520(void);
void __stdcall sub_425a20(void);
void __stdcall sub_425aa0(void);
void __stdcall sub_425ea0(void);
void __stdcall sub_4255a0(void);
void __stdcall sub_425620(void);
void __stdcall sub_4256a0(void);
void __stdcall sub_444810(void*, void*);
void __stdcall sub_443450(void*, void*, void*, void*);

void S::construct(char* name, int flags, int mode) {
    void* h;
    void* findData[80];
    void* str1[8];
    void* str2[8];
    void* str3[8];
    void* ifs[80];
    void* p;
    void* q;
    void* r;

    h = CreateFileA(name, 0x80000000, 1, 0, 3, 0x80, 0);
    if (h == (void*)-1) {
        return;
    }
    CloseHandle(h);

    sub_566c00(str1, name);
    *(void**)str1 = G2_00786dcc;
    sub_567100(str2, str1);
    p = *(void**)str2;
    *(void**)str2 = 0;
    q = *(void**)str1;
    if (q != 0) {
        sub_40f800(q);
        sub_62fc62(q);
    }
    *(void**)str3 = G3_0078f6fc;
    *(void**)((char*)str3 + 8) = 0;
    *(void**)((char*)str3 + 12) = 0;
    *(void**)((char*)str3 + 16) = 0;
    sub_542160(this, p, str3);
    sub_4434c0(str3);
    r = sub_443140(this);
    this->field_e8 = r;
    if (r != 0) {
        sub_418400();
        sub_444810(this->field_e8, r);
        sub_418690();
        sub_444810(this->field_e8, r);
        sub_443ca0();
        sub_444810(this->field_e8, r);
        sub_425520();
        sub_444810(this->field_e8, r);
        sub_425a20();
        sub_444810(this->field_e8, r);
        sub_425aa0();
        sub_444810(this->field_e8, r);
        sub_425ea0();
        sub_444810(this->field_e8, r);
        sub_4255a0();
        sub_444810(this->field_e8, r);
        sub_425620();
        sub_444810(this->field_e8, r);
        sub_4256a0();
        sub_444810(this->field_e8, r);
    }
    if (*(void**)((char*)str3 + 8) != 0) {
        sub_443450(*(void**)((char*)str3 + 8), *(void**)((char*)str3 + 12), str3, p);
        sub_62fc62(*(void**)((char*)str3 + 16));
    }
    *(void**)((char*)str3 + 8) = 0;
    *(void**)((char*)str3 + 12) = 0;
    *(void**)((char*)str3 + 16) = 0;
    if (p != 0) {
        sub_40f800(p);
        sub_62fc62(p);
    }
    sub_40fb40(ifs);
    FindClose(ifs);
}
