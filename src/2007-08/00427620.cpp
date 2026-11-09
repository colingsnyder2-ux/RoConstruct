// from server: 35% by colin
struct std_string {
    char pad[0x1c];
    const char* c_str();
    unsigned int size();
    std_string& insert(unsigned int, const char*);
};

struct LogManager {
    char pad0[8];
    int field8;
    char pad1[4];
    std_string name;
};

struct ThreadLogManager : LogManager {
    std_string getLogFileName();
};

extern "C" {
    void* __stdcall sub_77DDAC(void*);
    void* __stdcall sub_77E6A8(int);
    void* __stdcall sub_77DD94(void*, const char*, void*);
    void* __stdcall sub_77DD98(void*);
    void* __stdcall sub_77DDBC(void*);
    void* __stdcall sub_77E64C(void*);
    void* __stdcall sub_77E650(void*, int);
}

extern void* g_8bb8e8;
extern void* g_8b5188;

std_string ThreadLogManager::getLogFileName()
{
    std_string fileName;
    void* p = (void*)((char*)g_8bb8e8 + 4);
    void* obj = *(void**)p;
    void* vt = *(void**)((char*)obj + 4);
    ((void (__thiscall*)(void*, void*))vt)(obj, (void*)this);
    sub_77DDAC(&fileName);
    sub_77E6A8(this->field8);
    sub_77DD94(&fileName, "_%s_%d", 0);
    sub_77DD98(&fileName);
    sub_77E64C((void*)this);
    sub_77E650((void*)this, 0);
    sub_77DDBC(&fileName);
    return fileName;
}
