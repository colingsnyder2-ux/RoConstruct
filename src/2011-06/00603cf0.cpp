// from server: 62% by atomic.potato
struct CameraZoomInCommand
{
    int* field0C;
    void f();
};

extern "C" void __cdecl sub_00663F70(int);

void CameraZoomInCommand::f()
{
    int* p = field0C;
    int* q = *(int**)((char*)p + 0x118);
    typedef void (CameraZoomInCommand::*Fn)(int*);
    Fn fn = *(Fn*)((char*)q + 8);
    (this->*fn)((int*)((char*)p + 0x118));
    sub_00663F70(1);
}
