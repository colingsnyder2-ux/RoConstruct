// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
// INFERRED: same name as the verified analog, to avoid clashing with the CRT's _CxxThrowException declaration
extern "C" __declspec(noreturn) void __stdcall ThrowObject(void*, void*);

namespace std {
    struct bad_cast {
        char storage[12];
        bad_cast(const char*);
    };
}

// INFERRED: type descriptors / throw info are unknown globals in the exe
extern "C" char g_009291fc;
extern "C" char g_00937c18;
extern "C" char g_008d362c;

// INFERRED: imported MSVCR90 bad_cast constructor (call dword ptr [0x802864])
extern void (__thiscall *badCastConstructor)(std::bad_cast*, const char*);

__forceinline std::bad_cast::bad_cast(const char* message) {
    badCastConstructor(this, message);
}

struct Value {
    virtual ~Value();
    virtual void unused();
    virtual Value* clone();
};

__forceinline Value* cloneValue(Value* value) {
    if (value)
        return value->clone();
    return 0;
}

struct Argument {
    void* value;
    Value* owner;

    Argument(void*, Value*);
    ~Argument();
};

__forceinline Argument::Argument(void* p, Value* q) : value(p) {
    owner = cloneValue(q);
}

__forceinline Argument::~Argument() {
    if (owner)
        delete owner;
}

struct Input {
    virtual void unused();
    virtual void get(int, Argument*);
};

// INFERRED: object layout from offsets 0x40 / 0x44
struct S {
    char padding[64];
    void* value;
    Value* owner;
};

extern "C" int __fastcall fn_0049b0b0(void* self, int unusedEdx, int a1, int a2, int a3);

extern "C" void __fastcall fn_0049b160(S* self, int unusedEdx, void* object, Input* input) {
    Argument argument(self->value, self->owner);
    input->get(1, &argument);

    void* result = __RTDynamicCast(
        object, 0,
        &g_009291fc,
        &g_00937c18,
        0);

    if (!result) {
        std::bad_cast error("bad cast");
        ThrowObject(&error, &g_008d362c);
    }

    fn_0049b0b0(self, 0, (int)result, (int)(reinterpret_cast<char*>(input) + 4), (int)&argument);
}
