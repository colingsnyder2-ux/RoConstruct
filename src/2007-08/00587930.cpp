// from server: 62% by colin
struct Descriptor {
    char pad[0x11d];
    char flags;
    char pad2[6];
    void* ptr124;
};

struct Vec3 {
    float x, y, z;
};

extern "C" void* __stdcall sub_573f80(void* p);
extern "C" void* __stdcall sub_573fd0(void* p);
extern "C" void __stdcall sub_62fc02(void* a, void* b, void* c);

struct EnumDescriptor {
    void func(void* arg);
};

void EnumDescriptor::func(void* arg) {
    if ((*(unsigned char*)((char*)this + 0x11d) & 1) != 0) {
        void* p = *(void**)((char*)this + 0x124);
        if (p != 0) {
            void* r1 = sub_573f80(p);
            Vec3 v1;
            v1.x = *(float*)((char*)r1 + 0x24);
            v1.y = *(float*)((char*)r1 + 0x28);
            v1.z = *(float*)((char*)r1 + 0x2c);
            void* p2 = *(void**)((char*)this + 0x124);
            void* r2 = sub_573fd0(p2);
            Vec3 v2;
            v2.x = *(float*)((char*)r2 + 0);
            v2.y = *(float*)((char*)r2 + 4);
            v2.z = *(float*)((char*)r2 + 8);
            sub_62fc02(arg, &v1, &v2);
        }
    }
}
