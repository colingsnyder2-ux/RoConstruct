// from server: 100% by colin
struct GuiItem {
    void (__thiscall **vtable)(GuiItem *, int);
};

struct Entry {
    void *object;
    void *control;
};

struct Children {
    char pad[12];
    Entry *begin;
    Entry *end;
};

extern "C" void (__cdecl *invalid_parameter_noinfo)();
extern "C" void *__cdecl __RTDynamicCast(void *, long, void *, void *, int);

extern char instance_type;
extern char gui_item_type;

struct S_func_00574280 {
    char pad0[0x108];
    Children *children;
    char pad1[0x38];
    int state;

    unsigned int count();
    void f(int argument);
};

void S_func_00574280::f(int argument)
{
    if (state >= 2) {
        for (unsigned int i = 0; i < count(); ++i) {
            Children *list = children;
            if (i >= static_cast<unsigned int>(list->end - list->begin))
                invalid_parameter_noinfo();

            void *object = list->begin[i].object;
            GuiItem *item = static_cast<GuiItem *>(
                __RTDynamicCast(object, 0,
                                &instance_type, &gui_item_type, 0));

            if (item)
                item->vtable[24](item, argument);
        }
    }
}
