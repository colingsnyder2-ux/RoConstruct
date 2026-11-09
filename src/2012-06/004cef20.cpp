// from server: 28% by Intel
struct OgreGfxClustererPart {
    void* vfptr;
    char pad[0x45];
    unsigned char flag;
    char pad2[0x3];
    OgreGfxClustererPart* next;
    char pad3[0x4];
    void* unk_ptr;
    char pad4[0x18];
    void* unk_obj;

    void Release(OgreGfxClustererPart* node);
};

extern "C" void __stdcall OgreDeallocBytes(void* ptr);
extern "C" void __stdcall StringDestructor(void* str);
extern "C" void __stdcall UnkCall1(void* obj);
extern "C" void __stdcall UnkCall2(void* obj);

void OgreGfxClustererPart::Release(OgreGfxClustererPart* node) {
    if (!node->flag) {
        OgreGfxClustererPart* current = node;
        do {
            OgreGfxClustererPart* child = current->next;
            if (child) {
                this->Release(child);
            }
            current = current->next;
            void* str = (char*)node + 0xC;
            StringDestructor(str);
            void* obj = (char*)str + 0x1C;
            UnkCall1(obj);
            UnkCall2(obj);
            OgreDeallocBytes(node);
            node = current;
        } while (current && !current->flag);
    }
}
