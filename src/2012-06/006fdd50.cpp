// from server: 70% by Intel




extern "C" void __stdcall unknown_function(void*, void*);

struct S {
    void f(int, int, void*, void*, unsigned char);
};

void S::f(int a1, int a2, void* a3, void* a4, unsigned char a5) {
    int* esi = (int*)this;
    esi[0] = a1;
    esi[1] = a2;
    esi[2] = (int)a3;
    int* edi = (int*)a4;
    esi[3] = edi[0];
    esi[4] = edi[1];
    esi[5] = 0;
    if (edi[2]) {
        void* ptr[2];
        ptr[0] = (void*)( (char*)esi + 0x18 );
        ptr[1] = (void*)((int*)edi[0])[2];
        void* ecx_ptr = (void*)( (char*)edi + 0xc );
        unknown_function(ptr[0], ptr[1]);
    }
    esi[5] = edi[2];
    esi[21] = a5;
    esi[22] = 0;
}
