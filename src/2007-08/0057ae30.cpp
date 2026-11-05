// from server: 100% by colin
struct ArrowTool {
    char pad[0x318];
    void* field_318;
    void* field_31c;
    void destroy();
};

extern void* __cdecl sub_57AB60(void*);

void ArrowTool::destroy()
{
    if (field_31c) {
        (*(void (__thiscall**)(void*, int))(*(int*)field_31c + 0x2c))(field_31c, 1);
    }
    field_31c = 0;
    void* p = sub_57AB60(this);
    void* old = field_318;
    if (p != old) {
        if (old) {
            (*(void (__thiscall**)(void*, int))(*(int*)old + 0x2c))(old, 1);
        }
    }
    field_318 = p;
}
