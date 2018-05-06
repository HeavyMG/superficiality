#include <iostream>
#include <stdint.h>
#include <limits>
#include <numeric>
#include <cmath>
#include <conio.h>
#include <vector>
#include <random>
#include <boost/numeric/ublas/matrix.hpp>
#include <fstream>

struct city
{
	int x;
	int y;
	int index;
};

struct tsp
{
	std::vector<city> m_cities = { {1, 1, 1}, {1, 1, 1} };
	boost::numeric::ublas::matrix<int> distance;
	tsp(std::vector<city> cities)
		:m_cities(cities)
	{
		auto n = cities.size();
		boost::numeric::ublas::zero_matrix<int> temp(n, n);
		distance = temp;

		for (int i = 0; i < n - 1; ++i)
		{
			auto xi = cities[i].x;
			auto yi = cities[i].y;
			for (int j = i + 1; j < n; ++j)
			{
				auto xj = cities[j].x;
				auto yj = cities[j].y;

				auto dist = sqrt((xi - xj) * (xi - xj) + (yi - yj) * (yi - yj));
				distance(i, j) = static_cast<int>(dist);
				distance(j, i) = static_cast<int>(dist);
			}
		}
	}
};

void load_from_file(const std::string& filename)
{
	std::ifstream file;
	file.open(filename);


}

std::vector<int> ox(const std::vector<int>& parent_one, const int start, const int end,const std::vector<int>& parent_two)
{
	std::vector<int> res(parent_one.size());
	for (int i = start; i <= end; ++i)
	{
		res[i] = parent_one[i];
	}

	std::vector<int> two(parent_two.begin() + end + 1, parent_two.end());
	for (int i = 0; i <= end; ++i)
	{
		two.push_back(parent_two[i]);
	}

	for (int i = start; i <= end; ++i)
	{
		auto it = std::find(two.begin(), two.end(), res[i]);
		if (it != two.end())
		{
			two.erase(it);
		}
	}

	int count = 0;
	for (int i = end + 1; i < res.size(); ++i)
	{
		res[i] = two[count++];
	}

	for (int i = 0; i < start; ++i)
	{
		res[i] = two[count++];
	}

	return res;
}

void order_crossover(const std::vector<int>& first, const std::vector<int>& second)
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> frst(0, first.size());
	int random_j = 6; //frst(rng);
	std::uniform_int_distribution<int> scnd(0, random_j);
	int random_i = 3; //scnd(rng);

	auto offspring_one = ox(first, random_i, random_j, second);
	auto offspring_two = ox(second, random_i, random_j, first);

}

int main()
{
	std::vector<int> p1({ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
	std::vector<int> p2({ 4, 5, 2, 1, 8, 7, 6, 9, 3 });
	std::vector<int> res = ox(p2, 3, 6, p1);

	order_crossover(p1, p2);

	std::vector<city> m_cities = { { 1, 1, 1 },{ 1, 1, 1 } };
	tsp a(m_cities);
	while (_kbhit);
	return 0;
}