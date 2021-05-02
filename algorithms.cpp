//
//стек вызовов -- DONE - StackWeightsCalls
//переполнение стека -- DONE - OverFlowWeight_ERR
//пирамидальная сортировка (heap sort) -- DONE - WeightHeapSort (и вложенные)
//поиск значения при мин. кол-ве итераций (binary search) -- DONE - BinSearchWeight
//
//бор и префиксное древо(map)
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Food {

private:

	unsigned int distance = NULL;
	string way;

	void SortPyramid(vector<int>& weights) {
		for (size_t sort_it = 0; sort_it < weights.size() - 2; sort_it++) {
			swap(weights[0], weights[((weights.size() - 1) - sort_it)]);
			HeapMake(weights, 0, sort_it);
		}

		if (weights[0] > weights[1]) swap(weights[0], weights[1]);
	}
	void HeapMake(vector<int>& weights, int middle, size_t sort_it) {
		for (int i = middle; i >= 0; i--)
		{
			int left = 2 * i + 1; int right = 2 * i + 2;

			if (weights[left] > weights[right] and weights[left] > weights[i] and left < (weights.size() - 1) - sort_it) {
				swap(weights[i], weights[left]);

				if (left <= weights.size() / 2 - 1)
					i = left + 1;
			}

			else if (weights[right] > weights[left] and weights[right] > weights[i] and right < (weights.size() - 1) - sort_it) {
				swap(weights[i], weights[right]);

				if (right < weights.size() / 2 - 1)
					i = right + 1;
			}

		}
	}

public:

	string OverFlowWeight_ERR(vector<int> weights) {

		cout << "Функция OverFlowWeight_ERR: начала выполнение! " << endl;

		weights.push_back(5);

		try
		{
			for (size_t i = 0; i < weights.size() + 1; i++)
			{
				if (i >= weights.size())
				{
					throw runtime_error("** Функция OverFlowWeight_ERR: переполнение стека! **");
				}
				cout << "  Вывод элемента вектора: " << weights[i] << endl;
			}
		}
		catch (const std::exception&ERR)
		{
			cout << ERR.what() << endl;
		}

		return "Функция OverFlowWeight_ERR: закончила выполнение!";

	}

	string StackWeightsCalls(vector<int> weights) {

		cout << "Функция StackWeightsCalls: начала выполнение! " << endl;

		if (weights.size() < 1)
		{
			weights.push_back(rand());
			cout << "  Добавилось число: " << weights[0] << " Размер стека: " << weights.size() << endl;
		}

		for (auto& it : weights) {
			weights.pop_back();
			cout << "  Удалилось число: " << it << " Размер стека: " << weights.size() << endl;
			cout << "  Указатель занулен!" << endl;
			weights.shrink_to_fit(); //освобождение памяти
		}

		return "Функция StackWeightsCalls: закончила выполнение!";

	}

	string BinSearchWeight(vector<int> counts, int sought) {
		cout << "Функция BinSortWeight: начала выполнение! " << endl;

		if (find(counts.begin(), counts.end(), sought) == counts.end()) 
			return "Функция BinSortWeight: *ERR* данного числа нет в векторе!";

		sort(counts.begin(), counts.end());
		
		bool Flag = false;

		//границы
		unsigned int left = NULL;
		unsigned int middle = NULL;
		unsigned int right = counts.size();

		while (left <= right)
		{
			middle = (right + left) / 2;

			if (counts[middle] == sought) { Flag = true; break; }
			if (counts[middle] < sought) left = middle;
			else right = middle;
		}

		if (Flag) cout << "  Искомое значение " << sought << " найдено по индексу: " << middle << endl;
		else cout << "  Искомое значение не найдено! " << endl;

		return "Функция BinSortWeight: закончила выполнение!";

	}

	string WeightHeapSort(vector<int> weights) {
		cout << "Функция WeightHeapSort: начала выполнение! " << endl;
		
		cout << "  Изначальный вектор: ";
		for (auto& it : weights) cout << it << ' ';
		cout << endl;

		HeapMake(weights, weights.size() / 2 - 1, NULL);
		SortPyramid(weights);
		
		cout << "  Отсортированный вектор: ";
		for (auto &it : weights) cout << it << ' '; 
		cout << endl;

		return "Функция WeightHeapSort: закончила выполнение!";
	}

};

void main() {

	setlocale(LC_ALL, "RU");

	vector<int> weights;
	Food Chickens;

	cout << Chickens.StackWeightsCalls(weights) << endl << endl;

	cout << Chickens.OverFlowWeight_ERR(weights) << endl << endl;

	weights = { 4, 2, 3, 1, 12, 5, 7, 8, 11, 10 };
	cout << Chickens.BinSearchWeight(weights, 1) << endl << endl;

	weights = { 12, 11, 13, 5, 6, 7, 8 };
	cout << Chickens.WeightHeapSort(weights) << endl << endl;

}
