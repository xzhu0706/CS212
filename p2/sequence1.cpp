/* Xiaohong Zhu
 * CS212   10/21/2017
 *    Invariants:
 *      1. The member varaiable used indicates how many items are stored
 *         in the sequence.
 *      2. The items are stored in their sequence order in the array from 
 *         data[0] to data[used-1], and we don't care what is stored in the
 *         rest of the indexes.
 *      3. If there is a current item, then it lies in data[current_index];
 *         if there is no current item, then current_index equals used.
 * */
#include "sequence1.h"
#include <cassert>

namespace main_savitch_3
{
	sequence::sequence()
	{
		used = 0;
		current_index = 0;
	}
	
	void sequence::start()
	{
		current_index = 0;
	}

	void sequence::advance()
	{
		assert(is_item());
		current_index++;
	}

	void sequence::insert(const value_type& entry)
	{
		assert(size() < CAPACITY);
		if (!is_item()) 
			current_index = 0;
		for (size_type i = used; i > current_index; i--)
			data[i] = data[i-1];
		data[current_index] = entry;
		used++;
	}

	void sequence::attach(const value_type& entry)
	{
		assert(size() < CAPACITY);
		if (!is_item())
			current_index = used;
		else 
		{
			current_index++;
			for (size_type i = used; i > current_index; i--)
				data[i] = data[i-1];
		}
		data[current_index] = entry;
		used++;
	}

	void sequence::remove_current()
	{
		assert(is_item());
		used--;
		for (size_type i = current_index; i < used; i++)
			data[i] = data[i+1];
	}
	
	sequence::size_type sequence::size() const
	{
		return used;
	}

	bool sequence::is_item() const
	{
		return (current_index < used);
	}

	sequence::value_type sequence::current() const
	{
		assert(is_item());
		return data[current_index];
	}
}
