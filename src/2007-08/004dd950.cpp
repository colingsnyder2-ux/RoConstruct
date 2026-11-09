// from server: 6% by colin
// roc 2007-08 004dd950  unit: RBX::Render::Mesh::Level  size: 1876 bytes

struct MeshLevel {
    void method(int a, int b, int c);
};

extern "C" {
    void* __stdcall InterlockedIncrement(int* p);
    void* __stdcall InterlockedDecrement(int* p);
}

void* __cdecl operator_new(unsigned int size);

void __stdcall sub_4f6180();
void __stdcall sub_4dd250();
void __stdcall sub_4dd8e0();
void __stdcall sub_4f6ff0();
void __stdcall sub_457dd0();

extern unsigned char g_8bbad4;

void MeshLevel::method(int a, int b, int c)
{
    sub_4f6180();
    *(int*)this = 0x79f30c;

    void* p = operator_new(0x1c);
    if (p) {
        *(int*)p = 0x797984;
        *(int*)((char*)p + 4) = 0;
        *(int*)((char*)p + 8) = 0;
        *(int*)p = 0x79f304;
        *(int*)((char*)p + 0x10) = 0;
        *(int*)((char*)p + 0x14) = 0;
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x18) = 5;
    } else {
        p = 0;
    }

    void* q = 0;
    if (p) {
        q = p;
        InterlockedIncrement((int*)((char*)p + 4));
    }

    sub_4dd250();

    if (g_8bbad4) {
        void* r = operator_new(0x1c);
        if (r) {
            sub_4dd8e0();
        } else {
            r = 0;
        }
        void* s = 0;
        if (r) {
            s = r;
            InterlockedIncrement((int*)((char*)r + 4));
        }
        sub_4f6ff0();
        if (s) {
            if (InterlockedDecrement((int*)((char*)s + 4)) == 0) {
                sub_457dd0();
                (*(void(**)(int))s)(1);
            }
        }
    }
}
