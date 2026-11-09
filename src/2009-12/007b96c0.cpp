// from server: 100% by atomic.potato
struct Stage;

struct IPipelined {
    char pad0[4];
    void* field4;
    void removeFromStage(Stage* s);
};

struct GroundStage {
    char pad0[8];
    void* field8;
    void func(Stage* s);
};

extern "C" void __stdcall sub_7b9580(Stage* s, int flag);
extern "C" void __stdcall sub_7da100(void* p, Stage* s);

void GroundStage::func(Stage* s) {
    int flag;
    if (*(char*)((char*)s + 0x100) != 0 || *(char*)((char*)s + 0x101) != 0)
        flag = 1;
    else
        flag = 0;
    sub_7b9580(s, flag);
    ((IPipelined*)field8)->removeFromStage(s);
    ((IPipelined*)s)->removeFromStage((Stage*)this);
}
