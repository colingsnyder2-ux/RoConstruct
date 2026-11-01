// from server: 100% by colin
// from server: 96% by colin
extern "C" __declspec(dllimport) int __stdcall PostMessageA(void*, unsigned int, unsigned int, int);
struct ChatEnter {
    char pad[0x14];
    void* field14;
    void method(int* out, int* a);
};
void ChatEnter::method(int* out, int* a)
{
    if (a[0] == 0xa && a[2] == 0x2f) {
        void* p = *(void**)((char*)field14 + 0x20);
        PostMessageA(p, 0x468, 0, 0);
        out[0] = 1;
        out[1] = 0;
    } else {
        out[0] = 0;
        out[1] = 0;
    }
}
