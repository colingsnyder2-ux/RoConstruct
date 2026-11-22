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
		~Association()
		{
			std::vector<Item*>::iterator it = items.begin();
			std::vector<Item*>::iterator end = items.end();

			while(it != end)
			{
				delete (*it);
				it++;
			}
		}
  
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
// 2008-06 native header port of rbxgs App/include/util/Association.h (2007 text). Kept only because every dependent exact native unit
// compiles to an identical object with it in native-headers (proof: work/donorfree-route/header_port_proof.json).
