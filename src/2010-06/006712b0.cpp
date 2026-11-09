// from server: 82% by colin
struct EventDesc {
    char pad[0x38];
    int field38;
    int field3c;
    void sub_4b12a0(int);
    void func(int, int);
};

void EventDesc::func(int a, int b) {
    EventDesc* p;
    if (a != 0) {
        p = (EventDesc*)((char*)a - 0x1c);
    } else {
        p = 0;
    }
    int* edx = *(int**)((char*)p + 0x148);
    int esi = field3c;
    int val = edx[esi];
    val += field38;
    sub_4b12a0(val + (int)p + 0x148);
}
