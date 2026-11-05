// from server: 100% by king_originala
extern "C" void* __cdecl castObject(void*, int, const void*, const void*, int);
extern "C" __declspec(noreturn) void __stdcall throwException(void*, const void*);

extern const char sourceType;
extern const char targetType;
extern const char badCastMessage[];
extern const char throwInfo;

namespace std
{
    struct bad_cast
    {
        unsigned data[3];
    };
}

typedef void (__thiscall *BadCastConstructor)(std::bad_cast*, const char*);
extern BadCastConstructor badCastConstructor;

typedef void (__thiscall *MemberFunction)(void*);

struct S
{
    char padding[0x38];
    MemberFunction function;
    int displacement;
    int tableOffset;

    void invoke(void* object, void* unused);
};

void S::invoke(void* object, void* unused)
{
    char* result = static_cast<char*>(
        castObject(object, 0, &sourceType, &targetType, 0));

    if (!result)
    {
        std::bad_cast error;
        badCastConstructor(&error, badCastMessage);
        throwException(&error, &throwInfo);
    }

    char* table = *reinterpret_cast<char**>(result + 0x134);
    int offset = *reinterpret_cast<int*>(table + tableOffset);
    function(result + 0x134 + offset + displacement);
}
