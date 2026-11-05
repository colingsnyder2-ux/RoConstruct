// from server: 53% by Intel
struct LuaArguments {
    int* vptr;

    int __stdcall func_84c970(int* arg);
};

extern "C" int __cdecl sub_832b40(int* a1, int a2);
extern "C" void __cdecl sub_832340(int* a1, int a2, int a3);
extern "C" void __cdecl sub_8326d0(int* a1, int a2);

int __stdcall LuaArguments::func_84c970(int* arg) {
    int* this_ptr = this->vptr;
    int* arg_ptr = arg;
    int v7 = *arg_ptr;

    sub_832b40(this_ptr, 4);

    int global_val = *reinterpret_cast<int*>(0xDE13E4);
    sub_832340(this_ptr, global_val, 0xFFFFD8F0);
    sub_8326d0(this_ptr, -2);

    return 1;
}
