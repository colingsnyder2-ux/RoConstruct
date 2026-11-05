// from server: 100% by atomic.potato
struct RbxTextureCompositorSceneManager {
    char pad0[0x10];
    void** begin;
    unsigned int end;
    unsigned int pos;
    unsigned int count;
    void remove();
};

extern "C" void __fastcall sub_4af640(void*);

void RbxTextureCompositorSceneManager::remove() {
    if (count != 0) {
        sub_4af640(begin[pos]);
        pos++;
        if (end <= pos) {
            pos = 0;
        }
        count--;
        if (count == 0) {
            pos = 0;
        }
    }
}
