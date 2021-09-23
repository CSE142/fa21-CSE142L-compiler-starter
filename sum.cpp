#include <cstdlib>
#include "archlab.hpp"
#include <unistd.h>
#include"omp.h"
#include"papi.h"
#include<algorithm>
#include<cstdint>
#include<unordered_set>
#include"function_map.hpp"



#define START_C extern "C" { // this just hides the braces from the editor, so it won't try to indent everything.
#define END_C  }


START_C

uint64_t sum_of_locations(uint64_t *search_space, uint32_t search_space_size, uint64_t* queries, uint32_t query_count)
{
	uint64_t r = 0;

	for(uint32_t i = 0; i < query_count; i++) {
		for(uint32_t j = 0; j < search_space_size; j++) {
			if (search_space[j] == queries[i]) {
				r += i;
				break;
			}
		}
	}
	return r;
}
FUNCTION("sum_impl", sum_of_locations);

uint64_t sum_of_locations_solution(uint64_t *search_space, uint32_t search_space_size, uint64_t* queries, uint32_t query_count)
{
	uint64_t r = 0;

	for(uint32_t i = 0; i < query_count; i++) {
		for(uint32_t j = 0; j < search_space_size; j++) {
			if (search_space[j] == queries[i]) {
				r += i;
				break;
			}
		}
	}
	return r;
}

FUNCTION("sum_impl", sum_of_locations_solution);

uint64_t sum_of_locations_binsearch(uint64_t *search_space, uint32_t search_space_size, uint64_t* queries, uint32_t query_count)
{
	uint64_t r = 0;

	std::sort(&search_space[0],&search_space[search_space_size]);
	
	for(uint32_t i = 0; i < query_count; i++) {
		uint64_t upper = search_space_size;
		uint64_t lower = 0;

		while (lower != upper) {
			uint64_t mid = (upper + lower)/2;
			if (search_space[mid] == queries[i]) {
				r+=i;
				break;
			} else if (search_space[mid] > queries[i]) {
				upper = mid;
			} else if (search_space[mid] < queries[i]) {
				lower = mid;
			}
		}
		
	}
	return r;
}
FUNCTION("sum_impl", sum_of_locations_binsearch);

uint64_t sum_of_locations_set(uint64_t *search_space, uint32_t search_space_size, uint64_t* queries, uint32_t query_count)
{
	uint64_t r = 0;
	std::set<uint64_t> s;

	std::copy(&search_space[0],&search_space[search_space_size], std::inserter(s, s.begin()));
	
	for(uint32_t i = 0; i < query_count; i++) {
		if (s.find(queries[i]) != s.end())
			r+=i;
	}
	return r;
}

FUNCTION("sum_impl", sum_of_locations_set);

uint64_t sum_of_locations_unorderedset(uint64_t *search_space, uint32_t search_space_size, uint64_t* queries, uint32_t query_count)
{
	uint64_t r = 0;
	std::unordered_set<uint64_t> s;

	std::copy(&search_space[0],&search_space[search_space_size], std::inserter(s, s.begin()));
	
	for(uint32_t i = 0; i < query_count; i++) {
		if (s.find(queries[i]) != s.end())
			r+=i;
	}
	return r;
}

FUNCTION("sum_impl", sum_of_locations_unorderedset);

END_C
