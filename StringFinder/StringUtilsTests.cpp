#include "stdafx.h"
#include "StringUtils.h"
#include "SearchDFA.h"
#include "PrefixFunction.h"
#include <sstream>
#include <boost/algorithm/string.hpp>

using std::vector;
using std::string;

BOOST_AUTO_TEST_SUITE(StringUtils_class)
	BOOST_AUTO_TEST_CASE(can_check_if_contains)
	{
		const std::string needle = "ax";
		const std::string text = "axdaxabxo!";
		CSearchDFA dfa;
		dfa.Compile(needle);
		BOOST_CHECK(CStringUtils::Contains(text, dfa));
	}

	BOOST_AUTO_TEST_CASE(can_count_all_matches)
	{
		const std::string needle = "ax";
		const std::string text = "axdaxabxo!";
		CSearchDFA dfa;
		dfa.Compile(needle);
		unsigned count = CStringUtils::Count(text, dfa);
		BOOST_CHECK_EQUAL(count, 2);
	}

	BOOST_AUTO_TEST_CASE(can_find_all_matches)
	{
		const std::string needle = "ax";
		const std::string text = "axdaxabxo!";
		CSearchDFA dfa;
		dfa.Compile(needle);
		std::vector<size_t> matches = CStringUtils::FindAll(text, dfa);
		std::vector<size_t> expected = {0, 3};
		BOOST_CHECK(matches == expected);
		
	}

	BOOST_AUTO_TEST_CASE(calculates_prefix_function_to_inputted_string)
	{
		const std::string needle = "abcdabcabcdabcdab";
		std::vector<int> expectedPrefixFunction = { 0,0,0,0,1,2,3,1,2,3,4,5,6,7,4,5,6 };
		BOOST_CHECK(GetSearchPrefixFunctions(needle) == expectedPrefixFunction);

		const std::string needle1 = "abcaby";
		CSearchDFA dfa;
		dfa.Compile(needle1);
	}
BOOST_AUTO_TEST_SUITE_END()