// from server: 100% by colin
extern "C" unsigned long (__stdcall *GetModuleFileNameA)(
    void *, char *, unsigned long);

struct Text;

struct Text
{
    void *data;
    __declspec(dllimport) Text(const char *);
    __declspec(dllimport) ~Text() throw();
};





struct DxUserInput
{
    int process(const Text &);
    int func_0046a4f0(void *);
};

int DxUserInput::func_0046a4f0(void *module)
{
    char path[500];
    GetModuleFileNameA(module, path, 500);
    Text text(path);
    return process(text);
}
