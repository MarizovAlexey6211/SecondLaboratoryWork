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

struct info_grath
{
	int size;
	std::string sort = "";
	std::string view_vector = "";
	stats st;
};

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
	if (data.size() < 1) throw "incorrect size";
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

stats generate_vect(size_t num, size_t size, stats sort(std::vector<int>& data))
{
	stats st;
	int elem;
	std::vector<int> vect;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < size; j++)
		{
			elem = -1000 + rand() % 2001;
			vect.push_back(elem);
		}
		stats st_sort = sort(vect);
		vect.clear();
		st.comparison_count += st_sort.comparison_count;
		st.copy_count += st_sort.copy_count;
	}
	st.comparison_count /= num;
	st.copy_count /= num;
	return st;
}

void data_stats(int size, std::vector<info_grath>& data_grath)//2
{
	info_grath info;
	stats sts = generate_vect(100, size, shell_sort);
	info.size = size;
	info.sort = "Shell";
	info.st = sts;
	info.view_vector = "Average";
	data_grath.push_back(info);

	auto _vect = create_vector(size);
	auto vect = _vect;
	shell_sort(vect);
	sts = shell_sort(vect);
	info.size = size;
	info.sort = "Shell";
	info.st = sts;
	info.view_vector = "Sorted";
	data_grath.push_back(info);

	reverse_sort(vect);
	sts = shell_sort(vect);
	info.size = size;
	info.sort = "Shell";
	info.st = sts;
	info.view_vector = "Back_sorted";
	data_grath.push_back(info);

	sts = generate_vect(100, size, selection_sort);
	info.size = size;
	info.sort = "Selection";
	info.st = sts;
	info.view_vector = "Average";
	data_grath.push_back(info);


	selection_sort(_vect);
	sts = selection_sort(_vect);
	info.size = size;
	info.sort = "Selection";
	info.st = sts;
	info.view_vector = "Sorted";
	data_grath.push_back(info);

	reverse_sort(_vect);
	sts = selection_sort(_vect);
	info.size = size;
	info.sort = "Selection";
	info.st = sts;
	info.view_vector = "Back_sorted";
	data_grath.push_back(info);
}