// from server: 100% by Intel
struct Inner {
    void* unknown0;
    void* field1;
    void* field2;
    void* field3;
};

struct Outer {
    Inner* inner;
    void cleanup();
};

extern "C" void __cdecl func_0041bef0(void* field1, void* field2, void* inner);
extern "C" void __cdecl func_00982114(void* p);

void Outer::cleanup() {
    Inner* inner = this->inner;
    if (inner) {
        if (inner->field1) {
            func_0041bef0(inner->field1, inner->field2, inner);
            func_00982114(inner->field1);
        }
        inner->field1 = 0;
        inner->field2 = 0;
        inner->field3 = 0;
        func_00982114(inner);
    }
}
