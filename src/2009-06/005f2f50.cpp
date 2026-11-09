// from server: 100% by why2
struct S_func_005f2f50 {
    char pad[0x8c];
    int m_value;
    int* get();
};

int* S_func_005f2f50::get()
{
    return (int*)((char*)this - 0x8c);
}
