// from server: 100% by king_originala
struct Helper {
    void method(void* arg);
};

extern "C" void* __stdcall sub_5de800();
extern "C" void* __stdcall sub_5de890();

struct GroupDragTool {
    char pad[0x1c];
    Helper* megaDragger;
    char pad2[8];
    bool dragging;
    void* onMouseUp(void* inputObject);
};

void* GroupDragTool::onMouseUp(void* inputObject)
{
    if (dragging) {
        switch (*(int*)((char*)inputObject + 8)) {
        case 0x72: {
            Helper* receiver = megaDragger;
            void* p = sub_5de800();
            receiver->method(p);
            break;
        }
        case 0x74: {
            Helper* receiver = megaDragger;
            void* p = sub_5de890();
            receiver->method(p);
            break;
        }
        }
        return this;
    }
    return 0;
}
