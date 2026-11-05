// from server: 88% by Intel
struct Object {
    int field_0;
    int field_20;
};

extern "C" Object* __cdecl sub_9823D2();
extern "C" int __stdcall PostMessageA(int, unsigned int, unsigned int, int);

int __stdcall LockPlayModeVerb_Func(int arg) {
    Object* obj = sub_9823D2();
    int target = obj->field_20;
    int hwnd = *(int*)(target + 0x20);
    PostMessageA(hwnd, 0x111, 0x80FF, 0);
    return 0;
}
