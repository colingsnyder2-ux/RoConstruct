// from server: 37% by colin
struct DxUserInput {
    char pad0[0x34];
    int field34;
    char pad38[0x30];
    unsigned char field68;
    char pad69[0x117];
    int field180;

    void sub_464D30();
};

extern "C" void __stdcall LeaveCriticalSection(void*);

void __cdecl sub_463770();
void __cdecl sub_41D870();
void __cdecl sub_464720();
void __cdecl sub_630940();
void __cdecl sub_630946(int);
int __cdecl sub_630D60(float);

void DxUserInput::sub_464D30()
{
    sub_463770();
    int local10 = (int)&this->field34;
    unsigned char local14 = 0;
    sub_41D870();
    int local3c = 0;
    if (this->field68 != 0) {
        int (__thiscall *fn)(void*, int*) = *(int (__thiscall **)(void*, int*))*(void**)this;
        int local18;
        fn(this, &local18);
        int edi = sub_630D60(*(float*)((char*)&local18 + 4));
        int ebp = sub_630D60(*(float*)&local18);
        int local20;
        sub_630946(this->field180);
        int (__thiscall *fn2)(void*, int, int) = *(int (__thiscall **)(void*, int, int))(*(int*)&local20 + 0x5c);
        unsigned char local44 = 1;
        int r = fn2(&local20, ebp, edi);
        if (r == 0) {
            sub_464720();
        }
        local3c = 0;
        sub_630940();
    }
    if (local14 != 0) {
        LeaveCriticalSection((void*)local10);
    }
}
