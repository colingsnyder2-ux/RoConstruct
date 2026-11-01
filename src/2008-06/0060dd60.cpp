// from server: 100% by colin
struct Contact {
    char pad[8];
};

struct BlockBlockContact {
    void generateDataForMovingAssemblyStage();
};

extern "C" void __cdecl sub_60EE30(Contact*);

void BlockBlockContact::generateDataForMovingAssemblyStage() {
    sub_60EE30((Contact*)((char*)this + 8));
}
