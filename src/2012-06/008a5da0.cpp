// from server: 57% by atomic.potato
struct GlueTool
{
    GlueTool();
};

extern "C" void __cdecl basic_string_ctor(void*, const char*);

GlueTool::GlueTool()
{
    basic_string_ctor((void*)0x00BDF1FC, "GlueCursor");
}
