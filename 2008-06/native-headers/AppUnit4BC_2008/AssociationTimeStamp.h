#pragma once
// >>> native-status (generated) -- do not edit >>>
// AssociationTimeStamp | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 2082a0ae | roc native-status --write
// 2008-06 native RBX::Association<Instance> template members and the TimeStamp association item (inactive).
// The donor util/Association.h (read-only, included unchanged) declares Item::~Item, TItem<T>::TItem, count() and
// get<T>() but defines none of them; this header (its own path, so no donor header is shadowed) supplies their bodies.
// Verified by tests/record_native_app_unit4bc_2008.py; every shape below is read from the 2008-06 binary.
//
// Association<Instance>::Item   vtable 008265e4, RTTI .?AVItem@?$Association@VInstance@RBX@@@RBX@@ (1 base); one slot:
//                               the scalar deleting destructor 004c7090. ~Item 004c6d30 only restores the vtable.
// Association<Instance>::TItem<TimeStamp>
//                               vtable 008265ec, RTTI [TItem<TimeStamp>, Item] (both mdisp 0); slot 0 is the same
//                               004c7090 (the empty ~TItem folds with ~Item). get<TimeStamp>() 004c7ef0 news 8 bytes
//                               and stores the vtable and a zero 4-byte value at +4: sizeof(TItem<TimeStamp>) == 8,
//                               so TimeStamp is one 4-byte field, value-initialized to 0.
// TimeStamp                     .?AUTimeStamp@@ (a struct in the global namespace). DirectPhysicsReceiver's packet
//                               handler 004c83b0 compares the value with its unsigned timestamp argument
//                               (`cmp [eax], ecx` / jbe at 004c87b8): unsigned int. The field name is an analog name.
// get<T>()                      004c7ef0: the item index is a guarded function-local static initialized from count()++
//                               (guard bit 1 of 00971a88, value 00971a84; count() is the shared static 00971a80 that
//                               other get<T> instances also bump, e.g. 005aaeaa). The guard is tested again for every
//                               loop compare and for the final subscript, so the index is read through a function
//                               that returns the static by const reference (a by-value return is 280 bytes, a single
//                               local static in get() 256 bytes; both rejected). push_back(NULL) grows the vector
//                               (the inline fast path stores 0, the slow path calls insert 004c7c60). A null slot gets
//                               new TItem<T>(); the reference to its value (item + 4) is returned.
#include "util/Association.h"

namespace RBX
{
	template<typename Associated>
	Association<Associated>::Item::~Item()
	{
	}

	template<typename Associated>
	template<typename T>
	Association<Associated>::TItem<T>::TItem()
		: t()
	{
	}

	template<typename Associated>
	size_t& Association<Associated>::count()
	{
		static size_t c;
		return c;
	}

	template<typename Associated>
	template<typename T>
	T& Association<Associated>::get()
	{
		struct Index
		{
			static const size_t& get()
			{
				static size_t index = count()++;
				return index;
			}
		};
		while (items.size() <= Index::get())
			items.push_back(NULL);
		Item*& item = items[Index::get()];
		if (!item)
			item = new TItem<T>();
		return static_cast<TItem<T>*>(item)->t;
	}
}

struct TimeStamp
{
	unsigned int time; // compared unsigned with the packet timestamp (004c87b8)
};
