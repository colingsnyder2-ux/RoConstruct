// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// Byte match unverified.
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// INFERRED: Source and destination RTTI descriptors and bad_cast throw metadata.
extern "C" char g_009291fc;
extern "C" char g_00950f1c;
extern "C" _ThrowInfo g_008d362c;

namespace std {
    // INFERRED: MSVC 2008 x86 storage for the imported bad_cast constructor.
    struct bad_cast {
        char storage[12];
        bad_cast(const char*);
    };
}

extern "C" void (__thiscall *g_00802864)(std::bad_cast*, const char*);

__forceinline std::bad_cast::bad_cast(const char* message) {
    g_00802864(this, message);
}

namespace {
    // INFERRED: Layouts and virtual slots follow the observed offsets.
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

    struct S {
        char padding[64];
        void* value;
        Value* owner;
    };
}

extern "C" int __fastcall fn_005c9950(void* self, int unusedEdx, int a1, int a2, int a3);

extern "C" void __fastcall fn_005c99f0(S* self, int unusedEdx, void* object, Input* input) {
    Argument argument(self->value, self->owner);
    input->get(1, &argument);

    void* result = __RTDynamicCast(
        object, 0,
        &g_009291fc,
        &g_00950f1c,
        0);

    if (!result) {
        std::bad_cast error("bad cast");
        _CxxThrowException(&error, &g_008d362c);
        __assume(0);
    }

    fn_005c9950(
        self,
        reinterpret_cast<int>(&argument),
        reinterpret_cast<int>(result),
        reinterpret_cast<int>(reinterpret_cast<char*>(input) + 4),
        reinterpret_cast<int>(&argument));
}
