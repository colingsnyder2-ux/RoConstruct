// from server: 100% by colin
struct VerbWidget {
    char pad[0x100];
    int field_100;
    VerbWidget(int arg);
};

void baseInit();

VerbWidget::VerbWidget(int arg) {
    baseInit();
    field_100 = arg;
    *(int*)((char*)this + 0x00) = 0x7c29b4;
    *(int*)((char*)this + 0x04) = 0x7c29a8;
    *(int*)((char*)this + 0x10) = 0x7c29a0;
    *(int*)((char*)this + 0x14) = 0x7c2990;
    *(int*)((char*)this + 0x2c) = 0x7c2980;
    *(int*)((char*)this + 0x44) = 0x7c2970;
    *(int*)((char*)this + 0x5c) = 0x7c2960;
    *(int*)((char*)this + 0x74) = 0x7c2950;
    *(int*)((char*)this + 0x8c) = 0x7c2940;
    *(int*)((char*)this + 0xe8) = 0x7c2938;
}
