// from server: 46% by colin
extern "C" void __stdcall G1_func_0077e6d8();
extern "C" void* __cdecl G2_func_0062fef6(unsigned int size);

struct S {
    char pad0[4];
    int* begin;
    int* end;
    int* cap;
    int f();
    int G3_func_0055e610();
    void G4_func_005cdf80(void* a, void* b, void* c);
};

int S::f()
{
    int* edi;
    int* edx;
    int* eax;
    int* ecx;
    int* tmp;
    int* result;

    for (;;) {
        int* ebx = *(int**)0x8c5dc8;
        if ((int)ebx & 1) {
            edi = *(int**)0x8c5dc4;
        } else {
            eax = *(int**)0x8c5dc0;
            ebx = (int*)((int)ebx | 1);
            edi = eax;
            eax = (int*)((int)eax + 1);
            *(int**)0x8c5dc8 = ebx;
            *(int**)0x8c5dc4 = edi;
            *(int**)0x8c5dc0 = eax;
        }

        int r = this->G3_func_0055e610();
        if ((unsigned int)r > (unsigned int)edi) {
            if (!((int)ebx & 1)) {
                eax = *(int**)0x8c5dc0;
                ebx = (int*)((int)ebx | 1);
                edi = eax;
                eax = (int*)((int)eax + 1);
                *(int**)0x8c5dc8 = ebx;
                *(int**)0x8c5dc4 = edi;
                *(int**)0x8c5dc0 = eax;
            }
            ecx = this->begin;
            if (ecx == 0) {
                G1_func_0077e6d8();
            } else {
                eax = this->end;
                eax = (int*)((int)eax - (int)ecx);
                eax = (int*)((int)eax >> 2);
                if ((unsigned int)edi >= (unsigned int)eax) {
                    G1_func_0077e6d8();
                }
            }
            edx = this->begin;
            result = (int*)((int)edx + (int)edi * 4);
            if (*result == 0) {
                eax = (int*)G2_func_0062fef6(8);
                if (eax == 0) {
                    *result = 0;
                } else {
                    *(int*)eax = 0x7b5ffc;
                    *result = (int)eax;
                    return (int)((char*)eax + 4);
                }
            }
            return *result + 4;
        }

        edx = this->begin;
        tmp = 0;
        if (edx == 0) {
            ecx = 0;
        } else {
            ecx = this->end;
            ecx = (int*)((int)ecx - (int)edx);
            ecx = (int*)((int)ecx >> 2);
        }
        if (edx != 0) {
            eax = this->cap;
            eax = (int*)((int)eax - (int)edx);
            eax = (int*)((int)eax >> 2);
            if ((unsigned int)ecx < (unsigned int)eax) {
                eax = this->end;
                *(int*)eax = 0;
                eax = (int*)((char*)eax + 4);
                this->end = eax;
                continue;
            }
        }
        edi = this->end;
        if ((unsigned int)edx > (unsigned int)edi) {
            G1_func_0077e6d8();
        }
        this->G4_func_005cdf80(&tmp, edi, this);
    }
}
