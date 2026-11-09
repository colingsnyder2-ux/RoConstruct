// from server: 72% by atomic.potato
extern "C" void __stdcall sub_string_ctor(void*, const char*);

struct RightMotorTool
{
    RightMotorTool* f(const char*);
};

RightMotorTool* RightMotorTool::f(const char* value)
{
    sub_string_ctor((void*)0xBDF654, "MotorCursor");
    return this;
}
