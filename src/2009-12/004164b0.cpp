// from server: 54% by atomic.potato
typedef const char* StringArg;

extern "C" StringArg __cdecl BuildString(StringArg value);

typedef void (__thiscall *TargetFunction)(void*, StringArg);

struct GlobalTable
{
    TargetFunction function;
};

extern GlobalTable g_table;

void Function(StringArg a, StringArg b, StringArg c)
{
    StringArg result = BuildString(b);
    g_table.function((void*)c, result);
}
