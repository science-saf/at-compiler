#include "stdafx.h"
#include "Tokenizer.h"
#include "structs.h"
#include "grammar.h"

using namespace std;

Tokenizer::Tokenizer(string const& str)
	: m_str(str)
{
}

int Tokenizer::GetToken(Token& token)
{
	SkipSpaces();
	if (m_str.empty())
	{
		return 0;
	}

	double value = ParseDouble();
	if (!isnan(value))
	{
		token.value = value;
		return TK_NUMBER;
	}
	switch (m_str[0])
	{
	case '+':
		m_str.remove_prefix(1);
		return TK_PLUS;
		break;
	default:
		return TK_ERROR;
		break;
	}
}

void Tokenizer::SkipSpaces()
{
	size_t i = 0;
	while (i < m_str.size() && isspace(m_str[i]))
	{
		++i;
	}
	m_str.remove_prefix(i);
}

double Tokenizer::ParseDouble()
{
	double value = 0;
	bool parsedAny = false;
	while (!m_str.empty() && isdigit(m_str[0]))
	{
		parsedAny = true;
		const int digit = m_str[0] - '0';
		value = value * 10.0 + double(digit);
		m_str.remove_prefix(1);
	}
	if (!parsedAny)
	{
		return numeric_limits<double>::quiet_NaN();
	}

	if (m_str.empty() || (m_str[0] != '.'))
	{
		return value;
	}
	m_str.remove_prefix(1);
	double factor = 1;
	while (!m_str.empty() && isdigit(m_str[0]))
	{
		const int digit = m_str[0] - '0';
		factor *= 0.1;
		value += factor * double(digit);
		m_str.remove_prefix(1);
	}

	return value;
}