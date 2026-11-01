// from server: 100% by tester
struct SlingshotTool {
    void sub_5FC540(int);
    SlingshotTool* method(int);
};

SlingshotTool* SlingshotTool::method(int arg) {
    (*(void (__thiscall **)(SlingshotTool*))(*(int*)this + 0x24))(this);
    if (*(int*)((char*)this + 0x2c) == 0) {
        this->sub_5FC540(arg);
    }
    return this;
}
