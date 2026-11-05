// from server: 85% by colin
struct VCLuaFunction {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    void clear();
};

extern "C" void __cdecl free_62fc62(void* p);

void VCLuaFunction::clear()
{
    while (field10 != 0) {
        int idx = field10;
        if (idx != 0) {
            unsigned int eax = (unsigned int)(idx + fieldC - 1);
            unsigned int ecx = (unsigned int)field8;
            if (ecx > eax) {
                eax -= ecx;
            }
            int* edi = (int*)((char*)field4 + eax * 4);
            int* p = (int*)*edi;
            if (*p != 0) {
                int (*fn)(int, int) = (int (*)(int, int))p[0];
                int arg = p[1];
                int r = fn(arg, 1);
                p[1] = r;
            }
            *p = 0;
            p[2] = 0;
            field10--;
            if (field10 == 0) {
                fieldC = 0;
            }
        }
    }

    unsigned int i = (unsigned int)field8;
    while (i > 0) {
        i--;
        int* slot = (int*)((char*)field4 + i * 4);
        if (*slot != 0) {
            free_62fc62((void*)*slot);
        }
    }

    if (field4 != 0) {
        free_62fc62((void*)field4);
    }

    field4 = 0;
    field8 = 0;
}
