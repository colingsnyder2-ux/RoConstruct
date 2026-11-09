// from server: 36% by atomic.potato
extern "C" void* __cdecl malloc(unsigned int);
extern "C" void __cdecl free(void*);
extern "C" int __cdecl __CxxFrameHandler3();

struct type_info;

struct S {
    void* field0;
    char pad[0x34];
};

struct T {
    void* field0;
    char pad[0x34];
};

void sub_795f50(void*);
void sub_7961e0(void*, void*);

void S_ctor(void* p, void* q);

void func(int a, void** b, void** c);

void func(int a, void** b, void** c)
{
    if (a == 0) {
        void* edi = *b;
        S* esi = (S*)malloc(0x38);
        if (esi) {
            *(void**)esi = *(void**)edi;
            sub_7961e0((char*)esi + 8, (char*)edi + 8);
            *c = esi;
        } else {
            *c = 0;
        }
        return;
    }
    if (a == 1) {
        void* eax = *b;
        *c = *(void**)eax;
        *(void**)eax = 0;
        return;
    }
    if (a == 2) {
        S* esi = (S*)*c;
        if (esi) {
            sub_795f50((char*)esi + 8);
            free(esi);
        }
        *c = 0;
        return;
    }
    if (a == 3) {
        void* esi = *c;
        if (*(bool*)0xc917d8) {
            *c = *b;
        } else {
            *c = 0;
        }
        return;
    }
    *c = (void*)0xc917d8;
    *((char*)c + 4) = 0;
    *((char*)c + 5) = 0;
}
