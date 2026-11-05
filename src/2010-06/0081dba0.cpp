// from server: 100% by auto
// roc 2010-06 0081dba0  unit: CXTPPropertyGridView  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081dba0
//
// 0081dba0  8b542404             mov edx, dword ptr [esp + 4]
// 0081dba4  8d41ac               lea eax, [ecx - 0x54]
// 0081dba7  c70200000000         mov dword ptr [edx], 0
// 0081dbad  85c0                 test eax, eax
// 0081dbaf  742e                 je 0x81dbdf
// 0081dbb1  83782000             cmp dword ptr [eax + 0x20], 0
// 0081dbb5  7428                 je 0x81dbdf
// 0081dbb7  85c0                 test eax, eax
// 0081dbb9  7510                 jne 0x81dbcb
// 0081dbbb  52                   push edx
// 0081dbbc  6820cba800           push 0xa8cb20
// 0081dbc1  50                   push eax
// 0081dbc2  50                   push eax
// 0081dbc3  e8f829fdff           call 0x7f05c0
// 0081dbc8  c20400               ret 4
// 0081dbcb  8b4020               mov eax, dword ptr [eax + 0x20]
// 0081dbce  52                   push edx
// 0081dbcf  6820cba800           push 0xa8cb20
// 0081dbd4  6a00                 push 0
// 0081dbd6  50                   push eax
// 0081dbd7  e8e429fdff           call 0x7f05c0
// 0081dbdc  c20400               ret 4
// 0081dbdf  b805400080           mov eax, 0x80004005
// 0081dbe4  c20400               ret 4
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?GetAccessibleParent@CXTPPropertyGridView@@MAEJPAPAUIDispatch@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
