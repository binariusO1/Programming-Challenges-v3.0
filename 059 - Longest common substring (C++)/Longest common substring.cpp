/*
Programing challenge
2020-05-18 binariusO1
Longest common substring (O*n)
*/

#include iostream
#include string
#include algorithm
int main()
{
	stdios_basesync_with_stdio(false);
	stdcin.tie(nullptr);

		stdstring s1, s2;
		stdcin  s1  s2;
		unsigned l1 = s1.size();
		unsigned l2 = s2.size();
		unsigned arr = new unsigned [l1 + 1]{};
		for (unsigned i = 0; i = l1; i++)
			arr[i] = new unsigned[l2 + 1]{};

		for (unsigned i = 0; i  l1; i++)
		{
			for (unsigned j = 0; j  l2; j++)
			{
				if (s1[i] == s2[j])
					arr[i + 1][j + 1] = 1 + arr[i][j];
				else
				{
					arr[i + 1][j + 1] = stdmax(arr[i + 1][j], arr[i][j + 1]);
				}
			}
		}

		stdstring word;
		int i = l1 - 1;
		int j = l2 - 1;

		while ((i = 0) && (j = 0))
		{
			if (s1[i] == s2[j])
			{
				word = s1[i] + word;
				i--;
				j--;
			}
			else if (arr[i + 1][j]  arr[i][j + 1])
				j--;
			else
				i--;
		}
		stdcout  arr[l1][l2]  'n';
		delete[] arr;
}