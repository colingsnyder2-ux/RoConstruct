// from server: 27% by Intel
struct VFriendService_EventDesc {
    int vftable;
    char pad[8];

    int func_006a05b0(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
};

extern "C" void __stdcall G1_func_0069c4c0(void* dest, const void* src, int size);
extern "C" int __stdcall G1_func_0069f400(int a1);
extern "C" void __stdcall G1_func_0069c0b0(void* thisptr);

int VFriendService_EventDesc::func_006a05b0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    int vftable_val = 0xD9E4DC;
    int result = G1_func_0069f400(vftable_val);
    int eax = result;
    eax = -eax;
    eax = (eax >> 31) & vftable_val;
    this->vftable = eax;

    char buffer[28];
    G1_func_0069c4c0(buffer, &a1, 28);

    G1_func_0069c0b0(this);
    return 0;
}
