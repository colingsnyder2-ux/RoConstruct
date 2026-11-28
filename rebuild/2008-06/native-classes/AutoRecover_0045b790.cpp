// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#pragma optimize("y", off)

void* __cdecl operator new(unsigned int);

// INFERRED: control block vtable at 0x819854, from `mov [eax], 0x819854`
extern void* g_00819854[];

// INFERRED: file-local types; real names unknown
struct Local_0045b790_Deleter {
    void operator()(void*) const;
};

struct Local_0045b790_Control {
    void** vtable;
    int strong;
    int weak;
    void* object;
    Local_0045b790_Deleter deleter;

    Local_0045b790_Control(void*, const Local_0045b790_Deleter&);
};

inline Local_0045b790_Control::Local_0045b790_Control(void* p, const Local_0045b790_Deleter& d)
    : strong(1), weak(1), deleter(d)
{
    vtable = g_00819854;
    object = p;
}

struct Local_0045b790_Holder {
    Local_0045b790_Control* control;
};

extern "C" Local_0045b790_Holder* __fastcall fn_0045b790(Local_0045b790_Holder* self, int unusedEdx, void* p, Local_0045b790_Deleter d)
{
    self->control = 0;
    try {
        self->control = new Local_0045b790_Control(p, d);
    }
    catch (...) {
        d(p);
        throw;
    }
    return self;
}
