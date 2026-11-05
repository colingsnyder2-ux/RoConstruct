// from server: 36% by colin
struct GuiItem {
    char pad0[0xc0];
    void* m_children;
    int getChildCount();
    void getPosition(float* out);
};

struct UnifiedWidget : GuiItem {
    void process(void* event);
};

extern "C" void __stdcall _invalid_parameter_noinfo();
extern "C" void* __cdecl sub_630d36(void* a, void* b, void* c, int d, int e);

void UnifiedWidget::process(void* event)
{
    float pos[2];
    this->getPosition(pos);
    unsigned int n = (unsigned int)this->getChildCount();
    for (unsigned int i = 0; i < n; ++i) {
        void** vec = (void**)((char*)this + 0xc0);
        void* begin = vec[1];
        if (begin != 0 || i >= (unsigned int)(((char*)vec[2] - (char*)begin) >> 3)) {
            _invalid_parameter_noinfo();
        }
        void* child = ((void**)vec[1])[i * 2];
        void* r = sub_630d36(child, (void*)0x881f4c, (void*)0x881f30, 0, 0);
        if (r != 0) {
            if (r == event) {
                break;
            }
            float childPos[2];
            this->getPosition(childPos);
            pos[0] += childPos[0];
            pos[1] += childPos[1];
        }
    }
}
