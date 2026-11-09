// from server: 100% by king_originala
struct CommandBars {
    int OnCmdMsg(unsigned int id, int code, void* extra, void* handlerInfo);
};

struct View {
    char reserved[0xF8];
    CommandBars* commandBars;

    int OnCmdMsg(unsigned int id, int code, void* extra, void* handlerInfo);
    int BaseOnCmdMsg(unsigned int id, int code, void* extra, void* handlerInfo);
};

int View::OnCmdMsg(unsigned int id, int code, void* extra, void* handlerInfo)
{
    if (commandBars && commandBars->OnCmdMsg(id, code, extra, handlerInfo))
        return 1;

    return BaseOnCmdMsg(id, code, extra, handlerInfo);
}
