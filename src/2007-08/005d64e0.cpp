// from server: 100% by colin
// roc 2007-08 005d64e0  unit: RBX::UnifiedImageWidget  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005d64e0

struct GuiDrawImage {
    void setImage(const char* name);
};

struct UnifiedImageWidget {
    char pad[0x100];
    GuiDrawImage guiImageDraw;
    const char* setImage(const char* name);
};

const char* UnifiedImageWidget::setImage(const char* name) {
    guiImageDraw.setImage(name);
    return name;
}
