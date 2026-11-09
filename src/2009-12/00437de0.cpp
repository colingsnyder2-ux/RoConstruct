// from server: 26% by atomic.potato
extern "C" void __stdcall _invalid_parameter_noinfo();

struct Arg {
    int f0;
    char pad4[0x14];
    int f18;
};

struct Vec2 {
    float x;
    float y;
    short a;
    short b;
};

extern "C" void __stdcall sub_4345c0(void*, void*);
extern "C" void __stdcall sub_8648f0(void*, int);

struct S {
    char pad0[4];
    int f4;
    char pad8[8];
    int f10;
    int f14;
    char pad18[8];
    int f20;
    void func(Arg* arg);
};

void S::func(Arg* arg) {
    Vec2 v;
    v.x = 0.0f;
    v.y = 0.0f;
    v.a = 0;
    v.b = 0;
    char flag = 0;

    int* p10 = (int*)this->f10;
    int* p14 = (int*)this->f14;
    int* p4 = (int*)this->f4;

    if ((unsigned)p10 > (unsigned)p14) {
        _invalid_parameter_noinfo();
    }

    int* ebx = p10;
    int* esi = p14;
    int* ebp = p4;

    if ((unsigned)this->f10 > (unsigned)esi) {
        _invalid_parameter_noinfo();
    }

    int* ecx2 = (int*)this->f4;
    if (ebp != 0 && ebp != ecx2) {
        _invalid_parameter_noinfo();
    }

    if (ebx == esi) {
        int edx = (flag == 0) ? 1 : 0;
        sub_8648f0((char*)this - 0x10c, edx);
        return;
    }

    if (ebp != 0) {
        ebp = (int*)*ebp;
    } else {
        _invalid_parameter_noinfo();
        ebp = 0;
    }

    if ((unsigned)ebx < (unsigned)*(int*)((char*)ebp + 0x10)) {
        _invalid_parameter_noinfo();
    }

    int edx = *ebx;
    sub_4345c0((char*)this + 0x10, &v);
    int* edi = (int*)*(int*)&v.x;
    int* esi2 = (int*)*(int*)&v.y;

    if (esi2 == (int*)arg->f18) {
        goto end;
    }

    while (1) {
        if (edi != 0) {
            edi = (int*)*edi;
        } else {
            _invalid_parameter_noinfo();
            edi = 0;
        }

        if (esi2 == (int*)*(int*)((char*)edi + 0x18)) {
            _invalid_parameter_noinfo();
        }

        int* ebp2 = (int*)*(int*)((char*)esi2 + 0x1c);
        if ((unsigned)ebp2 > (unsigned)*(int*)((char*)esi2 + 0x20)) {
            _invalid_parameter_noinfo();
        }

        int* ebx2 = (int*)*(int*)((char*)esi2 + 0x10);
        int* edi2 = (int*)*(int*)((char*)esi2 + 0x20);
        int* esi3 = (int*)*(int*)((char*)esi2 + 0x10);

        if (ebx2 != 0 && ebx2 != esi3) {
            _invalid_parameter_noinfo();
        }

        if (ebp2 == edi2) {
            ebp = (int*)*(int*)((char*)this + 0x28);
            ebx = (int*)*(int*)((char*)this + 0x2c);
            goto loop2;
        }

        if (flag != 0) {
            if (ebx2 != 0) {
                ebx2 = (int*)*ebx2;
            } else {
                _invalid_parameter_noinfo();
                ebx2 = 0;
            }
            int* eax = (int*)*(int*)((char*)ebx2 + 0x1c);
            if (eax != 0) {
                eax = (int*)((char*)eax + 0x1c);
            } else {
                eax = 0;
            }
            void* ecx3 = (void*)*(int*)((char*)this + 0x20);
            ecx3 = (void*)*(int*)((char*)ecx3 + 0x1c);
            void* edx3 = (void*)*(int*)ecx3;
            edx3 = (void*)*(int*)((char*)edx3 + 0xc);
            Vec2 v2;
            ((void(__thiscall*)(void*, void*, void*))edx3)(ecx3, &v2, eax);
            v.x = v2.x;
            v.y = v2.y;
            v.a = v2.a;
            v.b = v2.b;
            void* edx4 = (void*)*(int*)((char*)this - 0x10c);
            edx4 = (void*)*(int*)((char*)edx4 + 0xe8);
            ((void(__thiscall*)(void*, Vec2*))edx4)((char*)this - 0x10c, &v);
        } else {
            if (ebx2 != 0) {
                ebx2 = (int*)*ebx2;
            } else {
                _invalid_parameter_noinfo();
                ebx2 = 0;
            }
            int* eax = (int*)*(int*)((char*)ebx2 + 0x1c);
            if (eax != 0) {
                eax = (int*)((char*)eax + 0x1c);
            } else {
                eax = 0;
            }
            void* ecx3 = (void*)*(int*)((char*)this + 0x20);
            ecx3 = (void*)*(int*)((char*)ecx3 + 0x1c);
            void* edx3 = (void*)*(int*)ecx3;
            edx3 = (void*)*(int*)((char*)edx3 + 0xc);
            Vec2 v2;
            ((void(__thiscall*)(void*, void*, void*))edx3)(ecx3, &v2, eax);
            void* eax2 = (void*)*(int*)((char*)this - 0x10c);
            eax2 = (void*)*(int*)((char*)eax2 + 0xec);
            if (((char(__thiscall*)(void*, Vec2*, Vec2*))eax2)((char*)this - 0x10c, &v2, &v)) {
                flag = 1;
                if (ebx2 != 0) {
                    ebx2 = (int*)*ebx2;
                } else {
                    _invalid_parameter_noinfo();
                    ebx2 = 0;
                }
                ebp2 = (int*)((char*)ebp2 + 8);
                edi2 = (int*)*(int*)((char*)this + 0x18);
                continue;
            } else {
                void* ecx4 = (void*)*(int*)((char*)this + 0x20);
                ecx4 = (void*)*(int*)((char*)ecx4 + 0x1c);
                void* edx4 = (void*)*(int*)ecx4;
                edx4 = (void*)*(int*)((char*)edx4 + 0xc);
                Vec2 v3;
                ((void(__thiscall*)(void*, void*, void*))edx4)(ecx4, &v3, 0);
                void* eax3 = (void*)*(int*)((char*)this - 0x10c);
                eax3 = (void*)*(int*)((char*)eax3 + 0xe8);
                ((void(__thiscall*)(void*, Vec2*))eax3)((char*)this - 0x10c, &v3);
                flag = 1;
                if (ebx2 != 0) {
                    ebx2 = (int*)*ebx2;
                } else {
                    _invalid_parameter_noinfo();
                    ebx2 = 0;
                }
                ebp2 = (int*)((char*)ebp2 + 8);
                edi2 = (int*)*(int*)((char*)this + 0x18);
                continue;
            }
        }
        break;
    }

loop2:
    if (ebp != 0) {
        ebp = (int*)*ebp;
    } else {
        _invalid_parameter_noinfo();
        ebp = 0;
    }

    if ((unsigned)ebx < (unsigned)*(int*)((char*)ebp + 0x10)) {
        _invalid_parameter_noinfo();
    }

    ebx = (int*)((char*)ebx + 4);
    goto loop2;

end:
    {
        int edx = (flag == 0) ? 1 : 0;
        sub_8648f0((char*)this - 0x10c, edx);
    }
}
