// from server: 74% by atomic.potato
struct CameraTiltUpCommand
{
    int f();
};

typedef int (__thiscall *CameraFunction)(int*);

extern "C" int __cdecl Call686620(int, int);

int CameraTiltUpCommand::f()
{
    int* object = *(int**)((char*)this + 0x0c);
    CameraFunction function = (CameraFunction)object[0x150 / 4];
    int result = function((int*)((char*)object + 0x150));
    return Call686620(result, -1);
}
