// from server: 21% by Intel
// Global data
bool g_initialized = false; // 0xe16f5c
void* g_global_b5766c = 0;  // 0xb5766c
void* g_instance_e16d78 = 0; // 0xe16d78
const char* g_string_b116d0 = "8csm"; // 0xb116d0

// External functions
extern "C" void* __cdecl sub_4125d0(void* a1, void* a2);
extern "C" void __cdecl sub_6cab60(void* a1, void* a2);
extern "C" void __cdecl sub_9831f5(const char* str);

struct TypedPropertyDescriptor {
    void* GetInstance();
};

void* TypedPropertyDescriptor::GetInstance() {
    if (!g_initialized) {
        g_initialized = true;
        
        struct LocalStruct {
            char b0;
            char b1;
            int d4;
            int d8;
        } local = {0, 0, 0, 0x1b};
        
        void* result = sub_4125d0(&local, g_global_b5766c);
        sub_6cab60(g_instance_e16d78, result);
        sub_9831f5(g_string_b116d0);
    }
    return g_instance_e16d78;
}
