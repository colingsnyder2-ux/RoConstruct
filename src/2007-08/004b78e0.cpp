// from server: 100% by EspClaude
// from server: 80% by EspClaude
// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 50727
// roc-lib: rbxgs-raknet roc_claude_f6138c626c2edcf6.cpp

// Candidate translation unit (score above; library headers required).
/// \file
///
/// This file is part of RakNet Copyright 2003 Kevin Jenkins.
///
/// Usage of RakNet is subject to the appropriate license agreement.
/// Creative Commons Licensees are subject to the
/// license found at
/// http://creativecommons.org/licenses/by-nc/2.5/
/// Single application licensees are subject to the license found at
/// http://www.rakkarsoft.com/SingleApplicationLicense.html
/// Custom license users are subject to the terms therein.
/// GPL license users are subject to the GNU General Public
/// License as published by the Free
/// Software Foundation; either version 2 of the License, or (at your
/// option) any later version.

// 2007-08: OrderedList without per-call comparison pointer (target pushes 2 args to GetIndexFromKey)
/// \file
/// \brief \b [Internal] Quicksort ordered list.
///
/// This file is part of RakNet Copyright 2003 Kevin Jenkins.
///
/// Usage of RakNet is subject to the appropriate license agreement.
/// Creative Commons Licensees are subject to the
/// license found at
/// http://creativecommons.org/licenses/by-nc/2.5/
/// Single application licensees are subject to the license found at
/// http://www.rakkarsoft.com/SingleApplicationLicense.html
/// Custom license users are subject to the terms therein.
/// GPL license users are subject to the GNU General Public
/// License as published by the Free
/// Software Foundation; either version 2 of the License, or (at your
/// option) any later version.

#include "DS_List.h"
#include "Export.h"

#ifndef __ORDERED_LIST_H
#define __ORDERED_LIST_H

/// The namespace DataStructures was only added to avoid compiler errors for commonly named data structures
/// As these data structures are stand-alone, you can use them outside of RakNet for your own projects if you wish.
namespace DataStructures
{
	template <class key_type, class data_type>
	int defaultOrderedListComparison(const key_type &a, const data_type &b)
	{
		if (a<b) return -1; if (a==b) return 0; return 1;
	}

	/// \note IMPORTANT! If you use defaultOrderedListComparison then call IMPLEMENT_DEFAULT_COMPARISON or you will get an unresolved external linker error.
	template <class key_type, class data_type, int (*default_comparison_function)(const key_type&, const data_type&)=defaultOrderedListComparison<key_type, data_type> >
	class RAK_DLL_EXPORT OrderedList
	{
	public:
		static void IMPLEMENT_DEFAULT_COMPARISON(void) {DataStructures::defaultOrderedListComparison<key_type, data_type>(key_type(),data_type());}

		OrderedList();
		~OrderedList();
		OrderedList( const OrderedList& original_copy );
		OrderedList& operator= ( const OrderedList& original_copy );

		/// comparisonFunction must take a key_type and a data_type and return <0, ==0, or >0
		/// If the data type has comparison operators already defined then you can just use defaultComparison
		bool HasData(const key_type &key) const;
		// GetIndexFromKey returns where the insert should go at the same time checks if it is there
		unsigned GetIndexFromKey(const key_type &key, bool *objectExists) const;
		data_type GetElementFromKey(const key_type &key) const;
		bool GetElementFromKey(const key_type &key, data_type &element) const;
		unsigned Insert(const key_type &key, const data_type &data);
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

// 2007-08: OrderedList::Insert(key,data) without assertOnDuplicate (target pushes 2 args, ret 8)
/// \file
/// \brief \b [Internal] Map
///
/// This file is part of RakNet Copyright 2003 Kevin Jenkins.
///
/// Usage of RakNet is subject to the appropriate license agreement.
/// Creative Commons Licensees are subject to the
/// license found at
/// http://creativecommons.org/licenses/by-nc/2.5/
/// Single application licensees are subject to the license found at
/// http://www.rakkarsoft.com/SingleApplicationLicense.html
/// Custom license users are subject to the terms therein.
/// GPL license users are subject to the GNU General Public
/// License as published by the Free
/// Software Foundation; either version 2 of the License, or (at your
/// option) any later version.

#ifndef __RAKNET_MAP_H
#define __RAKNET_MAP_H

#include "DS_OrderedList.h"
#include "Export.h"

// If I want to change this to a red-black tree, this is a good site: http://www.cs.auckland.ac.nz/software/AlgAnim/red_black.html
// This makes insertions and deletions faster.  But then traversals are slow, while they are currently fast.

/// The namespace DataStructures was only added to avoid compiler errors for commonly named data structures
/// As these data structures are stand-alone, you can use them outside of RakNet for your own projects if you wish.
namespace DataStructures
{
	/// The default comparison has to be first so it can be called as a default parameter.
	/// It then is followed by MapNode, followed by NodeComparisonFunc
	template <class key_type>
		int defaultMapKeyComparison(const key_type &a, const key_type &b)
	{
		if (a<b) return -1; if (a==b) return 0; return 1;
	}

	/// \note IMPORTANT! If you use defaultMapKeyComparison then call IMPLEMENT_DEFAULT_COMPARISON or you will get an unresolved external linker error.
	template <class key_type, class data_type, int (*key_comparison_func)(const key_type&, const key_type&)=defaultMapKeyComparison<key_type> >
	class RAK_DLL_EXPORT Map
	{
	public:
		static void IMPLEMENT_DEFAULT_COMPARISON(void) {DataStructures::defaultMapKeyComparison<key_type>(key_type(),key_type());}

		struct MapNode
		{
			MapNode() {}
			MapNode(key_type _key, data_type _data) : mapNodeKey(_key), mapNodeData(_data) {}
			MapNode& operator = ( const MapNode& input ) {mapNodeKey=input.mapNodeKey; mapNodeData=input.mapNodeData; return *this;}
			MapNode( const MapNode & input) {mapNodeKey=input.mapNodeKey; mapNodeData=input.mapNodeData;}
			key_type mapNodeKey;
			data_type mapNodeData;
		};

		// Has to be a static because the comparison callback for DataStructures::OrderedList is a C function
		static int NodeComparisonFunc(const key_type &a, const MapNode &b)
		{
#ifdef _MSC_VER
#pragma warning( disable : 4127 ) // warning C4127: conditional expression is constant
#endif
			return key_comparison_func(a, b.mapNodeKey);
		}

		Map();
		~Map();
		Map( const Map& original_copy );
		Map& operator= ( const Map& original_copy );

		data_type& Get(const key_type &key); 
		data_type Pop(const key_type &key);
		// Add if needed
		void Set(const key_type &key, const data_type &data);
		// Must already exist
		void SetExisting(const key_type &key, const data_type &data);
		// Must add
		void SetNew(const key_type &key, const data_type &data);
		bool Has(const key_type &key);
		bool Delete(const key_type &key);
		data_type& operator[] ( const unsigned int position ) const;
		key_type GetKeyAtIndex( const unsigned int position ) const;
		unsigned GetIndexAtKey( const key_type &key );
		void RemoveAtIndex(const unsigned index);
		void Clear(void);
		unsigned Size(void) const;

	protected:
		DataStructures::OrderedList< key_type,MapNode,Map::NodeComparisonFunc > mapNodeList;

		void SaveLastSearch(const key_type &key, unsigned index);
		bool HasSavedSearchResult(const key_type &key) const;

		unsigned lastSearchIndex;
		key_type lastSearchKey;
		bool lastSearchIndexValid;
	};

	template <class key_type, class data_type, int (*key_comparison_func)(const key_type&,const key_type&)>
	Map<key_type, data_type, key_comparison_func>::Map()
	{
		lastSearchIndexValid=false;
	}

	template <class key_type, class data_type, int (*key_comparison_func)(const key_type&,const key_type&)>
	Map<key_type, data_type, key_comparison_func>::~Map()
	{
		Clear();
	}

	template <class key_type, class data_type, int (*key_comparison_func)(const key_type&,const key_type&)>
	Map<key_type, data_type, key_comparison_func>::Map( const Map& original_copy )
	{
		mapNodeList=original_copy.mapNodeList;
        lastSearchIndex=original_copy.lastSearchIndex;
		lastSearchKey=original_copy.lastSearchKey;
		lastSearchIndexValid=original_copy.lastSearchIndexValid;
	}

    template <class key_type, class data_type, int (*key_comparison_func)(const key_type&,const key_type&)>
	Map<key_type, data_type, key_comparison_func>& Map<key_type, data_type, key_comparison_func>::operator= ( const Map& original_copy )
	{
		mapNodeList=original_copy.mapNodeList;
		lastSearchIndex=original_copy.lastSearchIndex;
		lastSearchKey=original_copy.lastSearchKey;
		lastSearchIndexValid=original_copy.lastSearchIndexValid;
		return *this;
	}

	template <class key_type, class data_type, int (*key_comparison_func)(const key_type&,const key_type&)>
	data_type& Map<key_type, data_type, key_comparison_func>::Get(const key_type &key)
	{
		if (HasSavedSearchResult(key))
			return mapNodeList[lastSearchIndex].mapNodeData;

		bool objectExists;
		unsigned index;
		index=mapNodeList.GetIndexFromKey(key, &objectExists);
		assert(objectExists);
		SaveLastSearch(key,index);
		return mapNodeList[index].mapNodeData;
	}

	template <class key_type, class data_type, int (*key_comparison_func)(const key_type&,const key_type&)>
	unsigned Map<key_type, data_type, key_comparison_func>::GetIndexAtKey( const key_type &key )
	{
		if (HasSavedSearchResult(key))
			return lastSearchIndex;

		bool objectExists;
		unsigned index;
		index=mapNodeList.GetIndexFromKey(key, &objectExists);
		if (objectExists==false)
		{
			assert(objectExists);
		}
		SaveLastSearch(key,index);
		return index;
	}

	template <class key_type, class data_type, int (*key_comparison_func)(const key_type&,const key_type&)>
	void Map<key_type, data_type, key_comparison_func>::RemoveAtIndex(const unsigned index)
	{
		mapNodeList.RemoveAtIndex(index);
		lastSearchIndexValid=false;
	}

	template <class key_type, class data_type, int (*key_comparison_func)(const key_type&,const key_type&)>
		data_type Map<key_type, data_type, key_comparison_func>::Pop(const key_type &key)
	{
		bool objectExists;
		unsigned index;
		if (HasSavedSearchResult(key))
			index=lastSearchIndex;
		else
		{
			index=mapNodeList.GetIndexFromKey(key, &objectExists);
			assert(objectExists);
		}		
		data_type tmp = mapNodeList[index].mapNodeData;
		mapNodeList.RemoveAtIndex(index);
		lastSearchIndexValid=false;
		return tmp;
	}

	template <class key_type, class data_type, int (*key_comparison_func)(const key_type&,const key_type&)>
	void Map<key_type, data_type, key_comparison_func>::Set(const key_type &key, const data_type &data)
	{
		bool objectExists;
		unsigned index;

		if (HasSavedSearchResult(key))
		{
			mapNodeList[lastSearchIndex].mapNodeData=data;
			return;
		}
		
		index=mapNodeList.GetIndexFromKey(key, &objectExists);

		if (objectExists)
		{
			SaveLastSearch(key,index);
			mapNodeList[index].mapNodeData=data;
		}
		else
		{
			SaveLastSearch(key,mapNodeList.Insert(key,MapNode(key,data)));
		}
	}

	template <class key_type, class data_type, int (*key_comparison_func)(const key_type&,const key_type&)>
	void Map<key_type, data_type, key_comparison_func>::SetExisting(const key_type &key, const data_type &data)
	{
		bool objectExists;
		unsigned index;

		if (HasSavedSearchResult(key))
		{
			index=lastSearchIndex;
		}
		else
		{
			index=mapNodeList.GetIndexFromKey(key, &objectExists);
			assert(objectExists);
			SaveLastSearch(key,index);
		}		

		mapNodeList[index].mapNodeData=data;
	}	

	template <class key_type, class data_type, int (*key_comparison_func)(const key_type&,const key_type&)>
	void Map<key_type, data_type, key_comparison_func>::SetNew(const key_type &key, const data_type &data)
	{
#ifdef _DEBUG
		unsigned index;
		bool objectExists;
		index=mapNodeList.GetIndexFromKey(key, &objectExists);
		assert(objectExists==false);
#endif
		SaveLastSearch(key,mapNodeList.Insert(key,MapNode(key,data)));
	}

	template <class key_type, class data_type, int (*key_comparison_func)(const key_type&,const key_type&)>
	bool Map<key_type, data_type, key_comparison_func>::Has(const key_type &key)
	{
		if (HasSavedSearchResult(key))
			return true;

		bool objectExists;
		unsigned index;
		index=mapNodeList.GetIndexFromKey(key, &objectExists);
		if (objectExists)
			SaveLastSearch(key,index);
		return objectExists;
	}

	template <class key_type, class data_type, int (*key_comparison_func)(const key_type&,const key_type&)>
	bool Map<key_type, data_type, key_comparison_func>::Delete(const key_type &key)
	{
		if (HasSavedSearchResult(key))
		{
			lastSearchIndexValid=false;
			mapNodeList.RemoveAtIndex(lastSearchIndex);   
			return true;
		}

		bool objectExists;
		unsigned index;
		index=mapNodeList.GetIndexFromKey(key, &objectExists);
		if (objectExists)
		{
			lastSearchIndexValid=false;
			mapNodeList.RemoveAtIndex(index);
			return true;
		}
		else
			return false;
	}

	template <class key_type, class data_type, int (*key_comparison_func)(const key_type&,const key_type&)>
	void Map<key_type, data_type, key_comparison_func>::Clear(void)
	{
		lastSearchIndexValid=false;
		mapNodeList.Clear();
	}

	template <class key_type, class data_type, int (*key_comparison_func)(const key_type&,const key_type&)>
	data_type& Map<key_type, data_type, key_comparison_func>::operator[]( const unsigned int position ) const
	{
		return mapNodeList[position].mapNodeData;
	}

	template <class key_type, class data_type, int (*key_comparison_func)(const key_type&,const key_type&)>
		key_type Map<key_type, data_type, key_comparison_func>::GetKeyAtIndex( const unsigned int position ) const
	{
		return mapNodeList[position].mapNodeKey;
	}

	template <class key_type, class data_type, int (*key_comparison_func)(const key_type&,const key_type&)>
	unsigned Map<key_type, data_type, key_comparison_func>::Size(void) const
	{
		return mapNodeList.Size();
	}

	template <class key_type, class data_type, int (*key_comparison_func)(const key_type&,const key_type&)>
	void Map<key_type, data_type, key_comparison_func>::SaveLastSearch(const key_type &key, const unsigned index)
	{
		lastSearchIndex=index;
		lastSearchKey=key;
		lastSearchIndexValid=true;
	}

	template <class key_type, class data_type, int (*key_comparison_func)(const key_type&,const key_type&)>
	bool Map<key_type, data_type, key_comparison_func>::HasSavedSearchResult(const key_type &key) const
	{
		return lastSearchIndexValid && key_comparison_func(key,lastSearchKey)==0;
	}
}

#endif

#include "StringCompressor.h"
#include "DS_HuffmanEncodingTree.h"
#include "BitStream.h"
#include <assert.h>
#include <string.h>
#include <memory.h>

StringCompressor* StringCompressor::instance=0;
int StringCompressor::referenceCount=0;

void StringCompressor::AddReference(void)
{
	if (++referenceCount==1)
	{
		instance = new StringCompressor;
	}
}
void StringCompressor::RemoveReference(void)
{
	assert(referenceCount > 0);

	if (referenceCount > 0)
	{
		if (--referenceCount==0)
		{
			delete instance;
			instance=0;
		}
	}
}

StringCompressor* StringCompressor::Instance(void)
{
	return instance;
}

unsigned int englishCharacterFrequencies[ 256 ] =
{
	0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		722,
		0,
		0,
		2,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		11084,
		58,
		63,
		1,
		0,
		31,
		0,
		317,
		64,
		64,
		44,
		0,
		695,
		62,
		980,
		266,
		69,
		67,
		56,
		7,
		73,
		3,
		14,
		2,
		69,
		1,
		167,
		9,
		1,
		2,
		25,
		94,
		0,
		195,
		139,
		34,
		96,
		48,
		103,
		56,
		125,
		653,
		21,
		5,
		23,
		64,
		85,
		44,
		34,
		7,
		92,
		76,
		147,
		12,
		14,
		57,
		15,
		39,
		15,
		1,
		1,
		1,
		2,
		3,
		0,
		3611,
		845,
		1077,
		1884,
		5870,
		841,
		1057,
		2501,
		3212,
		164,
		531,
		2019,
		1330,
		3056,
		4037,
		848,
		47,
		2586,
		2919,
		4771,
		1707,
		535,
		1106,
		152,
		1243,
		100,
		0,
		2,
		0,
		10,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
};

StringCompressor::StringCompressor()
{
	DataStructures::Map<int, HuffmanEncodingTree *>::IMPLEMENT_DEFAULT_COMPARISON();

	// Make a default tree immediately, since this is used for RPC possibly from multiple threads at the same time
	HuffmanEncodingTree *huffmanEncodingTree = new HuffmanEncodingTree;
	huffmanEncodingTree->GenerateFromFrequencyTable( englishCharacterFrequencies );

	huffmanEncodingTrees.Set(0, huffmanEncodingTree);
}
void StringCompressor::GenerateTreeFromStrings( unsigned char *input, unsigned inputLength, int languageID )
{
	HuffmanEncodingTree *huffmanEncodingTree;
	if (huffmanEncodingTrees.Has(languageID))
	{
		huffmanEncodingTree = huffmanEncodingTrees.Get(languageID);
		delete huffmanEncodingTree;
	}

	unsigned index;
	unsigned int frequencyTable[ 256 ];

	if ( inputLength == 0 )
		return ;

	// Zero out the frequency table
	memset( frequencyTable, 0, sizeof( frequencyTable ) );

	// Generate the frequency table from the strings
	for ( index = 0; index < inputLength; index++ )
		frequencyTable[ input[ index ] ] ++;

	// Build the tree
	huffmanEncodingTree = new HuffmanEncodingTree;
	huffmanEncodingTree->GenerateFromFrequencyTable( frequencyTable );
	huffmanEncodingTrees.Set(languageID, huffmanEncodingTree);
}

StringCompressor::~StringCompressor()
{
	for (unsigned i=0; i < huffmanEncodingTrees.Size(); i++)
		delete huffmanEncodingTrees[i];
}

void StringCompressor::EncodeString( const char *input, int maxCharsToWrite, RakNet::BitStream *output, int languageID )
{
	HuffmanEncodingTree *huffmanEncodingTree;
	if (huffmanEncodingTrees.Has(languageID)==false)
		return;
	huffmanEncodingTree=huffmanEncodingTrees.Get(languageID);

	if ( input == 0 )
	{
		output->WriteCompressed( (unsigned int) 0 );
		return ;
	}

	RakNet::BitStream encodedBitStream;

	unsigned int stringBitLength;

	int charsToWrite;

	if ( maxCharsToWrite<=0 || ( int ) strlen( input ) < maxCharsToWrite )
		charsToWrite = ( int ) strlen( input );
	else
		charsToWrite = maxCharsToWrite - 1;

	huffmanEncodingTree->EncodeArray( ( unsigned char* ) input, charsToWrite, &encodedBitStream );

	stringBitLength = encodedBitStream.GetNumberOfBitsUsed();

	output->WriteCompressed( stringBitLength );

	output->WriteBits( encodedBitStream.GetData(), stringBitLength );
}

bool StringCompressor::DecodeString( char *output, int maxCharsToWrite, RakNet::BitStream *input, int languageID )
{
	HuffmanEncodingTree *huffmanEncodingTree;
	if (huffmanEncodingTrees.Has(languageID)==false)
		return false;
	huffmanEncodingTree=huffmanEncodingTrees.Get(languageID);

	unsigned int stringBitLength;
	int bytesInStream;

	output[ 0 ] = 0;

	if ( input->ReadCompressed( stringBitLength ) == false )
		return false;

	if ( (unsigned) input->GetNumberOfUnreadBits() < stringBitLength )
		return false;

	bytesInStream = huffmanEncodingTree->DecodeArray( input, stringBitLength, maxCharsToWrite, ( unsigned char* ) output );

	if ( bytesInStream < maxCharsToWrite )
		output[ bytesInStream ] = 0;
	else
		output[ maxCharsToWrite - 1 ] = 0;

	return true;
}
