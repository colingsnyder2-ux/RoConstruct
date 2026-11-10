#include <stddef.h>
#include "CDeclarationView.h"
// Size from CRuntimeClass 008124e8 and CreateObject 00434640 (operator new(0x114)); CHtmlView (mfc90) is 0xf4.
// Member offsets from the constructor 00434500 (eight zero stores), the destructor 00434570 (eight Releases in
// reverse order) and OnDocumentComplete 004346b0 (QI targets per element name).
typedef char HtmlViewSize[sizeof(CHtmlView) == 0xf4 ? 1 : -1];
typedef char DeclarationViewSize[sizeof(CDeclarationView) == 0x114 ? 1 : -1];
typedef char SmartPointerSize[sizeof(CComQIPtr<IHTMLElement>) == 4 ? 1 : -1];
typedef char DocumentOffset[offsetof(CDeclarationView, document) == 0xf4 ? 1 : -1];
typedef char DeclarationOffset[offsetof(CDeclarationView, declaration) == 0xf8 ? 1 : -1];
typedef char OwnerDivOffset[offsetof(CDeclarationView, ownerDiv) == 0xfc ? 1 : -1];
typedef char OwnerOffset[offsetof(CDeclarationView, owner) == 0x100 ? 1 : -1];
typedef char SummaryDivOffset[offsetof(CDeclarationView, summaryDiv) == 0x104 ? 1 : -1];
typedef char SummaryOffset[offsetof(CDeclarationView, summary) == 0x108 ? 1 : -1];
typedef char DeprecatedOffset[offsetof(CDeclarationView, deprecatedElement) == 0x10c ? 1 : -1];
typedef char PreliminaryOffset[offsetof(CDeclarationView, preliminaryElement) == 0x110 ? 1 : -1];
