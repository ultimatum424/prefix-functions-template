#include "stdafx.h"
#include "SearchDFA.h"
#include "PrefixFunction.h"

CSearchDFA::CSearchDFA()
{
}

CSearchDFA::~CSearchDFA()
{
}

void CSearchDFA::Compile(const std::string &needle)
{
	m_needle = needle;
	size_t n = m_needle.length();
	vector< vector<int> > nxt(n + 1, vector<int>(256));
	vector<int> p = GetSearchPrefixFunctions(m_needle); 
	nxt[0][m_needle[0]] = 1;
	for (int i = 1; i <= n; i++) {
		for (int c = 0; c < 256; c++)
			nxt[i][c] = nxt[p[i - 1]][c];
		if (i < n) nxt[i][m_needle[i]] = i + 1;
	}
}

size_t CSearchDFA::Find(const std::string &text, size_t from) const
{
	// TODO: реализовать метод "по-честному".

	// ѕодсказка: можно использовать boost::string_ref, чтобы не извлекать подстроку из текста.
	// Ёто позволит оптимизировать повторные вызовы Search на одной строке.
	
	return text.find(m_needle, from);
}