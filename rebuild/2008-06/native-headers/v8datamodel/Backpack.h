#pragma once
// >>> native-status (generated) -- do not edit >>>
// Backpack | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src e9f42895 | roc native-status --write
// 2008-06 native RBX::Backpack (inactive). Shape after the donor tools/rbxgs v8datamodel/Backpack.h; the one change is
// the class-name template argument (a const char array, RTTI $1?sBackpack@2@3QBDB). From the 2008-06 binary:
//   RTTI       vtable 0083b9bc .?AVBackpack@RBX@@ -> DescribedCreatable<Backpack, Hopper, sBackpack> -> Hopper, plus
//              IScriptOwner at +0x168 (vtable 0083b924, slot 0 scriptShouldRun 005d18e0).
//   size       0x16c: factory 0048bc20 allocates 0x16c and calls the constructor 005d1a80 (setName("Backpack") with
//              the literal 0083ba20; the class-name array is 0083b738).
// IScriptOwner is declared by the native script/Script.h (included read-only).
#include "script/Script.h"
#include "v8datamodel/Hopper.h"

namespace RBX
{
	extern const char sBackpack[];
	class Backpack : public RBX::DescribedCreatable<Backpack, Hopper, sBackpack>,
					 public IScriptOwner
	{
	private:
		virtual IScriptOwner* scriptShouldRun(Script* script);   // 005d18e0 (not attempted)
	public:
		Backpack();                                               // 005d1a80
	};
}
