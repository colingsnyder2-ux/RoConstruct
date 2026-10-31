// from server: 66% by Intel
struct VInstance {
    int field_8;
    int field_C;
    int field_20;
    int field_24;
    int field_34;
    void func(void* arg);
};

void __stdcall sub_7DEFF0(int* ecx, void* edx, void* arg1, void* arg2);
void __stdcall sub_982114(void* ptr);
void __stdcall sub_B2263C(void* ecx);

void VInstance::func(void* arg) {
    int* ebx = (int*)arg;
    int eax = ebx[1];
    int* esi = (int*)this;

    int* node1;
    if (eax) {
        node1 = (int*)((char*)(eax) - 0x20);
    } else {
        node1 = 0;
    }
    int val1 = node1[7];
    esi[13] -= val1;

    eax = ebx[1];
    int* node2;
    if (eax) {
        node2 = (int*)((char*)(eax) - 0x20);
    } else {
        node2 = 0;
    }
    int* edi = (int*)node2[7];

    if (edi != (int*)esi[2]) {
        int* edx = (int*)edi[1];
        int* ecx_val = (int*)edi[0];
        *edx = (int)ecx_val;
        ecx_val = (int*)edi[0];
        edx = (int*)edi[1];
        ecx_val[1] = (int)edx;

        sub_B2263C(edi + 2);
        sub_982114(edi);
        esi[3]--;
    }

    eax = ebx[1];
    int ecx_val2 = ebx[0];
    int* edx_ptr = (int*)((char*)esi + 0x20);
    sub_7DEFF0(&ecx_val2, &eax, edx_ptr, edx_ptr + 1);
}
