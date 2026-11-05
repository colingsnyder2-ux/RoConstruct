// from server: 35% by colin
struct S {
    char pad[0xb8];
    int field_b8;
    char field_bc;
    char pad2[0xf];
    int field_cc;
    int field_c4;
    int method(int* out);
};

extern "C" {
    void __stdcall sub_77e6a4(void*);
    void __stdcall sub_77e69c(void*, void*);
    void __stdcall sub_77e6ac(void*);
    void* __cdecl sub_62fef6(unsigned int);
    void __cdecl sub_4fb9c0(void*);
    void __cdecl sub_4fb8c0(void*);
    void __cdecl sub_474f70(void*, void*);
    void __cdecl sub_4cfe90(void*, void*, void*);
    void __cdecl sub_4d09f0(void*, void*, int);
    void* __cdecl sub_408740();
    void __cdecl sub_549260(void*, void*);
}

int S::method(int* out)
{
    if (this->field_bc != 0)
    {
        char buf1[0x20];
        char buf2[0x20];
        sub_77e6a4(buf1);
        sub_4cfe90(&buf2, buf1, (void*)this->field_cc);
        char* p = buf2;
        char buf3[0x20];
        sub_77e69c(buf3, p);
        *(int*)(buf3 + 0x1c) = *(int*)(p + 0x1c);
        void* r = sub_408740();
        char b = 0;
        sub_549260(r, &b);
        sub_77e6ac(buf1);
        if (b != 0)
        {
            void* mem = sub_62fef6(0x18);
            if (mem != 0)
                sub_4fb9c0(mem);
            sub_474f70(&this->field_b8, mem);
            void* mem2 = sub_62fef6(0x4c);
            void* edx = 0;
            if (mem2 != 0)
            {
                int* p2 = (int*)this->field_c4;
                int v = *(int*)((char*)p2 + 0x50);
                sub_4d09f0(mem2, buf1, v);
                edx = mem2;
            }
            int* eax = (int*)this->field_cc;
            float f1 = *(float*)((char*)eax + 0x110);
            float f2 = *(float*)((char*)eax + 0x10c);
            float f3 = *(float*)0x89820c;
            float f4 = *(float*)0x898210;
            float f5 = *(float*)0x898214;
            float args[7];
            args[0] = f3;
            args[1] = f4;
            args[2] = f5;
            args[3] = 0.0f;
            args[4] = f2;
            args[5] = f1;
            args[6] = 0.0f;
            sub_474f70(&this->field_b8, edx);
            sub_4fb8c0((void*)this->field_b8);
            this->field_bc = 0;
        }
        sub_77e6ac(buf1);
    }
    *out = 0;
    sub_474f70(out, (void*)this->field_b8);
    return (int)out;
}
