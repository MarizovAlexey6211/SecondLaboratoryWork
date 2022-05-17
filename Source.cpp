#include <iostream>
#include <time.h>
#include <random>
#include <fstream>
using namespace std;

struct stats {
	size_t comparison_count = 0;
	size_t copy_count = 0;
};
stats selection_sort(std::vector<int>& data);
stats shell_sort(std::vector<int>& data);

template <typename T>
void print_mas(T* arr, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void print_vector(std::vector<T>& data)
{
	auto size = data.size();
	for (int i = 0; i < size; i++)
	{
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}