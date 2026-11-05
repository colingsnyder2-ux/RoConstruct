// from server: 89% by tester
extern "C" void __stdcall sub_89E620(void* self, const void* name);

struct UnifiedImageWidget {
    char pad[0x98];
    void* setImageName(const void* name);
};

void* UnifiedImageWidget::setImageName(const void* name) {
    void* result = const_cast<void*>(name);
    void* sub = reinterpret_cast<char*>(this) + 0x98;
    sub_89E620(sub, name);
    return result;
}
