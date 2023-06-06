#pragma once
class Sumy
{
	#include <iostream>
	#include <tuple>
	#include <vector>
	#include <algorithm>

	using namespace std;
	int n, m, x;
	typedef vector<tuple<int, int, char>> data_list;

	int main()
	{
		data_list dl;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> m;
			dl.push_back(tuple<int, int, char>(m, i, 'N'));
		}
		sort(dl.begin(), dl.end());

		for (int i = 0; i < dl.size(); i++)
		{
			cout << get<0>(dl[i]) << "  " << get<1>(dl[i]) << "  " << get<2>(dl[i]) << endl;
		}

		int curr = n / 2;
		int min = 0;

		x = get<0>(dl[curr]);
		cout << "poczatkowe x: " << x;
		cout << endl << n << endl;


		// jakaœ petla tutaj
		while (min != curr)
		{
			for (int i = 0; i < dl.size() - 1; i++)
			{
				cout << x << "   ";
				if (curr == i)
				{
					continue;
				}
				if ((i < n) && (x > get<0>(dl[i])))
					x += get<0>(dl[i]);
				else
					break;
			}
			//x = x - get<0>(dl[curr]);
			cout << "\naktualne x: " << x << endl;
			cout << "aktualne curr: " << curr << endl;
			if (x > get<0>(dl[n - 1]))
			{
				for (int i = curr; i < n; i++) // b³¹d
				{
					get<2>(dl[i]) = 'T';
					cout << get<0>(dl[i]) << "  " << get<1>(dl[i]) << "  " << get<2>(dl[i]) << endl;
				}
				n = curr + 1;
				curr = n / 2;
				x = get<0>(dl[curr]);
			}
			else
			{
				min = curr;
				curr = (min + n) / 2;
				x = get<0>(dl[curr]);
				cout << "\naktualne x w else: " << x << endl;
			}
			cout << "kontynuje.." << endl;
			cout << "aktualne min: " << min << endl;
			cout << "aktualne n: " << n << endl;
			cout << "aktualne curr: " << curr << endl << endl;

			//getchar();
		}

		sort(dl.begin(), dl.end(),
			[](const tuple<int, int, char>& a,
				const tuple<int, int, char>& b) -> bool
			{
				return get<1>(a) > get<1>(b);
			});
		cout << endl << " roz\n";
		for (int i = dl.size() - 1; i >= 0; i--)
		{
			cout << get<1>(dl[i]) << " " << get<0>(dl[i]) << " " << get<2>(dl[i]) << endl;
		}
		cout << "\n\nRozwiazanie zadania ponizej: " << endl;

		// test
		string testString = "TNN";
		int countTest = 0;
		int y = 0;
		for (int i = dl.size() - 1; i >= 0; i--)
		{
			cout << get<2>(dl[i]) << " ";
			cout << testString[y] << endl;
			if (get<2>(dl[i]) == testString[y])
			{
				countTest++;
			}
			else
				break;
			y++;
		}
		if (countTest == dl.size())
		{
			cout << "Test przebiegl prawidlowo";
		}
		else
		{
			cout << "ERROR" << " " << countTest;
		}
	}
};

