// from server: 24% by atomic.potato
// roc 2012-06 00831110  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 492 bytes

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);
extern "C" void __cdecl sub_428540(void*);
extern "C" void* __cdecl sub_4433A0();
extern "C" void* __cdecl sub_5670E0();
extern "C" void __cdecl sub_697860(void*);
extern "C" void* __cdecl sub_722DC0(int);
extern "C" void __cdecl sub_830FF0(void*, void*, void*);
extern "C" void __cdecl sub_831080(void*, void*, void*);
extern "C" void __cdecl sub_972E20(void*);
extern "C" char __cdecl sub_973040(void*, void*);
extern "C" void __cdecl sub_973130(void*, void*);
extern "C" void __cdecl sub_9820F6(void*, float);
extern "C" void __cdecl sub_9820FC(void*, int);
extern "C" void __cdecl sub_982102(void*, void*);
extern "C" void* __cdecl sub_982108(void*, void*, void*);
extern "C" void* __cdecl sub_98210E(void*, void*, void*);

struct PAVPrimitive {
    void construct(int);
};

void PAVPrimitive::construct(int a2)
{
    char* self = (char*)this;
    *(int*)self = a2;
    char* edi = self + 4;
    void* p = sub_5670E0();
    *(void**)(edi + 4) = p;
    *(char*)((char*)p + 0x19) = 1;
    void* q = *(void**)(edi + 4);
    *(void**)((char*)q + 4) = q;
    void* r = *(void**)(edi + 4);
    *(void**)r = r;
    void* s = *(void**)(edi + 4);
    *(void**)((char*)s + 8) = s;
    *(int*)(edi + 8) = 0;
    *(float*)(self + 0x18) = *(float*)0xbd0974;
    char* edi2 = self + 0x1c;
    *(int*)edi2 = 0;
    char* ebp = self + 0x20;
    *(int*)ebp = 0;
    *(float*)(self + 0x24) = *(float*)0xb685ac;
    *(float*)(self + 0x28) = *(float*)0xb69f3c;
    void* v = sub_722DC0(a2);
    if (v != 0) {
        void* eax = *(void**)((char*)v + 0x170);
        void* tmp1;
        void* tmp2;
        *(void**)&tmp1 = (void*)0x82fdf0;
        *(void**)&tmp2 = self;
        sub_830FF0((char*)eax + 8, &tmp2, &tmp1);
        void* ebx = eax;
        if (sub_973040(edi2, ebx)) {
            sub_972E20(edi2);
            sub_973130(edi2, ebx);
        }
        void* t = tmp1;
        if (t != 0) {
            sub_428540((char*)t + 5);
        }
        void* ecx = *(void**)&tmp2;
        void* tmp3;
        void* tmp4;
        *(void**)&tmp3 = (void*)0x830000;
        *(void**)&tmp4 = self;
        sub_831080((char*)ecx + 0xc, &tmp4, &tmp3);
        void* edi3 = ecx;
        if (sub_973040(ebp, edi3)) {
            sub_972E20(ebp);
            sub_973130(ebp, edi3);
        }
        void* u = tmp3;
        if (u != 0) {
            sub_428540((char*)u + 5);
        }
        void* ecx2 = *(void**)self;
        char* edi4 = self + 0x14;
        void* r1 = sub_98210E(ecx2, (void*)0xbd0964, edi4);
        sub_697860(r1);
        void* edx = *(void**)self;
        char* ebp2 = self + 0x10;
        void* r2 = sub_982108(edx, (void*)0xbd0964, ebp2);
        sub_697860(r2);
        void* g = sub_4433A0();
        void* eax2 = *(void**)((char*)g + 0x98);
        void* ecx3 = *(void**)edi4;
        sub_982102(ecx3, eax2);
        void* edx2 = *(void**)edi4;
        sub_9820FC(edx2, 2);
        void* g2 = sub_4433A0();
        float f = *(float*)((char*)g2 + 0x94);
        f *= *(float*)0xb5abe8;
        void* eax3 = *(void**)ebp2;
        sub_9820F6(eax3, f);
    }
}
