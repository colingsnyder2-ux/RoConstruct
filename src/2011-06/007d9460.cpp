// from server: 84% by atomic.potato
struct EqDisp;

extern "C" int __cdecl sub_7d93a0(int a, int b);

struct EqDisp {
    char pad0[8];
    unsigned char field8;
    char pad9[7];
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
};

struct Out {
    double d0;
    int f8;
    char padc[4];
    int f10;
    int f14;
    int f18;
};

int __cdecl sub_7d9460(EqDisp* a, Out* b) {
    int eax = sub_7d93a0((int)a, (int)b);
    int ecx = a->field20;
    eax++;
    if (eax < ecx) {
        int ebx = a->field10;
        int edx = eax << 4;
        edx = edx + ebx + 8;
        do {
            if (*(int*)edx != 0) {
                int ecx2 = eax + 1;
                *(int*)((char*)b + 8) = 3;
                *(double*)b = (double)ecx2;
                eax <<= 4;
                eax += a->field10;
                *(int*)((char*)b + 0x10) = *(int*)eax;
                *(int*)((char*)b + 0x14) = *(int*)(eax + 4);
                *(int*)((char*)b + 0x18) = *(int*)(eax + 8);
                return 1;
            }
            eax++;
            edx += 0x10;
        } while (eax < ecx);
    }
    eax -= ecx;
    unsigned char cl = a->field8;
    int edx2 = 1 << cl;
    if (eax < edx2) {
        int ecx3 = a->field14;
        int ebx2 = eax << 5;
        ebx2 = ebx2 + ecx3 + 8;
        do {
            if (*(int*)ebx2 != 0) {
                eax <<= 5;
                int edx3 = *(int*)(ecx3 + eax + 0x10);
                *(int*)b = edx3;
                edx3 = *(int*)(ecx3 + eax + 0x14);
                *(int*)((char*)b + 4) = edx3;
                int ecx4 = *(int*)(ecx3 + eax + 0x18);
                *(int*)((char*)b + 8) = ecx4;
                ecx4 = a->field14;
                edx3 = *(int*)(ecx4 + eax);
                ecx4 += eax;
                *(int*)((char*)b + 0x10) = edx3;
                eax = *(int*)(ecx4 + 4);
                *(int*)((char*)b + 0x14) = eax;
                ecx4 = *(int*)(ecx4 + 8);
                *(int*)((char*)b + 0x18) = ecx4;
                return 1;
            }
            eax++;
            ebx2 += 0x20;
        } while (eax < edx2);
    }
    return 0;
}
