// from server: 57% by Intel
extern "C" int (__cdecl *g_callback)(const char*, const char*, int);
extern "C" unsigned char g_global_flag;
extern "C" const char* g_str_a;
extern "C" const char* g_str_b;
extern "C" const char* g_str_c;

extern "C" void __cdecl sub_946a40(void* thisptr, int arg);
extern "C" void __cdecl sub_972290(const char* str, int flag);
extern "C" void __cdecl sub_9481d0(void* thisptr, int arg);

namespace RBX {
    struct ResizeTool {
        char _pad0[0x1c];
        unsigned char field_1c;
        char _pad1[0x3c - 0x1c - 1];
        void* field_3c;
        unsigned char field_40;

        void method(int arg);
    };
}

void RBX::ResizeTool::method(int arg) {
    if (g_global_flag == 0)
        goto LABEL_947146;
    if (this->field_1c == 0)
        goto LABEL_947146;
    if (g_callback != 0) {
        int result = g_callback(g_str_a, g_str_b, 0x68);
        if (result != 0)
            goto LABEL_947146;
    }
    sub_972290(g_str_c, g_global_flag);

LABEL_947146:
    sub_946a40(this, arg);

    void* ptr = this->field_3c;
    int value = 0;
    if (ptr != 0) {
        value = *(int*)((char*)ptr + 4);
    }

    this->field_40 = (value != 0);

    sub_9481d0(this, arg);
}
