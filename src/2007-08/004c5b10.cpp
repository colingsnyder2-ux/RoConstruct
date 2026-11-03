// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS /EHsc /MD
// roc-lib: rbxgs-raknet roc_espclaude_36da85113a3bdff2.cpp

// Candidate translation unit (score above; library headers required).
// 2007-08 RakNet: older DS_OrderedList (comparison is the template parameter only, no runtime cf argument; Insert(key,data) has no assertOnDuplicate)
#define _DLL

#include "DS_List.h"
#include "Export.h"

#ifndef __ORDERED_LIST_H
#define __ORDERED_LIST_H
namespace DataStructures
{
	template <class key_type, class data_type>
	int defaultOrderedListComparison(const key_type &a, const data_type &b)
	{
		if (a<b) return -1; if (a==b) return 0; return 1;
	}
	template <class key_type, class data_type, int (*default_comparison_function)(const key_type&, const data_type&)=defaultOrderedListComparison<key_type, data_type> >
	class RAK_DLL_EXPORT OrderedList
	{
	public:
		static void IMPLEMENT_DEFAULT_COMPARISON(void) {DataStructures::defaultOrderedListComparison<key_type, data_type>(key_type(),data_type());}

		OrderedList();
		~OrderedList();
		OrderedList( const OrderedList& original_copy );
		OrderedList& operator= ( const OrderedList& original_copy );
		bool HasData(const key_type &key) const;
		// GetIndexFromKey returns where the insert should go at the same time checks if it is there
		unsigned GetIndexFromKey(const key_type &key, bool *objectExists) const;
		data_type GetElementFromKey(const key_type &key) const;
		bool GetElementFromKey(const key_type &key, data_type &element) const;
		unsigned Insert(const key_type &key, const data_type &data);
		unsigned Insert(const key_type &key, const data_type &data, bool) { return Insert(key, data); }
		unsigned Remove(const key_type &key);
		unsigned RemoveIfExists(const key_type &key);
		data_type& operator[] ( const unsigned int position ) const;
		void RemoveAtIndex(const unsigned index);
		void InsertAtIndex(const data_type &data, const unsigned index);
		void InsertAtEnd(const data_type &data);
		void RemoveFromEnd(const unsigned num=1);
		void Clear(bool doNotDeallocate=false);
		unsigned Size(void) const;

	protected:
		DataStructures::List<data_type> orderedList;
	};

	template <class key_type, class data_type, int (*default_comparison_function)(const key_type&, const data_type&)>
	OrderedList<key_type, data_type, default_comparison_function>::OrderedList()
	{
	}

	template <class key_type, class data_type, int (*default_comparison_function)(const key_type&, const data_type&)>
	OrderedList<key_type, data_type, default_comparison_function>::~OrderedList()
	{
		Clear();
	}

	template <class key_type, class data_type, int (*default_comparison_function)(const key_type&, const data_type&)>
	OrderedList<key_type, data_type, default_comparison_function>::OrderedList( const OrderedList& original_copy )
	{
		orderedList=original_copy.orderedList;
	}

	template <class key_type, class data_type, int (*default_comparison_function)(const key_type&, const data_type&)>
	OrderedList<key_type, data_type, default_comparison_function>& OrderedList<key_type, data_type, default_comparison_function>::operator= ( const OrderedList& original_copy )
	{
		orderedList=original_copy.orderedList;
		return *this;
	}

	template <class key_type, class data_type, int (*default_comparison_function)(const key_type&, const data_type&)>
	bool OrderedList<key_type, data_type, default_comparison_function>::HasData(const key_type &key) const
	{
		bool objectExists;
		unsigned index;
		index = GetIndexFromKey(key, &objectExists);
		return objectExists;
	}

	template <class key_type, class data_type, int (*default_comparison_function)(const key_type&, const data_type&)>
	data_type OrderedList<key_type, data_type, default_comparison_function>::GetElementFromKey(const key_type &key) const
	{
		bool objectExists;
		unsigned index;
		index = GetIndexFromKey(key, &objectExists);
		assert(objectExists);
		return orderedList[index];
	}
	template <class key_type, class data_type, int (*default_comparison_function)(const key_type&, const data_type&)>
	bool OrderedList<key_type, data_type, default_comparison_function>::GetElementFromKey(const key_type &key, data_type &element) const
	{
		bool objectExists;
		unsigned index;
		index = GetIndexFromKey(key, &objectExists);
		if (objectExists)
			element = orderedList[index];
		return objectExists;
	}
	template <class key_type, class data_type, int (*default_comparison_function)(const key_type&, const data_type&)>
	unsigned OrderedList<key_type, data_type, default_comparison_function>::GetIndexFromKey(const key_type &key, bool *objectExists) const
	{
		int index, upperBound, lowerBound;
		int res;

		if (orderedList.Size()==0)
		{
			*objectExists=false;
			return 0;
		}

		upperBound=(int)orderedList.Size()-1;
		lowerBound=0;
		index = (int)orderedList.Size()/2;

#ifdef _MSC_VER
	#pragma warning( disable : 4127 ) // warning C4127: conditional expression is constant
#endif
		while (1)
		{
			res = default_comparison_function(key,orderedList[index]);
			if (res==0)
			{
				*objectExists=true;
				return index;
			}
			else if (res<0)
			{
				upperBound=index-1;
			}
			else// if (res>0)
			{
				lowerBound=index+1;
			}

			index=lowerBound+(upperBound-lowerBound)/2;

			if (lowerBound>upperBound)
			{
				*objectExists=false;
				return lowerBound; // No match
			}
		}
	}

	template <class key_type, class data_type, int (*default_comparison_function)(const key_type&, const data_type&)>
	unsigned OrderedList<key_type, data_type, default_comparison_function>::Insert(const key_type &key, const data_type &data)
	{
		bool objectExists;
		unsigned index;
		index = GetIndexFromKey(key, &objectExists);

		// Don't allow duplicate insertion.
		if (objectExists)
		{
			// This is usually a bug!  Use InsertAllowDuplicate if you want duplicates
			return (unsigned)-1;
		}

		if (index>=orderedList.Size())
		{
			orderedList.Insert(data);
			return orderedList.Size()-1;
		}
		else
		{
			orderedList.Insert(data,index);
			return index;
		}		
	}

	template <class key_type, class data_type, int (*default_comparison_function)(const key_type&, const data_type&)>
	unsigned OrderedList<key_type, data_type, default_comparison_function>::Remove(const key_type &key)
	{
		bool objectExists;
		unsigned index;
		index = GetIndexFromKey(key, &objectExists);

		// Can't find the element to remove if this assert hits
	//	assert(objectExists==true);
		if (objectExists==false)
		{
			assert(objectExists==true);
			return 0;
		}

		orderedList.RemoveAtIndex(index);
		return index;
	}

	template <class key_type, class data_type, int (*default_comparison_function)(const key_type&, const data_type&)>
	unsigned OrderedList<key_type, data_type, default_comparison_function>::RemoveIfExists(const key_type &key)
	{
		bool objectExists;
		unsigned index;
		index = GetIndexFromKey(key, &objectExists);

		// Can't find the element to remove if this assert hits
		if (objectExists==false)
			return 0;

		orderedList.RemoveAtIndex(index);
		return index;
	}

	template <class key_type, class data_type, int (*default_comparison_function)(const key_type&, const data_type&)>
	void OrderedList<key_type, data_type, default_comparison_function>::RemoveAtIndex(const unsigned index)
	{
		orderedList.RemoveAtIndex(index);
	}

	template <class key_type, class data_type, int (*default_comparison_function)(const key_type&, const data_type&)>
		void OrderedList<key_type, data_type, default_comparison_function>::InsertAtIndex(const data_type &data, const unsigned index)
	{
		orderedList.Insert(data, index);
	}

	template <class key_type, class data_type, int (*default_comparison_function)(const key_type&, const data_type&)>
		void OrderedList<key_type, data_type, default_comparison_function>::InsertAtEnd(const data_type &data)
	{
		orderedList.Insert(data);
	}

	template <class key_type, class data_type, int (*default_comparison_function)(const key_type&, const data_type&)>
		void OrderedList<key_type, data_type, default_comparison_function>::RemoveFromEnd(const unsigned num)
	{
		orderedList.RemoveFromEnd(num);
	}

	template <class key_type, class data_type, int (*default_comparison_function)(const key_type&, const data_type&)>
	void OrderedList<key_type, data_type, default_comparison_function>::Clear(bool doNotDeallocate)
	{
		orderedList.Clear(doNotDeallocate);
	}

	template <class key_type, class data_type, int (*default_comparison_function)(const key_type&, const data_type&)>
	data_type& OrderedList<key_type, data_type, default_comparison_function>::operator[]( const unsigned int position ) const
	{
		return orderedList[position];
	}

	template <class key_type, class data_type, int (*default_comparison_function)(const key_type&, const data_type&)>
	unsigned OrderedList<key_type, data_type, default_comparison_function>::Size(void) const
	{
		return orderedList.Size();
	}
}

#endif
#include "ReliabilityLayer.cpp"
template unsigned DataStructures::OrderedList<SplitPacketIndexType, InternalPacket*, SplitPacketIndexComp>::GetIndexFromKey(const SplitPacketIndexType&, bool*) const;
template unsigned DataStructures::OrderedList<SplitPacketIdType, SplitPacketChannel*, SplitPacketChannelComp>::GetIndexFromKey(const SplitPacketIdType&, bool*) const;
template unsigned DataStructures::OrderedList<MessageNumberType, DataStructures::RangeNode<MessageNumberType>, DataStructures::RangeNodeComp<MessageNumberType> >::GetIndexFromKey(const MessageNumberType&, bool*) const;
