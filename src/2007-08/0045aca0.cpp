// from server: 100% by EspClaude
// roc 2007-08 0045aca0  (trial): boost 1.33-style function0<R>::operator().
// [this+0] manager (null => empty), [this+4] functor, [this+8] invoker.
// 0x413c00 = bad_function_call ctor ("call to empty boost::function"),
// 0x414170 = throw_exception<bad_function_call>. R is 0x16 dwords (rep movsd).
struct bad_function_call {
    bad_function_call();
    ~bad_function_call();
    int data[10]; // runtime_error: exception (0xc) + std::string at +0xc (0x1c), per copy ctor 0x4136b0
};

template<class E> __declspec(noreturn) void throw_exception(E const& e);

union any_pointer {
    void* obj_ptr;
    const void* const_obj_ptr;
    void (*func_ptr)();
};

struct Result {
    int data[22];
};

struct function0 {
    void* manager;
    any_pointer functor;
    Result (*invoker)(any_pointer);

    bool empty() const { return !manager; }
    Result operator()() const;
};

Result function0::operator()() const
{
    if (this->empty())
        throw_exception(bad_function_call());
    Result result = invoker(this->functor);
    return result;
}
