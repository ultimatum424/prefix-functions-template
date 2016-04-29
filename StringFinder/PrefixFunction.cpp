#include "stdafx.h"
#include "PrefixFunction.h"

std::vector<int> GetSearchPrefixFunctions(const std::string &needle)
{
	std::vector<int> result(needle.size(), 0);
	result[0] = 0;
	int k = 0;
	for (int i = 1; i < needle.size(); i++) {
		while ((k > 0) && (needle[k] != needle[i]))
			k = result[k - 1];
		if (needle[k] == needle[i])
			k++;
		result[i] = k;
	}
	return result;
}

