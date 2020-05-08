/*
# programming challenge
# Natural string order sorting
# C++ 17
# binariusO1
*/

// Natural string order sorting (a1,a2,a10,a20 instead of a1,a10,a2,a20)
// Natural sorting
bool CprStringNatural(string& a, string& b)
{
	if ((a.size() < b.size()))
		return 1;
	else if ((a.size() > b.size()))
		return 0;
	else
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] < b[i])
				return 1;
			if (a[i] > b[i])
				return 0;
		}
	}
	return 0;
}
