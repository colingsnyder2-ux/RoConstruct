// from server: 100% by Xemicl
// copied from an identical function in another client (function ?fn_ROCX000002_0060b970@ns_ROCX000002@@YAPAXPAX@Z)

namespace ns_ROCX000002 {
extern char sourceType;
extern char targetType;
extern char badCastType;

extern "C" void* __cdecl runtimeCast(
    void*, long, void*, void*, int);

typedef void (__thiscall *BadCastConstructor)(void*, const char*);
extern BadCastConstructor constructBadCast;

extern "C" __declspec(noreturn) void __stdcall throwException(
    void*, void*);

void* fn_ROCX000002_0060b970(void* object)
{
    void* result = runtimeCast(object, 0, &sourceType, &targetType, 0);
    if (!result)
    {
        char exception[12];
        constructBadCast(exception, "bad cast");
        throwException(exception, &badCastType);
    }
    return result;
}
}
