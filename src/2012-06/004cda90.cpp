// from server: 32% by 41k
struct Ogre_GfxClustererPart {
    char padding[0x10];
    void* someData;

    int someMethod(void* param1, void* param2);
};

extern "C" int someFunction(void* param1, void* param2);

int Ogre_GfxClustererPart::someMethod(void* param1, void* param2) {
    void* ptr = *(void**)((char*)this + 0x10);
    if (ptr == 0) {
        someFunction(param1, param2);
        if (*(char*)((char*)ptr + 0x75) != 0) {
            ptr = *(void**)((char*)ptr + 8);
        }
    }
    if (*(char*)((char*)ptr + 0x75) != 0) {
        return 0;
    }
    return 1;
}
