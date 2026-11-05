// from server: 9% by colin
struct RotateAxisCommand {
    void doIt(void* dataState);
};

struct DataModel;
struct PVInstance;

struct Matrix3 {
    float m[9];
};

struct PVInstancePtr {
    PVInstance* p;
};

struct PVInstanceList {
    PVInstancePtr* begin;
    PVInstancePtr* end;
    PVInstancePtr* cap;
};

struct DataState {
    void* vtable;
};

struct Selection {
    void* vtable;
};

struct Workspace {
    char pad[0x2d4];
};

struct DataModelImpl {
    char pad0[0x0c];
    Workspace* workspace;
    char pad1[0x10];
    void* selection;
};

struct EditSelectionVerb {
    char pad0[0x20];
    void* selection;
};

struct CommandBase {
    void* vtable;
    int refCount;
};

struct String {
    char pad[0x1c];
};

extern "C" {
    void* __stdcall operator_new(unsigned int size);
    void __stdcall operator_delete(void* p);
    void __stdcall _invalid_parameter_noinfo();
}

void RotateAxisCommand::doIt(void* dataState)
{
    EditSelectionVerb* self = (EditSelectionVerb*)this;
    DataModelImpl* dm = (DataModelImpl*)self->selection;

    void* sel = self->selection;
    if (sel) {
        sel = (void*)((char*)sel + 0);
    }

    void* cmd = operator_new(0x2c);
    if (cmd) {
        *(void**)((char*)cmd + 4) = (void*)0x786db0;
        *(void**)((char*)cmd + 0x28) = (void*)0x786d0c;
        void* vtbl = *(void**)((char*)cmd + 4);
        *(void**)cmd = (void*)0x786d9c;
        void* vtbl2 = *(void**)((char*)vtbl + 4);
        *(void**)((char*)cmd + (int)vtbl2 + 4) = (void*)0x786d94;
        *(int*)((char*)cmd + 8) = 0;
        *(int*)((char*)cmd + 0xc) = 0;
        *(int*)((char*)cmd + 0x10) = 0;
        *(int*)((char*)cmd + 0x14) = *(int*)0x8c225c;
        *(int*)((char*)cmd + 0x18) = 0;
        *(int*)((char*)cmd + 0x20) = 0;
        *(int*)((char*)cmd + 0x24) = 0;
        void* vtbl3 = *(void**)((char*)cmd + 4);
        *(void**)cmd = (void*)0x786dac;
        void* vtbl4 = *(void**)((char*)vtbl3 + 4);
        *(void**)((char*)cmd + (int)vtbl4 + 4) = (void*)0x786da4;
    }

    PVInstanceList* list = (PVInstanceList*)((char*)sel + 0xf4);
    PVInstancePtr* it = list->begin;
    PVInstancePtr* end = list->end;
    while (it != end) {
        it++;
    }

    void* result = 0;
    void* vtable = *(void**)self;
    void* fn = *(void**)((char*)vtable + 0x14);
    typedef void* (__thiscall *GetAxisFn)(void*, void*);
    GetAxisFn getAxis = (GetAxisFn)fn;
    getAxis(self, &result);

    void* sel2 = self->selection;
    if (sel2) {
        sel2 = (void*)((char*)sel2 + 0);
    }

    void* cmd2 = operator_new(0x2c);
    if (cmd2) {
        *(void**)((char*)cmd2 + 4) = (void*)0x786db0;
        *(void**)((char*)cmd2 + 0x28) = (void*)0x786d0c;
        void* vtbl = *(void**)((char*)cmd2 + 4);
        *(void**)cmd2 = (void*)0x786d9c;
        void* vtbl2 = *(void**)((char*)vtbl + 4);
        *(void**)((char*)cmd2 + (int)vtbl2 + 4) = (void*)0x786d94;
        *(int*)((char*)cmd2 + 8) = 0;
        *(int*)((char*)cmd2 + 0xc) = 0;
        *(int*)((char*)cmd2 + 0x10) = 0;
        *(int*)((char*)cmd2 + 0x14) = *(int*)0x8c225c;
        *(int*)((char*)cmd2 + 0x18) = 0;
        *(int*)((char*)cmd2 + 0x20) = 0;
        *(int*)((char*)cmd2 + 0x24) = 0;
        void* vtbl3 = *(void**)((char*)cmd2 + 4);
        *(void**)cmd2 = (void*)0x786dc4;
        void* vtbl4 = *(void**)((char*)vtbl3 + 4);
        *(void**)((char*)cmd2 + (int)vtbl4 + 4) = (void*)0x786dbc;
    }

    PVInstancePtr* it2 = list->begin;
    PVInstancePtr* end2 = list->end;
    while (it2 != end2) {
        it2++;
    }

    void* dm2 = (void*)((char*)dm + 4);
    void* ws = (void*)((char*)dm2 + 4);
    void* sel3 = self->selection;
    if (sel3) {
        sel3 = (void*)((char*)sel3 + 0);
    }

    typedef void (__thiscall *DoItFn)(void*, void*);
    DoItFn doIt = (DoItFn)(*(void**)((char*)sel3));
    doIt(sel3, dataState);
}
