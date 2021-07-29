#include "preorder.h"

#include <cassert>
#include <vector>
#include <iostream>
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
		//cout<<"iter= "<<iter<<endl;
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

	cout<<"test 1"<<endl;
	assert(preorder_search(vec0, 0) == false);
	cout<<"test 2"<<endl;
	assert(preorder_search(vec1, 0) == false);
	cout<<"test 3"<<endl;
	assert(preorder_search(vec1, 1) == true);
	cout<<"test 4"<<endl;
	assert(preorder_search(vec1, 2) == false);
	cout<<"test 4"<<endl;
	assert(preorder_search(vec2, 0) == false);
	cout<<"test 5"<<endl;
	assert(preorder_search(vec2, 1) == true);
	cout<<"test 6"<<endl;
	assert(preorder_search(vec2, 2) == true);
	cout<<"test 7"<<endl;
	assert(preorder_search(vec2, 3) == false);
	cout<<"test 8"<<endl;

	assert(preorder_search(vec3, 0) == false);
	cout<<"test 9"<<endl;
	assert(preorder_search(vec3, 1) == true);
	cout<<"test 10"<<endl;
	assert(preorder_search(vec3, 2) == true);
	cout<<"test 12"<<endl;
	assert(preorder_search(vec3, 3) == true);
	cout<<"test 13"<<endl;
	assert(preorder_search(vec3, 4) == false);
	cout<<"test 14"<<endl;
	test_interval(vec0, -1000, +1000);
	cout<<"test 15"<<endl;
	test_interval(vec1, -1000, +1000);
	cout<<"test 16"<<endl;
	test_interval(vec2, -1000, +1000);
	cout<<"test 17"<<endl;
	test_interval(vec3, -1000, +1000);
	cout<<"test 18"<<endl;
	for (int k = 0; k < 100; ++k) {
		cout<<" k = "<<k<<endl;
		vector<int> vec = vector_preorder(0, k);
		print_vect(vec);
		test_interval(vec, -200, +200);
	}
	cout<<"TERMINOOOOOOOOOOOOOO"<<endl;
}

int main()
{
    run_tests();
}
