// from server: 44% by colin
struct DataModel;
struct IDataState;

struct Selection {
    void* begin;
    void* end;
};

struct Instance {
    char pad[0x2d4];
};

struct EditSelectionVerb {
    char pad0[0xc];
    DataModel* dataModel;
    char pad1[0x10];
    void* selection;
    float moveUpHeight;
};

struct MoveUpSelectionVerb : EditSelectionVerb {
    void doIt(IDataState* dataState);
};

extern "C" void __stdcall sub_55E290(void*);
extern "C" void __stdcall sub_5618E0(void*);
extern "C" void __stdcall sub_55A920(void*);
extern "C" void __stdcall sub_58C810(void*, int);
extern "C" void __stdcall sub_558B60(void*, int);
extern "C" void __stdcall sub_4108B0(void*, int);
extern "C" void __stdcall sub_5E0D50(void*, void*, int, int);
extern "C" void __stdcall sub_5E0660(void*);
extern "C" void __stdcall sub_5E09E0(void*, void*, void*);
extern "C" void __stdcall sub_5E0FA0(void*);
extern "C" void __stdcall sub_5E0EF0(void*);

void MoveUpSelectionVerb::doIt(IDataState* dataState)
{
    void* sel = this->selection;
    sub_55E290(sel);

    void* inst = 0;
    if (this->selection) {
        sub_5618E0(this->selection);
        inst = this->selection;
    }

    Selection* s = (Selection*)((char*)inst + 0xf4);
    if (s->begin && s->end) {
        int count = ((char*)s->end - (char*)s->begin) >> 2;
        if (count != 0) {
            char buf1[0x18];
            char buf2[0x18];
            char buf3[0x18];

            sub_5E0D50(buf1, s, 0, (int)this->dataModel);
            sub_5E0660(buf2);

            float h = this->moveUpHeight;
            float zero = 0.0f;
            float v1 = zero;
            float v2 = zero;
            float v3 = h;

            sub_5E09E0(buf3, &v1, &v2);
            sub_5E0FA0(buf2);

            void* dm = this->dataModel;
            void* obj = 0;
            if (dm) {
                sub_55A920(dm);
                obj = dm;
            }
            sub_58C810(obj, 4);

            Instance* inst2 = (Instance*)this->dataModel;
            char flag = 0;
            sub_558B60((char*)inst2 + 0x2d4, (int)flag);

            void* p = *(void**)((char*)&buf1 + 0x34);
            sub_4108B0(p, -1);
            void** vt = *(void***)p;
            *(int*)((char*)p + 4) = -1;
            ((void (__stdcall*)(void*, int))vt[1])(p, 1);

            sub_5E0EF0(buf2);
        }
    }
}
