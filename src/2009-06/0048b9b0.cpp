// from server: 100% by why2
struct RbxManualTextureLoader {
    static void release(RbxManualTextureLoader *self);
};

void RbxManualTextureLoader::release(RbxManualTextureLoader *self) {
    if (self != 0) {
        void (__thiscall *fn)(void *, int) = *(void (__thiscall **)(void *, int))((*(char **)self) + 0x98);
        fn(self, 1);
    }
}
