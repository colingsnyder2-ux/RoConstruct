// from server: 100% by king_originala
union Buffer {
    double alignment;
    char data[24];
};

struct Table {
    void (__cdecl *manage)(Buffer*, Buffer*, int);
    void (__cdecl *invoke)(Buffer*);
};

struct Callback {
    Table* table;
    Buffer buffer;
};

struct Workspace {
    char padding[0x20];
    Callback* callback;

    void clearCallback();
};

struct BadFunctionCall {
    char data[40];
    BadFunctionCall();
};

extern "C" __declspec(noreturn) void __cdecl throwBadFunctionCall(
    const BadFunctionCall&);
extern "C" void __cdecl finishCallback();

int __stdcall runCallback(Workspace* workspace)
{
    Callback saved;
    saved.table = 0;

    Callback* source = workspace->callback;
    if (source->table) {
        saved.table = source->table;
        source->table->manage(&source->buffer, &saved.buffer, 0);
    }

    workspace->clearCallback();

    if (!saved.table)
        throwBadFunctionCall(BadFunctionCall());

    saved.table->invoke(&saved.buffer);
    finishCallback();

    if (saved.table && saved.table->manage)
        saved.table->manage(&saved.buffer, &saved.buffer, 1);

    return 0;
}
