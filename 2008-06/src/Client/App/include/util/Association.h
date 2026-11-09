#pragma once
#include <vector>

namespace RBX
{
	// NOTE: this class uses templated functions: add those in manually
	template<typename Associated>
	class Association
	{
	public:
		class Item
		{
		public:
			virtual ~Item();
		};

		template<typename T>
		class TItem : public Item
		{
		public:
			T t;
  
		public:
			TItem();
		};

	private:
		std::vector<Item*> items;
  
	public:
		~Association();
  
	private:
		static size_t& count();

	public:
		template<typename T>
		bool contains() const;

		template<typename T>
		T& get();

		template<typename T>
		void remove();
	};
}

// rebuild overlay: template bodies rbxgs declares but never defines
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
		static size_t n = 0;
		return n;
	}

	// one slot index per associated type, allocated on first use
	template<typename Associated, typename T>
	size_t rebuildAssociationSlot(size_t& count)
	{
		static size_t slot = count++;
		return slot;
	}

	template<typename Associated>
	Association<Associated>::~Association()
	{
		for (size_t i = 0; i < items.size(); ++i)
			delete items[i];
	}

	template<typename Associated>
	template<typename T>
	bool Association<Associated>::contains() const
	{
		size_t slot = rebuildAssociationSlot<Associated, T>(count());
		return slot < items.size() && items[slot] != NULL;
	}

	template<typename Associated>
	template<typename T>
	T& Association<Associated>::get()
	{
		size_t slot = rebuildAssociationSlot<Associated, T>(count());
		if (items.size() <= slot)
			items.resize(slot + 1, NULL);
		if (!items[slot])
			items[slot] = new TItem<T>();
		return static_cast<TItem<T>*>(items[slot])->t;
	}

	template<typename Associated>
	template<typename T>
	void Association<Associated>::remove()
	{
		size_t slot = rebuildAssociationSlot<Associated, T>(count());
		if (slot < items.size())
		{
			delete items[slot];
			items[slot] = NULL;
		}
	}
}
