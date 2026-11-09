// from server: 51% by atomic.potato
typedef unsigned long DWORD;

extern "C" void MSVCP90_basic_string_ctor(void *, const char *);

struct RotateAxisCommand
{
    RotateAxisCommand(const char *);
};

RotateAxisCommand::RotateAxisCommand(const char *value)
{
    char buffer[28];
    MSVCP90_basic_string_ctor(buffer, "D$0P");
    *(void **)this = (void *)0x00B9C954;
}
