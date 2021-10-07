#include <vector>
#include <iostream>







template<typename T>
T scalerProduct(std::vector<T> vec1, std::vector<T> vec2)
{


	return vec1[0] + vec2[0] + vec1[1] + vec2[1] + vec1[2] + vec2[2];
}


template<typename T1>
T1 minMax(std::vector<T1> vec)
{
	int size = vec.size();
	int lowest = 0;
	int highest = 0;

	for (int i = 0; i < size; i++)
	{

	}

}

int main()
{
	std::vector<int> v1 = { 1,3,5 };
	std::vector<int> v2 = { 2,4,6 };

	std::vector<int> bigVec = { 5,2,7,1,9,8 };

	int result = scalerProduct(v1, v2);
	int result2 = minMax(bigVec);
	std::cout << result2 << std::endl;
}