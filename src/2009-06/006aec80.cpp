// from server: 42% by tester
// roc 2009-06 006aec80  unit: RBX::NormalBreakConnector  size: 208 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006aec80

struct Point {
    char pad0[0x24];
    float f24;
    float f28;
    float f2c;
    char pad30[0x10];
    float f40;
    float f44;
    float f48;
    char pad4C[0x24];
    float f70;
    float f74;
    float f78;
    float f7C;
};

struct Connector {
    int vtable;
    int unk4;
    int unk8;
    int unkC;
};

struct JointConnector : Connector {
    char pad10[0x30];
    float f40;
    float f44;
    float f48;
    char pad4C[0x24];
    float f70;
    float f74;
    float f78;
    float f7C;
    char f80;
};

struct PointToPointBreakConnector : JointConnector {
};

struct NormalBreakConnector : PointToPointBreakConnector {
    int normalIdBody0;
    NormalBreakConnector(Point* point0, Point* point1, float k, float breakForce, int normalIdBody0);
};

extern "C" void __stdcall sub_499f80(void* dst, void* src);
extern "C" void __stdcall sub_65d430(void* p);
extern "C" void __stdcall sub_6ae5c0(void* a, void* b, void* c, void* d, void* e);

NormalBreakConnector::NormalBreakConnector(
    Point* point0,
    Point* point1,
    float k,
    float breakForce,
    int normalIdBody0)
{
    this->unk4 = -1;
    this->unkC = normalIdBody0;
    this->vtable = 0x8eaa5c;
    this->unk8 = (int)point0;
    sub_499f80(&this->f40, point1);
    this->f40 = point1->f24;
    this->f44 = point1->f28;
    this->f48 = point1->f2c;
    sub_499f80(&this->f70, point1);
    this->f70 = point1->f24;
    this->f74 = point1->f28;
    this->f7C = point1->f2c;
    this->f80 = 0;
    this->f70 = k * breakForce;
    this->f74 = breakForce;
    this->f7C = 0.0f;
    sub_65d430((char*)this->unkC + 0x9c);
    sub_65d430((char*)this->unk8 + 0x9c);
    sub_6ae5c0(
        (char*)this->unk8 + 0x9c,
        (char*)this->unkC + 0x9c,
        &this->f40,
        &this->f70,
        &this->f78);
    this->f78 = this->f78 - this->f74;
}
