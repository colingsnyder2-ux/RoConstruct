// from server: 81% by atomic.potato
struct KernelJoint {
    bool __cdecl method_74a3f0(float arg1, int arg2, int arg3, int arg4, int arg5, float arg6);
};

extern "C" bool __cdecl sub_7492B0(float, int, int, int, int);
extern "C" bool __cdecl sub_749690(float, int, int, int, int);

bool KernelJoint::method_74a3f0(float arg1, int arg2, int arg3, int arg4, int arg5, float arg6) {
    if (sub_7492B0(arg1, arg5, arg4, arg2, arg3)) {
        return true;
    }
    return sub_749690(arg6, arg5, arg4, arg2, arg3);
}
