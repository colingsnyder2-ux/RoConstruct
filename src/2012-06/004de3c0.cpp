// from server: 36% by atomic.potato
struct OgreString {
    char pad[0x1c];
    OgreString();
    OgreString(const char*);
    OgreString(const OgreString&);
    ~OgreString();
    OgreString& operator=(const OgreString&);
};

struct OgreTexturePtr {
    char pad[0x10];
    OgreTexturePtr();
    OgreTexturePtr(const OgreTexturePtr&);
    ~OgreTexturePtr();
    OgreTexturePtr& operator=(const OgreTexturePtr&);
};

struct OgreOStringStream {
    char pad[0x40];
    OgreOStringStream(int);
    ~OgreOStringStream();
    OgreString str();
    OgreOStringStream& operator<<(float);
};

extern "C" {
    void __stdcall sub_44d230();
    void __stdcall sub_b22680();
    void __stdcall sub_b22558();
    void __stdcall sub_b22e9c();
    void __stdcall sub_b2267c();
    void __stdcall sub_b23048();
    void __stdcall sub_b2263c();
    void __stdcall sub_b22648();
    void __stdcall sub_b22da0();
    void __stdcall sub_b22da4();
    void __stdcall sub_b230b0();
    void __stdcall sub_b22dd8();
    void __stdcall sub_b22dfc();
    void __stdcall sub_b22678();
}

struct VRbxTextureCompositorSceneManager {
    char pad0[0x58];
    void* begin;
    void* end;

    OgreTexturePtr createManualTexture(float a, float b, float c);
};

OgreTexturePtr VRbxTextureCompositorSceneManager::createManualTexture(float a, float b, float c) {
    OgreTexturePtr result;
    char* p = (char*)begin;
    char* e = (char*)end;
    int count = (int)((e - p) / 0x18);
    int i = 0;
    while (i < count) {
        float x = *(float*)(p);
        if (x == a) {
            float y = *(float*)(p + 4);
            if (y == b) {
                result = *(OgreTexturePtr*)(p + 8);
                return result;
            }
        }
        i++;
        p += 0x18;
    }

    OgreOStringStream oss(2);
    OgreString s1("Generated");
    OgreString s2("Shaders");
    OgreString s3("reusableRTT");
    OgreString s4("\\AppSettings.xml");

    oss << a;
    oss << b;

    OgreString name = oss.str();

    OgreTexturePtr tex;
    tex = *(OgreTexturePtr*)0;

    return tex;
}
