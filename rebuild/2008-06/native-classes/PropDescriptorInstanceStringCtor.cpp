// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// Reflection::PropDescriptor<Instance, std::string> get-only constructor (inactive), the reflection.h template
// constructor emitted out of line. Flags line copied from the Instance sibling InstanceChildPermission.cpp.
// Identity: registry ??$?0P8Instance@RBX@@BE?AV?$basic_string@...@XZH@?$PropDescriptor@VInstance@RBX@@V?$basic_string@...
// @Reflection@RBX@@QAE@PBD0P8Instance@2@BE?AV?$basic_string@...@XZHW4Functionality@PropertyDescriptor@12@@Z at
// 005597d0 (getter std::string (Instance::*)() const, setter int = NULL). Shape: getset<GetFunction>(get, 0)
// 00557f50, Instance::classDescriptor() 0040ad80, TypedPropertyDescriptor<std::string> constructor 00443230 (auto_ptr
// passed by value, the temporary deleted afterwards), then the PropDescriptor<Instance, std::string> vftable 0082d72c.
#include "v8tree/Instance.h"

// 005597d0
template RBX::Reflection::PropDescriptor<RBX::Instance, std::string>::PropDescriptor(
	const char*, const char*, std::string (RBX::Instance::*)() const, int, RBX::Reflection::PropertyDescriptor::Functionality);
