#pragma once

namespace epicyclism
{
	template<typename I> void qsort(I b, I e)
	{
		auto swap = [&](I l, I r)
		{
			auto tmp = *l;
			*l = *r;
			*r = tmp;
		};
		auto partition = [&](I l, I r)
		{
			--r;
			auto v = *r;
			auto i = l;
			while (l < r)
			{
				if (*l < v)
				{
					swap(i, l);
					++i;
				}
				++l;
			}
			swap(i, r);
			return i;
		};
		if (b < e)
		{
			I sp = partition(b, e);
			qsort(b, sp);
			qsort(sp + 1, e);
		}
	}
}