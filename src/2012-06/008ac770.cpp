// from server: 84% by tester
// roc 2012-06 008ac770  unit: RBX::NullTool  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008ac770

extern "C" void* __cdecl sub_54B720(void*);
extern "C" void* __cdecl sub_798700(void*);

struct Inner {
    void* sub_798870();
};

struct NullTool {
    void* field_0x20;
    bool method();
};

bool NullTool::method() {
    void* a = sub_54B720(field_0x20);
    if (a) {
        void* b = sub_798700(a);
        if (b) {
            void* c = ((Inner*)b)->sub_798870();
            if (c) {
                float v = *(float*)((char*)c + 0x1e8);
                if (!(v != *(float*)0xb53ac8)) {
                    return true;
                }
            }
        }
    }
    return false;
}
