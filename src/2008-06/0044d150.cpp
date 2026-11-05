// from server: 100% by king_originala
extern char text_8169e8[];
extern char text_8165c8[];
extern unsigned long global_96c268;

struct MessageData {
    const char* first;
    const char* second;
    unsigned long third;
    unsigned long fourth;
};

extern "C" int __stdcall dispatch(
    unsigned long, unsigned int, unsigned long, MessageData*);

int __stdcall command(unsigned long argument)
{
    MessageData data = { text_8169e8, text_8165c8, 0, 0 };
    return dispatch(global_96c268, 103, argument, &data);
}
