#include <windows.h>

// Typed GUID definitions for the symbols CBrowserViewExternal.h declares extern "C" const. Values read from the registered original's data.
// Kept in their own unit: defined in the class unit, the compiler folds IID_IBrowserViewExternal into ISupportErrorInfoImpl::InterfaceSupportsErrorInfo (76 vs 78 bytes).
extern "C" const IID IID_IBrowserViewExternal = {0xe2ece10d, 0x9997, 0x414b, {0xb4, 0x0b, 0x09, 0x28, 0xb8, 0xf3, 0xca, 0xdb}};
extern "C" const IID LIBID_RobloxLib = {0x03e1c8ed, 0xc1c6, 0x47bf, {0xb9, 0xb9, 0xa3, 0x7b, 0x67, 0x73, 0x18, 0xdd}};
extern "C" const CLSID CLSID_BrowserViewExternal = {0x70ebd57e, 0xfd0d, 0x4032, {0xb0, 0x90, 0x92, 0x44, 0xaa, 0x7d, 0xed, 0x6e}};
