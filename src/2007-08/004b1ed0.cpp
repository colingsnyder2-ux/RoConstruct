// from server: 42% by colin
struct TypedStatsItem {
    char pad[0x110];
    void* field110;
    void* field114;
    void* field118;
    void destroy();
};

void TypedStatsItem::destroy()
{
    if (field110) {
        void* (*fn)(void*, int) = (void* (*)(void*, int))field110;
        field114 = fn(field114, 1);
    }
    field110 = 0;
    field118 = 0;
    ((void (*)(void*))0x4588e0)(this);
}
