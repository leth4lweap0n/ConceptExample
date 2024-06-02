#include <algorithm>
#include <iostream>
#include <vector>
#include <Windows.h>

template<typename T>
concept sortable = requires(T a, T b) {
	{ a < b } -> _STD convertible_to<bool>;
};

template<sortable T>
void sort(T& container) {

	for (size_t i = 0; i < container.size(); i++) {
		for (size_t j = 0; j < container.size() - 1; j++) {
			if (container[j] > container[j + 1]) {
				_STD swap(container[j], container[j + 1]);
			}
		}
	}

	_STD cout << "--> Sort Success BrooO !" << '\n';
}

int main() {

	_STD vector vecNumbers = { 1, 5, 2, 7, 22, 9 ,31,7,47,35 };

	sort(vecNumbers);

	_RANGES for_each(vecNumbers, [](const auto& x) {
		_STD cout << x << ' ';
		});

	return EXIT_SUCCESS;
}