// from server: 29% by colin
extern "C" void __cdecl sub_4FF810(void*);
extern "C" void __cdecl sub_4F48B0(void*, void*);

struct S {
    void* vtable;
    int field_4;
    int field_8;
    int* field_C;
    int field_10;
    int field_14;
    void destroy();
};

void S::destroy()
{
    this->vtable = (void*)0x79F304;
    int i = 0;
    if (this->field_10 > 0) {
        do {
            int* ecx = *(int**)0x8BFB38;
            int eax = this->field_C[i];
            if (ecx != 0) {
                int edx = ecx[eax];
                *(int*)0x8BFAC4 = *(int*)0x8BFAC4 - 1;
                if (edx != 1) {
                    ecx[eax] = 0;
                    int tmp = eax;
                    sub_4F48B0((void*)0x8BFB44, &tmp);
                } else {
                    ecx[eax] = edx - 1;
                }
            }
            i++;
        } while (i < this->field_10);
    }
    sub_4FF810(this->field_C);
    this->field_C = 0;
    this->field_10 = 0;
    this->field_14 = 0;
    this->vtable = (void*)0x797984;
}
