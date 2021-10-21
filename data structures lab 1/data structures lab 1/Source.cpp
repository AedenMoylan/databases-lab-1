#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <time.h>

class Record
{
public:
	Record(int t_price, int t_count);
	int getPrice();
	int getCount();

private:
	int price;
	int count;
};

enum class SortBy
{
	PRICE,
	COUNT

};

class RecordSort
{
public:
	SortBy sortType;
	RecordSort(SortBy t_sort);

	bool operator() (Record t_recOne, Record t_recTwo)
	{
		if (sortType == SortBy::PRICE)
		{
			return t_recOne.getPrice() < t_recTwo.getPrice();
		}
		else
		{
			return t_recOne.getCount() < t_recTwo.getCount();
		}
	}
};


// QUESTION 1!

template<typename T>
T scalerProduct(std::vector<T> vec1, std::vector<T> vec2)
{


	return vec1[0] + vec2[0] + vec1[1] + vec2[1] + vec1[2] + vec2[2];
}


// QUESTION 2!

template<typename T1>

std::pair<T1, T1> minMax(std::vector<T1> const& t_vec)
{
	int size = t_vec.size();
	T1 lowest = 99999;
	T1 highest = 0;

	for (int i = 0; i < size; i++)
	{
		if (t_vec[i] < lowest)
		{
			lowest = t_vec[i];
		}
		if (t_vec[i] > highest)
		{
			highest = t_vec[i];
		}
	}

	return std::pair<T1, T1> { lowest, highest };
}

template<typename T2>
T2 sort()
{

}

bool isEven(int n)
{
	return n % 2 == 0;
}


/// <summary>
/// QUESTION 4 and 5!
/// </summary>
/// <returns></returns>
int divisible()
{
	srand(time(NULL));

	std::vector<int> randNums;

	for (int i = 0; i < 20; i++)
	{
		randNums.push_back((rand() % 9) + 1);
	}
	int answer = std::count_if(randNums.begin(), randNums.end(), isEven);

	for (int i = 0; i < answer; i++)
	{
		std::vector<int>::iterator ansVec = std::find_if(randNums.begin(), randNums.end(), isEven);
		randNums.erase(ansVec);

		

	}
	/*for (int i = 0; i < randNums.size(); i++)
	{
		std::cout << randNums[i] << std::endl;
	}*/
	return randNums.size();
}

Record::Record(int t_price, int t_count) : price(t_price), count(t_count)
{
}

int Record::getPrice()
{
	return price;
}

int Record::getCount()
{
	return count;
}

class isEvenFunctor
{
public:
	bool operator()(int number)
	{
		return number % 2 == 0;
	}
};

RecordSort::RecordSort(SortBy t_sort)
{
}

class Gamer
{
public:
	Gamer() {}
	// Destructor function
	~Gamer()
	{
		std::cout << "Destructor called" << std::endl;
	}
	// Define a copy constructor
	Gamer(Gamer const& t_copy)
	{
		std::cout << "Copy constructor called" << std::endl;
	}
};

//std::vector<int> randomizeVector()
//{
//	std::vector<int> ansVec;
//	for (int i = 0; i < 20; i++)
//	{
//		ansVec.push_back((rand() % 9) + 1);
//	}
//}
	int main()
	{
		srand(time(NULL));

		std::vector<int> Vector = { 1,2,3 };
		std::vector<int> v1 = { 1,3,5 };
		std::vector<int> v2 = { 2,4,6 };
		std::vector<int> Q6Vector;
		std::vector<int> Q7Vector;
		std::vector<int> bigVec = { 5,2,7,1,9,8 };

	
		

		// Q1
		/*int result = scalerProduct(v1, v2);*/

		// Q2
		//std::pair<double, double> result2 =  minMax(bigVec);

		//std::cout << result2.first << std::endl;
		//std::cout << result2.second << std::endl;
		/*std::cout << result2 << std::endl;*/

		std::vector<Record> records = { Record(3,20), Record(2,10), Record(9,80), Record(7,50) };

		SortBy sortPrice = SortBy::PRICE;
		std::sort(records.begin(), records.end(), RecordSort(sortPrice));

		SortBy sortCount = SortBy::COUNT;
		std::sort(records.begin(), records.end(), RecordSort(sortCount));

		// Q4 + Q5
		 int answer = divisible();

		//	// Q6
		for (int i = 0; i < 20; i++)
		{
			Q6Vector.push_back((rand() % 9) + 1);
			Q7Vector.push_back((rand() % 9) + 1);
		}

		Q6Vector.erase(std::remove_if(std::begin(Q6Vector), std::end(Q6Vector), isEvenFunctor()), std::end(Q6Vector));


		//Q7
		Q7Vector.erase(std::remove_if(std::begin(Q7Vector), std::end(Q7Vector), [](int num)
			{
				if (num % 2 == 0)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		),
			std::end(Q7Vector));

		// Q8 and Q9
		Gamer gamer;
		Gamer* gamerPointer = new Gamer;
		
		int loopCount = 5;
		std::vector<Gamer> gamerVector{};
		std::vector<Gamer *> gamerVectorPointer{};

		for (int i = 0; i < loopCount; i++)
		{
			gamerVector.push_back(gamer);
			gamerVectorPointer.push_back(gamerPointer);
		}

		/*std::cout << gamerVector.size() << std::endl;
		std::cout << gamerVector.capacity() << std::endl;*/

		std::cout << gamerVectorPointer.size() << std::endl;
		std::cout << gamerVectorPointer.capacity() << std::endl;



		//gamerVector.clear();
		gamerVectorPointer.clear();

		/*std::cout << gamerVector.size() << std::endl;
		std::cout << gamerVector.capacity() << std::endl;*/

		/*std::cout << gamerVectorPointer.size() << std::endl;
		std::cout << gamerVectorPointer.capacity() << std::endl;*/

		// the higher count is, the higher capacity is. size gets cleared but capacity does not;
		// clear erases the contents the gamerVector, but the number of cells stays the same

		//using the clear function on pointers does not call the destructor in the Gamer class.
		//the output of size and capacity is still the same



//		std::cout << "baba" << std::endl;

		std::cin.get();
	}

