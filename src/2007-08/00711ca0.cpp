// from server: 67% by colin
struct CXTColorSelectorCtrl
{
    char pad0[0x20];
    void* field_20;
    char pad24[0x48];
    int field_6c;
    int field_70;
    int field_74;
    char pad78[0x8];
    void* field_80;
    char pad84[0x4];
    int field_88;
    int field_8c;
    int field_90;
    int field_94;
    int field_98;
    int field_9c;
    int field_a0;
    int field_a4;
    int field_a8;
    int field_ac;
    char padb0[0x8];
    int field_b8;
    int field_bc;

    int func(void* arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8);
};

extern "C" void __stdcall sub_69dd20(void*);
extern "C" void __stdcall sub_77ede0(void*, void*);
extern "C" void __stdcall sub_62ff02();
extern "C" void* __stdcall sub_77ec20(int, int);
extern "C" void* __stdcall sub_6304f6(void*, int, int, int);
extern "C" void __stdcall sub_77ddb8(void*, void*);
extern "C" void __stdcall sub_77dd98(void*, const char*, int, void*, int, int, void*);
extern "C" int __stdcall sub_62fce0(void*, void*, int);
extern "C" void __stdcall sub_77ddbc(void*);
extern "C" void __stdcall sub_62ff4a(void*, int);
extern "C" void* __stdcall sub_6978f0();
extern "C" void __stdcall sub_77ecd8(void*, int, void*, int);

extern int g_8c97ac;

int CXTColorSelectorCtrl::func(void* arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8)
{
    this->field_80 = arg1;
    if (arg1 == 0)
        return 0;

    sub_69dd20(*(void**)((char*)arg1 + 0x20));

    this->field_ac = arg2;
    this->field_b8 = arg3;
    this->field_bc = arg4;

    sub_77ede0(&this->field_8c, &arg5);

    int v1 = this->field_a4 + this->field_9c;
    int v2 = this->field_8c;
    int v3 = v1 + v2 + 0x90;
    int v4 = this->field_a8 + this->field_a0;

    this->field_94 = v3;
    this->field_90 = this->field_98;
    int v5 = v4 + this->field_98 + 0x6e;
    this->field_98 = v5;

    if ((this->field_ac & 2) != 0)
    {
        v5 += 0x22;
        this->field_74 = 0x28;
        this->field_98 = v5;
    }
    else
    {
        this->field_74 = 0x10;
    }

    int v6 = this->field_74;
    this->field_6c = v6 / this->field_70;
    this->field_74 = v6 + 1;

    sub_62ff02();

    void* h = sub_77ec20(0, 0x7f00);
    void* h2 = sub_6304f6(h, 0, 0, 0);
    sub_77ddb8(&arg5, h2);

    arg5 = 0;

    if ((this->field_ac & 4) != 0)
    {
        if (g_8c97ac > 0)
        {
            int v7 = this->field_88 + 4;
            this->field_98 += v7;
            this->field_74 += g_8c97ac;
        }
    }
    else
    {
        this->field_98 -= 0x1c;
    }

    int v8 = (arg2 & 0x80000000) ? 0x40000000 : 0x80000000;
    v8 += 0x40000000;

    sub_77dd98(&arg5, (const char*)0x785954, v8, &this->field_8c, 0, 0, this->field_80);

    if (sub_62fce0(this, &arg5, 0) == 0)
    {
        sub_77ddbc(&arg5);
        return 0;
    }

    sub_62ff4a(this, 8);

    void* v9 = sub_6978f0();
    v9 = (char*)v9 + 0xdc;
    if (v9 != 0)
        v9 = *(void**)((char*)v9 + 4);

    sub_77ecd8(this->field_20, 0x30, v9, 1);

    sub_77ddbc(&arg5);
    return 1;
}
