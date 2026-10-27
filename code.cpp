struct ExceptionObject {
    unsigned long words[10];
    void __thiscall copy(const void *source);
};

extern "C" __declspec(noreturn) void __stdcall throw_exception(void *, void *);

struct ReflectionFunctionHolder {
    DWORD field0;

    void __thiscall invoke();
};

void __thiscall ReflectionFunctionHolder::invoke()
{
    if (this->field0 == 0) {
        ExceptionObject exc;
        exc.copy(0);
    }

    typedef void (__stdcall *FuncPtr)(void *);
    FuncPtr func = reinterpret_cast<FuncPtr>(reinterpret_cast<char *>(this->field0) + 4);
    func(reinterpret_cast<void *>(reinterpret_cast<char *>(this) + 8));

    throw_exception(0, 0);
}