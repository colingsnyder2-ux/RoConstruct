// from server: 100% by tester
struct SlingshotTool {
    void sub_5FC540(int);
    SlingshotTool* method(int);
};

SlingshotTool* SlingshotTool::method(int arg) {
    (*(void (__thiscall **)(SlingshotTool*))(*(int*)this + 0x20))(this);
    if (*(int*)((char*)this + 0x30) == 0) {
        this->sub_5FC540(arg);
    }
    return this;
}
