// from server: 94% by Intel
typedef double QWORD_FLOAT;

extern "C" void __stdcall Function977d20(void*, void*, QWORD_FLOAT);

struct UserInputJob
{
    int Run(void*, void*);
};

int UserInputJob::Run(void* a, void* b)
{
    QWORD_FLOAT value = *(QWORD_FLOAT*)0xB5EF30;
    Function977d20(b, a, value);
    return (int)b;
}
