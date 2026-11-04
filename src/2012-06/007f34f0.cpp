// from server: 42% by Intel
struct VGuiButton {
    char pad[4];
    int field_4;

    int __stdcall EventReplicator(int a2, int a3);
};

extern "C" void __stdcall sub_4C8700(int* thisptr);
extern "C" void __stdcall sub_7F2860(VGuiButton* thisptr, int a2, int a3);

int __stdcall VGuiButton::EventReplicator(int a2, int a3) {
    sub_4C8700(&this->field_4);
    sub_7F2860(this, a2, a3);
    return a2;
}
