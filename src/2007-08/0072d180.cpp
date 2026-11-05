// from server: 100% by colin
struct seg_00720000 {
    char pad0[0x14];
    int field_14;
    char pad18[0x4];
    int field_1c;
    char pad20[0x10];
    int field_30;
};

int __stdcall func_0072d180(seg_00720000* p)
{
    if (p != 0) {
        seg_00720000* q = (seg_00720000*)p->field_1c;
        if (q != 0) {
            q->field_1c = 0;
            p->field_14 = 0;
            *(int*)((char*)p + 8) = 0;
            *(int*)((char*)p + 0x18) = 0;
            p->field_30 = 1;
            *(int*)((char*)q + 0) = 0;
            *(int*)((char*)q + 4) = 0;
            *(int*)((char*)q + 0xc) = 0;
            *(int*)((char*)q + 0x20) = 0;
            *(int*)((char*)q + 0x28) = 0;
            *(int*)((char*)q + 0x2c) = 0;
            *(int*)((char*)q + 0x30) = 0;
            *(int*)((char*)q + 0x38) = 0;
            *(int*)((char*)q + 0x3c) = 0;
            int* r = (int*)((char*)q + 0x530);
            *(int*)((char*)q + 0x14) = 0x8000;
            *(int*)((char*)q + 0x6c) = (int)r;
            *(int*)((char*)q + 0x50) = (int)r;
            *(int*)((char*)q + 0x4c) = (int)r;
            return 0;
        }
    }
    return -2;
}
