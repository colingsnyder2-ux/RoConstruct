// from server: 44% by colin
struct Instance;

extern "C" void __stdcall invalid_parameter_noinfo();
extern "C" void __fastcall func_00541f60(Instance* self);
extern "C" void __fastcall func_00541630(Instance* self, int a);
extern "C" void __fastcall func_00464ec0(void* self, void* a);

struct Selection {
    void clearSelection();
    void removeFilteredSelection(void* p);
};

struct FilteredSelection {
    Instance* rootSelection;
    char flag;

    void func(Instance* inst);
};

void FilteredSelection::func(Instance* inst)
{
    void* v = *(void**)((char*)inst + 0xc0);
    if (v == 0)
        return;
    void* begin = *(void**)((char*)v + 4);
    if (begin == 0)
        return;
    void* end = *(void**)((char*)v + 8);
    if (((char*)end - (char*)begin) >> 3 == 0)
        return;

    unsigned int i = 0;
    while (true) {
        void* v2 = *(void**)((char*)inst + 0xc0);
        if (v2 == 0)
            break;
        void* b2 = *(void**)((char*)v2 + 4);
        if (b2 == 0)
            break;
        void* e2 = *(void**)((char*)v2 + 8);
        if (i >= (unsigned int)(((char*)e2 - (char*)b2) >> 3))
            break;

        void* v3 = *(void**)((char*)inst + 0xc0);
        void* b3 = *(void**)((char*)v3 + 4);
        if (b3 == 0 || i >= (unsigned int)(((char*)*(void**)((char*)v3 + 8) - (char*)b3) >> 3))
            invalid_parameter_noinfo();

        void* item = *(void**)((char*)b3 + i * 8);
        void* tmp = item;
        ((Selection*)rootSelection)->removeFilteredSelection(&tmp);
        i++;
    }

    func_00541f60((Instance*)v);
    func_00541630(*(Instance**)inst, 0);
    flag = 1;
}
