#pragma once
// >>> native-status (generated) -- do not edit >>>
// Stats | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src a9eb69da | roc native-status --write
// 2008-06 native RBX::Stats::Item, TypedStatsItem<T>, TypedMemItem and StatsService (inactive). Shape after the
// donor tools/rbxgs v8datamodel/Stats.h; every base, field, virtual and argument below is read from the 2008-06
// binary (the donor's Stats.cpp is empty, its TypedStatsItem::deref signature is wrong).
//   RTTI       Item vtable 00819fc4 .?AVItem@Stats@RBX@@ -> DescribedNonCreatable<Item, Instance, sStatsItem>
//              (name mangled $1?sStatsItem@23@3PADA: a non-const char array in .data, 00950c6c "StatsItem",
//              pushed by classDescriptor 0045dc70). TypedMemItem vtable 00839d7c -> TypedStatsItem<unsigned int>
//              (vtable 00837f1c) -> Item. StatsService vtable 00818c1c -> DescribedNonCreatable<StatsService,
//              Instance, sStats> (sStats 00950c64 "Stats", .data, 3PADA) + Service (empty, mdisp 0x130).
//   Item       constructors 0045ebe0 () and 005ad810 (const char*), both COMDAT copies outside the Stats unit:
//              val (double) +0x130 = 0, sValue (std::string) +0x138; destructor 0045ba10 only destroys sValue.
//              Size 0x158 (WorkspaceStatsItem, which adds no field, is allocated with 0x158 by 005a6620).
//   vtable     slot 2 askAddChild 0045ec80 (dynamic_cast to Item); new slot 16 update: Item/WorkspaceStatsItem
//              keep the empty 0047d410, TypedStatsItem<unsigned int> 005bc930, TypedMemItem 005c9c50.
//   Typed      TypedStatsItem<unsigned int>(const unsigned int*) 005bc860: boost::function0<T> func at +0x158
//              holding boost::bind(&deref, value) (deref<unsigned int> 005ec170 returns its argument);
//              TypedMemItem is allocated with 0x178 (Creatable<Instance>::create<TypedMemItem> 005c9d40).
//   methods    getValue 005c8e50, getStringValue2 005c8e70 (by value; GetValueString), formatMem 005c8ea0,
//              formatValue(double, const char*, ...) 005c8f20 (__cdecl varargs), formatValue<double/float/int/
//              unsigned int/bool> 005c90b0/005c90e0/005c9110/005c9140/005c9170, createChildItem 005c9c70,
//              createBoundMemChildItem 005c9dc0, createBoundChildItem(const Profiler&) 005ca240.
//   service    StatsService size 0x130 (Creatable<Instance>::create<StatsService> 00458590); constructor 00458520
//              passes the literal "Stats" (00818c5c) to Instance(const char*); askAddChild is ICF-shared with
//              Item's (0045ec80), write returns 0 (00416690, ICF-shared).
#include "v8tree/Instance.h"
#include "v8tree/Service.h"
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <string>

struct NativeStatsServiceLayout;

namespace RBX
{
	namespace Profiling
	{
		class Profiler; // 2008 layout pending (getData 005c4120, name std::string at +0xc020, read in 005ca240); see the Stats unit
	}

	namespace Stats
	{
		extern char sStatsItem[];

		class Item : public DescribedNonCreatable<Item, Instance, sStatsItem>
		{
			friend struct ::NativeStatsServiceLayout; // tests/NativeStatsServiceLayout.cpp offset asserts
		protected:
			double val;          // +0x130
			std::string sValue;  // +0x138

		protected:
			virtual void update() // slot 16; the empty body is 0047d410 (ICF-shared)
			{
			}

		public:
			Item()               // 0045ebe0
				: val(0)
			{
			}
			Item(const char* name) // 005ad810
				: DescribedNonCreatable<Item, Instance, sStatsItem>(name),
				  val(0)
			{
			}

			double getValue();                // 005c8e50
			std::string getStringValue2();    // 005c8e70
			void setValue(double value, const std::string& s)
			{
				val = value;
				sValue = s;
			}
			void formatMem(size_t bytes);     // 005c8ea0
			void __cdecl formatValue(double value, const char* format, ...); // 005c8f20
			template<typename T>
			void formatValue(const T& value);

			Item* createChildItem(const char* name);                                 // 005c9c70
			Item* createBoundChildItem(const Profiling::Profiler& profiler);         // 005ca240
			Item* createBoundMemChildItem(const char* name, const size_t& value);    // 005c9dc0

		protected:
			virtual bool askAddChild(const Instance* instance) const; // 0045ec80
		};

		// Explicit specializations defined in the Stats unit (called out of line from other units).
		template<> void Item::formatValue<double>(const double& value);             // 005c90b0
		template<> void Item::formatValue<float>(const float& value);               // 005c90e0
		template<> void Item::formatValue<int>(const int& value);                   // 005c9110
		template<> void Item::formatValue<unsigned int>(const unsigned int& value); // 005c9140
		template<> void Item::formatValue<bool>(const bool& value);                 // 005c9170

		template<typename T>
		class TypedStatsItem : public Item
		{
			friend struct ::NativeStatsServiceLayout;
		protected:
			boost::function0<T> func; // +0x158

		public:
			TypedStatsItem(const T* value) // 005bc860 (unsigned int)
				: func(boost::bind(&deref, value))
			{
			}

		protected:
			virtual void update() // 005bc930 (unsigned int)
			{
				formatValue(func());
			}

		private:
			static const T& deref(const T* value) // 005ec170 (unsigned int)
			{
				return *value;
			}
		};

		class TypedMemItem : public TypedStatsItem<size_t>
		{
		public:
			TypedMemItem(const size_t* value); // 005c9bd0

		protected:
			virtual void update();             // 005c9c50
		};

		extern char sStats[];

		class StatsService : public DescribedNonCreatable<StatsService, Instance, sStats>,
							 public Service
		{
		public:
			StatsService();                    // 00458520

		protected:
			virtual bool askAddChild(const Instance* instance) const; // ICF-shared with Item's 0045ec80
			virtual XmlElement* write();       // 00416690 (returns 0, ICF-shared)
		};
	}
}
