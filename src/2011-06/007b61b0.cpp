// from server: 60% by atomic.potato
struct Vec3 { float x, y, z; };

extern "C" void __stdcall sub_6a1eb0(Vec3* out, int arg);
extern "C" void __stdcall sub_6db2b0(void* self, Vec3* in, float f);

struct MovingAssemblyStage {
    char pad[0x1c];
    void method(int arg);
};

void MovingAssemblyStage::method(int arg) {
    Vec3 v;
    sub_6a1eb0(&v, arg);
    sub_6db2b0((char*)this + 0x1c, &v, *(float*)0xab6310);
}
