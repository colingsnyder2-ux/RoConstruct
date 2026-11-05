// from server: 51% by tester
struct CXTPSyntaxEditCommand {
    void destroy();
};

extern "C" void __stdcall sub_802468();

void CXTPSyntaxEditCommand::destroy()
{
    char buf[0x2c];
    *(int*)(buf + 0x2c) = -1;
    sub_802468();
    int ecx = *(int*)(buf + 0x24);
    *(int*)0 = ecx;
    sub_802468();
    *(int*)0 = ecx;
}
