#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <time.h>



class Record
{
public:
	Record(int _price, int _count);
	int count;
	int price;
};

Record::Record(int _price,int  _count)
{
	price = _price;
	count = _count;
}

enum class SortBy { PRICE, COUNT };


// QUESTION 1!

//template<typename T>
//T scalerProduct(std::vector<T> vec1, std::vector<T> vec2)
//{
//
//
//	return vec1[0] + vec2[0] + vec1[1] + vec2[1] + vec1[2] + vec2[2];
//}


// QUESTION 2!

//template<typename T1>
//
//std::pair<T1, T1> minMax(std::vector<T1> const& t_vec)
//{
//	int size = t_vec.size();
//	T1 lowest = 99999;
//	T1 highest = 0;
//
//	for (int i = 0; i < size; i++)
//	{
//		if (t_vec[i] < lowest)
//		{
//			lowest = t_vec[i];
//		}
//		if (t_vec[i] > highest)
//		{
//			highest = t_vec[i];
//		}
//	}
//
//	return std::pair<T1, T1> { lowest, highest };
//}

//template<typename T2>
//T2 sort()
//{
//
//}

bool isEven(int n)
{
	return n % 2 == 0;
}


/// <summary>
/// QUESTION 4!
/// </summary>
/// <returns></returns>
int divisible()
{
	srand(time(NULL));

	std::vector<int> randNums{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	for (int i = 0; i < 20 ; i++)
	{
		randNums.at(i) = (rand() % 9) + 1;
	}
	   /* auto is_even = [](auto e) {
			return e % 2 == 0; 
		};*/

	return std::count_if(randNums.begin(), randNums.end(), isEven);

}

/// <summary>
/// QUESTION 5
/// </summary>
/// <returns></returns>
int divisible2()
{

	srand(time(NULL));

		std::vector<int> randNums;

		for (int i = 0; i < 20; i++)
		{
			randNums.push_back((rand() % 9) + 1);
		}
		while (true)
		{
			std::vector<int>::iterator ansVec = std::find_if(randNums.begin(), randNums.end(), isEven);
			std::cout << *ansVec << std::endl;
			if (ansVec == randNums.end() - 1)
			{
				randNums.erase(ansVec);
				break;
			}
			else
				randNums.erase(ansVec);
		}
	return 1;
}


int main()
{
	std::vector<int> v1 = { 1,3,5 };
	std::vector<int> v2 = { 2,4,6 };

	std::vector<int> bigVec = { 5,2,7,1,9,8 };

	// Q1
	/*int result = scalerProduct(v1, v2);*/

	std::vector<Record> records = { Record(3, 10), Record(4, 20) };

	// Q2
	//std::pair<double, double> result2 =  minMax(bigVec);

	//std::cout << result2.first << std::endl;
	//std::cout << result2.second << std::endl;
	/*std::cout << result2 << std::endl;*/

	// Q4
	//int answer = divisible();

	//std::cout << answer << std::endl;

	int answer = divisible2();

	std::cout << "baba" << std::endl;
}


