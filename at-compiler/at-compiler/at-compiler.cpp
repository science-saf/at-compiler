// at-compiler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "structs.h"
#include "ParserWrapper.h"
#include "Tokenizer.h"
#include "grammar.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string str("2+3");
	Tokenizer t(str);
	Token token;
	ParserWrapper parserWrapper;
	while (true)
	{
		int tokenId = t.GetToken(token);
		parserWrapper.Parse(tokenId, token);
		if ((tokenId == 0) || (tokenId == TK_ERROR))
		{
			break;
		}
	}
	
	return 0;
}

