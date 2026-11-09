// from server: 39% by colin
extern "C" {
    void __stdcall PostMessageA(void*, unsigned int, unsigned int, int);
    void __cdecl _invalid_parameter_noinfo();
}

struct CSelectionPropGrid
{
    char pad0[4];
    int field4;
    char pad8[0x18];
    int field20;
    char pad24[0x14];
    char field38;
    char field39;
    char pad3a[2];
    int field3c;
    char pad40[0x11c];
    int field15c;

    void func_0043a8e0(int arg0, int arg1, int arg2);
};

extern int G_8b5188;
extern int G_77e6d8;
extern int G_77ecd0;

void __stdcall sub_725750(int*);
void __stdcall sub_725770(int*);
int* __stdcall sub_44f4c0(int*, int*);
void __stdcall sub_4a9660(int*, int*);

void CSelectionPropGrid::func_0043a8e0(int arg0, int arg1, int arg2)
{
    int local14;
    char local18;
    int local20;
    int local38;
    int local44;
    int local48;

    local14 = (int)&this->field4;
    sub_725750(&this->field4);
    local18 = 1;
    local38 = 0;

    if (this->field39 == 0)
    {
        local44 = arg0;
        int* p = sub_44f4c0(&this->field20, &local20);
        int ebp = p[0];
        int ebx = p[1];
        local48 = this->field20;
        if (ebp != 0 && ebp == (int)&this->field20)
        {
        }
        else
        {
            ((void (__stdcall*)())G_77e6d8)();
        }
        if (ebx != local48)
        {
            if (ebp == 0)
                ((void (__stdcall*)())G_77e6d8)();
            if (ebx == *(int*)(ebp + 4))
                ((void (__stdcall*)())G_77e6d8)();
            ebx += 0x10;
            sub_4a9660(&this->field3c, &local20);
        }

        sub_725750(&this->field4);
        if (this->field38 == 0)
        {
            int v = *(int*)((char*)this - 0x15c);
            if (v != 0)
            {
                PostMessageA((void*)v, 0x465, 0, 0);
            }
            this->field38 = 1;
        }
        sub_725770(&this->field4);
    }

    local38 = -1;
    sub_725770(&this->field4);
}
