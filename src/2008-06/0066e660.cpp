// from server: 100% by colin
struct MouseCommand {
    char pad[0xa0];
    float f0;
    float f1;
};

struct GroupDragTool {
    void* vtable;
    void* vtable2;
    char pad[0x98];
    float fieldA0;
    float fieldA4;
    GroupDragTool* construct(void* a, float x, float y);
};

extern "C" void __stdcall sub_643e00(void* a);

GroupDragTool* GroupDragTool::construct(void* a, float x, float y) {
    sub_643e00(a);
    fieldA0 = x;
    vtable = (void*)0x84d0dc;
    fieldA4 = y;
    vtable2 = (void*)0x84d0d4;
    return this;
}
