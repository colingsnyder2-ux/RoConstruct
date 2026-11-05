// from server: 100% by colin
struct UnifiedWidget {
    void construct(const char* imageName, int imageState);
};

struct UnifiedImageWidget : UnifiedWidget {
    char pad[0x100];
    UnifiedImageWidget(const char* imageName, int imageState);
};

UnifiedImageWidget::UnifiedImageWidget(const char* imageName, int imageState) {
    construct(imageName, imageState);
    *(int*)((char*)this + 0x00) = 0x7bbbfc;
    *(int*)((char*)this + 0x04) = 0x7bbbf0;
    *(int*)((char*)this + 0x10) = 0x7bbbe8;
    *(int*)((char*)this + 0x14) = 0x7bbbd8;
    *(int*)((char*)this + 0x2c) = 0x7bbbc8;
    *(int*)((char*)this + 0x44) = 0x7bbbb8;
    *(int*)((char*)this + 0x5c) = 0x7bbba8;
    *(int*)((char*)this + 0x74) = 0x7bbb98;
    *(int*)((char*)this + 0x8c) = 0x7bbb88;
    *(int*)((char*)this + 0xe8) = 0x7bbb80;
}
