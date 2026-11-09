// from server: 72% by atomic.potato
extern "C" void* __stdcall sub_00655c30();
extern "C" void sub_00656650(void*);

struct Pose_00656450
{
    void f();
};

void Pose_00656450::f()
{
    void* p = sub_00655c30();
    if (p)
        sub_00656650(p);
}
