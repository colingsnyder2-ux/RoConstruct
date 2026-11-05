// from server: 100% by king_originala
struct ExceptionStorage {
    unsigned long data[3];
};

extern "C" void (__thiscall *exceptionConstructor)(
    ExceptionStorage*, const char* const&);

extern unsigned char exceptionThrowInfo;
extern "C" __declspec(noreturn) void __stdcall throwException(
    void*, void*);

void getEdgeList()
{
    const char* message =
        "RBX RbxSubEntity::getEdgeList(): should not be called";
    ExceptionStorage exception;
    exceptionConstructor(&exception, message);
    throwException(&exception, &exceptionThrowInfo);
}
