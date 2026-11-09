// from server: 52% by atomic.potato
struct RbxSpatialHashedSceneNode {
    char pad0[0x1c4];
    int field1c4;
    char field1c8[4];
    int* field1cc;
    int* field1d0;
    char pad1d4[0x1f8 - 0x1d4];
    int field1f8;
    void method50edc0(int* arg);
};

extern "C" int __stdcall sub_50d400(int* arg);
extern "C" void __stdcall sub_50eaa0();
extern "C" void __stdcall sub_50eb70();
extern "C" void __stdcall sub_6226d0(void* arg);

void RbxSpatialHashedSceneNode::method50edc0(int* arg) {
    if (field1f8 > -1) {
        if (sub_50d400(arg)) {
            sub_50eb70();
            return;
        }
        sub_50eaa0();
        sub_6226d0(&arg);
        return;
    }
    int* p = field1cc;
    int* end = field1d0;
    while (p != end && *p != (int)arg) {
        p++;
    }
    if (sub_50d400(arg) || p != end) {
        int* vt = (int*)*arg;
        int (*fn)(int*) = (int (*)(int*))vt[6];
        int r = fn(arg);
        if (r) {
            int* vt2 = (int*)*arg;
            int (*fn2)(int*) = (int (*)(int*))vt2[6];
            int* obj = (int*)fn2(arg);
            int* vt3 = (int*)*obj;
            void (*fn3)(int*, int*) = (void (*)(int*, int*))vt3[0x2a];
            fn3(obj, arg);
        }
        int* vt4 = (int*)*(int*)this;
        void (*fn4)(void*, int*) = (void (*)(void*, int*))vt4[0x23];
        fn4(this, arg);
    }
}
