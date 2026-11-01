// from server: 100% by king_originala
struct Message {
    void* window;
    unsigned int message;
    unsigned int wParam;
};

extern "C" void* (__stdcall *GetFocus)();
extern char* GetViewClass();

struct Window {
    static Window* __stdcall FromHandle(void* window);
    int IsKindOf(char* type);
};

struct CommandBars {
    int PreTranslateMessage(Message* message);
};

struct View {
    char reserved[0xF8];
    CommandBars* commandBars;

    int PreTranslateMessage(Message* message);
    int BasePreTranslateMessage(Message* message);
};

int View::PreTranslateMessage(Message* message)
{
    if (message->message >= 0x100 && message->message <= 0x109 &&
        message->wParam != 13 && message->wParam != 9 &&
        message->wParam != 27)
    {
        Window* focused = Window::FromHandle(GetFocus());
        if (focused && focused->IsKindOf(GetViewClass()))
            return 0;
    }

    if (BasePreTranslateMessage(message))
        return 1;

    if (commandBars && commandBars->PreTranslateMessage(message))
        return 1;

    return 0;
}
