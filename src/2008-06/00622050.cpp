// from server: 100% by colin
struct State;

struct Context {
    char padding[0x58];
    void (__cdecl *handler)(State *);
};

struct Recovery {
    char padding[8];
    int status;
};

struct State {
    char padding0[6];
    unsigned char status;
    char padding1[9];
    Context *context;
    char padding2[0x5c];
    Recovery *recovery;
};

struct Exception {
    void *vtable;
    char base[8];
    State *state;
    Recovery *recovery;
    unsigned char flag;
    char padding[3];
};

typedef void (__thiscall *ExceptionConstructor)(Exception *);

extern ExceptionConstructor exception_constructor;
extern char exception_vtable;
extern char exception_type;

extern "C" __declspec(noreturn) void __stdcall throw_exception(void *, void *);
extern "C" void __cdecl prepare_error(int);
extern "C" __declspec(dllimport, noreturn) void __cdecl exit(int);

void __cdecl raise_error(State *state, int status)
{
    if (state->recovery) {
        state->recovery->status = status;
        Recovery *recovery = state->recovery;
        Exception exception;
        exception_constructor(&exception);
        exception.vtable = &exception_vtable;
        exception.state = state;
        exception.recovery = recovery;
        exception.flag = 0;
        throw_exception(&exception, &exception_type);
    }

    state->status = (unsigned char)status;
    if (state->context->handler) {
        prepare_error(status);
        state->context->handler(state);
    }

    exit(1);
}
