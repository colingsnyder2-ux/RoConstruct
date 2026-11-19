// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../native-classes
// 00587590: forwarding thunk generated from its proven jump target (thunk_lane.py, no model)
#include "ChangeHistoryFactory.cpp"
// INFERRED: 00587590 is a 5-byte jump to RBX::FactoryProduct<class RBX::ChangeHistoryService,class RBX::Instance,RBX::sChangeHistoryService>::~FactoryProduct<class RBX::ChangeHistoryService,class RBX::Instance,RBX::sChangeHistoryService>: the destructor of a derived class with nothing of its own to destroy; the class name is a placeholder.
struct __declspec(novtable) Thunk_00587590 : RBX::FactoryProduct<class RBX::ChangeHistoryService,class RBX::Instance,RBX::sChangeHistoryService> { ~Thunk_00587590(); };
Thunk_00587590::~Thunk_00587590() {}
