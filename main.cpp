#include <iostream>
#include <vector>

int main() {
	std::vector<int> vecNumbers = {-2,1,-3,4,-1,2,1,-5,4};
	int start = 0, end = 0;
	int currS = 0, currE = 0;
	int currSum = 0;
	int max = vecNumbers[0];
	bool newSum = false;
	bool haveNotI = true;
  
	for (int i = 0; i < vecNumbers.size() - 1; ++i) {
		if (newSum || vecNumbers[i] >= 0) {
			newSum = true;
			if (currSum + vecNumbers[i] >= currSum) {
				if (haveNotI) {
					currS = i;
					haveNotI = false;
				}
				currE = i;
				currSum += vecNumbers[i];
			}
			else {
				if (currSum + vecNumbers[i] < 0) {
					haveNotI = true;
					newSum = false;
					currSum = 0;
				}
				else
					currSum += vecNumbers[i];
			}
			if (currSum > max) {
				max = currSum;
				start = currS;
				end = currE;
			}
		} 
		else {
			currSum = 0;
		}
	}
	std::cout << start << " and " << end << std::endl;
}

/*
Вам даётся массив целых чисел. Необходимо найти такие два индекса i и j в этом массиве, что сумма a[i], a[i+1], a[i+2], … a[j] будет максимально возможной и вывести их.
Пример:
a = {-2,1,-3,4,-1,2,1,-5,4}
Тогда наибольшая сумма последовательных элементов находится между индексами 3 и 6: {4,-1,2,1}, сумма = 6. Необходимо вывести 3 и 6
*/