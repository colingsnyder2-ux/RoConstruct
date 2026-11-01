// from server: 48% by atomic.potato
struct VVehicleSeat {
    char pad0[0x90];
    void* field90;
    void* field94;
    char pad98[0x2c];
    void* fieldc4;
    void sub_715f30(int);
};

void VVehicleSeat::sub_715f30(int) {}

VVehicleSeat* __stdcall VVehicleSeat_ctor(VVehicleSeat* self, int flag) {
    if (flag != 0) {
        *(void**)((char*)self + 0x94) = (void*)0xab01c0;
        *(void**)((char*)self + 0xc4) = (void*)0xaa0d68;
    }
    self->sub_715f30(0);
    void* p94 = *(void**)((char*)self + 0x94);
    *(void**)self = (void*)0xaafe2c;
    *(void**)((char*)self + 4) = (void*)0xaafe24;
    *(void**)((char*)self + 0x18) = (void*)0xaafe18;
    *(void**)((char*)self + 0x1c) = (void*)0xaafe0c;
    *(void**)((char*)self + 0x90) = (void*)0xaafe04;
    *(void**)((char*)self + 0xa0) = (void*)0xaafdf0;
    *(void**)((char*)self + 0xac) = (void*)0xaafdc8;
    *(void**)((char*)self + 0xc0) = (void*)0xaafda0;
    void* ecx = *(void**)((char*)p94 + 4);
    *(void**)((char*)ecx + (int)self + 0x94) = (void*)0xaafd98;
    void* edx = *(void**)((char*)self + 0x94);
    void* eax = *(void**)((char*)edx + 4);
    void* ecx2 = (void*)((char*)eax - 0x200);
    *(void**)((char*)eax + (int)self + 0x90) = ecx2;
    return self;
}
