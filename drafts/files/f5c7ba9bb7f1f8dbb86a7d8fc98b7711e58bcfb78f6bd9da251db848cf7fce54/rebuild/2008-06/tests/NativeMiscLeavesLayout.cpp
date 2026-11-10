// Layout asserts for native-headers/util/MD5Hasher2008.h and native-headers/v8datamodel/MergeBinder2008.h.
// Each function returns the value; tests/record_native_misc_leaves.py checks the compiled `mov eax, imm32; ret`.
#include "util/MD5Hasher2008.h"
#include "v8datamodel/MergeBinder2008.h"

unsigned nativeMD5HasherImplSize() { return sizeof(RBX::MD5HasherImpl); }     // 0x28: new(0x28) in 0055c8b0
unsigned nativeMergeBinderSize() { return sizeof(RBX::MergeBinder); }         // 0x1c: vfptr + 0x18 vector (ArchiveBinder fields from +0x1c)
unsigned nativeInstanceHandleSize() { return sizeof(RBX::InstanceHandle); }   // 8: IDREFItem stride 0x10
