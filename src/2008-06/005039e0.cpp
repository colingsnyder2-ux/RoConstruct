// from server: 100% by colin
struct Exception;
typedef void (__thiscall *ExceptionConstructor)(Exception *, const char * const &);
extern ExceptionConstructor exceptionConstructor;
extern char exceptionThrowInfo;

extern "C" __declspec(noreturn) void __stdcall
throwException(void *, void *);

struct Exception {
    void *table;
    char *message;
    int ownsMessage;

    Exception();
    ~Exception();
};

__forceinline Exception::Exception()
{
}

void func_005039e0()
{
    Exception value;
    exceptionConstructor(&value, "shouldn't be here");
    throwException(&value, &exceptionThrowInfo);
}
