// from server: 100% by colin
struct VNode {
    int* field0;
    int* field4;
    VNode* construct(int* src);
};

extern "C" int* __cdecl sub_56db50();
extern "C" int* __cdecl sub_62fef6(unsigned int size);

VNode* VNode::construct(int* src) {
    int* p;
    field0 = sub_56db50();
    p = sub_62fef6(0x10);
    if (p) {
        *(float*)(p + 1) = *(float*)src;
        p[0] = 0x7a576c;
        *(float*)(p + 2) = *(float*)(src + 1);
        *(float*)(p + 3) = *(float*)(src + 2);
    } else {
        p = 0;
    }
    {
        int* old = field4;
        field4 = p;
        if (old) {
            (*(void(__thiscall**)(int*, int))(*old))(old, 1);
        }
    }
    return this;
}
