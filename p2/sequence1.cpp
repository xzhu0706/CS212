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
		{
			for (size_type i=used; i>0; i--)
				data[i] = data[i-1];
			data[0] = entry;
			current_index=0;
		} else
		{
			for (size_type i=used; i>current_index; i--)
				data[i] = data[i-1];
			data[current_index] = entry;
		}
		used++;
	}

	void sequence::attach(const value_type& entry)
	{
		assert(size() < CAPACITY);
		if (!is_item())
		{
			data[used] = entry;
			current_index = used;
		} else
		{
			for (size_type i=used; i>current_index+1; i--)
				data[i] = data[i-1];
			data[++current_index] = entry;
		}
		used++;
	}

	void sequence::remove_current()
	{
		assert(is_item());
		for (size_type i = current_index; i < used; i++)
			data[i] = data[i+1];
		used--;
	}
	
	sequence::size_type sequence::size() const
	{
		return used;
	}

	bool sequence::is_item() const
	{
		return (current_index<used && used<=CAPACITY);
	}

	sequence::value_type sequence::current() const
	{
		assert(is_item());
		return data[current_index];
	}
}
