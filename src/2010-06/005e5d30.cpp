// from server: 42% by atomic.potato
extern "C" void Function_005e0c40(void*);
extern "C" void* Function_005e4990(void*, int);
extern "C" void* Function_0059e320(void*, int);

struct ResetCommand
{
    int unused0;
    int unused1;
    int unused2;
    void* field0c;
    void* field10;
    void* reset();
};

void* ResetCommand::reset()
{
    void* value = field0c;
    Function_005e0c40(value);
    void* result = Function_005e4990(field10, 1);
    return Function_0059e320(result, 0);
}
