// from server: 41% by colin
struct Sub1 {
    char pad[0x64];
};

struct Sub2 {
    char pad[0x60];
    float* data;
};

struct Sub3 {
    char pad[0x84];
};

struct PartInstance {
    char pad[0x1a4];
    int field1a4;
    char pad2[0x1d8 - 0x1a8];
    Sub2* sub2;
    void method(int a, int* b);
};

extern float g_float_797e9c;
extern int g_int_8c9bc8;
extern int g_int_8c9bcc;

extern "C" void __stdcall func_530100(int a);
extern "C" void __stdcall func_51d9d0(int* a, int* b);
extern "C" void __stdcall func_737a20(int a, int b, int c, int d, int e, int f);
extern "C" void __stdcall func_5b6cb0(int a, int b);

void PartInstance::method(int a, int* b) {
    Sub1* s1 = (Sub1*)((char*)sub2 - 0x60 + 0x64);
    func_530100((int)s1);
    
    int local48;
    func_51d9d0(&local48, (int*)((char*)s1 + 0x84));
    
    float* fptr = sub2->data;
    float f0 = fptr[1];
    float f1 = g_float_797e9c;
    float f2 = fptr[2];
    float f3 = fptr[3];
    
    float arr1[6];
    arr1[0] = -f0 * f1;
    arr1[1] = -f2 * f1;
    arr1[2] = -f3 * f1;
    arr1[3] = f0;
    arr1[4] = f2;
    arr1[5] = f3;
    
    float arr2[6];
    arr2[0] = 0.0f;
    arr2[1] = 0.0f;
    arr2[2] = 0.0f;
    arr2[3] = f0;
    arr2[4] = f2;
    arr2[5] = f3;
    
    func_737a20((int)arr1, (int)arr2, (int)&g_int_8c9bc8, (int)&g_int_8c9bcc, (int)&local48, 0);
    
    for (int i = 0; i < 3; i++) {
        if (arr1[i] == arr2[i]) {
            *b = i;
            func_5b6cb0(field1a4, i);
            return;
        }
        if (arr1[i + 3] == arr2[i + 3]) {
            *b = i + 3;
            func_5b6cb0(field1a4, i + 3);
            return;
        }
    }
}
