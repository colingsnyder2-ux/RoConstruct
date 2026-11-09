// from server: 100% by colin
// roc 2007-08 0043ee20  unit: RefItem  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043ee20
//
// 0043ee20  8d4c2404             lea ecx, [esp + 4]
// 0043ee24  ff15bcdd7700         call dword ptr [0x77ddbc]
// 0043ee2a  c20400               ret 4

struct RefItem {
    void method(void* arg);
};

extern "C" void (__fastcall *sub_77ddbc)(void*);

void RefItem::method(void* arg) {
    sub_77ddbc(&arg);
}
