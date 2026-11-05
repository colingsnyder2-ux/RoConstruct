// from server: 35% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Box {
    void dtor();
};

struct Chunk {
    void* vptr;
    char pad[0x4c - 4];
    Box box1;
    char pad2[0x60 - 0x4c - sizeof(Box)];
    Box box2;
    char pad3[0x74 - 0x60 - sizeof(Box)];
    Box box3;
    char pad4[0x88 - 0x74 - sizeof(Box)];
    Box box4;
    char pad5[0x9c - 0x88 - sizeof(Box)];
    Box box5;
    char pad6[0xb4 - 0x9c - sizeof(Box)];
    void* ptr_b4;
    void* ptr_b8;
    void* ptr_c0;

    void sub_4d2e50();
    ~Chunk();
};

extern "C" int __stdcall InterlockedDecrement(int*);
extern "C" int (__stdcall *g_fn)(void*);

void Box::dtor() {}

void Chunk::sub_4d2e50() {}

Chunk::~Chunk() {
    this->vptr = (void*)0x79f180;
    if (this->ptr_c0) {
        if (InterlockedDecrement((int*)((char*)this->ptr_c0 + 4)) == 0) {
            (*(void(__thiscall**)(void*))this->ptr_c0)(this->ptr_c0);
        }
        this->ptr_c0 = 0;
    }
    if (this->ptr_b8) {
        if (InterlockedDecrement((int*)((char*)this->ptr_b8 + 4)) == 0) {
            (*(void(__thiscall**)(void*))this->ptr_b8)(this->ptr_b8);
        }
        this->ptr_b8 = 0;
    }
    if (this->ptr_b4) {
        void* p = this->ptr_b4;
        if (_InterlockedExchangeAdd((volatile long*)((char*)p + 4), -1) == 1) {
            (*(void(__thiscall**)(void*))p)(p);
        }
        if (_InterlockedExchangeAdd((volatile long*)((char*)p + 8), -1) == 1) {
            (*(void(__thiscall**)(void*))p)(p);
        }
    }
    this->box5.dtor();
    this->box4.dtor();
    this->box3.dtor();
    this->box2.dtor();
    this->box1.dtor();
    this->sub_4d2e50();
}
