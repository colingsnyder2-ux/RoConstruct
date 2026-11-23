// =============================================================================
// ComputeProp.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/util/ComputeProp.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once

namespace RBX
{
	// NOTE: i had to add a `const` to the getFunc definition
	template<typename T, typename U>
	class ComputeProp
	{
	private:
		mutable T val;
		mutable bool dirty;
		U* object;
		T(U::* getFunc)() const;

	public:
		ComputeProp(U* object, T(U::* getFunc)() const)
			: dirty(true),
			  object(object),
			  getFunc(getFunc)
		{
		}

		T getValue() const
		{
			if (dirty)
			{
				val = (object->*getFunc)();
				dirty = false;
			}
			return val;
		}

		operator T() const
		{
			return getValue();
		}

		const T* getValuePointer() const
		{
			getValue();
			return &val;
		}

		const T& getValueRef() const
		{
			getValue();
			return val;
		}

		bool setDirty() const
		{
			bool old = !dirty;
			dirty = true;
			return old;
		}
	};
}
