//
//���� ������� -- DONE - StackWeightsCalls
//������������ ����� -- DONE - OverFlowWeight_ERR
//������������� ���������� (heap sort) -- DONE - WeightHeapSort (� ���������)
//����� �������� ��� ���. ���-�� �������� (binary search) -- DONE - BinSearchWeight
//
//��� � ���������� �����(map)
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

		cout << "������� OverFlowWeight_ERR: ������ ����������! " << endl;

		weights.push_back(5);

		try
		{
			for (size_t i = 0; i < weights.size() + 1; i++)
			{
				if (i >= weights.size())
				{
					throw runtime_error("** ������� OverFlowWeight_ERR: ������������ �����! **");
				}
				cout << "  ����� �������� �������: " << weights[i] << endl;
			}
		}
		catch (const std::exception&ERR)
		{
			cout << ERR.what() << endl;
		}

		return "������� OverFlowWeight_ERR: ��������� ����������!";

	}

	string StackWeightsCalls(vector<int> weights) {

		cout << "������� StackWeightsCalls: ������ ����������! " << endl;

		if (weights.size() < 1)
		{
			weights.push_back(rand());
			cout << "  ���������� �����: " << weights[0] << " ������ �����: " << weights.size() << endl;
		}

		for (auto& it : weights) {
			weights.pop_back();
			cout << "  ��������� �����: " << it << " ������ �����: " << weights.size() << endl;
			cout << "  ��������� �������!" << endl;
			weights.shrink_to_fit(); //������������ ������
		}

		return "������� StackWeightsCalls: ��������� ����������!";

	}

	string BinSearchWeight(vector<int> counts, int sought) {
		cout << "������� BinSortWeight: ������ ����������! " << endl;

		if (find(counts.begin(), counts.end(), sought) == counts.end()) 
			return "������� BinSortWeight: *ERR* ������� ����� ��� � �������!";

		sort(counts.begin(), counts.end());
		
		bool Flag = false;

		//�������
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

		if (Flag) cout << "  ������� �������� " << sought << " ������� �� �������: " << middle << endl;
		else cout << "  ������� �������� �� �������! " << endl;

		return "������� BinSortWeight: ��������� ����������!";

	}

	string WeightHeapSort(vector<int> weights) {
		cout << "������� WeightHeapSort: ������ ����������! " << endl;
		
		cout << "  ����������� ������: ";
		for (auto& it : weights) cout << it << ' ';
		cout << endl;

		HeapMake(weights, weights.size() / 2 - 1, NULL);
		SortPyramid(weights);
		
		cout << "  ��������������� ������: ";
		for (auto &it : weights) cout << it << ' '; 
		cout << endl;

		return "������� WeightHeapSort: ��������� ����������!";
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
