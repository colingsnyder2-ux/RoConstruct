// from server: 100% by EspClaude
// from server: 90% by EspClaude
// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet roc_espclaude_514c1eba33152797.cpp

// Candidate translation unit (score above; library headers required).
#include <malloc.h>
#include <stdlib.h>
#define alloca _malloca
extern void (*rakFree)(void*);
extern void* (*rakMalloc)(size_t);
#define free rakFree
#define malloc rakMalloc
///
///
///

#ifndef __MEMORY_POOL_H
#define __MEMORY_POOL_H

#include <stdlib.h>

namespace DataStructures
{
	template <class MemoryBlockType>
	class MemoryPool
	{
	public:
		struct Page;

		struct MemoryWithPage
		{
			MemoryBlockType userMemory;
			Page *parentPage;
		};

		struct Page
		{
			MemoryWithPage **availableStack;
			int availableStackSize;
			MemoryWithPage *block;
			Page *next;
			Page *prev;
		};

		MemoryPool();
		~MemoryPool();

		MemoryBlockType *Allocate(void);
		void Preallocate(unsigned numElements);
		void Release(MemoryBlockType *m);
		void Clear(void);

	protected:
		int BlocksPerPage(void) const { return memoryPoolPageSize / sizeof(MemoryWithPage); }
		bool InitPage(Page *page, Page *prev);

		Page *availablePages;
		Page *unavailablePages;
		int availablePagesSize;
		int unavailablePagesSize;
		int memoryPoolPageSize;
	};

	template <class MemoryBlockType>
	MemoryPool<MemoryBlockType>::MemoryPool()
	{
		availablePagesSize = 0;
		unavailablePagesSize = 0;
		memoryPoolPageSize = 16384;
	}

	// FUNCTION: WEBSERVICE 0x101bcea0
	// DataStructures::MemoryPool<DataStructures::Page<unsigned int,InternalPacket *,32> >::~MemoryPool<DataStructures::Page<unsigned int,InternalPacket *,32> >
	template <class MemoryBlockType>
	MemoryPool<MemoryBlockType>::~MemoryPool()
	{
		Clear();
	}

	// FUNCTION: WEBSERVICE 0x101bc7b0
	// DataStructures::MemoryPool<InternalPacket>::InitPage
	// FUNCTION: WEBSERVICE 0x101bca50
	// DataStructures::MemoryPool<DataStructures::Page<unsigned int,InternalPacket *,32> >::InitPage
	template <class MemoryBlockType>
	bool MemoryPool<MemoryBlockType>::InitPage(Page *page, Page *prev)
	{
		int i = 0;
		const int bpp = BlocksPerPage();

		page->block = (MemoryWithPage *) malloc(memoryPoolPageSize);
		if (page->block==0)
			return false;
		MemoryWithPage **availableStack = (MemoryWithPage **) malloc(sizeof(MemoryWithPage *) * bpp);
		page->availableStack = availableStack;
		if (availableStack==0)
		{
			free(page->block);
			return false;
		}

		MemoryWithPage *curBlock = page->block;
		while (i < bpp)
		{
			curBlock->parentPage = page;
			availableStack[i++] = curBlock++;
		}

		page->availableStackSize = bpp;
		page->next = availablePages;
		page->prev = prev;
		return true;
	}

	// FUNCTION: WEBSERVICE 0x101bcd10
	// DataStructures::MemoryPool<InternalPacket>::Allocate
	// FUNCTION: WEBSERVICE 0x101bceb0
	// DataStructures::MemoryPool<DataStructures::Page<unsigned int,InternalPacket *,32> >::Allocate
	template <class MemoryBlockType>
	MemoryBlockType *MemoryPool<MemoryBlockType>::Allocate(void)
	{
		if (availablePagesSize > 0)
		{
			MemoryWithPage *retVal;
			Page *curPage = availablePages;

			retVal = curPage->availableStack[--(curPage->availableStackSize)];
			if (curPage->availableStackSize == 0)
			{
				--availablePagesSize;
				availablePages = curPage->next;
				curPage->next->prev = curPage->prev;
				curPage->prev->next = curPage->next;

				if (unavailablePagesSize++ == 0)
				{
					unavailablePages = curPage;
					curPage->next = curPage;
					curPage->prev = curPage;
				}
				else
				{
					curPage->next = unavailablePages;
					curPage->prev = unavailablePages->prev;
					unavailablePages->prev->next = curPage;
					unavailablePages->prev = curPage;
				}
			}

			return (MemoryBlockType *) retVal;
		}

		availablePages = (Page *) malloc(sizeof(Page));
		if (availablePages==0)
			return 0;
		availablePagesSize = 1;
		if (InitPage(availablePages, availablePages)==false)
			return 0;

		--(availablePages->availableStackSize);
		return (MemoryBlockType *) availablePages->availableStack[availablePages->availableStackSize];
	}

	template <class MemoryBlockType>
	void MemoryPool<MemoryBlockType>::Preallocate(unsigned numElements)
	{
		while ((unsigned) (availablePagesSize * BlocksPerPage()) < numElements)
		{
			Page *page = (Page *) malloc(sizeof(Page));
			if (availablePagesSize++ == 0)
			{
				availablePages = page;
				InitPage(page, page);
				page->next = page;
				page->prev = page;
			}
			else
			{
				InitPage(page, availablePages->prev);
				availablePages->prev->next = page;
				availablePages->prev = page;
			}
		}
	}

	// FUNCTION: WEBSERVICE 0x101bcdb0
	// DataStructures::MemoryPool<InternalPacket>::Release
	// FUNCTION: WEBSERVICE 0x101bcf50
	// DataStructures::MemoryPool<DataStructures::Page<unsigned int,InternalPacket *,32> >::Release
	template <class MemoryBlockType>
	void MemoryPool<MemoryBlockType>::Release(MemoryBlockType *m)
	{
		Page *curPage = ((MemoryWithPage *) m)->parentPage;

		if (curPage->availableStackSize == 0)
		{
			curPage->availableStack[curPage->availableStackSize++] = (MemoryWithPage *) m;

			--unavailablePagesSize;
			curPage->next->prev = curPage->prev;
			curPage->prev->next = curPage->next;
			if (unavailablePagesSize > 0 && curPage == unavailablePages)
			{
				unavailablePages = unavailablePages->next;
			}

			if (availablePagesSize++ == 0)
			{
				availablePages = curPage;
				curPage->next = curPage;
				curPage->prev = curPage;
			}
			else
			{
				curPage->next = availablePages;
				curPage->prev = availablePages->prev;
				availablePages->prev->next = curPage;
				availablePages->prev = curPage;
			}

			return;
		}

		curPage->availableStack[curPage->availableStackSize++] = (MemoryWithPage *) m;

		if (curPage->availableStackSize == BlocksPerPage() && availablePagesSize >= 4)
		{
			if (curPage == availablePages)
			{
				availablePages = curPage->next;
			}

			curPage->prev->next = curPage->next;
			curPage->next->prev = curPage->prev;
			--availablePagesSize;

			free(curPage->availableStack);
			free(curPage->block);
			free(curPage);
		}
	}

	// FUNCTION: WEBSERVICE 0x101bc670
	template <class MemoryBlockType>
	void MemoryPool<MemoryBlockType>::Clear(void)
	{
		Page *cur, *freeNext;

		if (availablePagesSize > 0)
		{
			cur = availablePages;
			while (1)
			{
				free(cur->availableStack);
				free(cur->block);
				freeNext = cur;
				cur = cur->next;
				if (cur == availablePages)
				{
					break;
				}
				free(freeNext);
			}
			free(freeNext);
		}

		if (unavailablePagesSize > 0)
		{
			cur = unavailablePages;
			while (1)
			{
				free(cur->availableStack);
				free(cur->block);
				freeNext = cur;
				cur = cur->next;
				if (cur == unavailablePages)
				{
					break;
				}
				free(freeNext);
			}
			free(freeNext);
		}

		availablePagesSize = 0;
		unavailablePagesSize = 0;
	}
}

#endif

#include "ReliabilityLayer.cpp"
