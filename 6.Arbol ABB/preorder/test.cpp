#include "preorder.h"

#include <cassert>
#include <vector>

using namespace std;

template<typename T>
bool test_present(vector<T> const &vec, T const &t)
{
	for (size_t k = 0; k < vec.size(); ++k) {
		if (vec[k] == t)
			return true;
	}

	return false;
}

template<typename T>
void test_vec(vector<T> const &vec)
{
	for (size_t k = 0; k < vec.size(); ++k) {
		assert(preorder_search(vec, vec[k] == true));
	}
}

template<typename T>
void test_interval(vector<T> const &vec, T const &lo, T const &hi)
{
	for (T iter = lo; iter <= hi; ++iter) {
		assert(preorder_search(vec, iter) == test_present(vec, iter));
	}

}

vector<int>
vector_preorder(int lo, int hi)
{
	vector<int> vec;
	int m = (lo + hi) / 2;

	if (lo <= hi)
		vec.push_back(m);

	if (lo < m) {
		vector<int> l = vector_preorder(lo, m - 1);
		vec.insert(vec.end(), l.begin(), l.end());
	}

	if (hi > m) {
		vector<int> r = vector_preorder(m + 1, hi);
		vec.insert(vec.end(), r.begin(), r.end());
	}

	return vec;
}

void
run_tests()
{
	vector<int> vec0 = {};
	vector<int> vec1 = {1};
	vector<int> vec2 = {1, 2};
	vector<int> vec3 = {3, 1, 2};

	assert(preorder_search(vec0, 0) == false);

	assert(preorder_search(vec1, 0) == false);
	assert(preorder_search(vec1, 1) == true);
	assert(preorder_search(vec1, 2) == false);

	assert(preorder_search(vec2, 0) == false);
	assert(preorder_search(vec2, 1) == true);
	assert(preorder_search(vec2, 2) == true);
	assert(preorder_search(vec2, 3) == false);

	assert(preorder_search(vec3, 0) == false);
	assert(preorder_search(vec3, 1) == true);
	assert(preorder_search(vec3, 2) == true);
	assert(preorder_search(vec3, 3) == true);
	assert(preorder_search(vec3, 4) == false);

	test_interval(vec0, -1000, +1000);
	test_interval(vec1, -1000, +1000);
	test_interval(vec2, -1000, +1000);
	test_interval(vec3, -1000, +1000);

	for (int k = 0; k < 100; ++k) {
		vector<int> vec = vector_preorder(0, k);
		test_interval(vec, -200, +200);
	}
}

int main()
{
    run_tests();
}
