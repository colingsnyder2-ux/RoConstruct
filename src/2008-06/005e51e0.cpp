// from server: 100% by tester
struct SimJob {
    SimJob* construct(int);
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
};

extern "C" void __fastcall SimJob_base_ctor(SimJob* self);

SimJob* SimJob::construct(int value) {
    SimJob_base_ctor(this);
    this->field24 = value;
    *(int*)this = 0x83f73c;
    return this;
}
