// from server: 72% by atomic.potato
struct ArrowTool
{
    int field_1c0;
    int field_1cc;
};

extern "C" int __stdcall sub_7b1f10(void*, void*);
extern "C" void __cdecl sub_61e830();

void __stdcall ArrowTool_function(ArrowTool* self, void* arg)
{
    int result = sub_7b1f10((char*)self + 0x1c0, arg);
    if (self->field_1cc != 0 && result == 0)
        sub_61e830();
}
