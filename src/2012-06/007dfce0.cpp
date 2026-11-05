// from server: 32% by atomic.potato
extern "C" void* __cdecl func_0098211a(unsigned int);
extern "C" void __cdecl func_00982114(void*);
extern "C" void __cdecl func_007de7b0(void*, void*);
extern "C" void __cdecl func_007de000(void*);
extern "C" int __stdcall func_b229ec(void*, void*);

struct type_info;

struct S {
};

void __cdecl func(int a, void* b)
{
    if (a == 0) {
        void** src = *(void***)b;
        void* p = func_0098211a(0x70);
        *(void**)((char*)b + 4) = p;
        if (p) {
            *(int*)p = *(int*)*src;
            func_007de7b0((char*)p + 8, (char*)*src + 8);
            *(void**)((char*)b + 4) = p;
        } else {
            *(void**)((char*)b + 4) = 0;
        }
    } else if (a == 1) {
        void** src = *(void***)b;
        *(void**)((char*)b + 4) = *src;
        *src = 0;
    } else if (a == 2) {
        void* p = *(void**)((char*)b + 4);
        if (p) {
            func_007de000((char*)p + 8);
            func_00982114(p);
        }
        *(void**)((char*)b + 4) = 0;
    } else if (a == 3) {
        void* p = *(void**)((char*)b + 4);
        if (func_b229ec((void*)0xdd16d0, p)) {
            void** src = *(void***)b;
            *(void**)((char*)b + 4) = *src;
        } else {
            *(void**)((char*)b + 4) = 0;
        }
    } else {
        *(void**)((char*)b + 4) = (void*)0xdd16d0;
        ((char*)b)[8] = 0;
        ((char*)b)[9] = 0;
    }
}
