#pragma once

#include "stdafx.h"
#include "structs.h"

class Tokenizer
{
public:
	Tokenizer(std::string const& str);

	int GetToken(Token& token);
	void SkipSpaces();

private:
	double ParseDouble();
	boost::string_ref m_str;
};
