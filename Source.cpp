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

void reverse_sort(std::vector<int>& data)
{
	auto size = data.size();
	for (int i = 0; i < (size / 2); i++)
	{

		auto copy = data[i];
		data[i] = data[size - 1 - i];
		data[size - 1 - i] = copy;
	}
}
std::vector<int> create_vector(size_t size)
{
	std::vector<int> data;
	int elem = 0;
	for (int i = 0; i < size; i++)
	{
		elem = -1000 + rand() % 2001;
		data.push_back(elem);
	}
	return data;
}
stats selection_sort(std::vector<int>& data)
{
	auto size = data.size();
	stats st;
	st.comparison_count = 0;
	st.copy_count = 0;
	for (int i = 0; i < size - 1; i++)
	{
		int min_index = i;
		for (int j = i + 1; j < size; j++)
		{
			if (data[j] < data[min_index])
			{
				min_index = j;
			}
			st.comparison_count++;
		}
		if (min_index != i)
		{

			auto copy = data[i];
			data[i] = data[min_index];
			data[min_index] = copy;
			st.copy_count++;
		}
	}
	return st;
}
stats shell_sort(std::vector<int>& data)
{
	if (data.size() < 1) throw "Размер некорректен";
	stats st;
	st.comparison_count = 0;
	st.copy_count = 0;
	auto size = data.size();
	int step = size;
	bool last_step = true;
	while (step > 1 || last_step)
	{
		last_step = false;
		if (step > 1)
			step = (int)(step / 2);
		for (int i = 0; (i + step) < size; i++)
		{
			if (data[i] > data[i + step]) {

				auto copy = data[i];
				data[i] = data[i + step];
				data[i + step] = copy;
				last_step = true;
				st.copy_count++;
			}
			st.comparison_count++;
		}
	}
	return st;
}
