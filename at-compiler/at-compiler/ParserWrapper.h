#pragma once

#include "structs.h"

class ParserWrapper
{
public:
	ParserWrapper();
	~ParserWrapper();

	void Parse(int tokenId, Token& token);
private:
	void* m_parserPtr;
};