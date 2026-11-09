// from server: 47% by colin
struct DxUserInput {
    char pad[0x58];
    float field58;
    float field5c;
    float field60;
    float field64;
    int field68;
    int field6c;
    int field70;
    void method(int a, int b);
};

extern "C" int __cdecl func_463520();
extern "C" int __cdecl func_464410();
extern "C" int __cdecl func_630d60();
extern "C" void __cdecl func_465390(void*, int, int);
extern "C" void __cdecl func_466220(void*, int, int, void*);
extern "C" void __cdecl func_465360(void*, int, int);
extern "C" int __cdecl func_463480();
extern "C" void* __cdecl func_4634f0(void*, void*);
extern "C" void* __cdecl func_4633c0(void*, void*);
extern "C" void __cdecl func_466250(void*, int, int, void*);
extern "C" void __cdecl func_4662e0(void*, int, int, void*);

void DxUserInput::method(int a, int b) {
    int state = this->field6c;
    if (state != 0) {
        if (func_463520()) {
            float f1 = this->field60 - this->field58;
            short s1 = (short)func_630d60();
            float f2 = this->field64 - this->field5c;
            short s2 = (short)func_630d60();
            int tmp1 = (int)s1;
            int tmp2 = (int)s2;
            float v1 = (float)tmp1;
            float v2 = (float)tmp2;
            func_466220((char*)this + 0x70, a, b, &v1);
            return;
        }
        if (!func_464410()) {
            func_465360((char*)this + 0x70, a, b);
            return;
        }
        if (func_463480()) {
            int tmp;
            func_4634f0(this, &tmp);
            void* p = func_4633c0(this, &tmp);
            func_466250((char*)this + 0x70, a, b, p);
            return;
        }
        int tmp;
        func_4634f0(this, &tmp);
        void* p = func_4633c0(this, &tmp);
        func_4662e0((char*)this + 0x70, a, b, p);
        return;
    }
    if (state == 1) {
        func_465390((char*)this + 0x70, a, b);
    }
}
