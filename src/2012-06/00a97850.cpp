// from server: 15% by Intel
typedef int DWORD;
typedef float FLOAT;

struct AdornBillboarder {
    void Method1();
};

extern "C" void __stdcall func1(AdornBillboarder* ptr);
extern "C" void __stdcall func2(AdornBillboarder* ptr);

void AdornBillboarder::Method1() {
    struct {
        AdornBillboarder* pThis;
        DWORD val0;
        DWORD offset1;
        FLOAT vec1[3];
        FLOAT vec2[3];
        DWORD offset2;
        DWORD offset3;
        FLOAT vec3[3];
        DWORD offset4;
    } stack;

    stack.pThis = this;
    func1(stack.pThis);
    stack.val0 = 0;
    stack.offset1 = (DWORD)stack.pThis + 0x30;
    stack.vec1[0] = *(FLOAT*)0xb53ac8;
    stack.vec1[1] = *(FLOAT*)0xb53ac8;
    stack.vec1[2] = *(FLOAT*)0xb53ac8;
    stack.offset2 = stack.offset1 + 8;
    stack.vec2[0] = *(FLOAT*)0xb53ac8;
    stack.vec2[1] = *(FLOAT*)0xb53ac8;
    stack.vec2[2] = *(FLOAT*)0xb53ac8;
    func2(stack.pThis);
    stack.offset3 = (DWORD)stack.pThis + 0x5c;
    stack.vec3[0] = *(FLOAT*)stack.offset3;
    stack.vec3[1] = *(FLOAT*)(stack.offset3 + 4);
    stack.vec3[2] = *(FLOAT*)(stack.offset3 + 8);
    stack.offset4 = (DWORD)stack.pThis + 0x68;
    *(FLOAT*)stack.offset4 = stack.vec3[0];
    *(FLOAT*)(stack.offset4 + 4) = stack.vec3[1];
    *(FLOAT*)(stack.offset4 + 8) = stack.vec3[2];
    DWORD f1 = (DWORD)stack.pThis + 0x74;
    *(FLOAT*)f1 = stack.vec2[0];
    *(FLOAT*)(f1 + 4) = stack.vec2[1];
    *(FLOAT*)(f1 + 8) = stack.vec2[2];
    DWORD f2 = (DWORD)stack.pThis + 0xc;
    *(FLOAT*)f2 = *(FLOAT*)stack.offset1;
    *(FLOAT*)(f2 + 4) = *(FLOAT*)(stack.offset1 + 4);
    *(FLOAT*)(f2 + 8) = *(FLOAT*)(stack.offset1 + 8);
}
