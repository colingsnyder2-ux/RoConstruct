// from server: 100% by colin
extern "C" int (__stdcall* PostMessageA)(void* hWnd, unsigned int Msg, unsigned int wParam, int lParam);

struct S {
    void* field0;
    void* field4;
    void method(int arg);
};

void S::method(int arg)
{
    PostMessageA(this->field4, 0x465, 0, arg);
}
