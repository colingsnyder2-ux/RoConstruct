// from server: 100% by king_originala
typedef void (__thiscall *ExceptionConstructor)(void*);
extern ExceptionConstructor construct_exception;
extern const void* bad_weak_ptr_vtable[];

namespace std {
    class exception {
    protected:
        const void** table;
        const char* message;
        bool ownsMessage;
    public:
        exception() throw();
    };

    namespace tr1 {
        class bad_weak_ptr : public exception {
        public:
            bad_weak_ptr() throw();
            ~bad_weak_ptr() throw();
        };
    }
}

__forceinline std::exception::exception() throw()
{
    construct_exception(this);
}

__forceinline std::tr1::bad_weak_ptr::bad_weak_ptr() throw()
{
    table = bad_weak_ptr_vtable;
}

struct ControlBlock {
    bool acquire();
};

struct WeakCount {
    ControlBlock* block;
};

__declspec(noreturn) void __cdecl throw_bad_weak_ptr(
    const std::tr1::bad_weak_ptr& error);

struct SharedCount {
    ControlBlock* block;
    SharedCount(const WeakCount& weak);
};

SharedCount::SharedCount(const WeakCount& weak)
    : block(weak.block)
{
    if (!block || !block->acquire())
        throw_bad_weak_ptr(std::tr1::bad_weak_ptr());
}
