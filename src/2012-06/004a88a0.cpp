// from server: 100% by Intel
extern unsigned char g_debugFlag;
extern "C" void __cdecl logEvent(unsigned char flag, const char* format, unsigned int value);

struct EventHandler {
    void handleEvent(void* event);
};

struct DxUserInput {
    char padding[0x1E8];
    EventHandler* handler;
    void processEvent(void* event);
};

void DxUserInput::processEvent(void* event) {
    if (g_debugFlag) {
        unsigned int eventValue = *reinterpret_cast<unsigned int*>(event);
        logEvent(g_debugFlag, "Processing event in DM %u", eventValue);
    }
    handler->handleEvent(event);
}
