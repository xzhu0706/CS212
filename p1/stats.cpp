// Xiaohong Zhu
// CS212   9/15/2017
// Assignment #1
#include "stats.h"
#include <cassert>

namespace main_savitch_2C
{
	statistician::statistician( )
	{
		total = 0;
		count = 0;
		tinyest = 0;
		largest = 0;
	}

	void statistician::next(double r)
	{
		total += r;
		count++;
		if (r < tinyest)
		{
			tinyest = r;
			if (count == 1) largest = r;
		}
		if (r > largest) 
		{
			largest = r;
			if (count == 1) tinyest = r;
		}
	}

	void statistician::reset( )
	{
		total = 0;
		count = 0;
		tinyest = 0;
		largest = 0;
	}

	int statistician::length( ) const
	{
		return count;
	}

	double statistician::sum( ) const
	{
		return total;
	}

	double statistician::mean( ) const
	{
		assert (count > 0);
		return (total/count);
	}

	double statistician::minimum( ) const
	{
		assert (count > 0);
		return tinyest;
	}

	double statistician::maximum( ) const
	{
		assert (count > 0);
		return largest;
	}

	statistician operator+(const statistician& s1, const statistician& s2)
	{
		if (s1.count == 0 && s2.count == 0)
			return statistician();
		if (s1.count == 0 && s2.count > 0) 
			return statistician(s2);
		if (s1.count > 0 && s2.count == 0)
			return statistician(s1);
		statistician s3;
		s3.total = s1.total + s2.total;
		s3.count = s1.count + s2.count;
		if (s1.tinyest < s2.tinyest) s3.tinyest = s1.tinyest;
		else s3.tinyest = s2.tinyest;
		if (s1.largest > s2.largest) s3.largest = s1.largest;
		else s3.largest = s2.largest;
		return s3;
	}

	statistician operator*(double scale, const statistician& s)
	{
		statistician s2;
		s2.total = (scale * s.total);
		s2.count = s.count;
		if (scale > 0)
		{
			s2.tinyest = (scale * s.tinyest);
			s2.largest = (scale * s.largest);
		} else
		{
			s2.tinyest = (scale * s.largest);
			s2.largest = (scale * s.tinyest);
		}
		return s2;
	}

	bool operator==(const statistician& s1, const statistician& s2)
	{
		if (s1.length() == s2.length())
		{
			if (s1.length() == 0)
				return true;
			if (s1.sum() == s2.sum() && s1.mean() == s2.mean() && s1.minimum() == s2.minimum() && s1.maximum() == s2.maximum())
				return true;
		}
		return false;
	}
}
