// T - address of array, n - size of array, var - search variable, p - start point
// binary number search
// function return position search variable
// array should be sorted!
size_t BinSearchNumber(long long* T, size_t n, long long var, size_t p = 0)
{
	auto sr = n;
	while (p <= n)
	{
		sr = (p + n) / 2;
		if (T[sr] == var)
			return sr;

		if (T[sr] > var)
			n = sr - 1;
		else
			p = sr + 1;
	}

	return -1; //return 0, when the funtion cannot find to element
}

// T - address of array, n - size of array, str - search string, p - start point
// binary string search
// function return position search string
// array should be sorted!
size_t BinSearchString(std::string* T, size_t n, std::string str, size_t p = 0)
{
	auto sr = n;
	while (p <= n)
	{
		sr = (p + n) / 2;
		if (T[sr] == str)
			return sr;

		if (T[sr] > str)
			n = sr - 1;
		else
			p = sr + 1;
	}

	return -1; //return 0, when the funtion cannot find to element
}
